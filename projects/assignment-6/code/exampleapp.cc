//------------------------------------------------------------------------------
// exampleapp.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "exampleapp.h"

#include <cstring>


int LightNode::id = 0;
using namespace Display;
namespace Example
{
	//------------------------------------------------------------------------------
	/**
	*/
	ExampleApp::ExampleApp()
	{
		// empty
	}

	//------------------------------------------------------------------------------
	/**
	*/
	ExampleApp::~ExampleApp()
	{
		// empty
	}

	//------------------------------------------------------------------------------
	/**
	*/
	bool
		ExampleApp::Open()
	{
		App::Open();
		this->window = new Display::Window;

		if (this->window->Open())
		{


			// Z-buffer
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);

			// set clear color to gray
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

			Renderer rend;
			rend.addBuffers();

			camera_.setup();
			glDisable(GL_FRAMEBUFFER_SRGB);

			std::shared_ptr<LightNode> light = std::make_shared<LightNode>();
			std::shared_ptr<MeshResource> mesh = std::make_shared<MeshResource>();
			std::shared_ptr<TextureResource> texture = std::make_shared<TextureResource>();
			std::shared_ptr<ShaderObject> shader = std::make_shared<ShaderObject>();

			mesh->loadOBJ("Obj/lumberJack.obj");
			mesh->setup();					//VAO
			mesh->bindVertexbuffer();		//VBO
			mesh->bindIndexBuffer();		//EBO
			mesh->bindPointers();			//read protocols

			shader->loadShaders("Shaders/vs.shader", "Shaders/fs.shader");

			texture->makeTexture("Texture/lumberJack_diffuse.png");
			texture->bindTexture();

			float move = 0.0;
			for (int i = 0; i < 1; i++)
			{
				GraphicsNode temp;

				temp.setMeshClass(mesh);
				temp.setTextureResource(texture);
				temp.setShaderObject(shader);
				temp.setLightNode(light);
				nodes.push_back(temp);
			}
			for (int i = 0; i < nodes.size(); i++)
			{
				GraphicsNode& node = nodes[i];
				node.translate(Vector4D(move, 3.0, 0.0, 0.0));
				node.scaling(Vector4D(3.0, 3.0, 3.0, 1.0));
				move = move + 6.0f;
			}

			window->SetMousePressFunction([this](int32 button, int32 action, int32 mods)
			{
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
				{
					this->leftmousebuttonpressed = true;
				}
				else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
				{
					this->leftmousebuttonpressed = false;
				}
			});

			window->SetMouseMoveFunction([this](float64 xpos, float64 ypos)
			{
				float radianconversion = 3.1415926 / 180; // g�nger f�r att f� radian.

				if (this->leftmousebuttonpressed && lastX != 0)
				{
					float xoffset = xpos - lastX;
					float yoffset = lastY - ypos; // reversed since y-coordinates range from bottom to top
					lastX = xpos;
					lastY = ypos;

					float sensitivity = 0.15f;
					xoffset *= sensitivity;
					yoffset *= sensitivity;

					yaw += xoffset;
					pitch += yoffset;

					if (pitch > 89.0f)
						pitch = 89.0f;
					if (pitch < -89.0f)
						pitch = -89.0f;

					Vector4D front;
					front.SetX(cos(pitch * radianconversion) * cos(yaw * radianconversion));
					front.SetY(sin(pitch * radianconversion));
					front.SetZ(cos(pitch * radianconversion) * sin(yaw * radianconversion));
					Vector4D temp = front.Normalize();
					camera_.changeCameraFront(front);
				}
				lastX = xpos; lastY = ypos;
			});

			window->SetKeyPressFunction([this](int32 key, int32 i, int32 action, int32 modifier)
			{
				if ((key == GLFW_KEY_A || key == GLFW_KEY_LEFT) && (action == GLFW_REPEAT || action == GLFW_PRESS))
				{
					camera_.moveCameraL();
				}
				if ((key == GLFW_KEY_D || key == GLFW_KEY_RIGHT) && (action == GLFW_REPEAT || action == GLFW_PRESS))
				{
					camera_.moveCameraR();
				}
				if ((key == GLFW_KEY_W || key == GLFW_KEY_UP) && (action == GLFW_REPEAT || action == GLFW_PRESS))
				{
					camera_.moveCameraF();
				}
				if ((key == GLFW_KEY_S || key == GLFW_KEY_DOWN) && (action == GLFW_REPEAT || action == GLFW_PRESS))
				{
					camera_.moveCameraB();
				}
				if (key == GLFW_KEY_SPACE && (action == GLFW_REPEAT || action == GLFW_PRESS))
				{
					camera_.moveCameraU();
				}
				if (key == GLFW_KEY_Q && (action == GLFW_REPEAT || action == GLFW_PRESS))
				{
					camera_.moveCameraD();
				}
				if (key == GLFW_KEY_T && action == GLFW_PRESS)
				{
					camera_.printCameraPos();
				}

				if (key == GLFW_KEY_ESCAPE)
					this->window->Close();
			});

			return true;
		}
		return false;
	}

	//------------------------------------------------------------------------------
	/**
	*/
	void
		ExampleApp::Run()
	{
		float rot = 0;
		while (this->window->IsOpen())
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			this->window->Update();

			float radius = 0.5f;
			float x = sin(glfwGetTime()) * radius;
			float z = cos(glfwGetTime()) * radius;
			float y = sin(glfwGetTime()) * radius;

			for each(GraphicsNode node in nodes)
			{
				node.setCamera(camera_);
				node.draw();
			}

			this->window->SwapBuffers();
			rot = rot + 0.01;
		}
	}

} // namespace Example