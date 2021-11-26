#include "Camera.h"

Camera::Camera(std::vector<Shader*> program)
{
	camPostion = glm::vec3(0.0f, 0.f, 0.0f);
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	camFront = glm::vec3(0.0f, 0.0f, -1.0f);
	ViewMatrix = glm::mat4(1.0f);
	ProjectionMatrix = glm::mat4(1.0f);

	this->right = glm::vec3(0.f);

	this->pitch = 0.f;
	this->yaw = -90.f;
	this->roll = 0.f;

	this->movementSpeed = 3.f;
	this->sensitivity = 5.f;

	this->updateCameraVectors();

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

glm::mat4 Camera::GetViewMatrix()
{
	this->updateCameraVectors();
	this->ViewMatrix = glm::lookAt(this->camPostion, this->camPostion + this->camFront, this->up);
	
	return this->ViewMatrix;
}

void Camera::move(const float& dt, const int direction)
{
	//Update position vector
	switch (direction)
	{
	case FORWARD:
		this->camPostion += this->camFront * this->movementSpeed * dt;
		break;
	case BACKWARD:
		this->camPostion -= this->camFront * this->movementSpeed * dt;
		break;
	case LEFT:
		this->camPostion -= this->right * this->movementSpeed * dt;
		break;
	case RIGHT:
		this->camPostion += this->right * this->movementSpeed * dt;
		break;
	default:
		break;
	}
}

void Camera::updateMouseInput(const float& dt, const double& offsetX, const double& offsetY)
{
		this->pitch += static_cast<GLfloat>(offsetY)* this->sensitivity* dt;
	this->yaw += static_cast<GLfloat>(offsetX)* this->sensitivity* dt;

	if (this->pitch > 80.f)
		this->pitch = 80.f;
	else if (this->pitch < -80.f)
		this->pitch = -80.f;

	if (this->yaw > 360.f || this->yaw < -360.f)
		this->yaw = 0.f;
}

void Camera::updateInput(const float& dt, const int direction, const double& offsetX, const double& offsetY)
{
	this->updateMouseInput(dt, offsetX, offsetY);
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
