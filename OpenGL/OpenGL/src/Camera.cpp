#include "Camera.h"

Camera::Camera()
{
	this->updateCameraVectors();
}

void Camera::Update(GLFWwindow* window)
{
	ImGui::Begin("Menu");
	ImGui::BeginChild("Menu", ImVec2(0, ImGui::GetFontSize() * 20.0f), true, ImGuiWindowFlags_MenuBar);
	ImGui::SliderFloat("Movement speed", &Movement_speed, 0.1f, 5.0f);
	ImGui::SliderFloat("Mouse Sensitivity", &sensitivity, 0.1f, 10.0f);
	ImGui::EndChild();
	ImGui::End();
	int frame_buffer_width;
	int frame_buffer_height;
	updateCameraVectors();

	View_matrix = glm::lookAt(Camera_position, Camera_position + Camera_front, World_up);

	glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);
	
	Projection_matrix = glm::perspective(glm::radians(Field_of_view), static_cast<float>(frame_buffer_width) / frame_buffer_height, Near_plane, Far_plane);
}

glm::mat4 Camera::GetViewMatrix()
{
	this->updateCameraVectors();
	this->View_matrix = glm::lookAt(this->Camera_position, this->Camera_position + this->Camera_front, this->up);
	
	return this->View_matrix;
}

void Camera::move(const float& dt, const int direction)
{
	//Update position vector
	switch (direction)
	{
	case FORWARD:
		this->Camera_position += this->Camera_front * this->Movement_speed * dt;
		break;
	case BACKWARD:
		this->Camera_position -= this->Camera_front * this->Movement_speed * dt;
		break;
	case LEFT:
		this->Camera_position -= this->right * this->Movement_speed * dt;
		break;
	case RIGHT:
		this->Camera_position += this->right * this->Movement_speed * dt;
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
	this->Camera_front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->Camera_front.y = sin(glm::radians(this->pitch));
	this->Camera_front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

	this->Camera_front = glm::normalize(this->Camera_front);
	this->right = glm::normalize(glm::cross(this->Camera_front, this->World_up));
	this->up = glm::normalize(glm::cross(this->right, this->Camera_front));
}
