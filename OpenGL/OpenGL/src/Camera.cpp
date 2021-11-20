#include "Camera.h"

Camera::Camera(std::vector<Shader*> program)
{
	camPostion = glm::vec3(0.0f, 0.f, 0.0f);
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	camFront = glm::vec3(0.0f, 0.0f, -1.0f);
	ViewMatrix = glm::mat4(1.0f);
	ProjectionMatrix = glm::mat4(1.0f);

	for (int i = 0; i < program.size(); i++)
	{
		program[i]->setMat4fv(ProjectionMatrix, "ProjectionMatrix");
		program[i]->setMat4fv(ViewMatrix, "ViewMatrix");
	}
	
}

void Camera::Update(std::vector<Shader*> program, GLFWwindow* window, int& frame_buffer_width, int& frame_buffer_height)
{
	updateCameraVectors();
	ViewMatrix = glm::lookAt(camPostion, camPostion + camFront, worldUp);
	glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);
	
	ProjectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(frame_buffer_width) / frame_buffer_height, nearPlane, farPlane);

	for (int i = 0; i < program.size(); i++)
	{
		program[i]->setMat4fv(ProjectionMatrix, "ProjectionMatrix");
		program[i]->setMat4fv(ViewMatrix, "ViewMatrix");
		program[i]->setVec3f(this->GetCameraPos(), "cameraPos");
	}
}

void Camera::updateCameraVectors()
{
	this->camFront.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->camFront.y = sin(glm::radians(this->pitch));
	this->camFront.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

	this->camFront = glm::normalize(this->camFront);
	this->right = glm::normalize(glm::cross(this->camFront, this->worldUp));
	this->up = glm::normalize(glm::cross(this->right, this->camFront));
}
