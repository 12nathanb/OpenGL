#include "Camera.h"

Camera::Camera(GLuint& program)
{
	camPostion = glm::vec3(0.0f, 0.f, 0.0f);
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	camFront = glm::vec3(0.0f, 0.0f, -1.0f);
	ViewMatrix = glm::mat4(1.0f);
	ProjectionMatrix = glm::mat4(1.0f);

	glUniformMatrix4fv(glGetUniformLocation(program, "ProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(ProjectionMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "ViewMatrix"), 1, GL_FALSE, glm::value_ptr(ViewMatrix));
}

void Camera::Update(GLuint& program, GLFWwindow* window, int& frame_buffer_width, int& frame_buffer_height)
{
	glUseProgram(program);
	updateCameraVectors();
	ViewMatrix = glm::lookAt(camPostion, camPostion + camFront, worldUp);
	glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);
	
	ProjectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(frame_buffer_width) / frame_buffer_height, nearPlane, farPlane);

	glUniformMatrix4fv(glGetUniformLocation(program, "ProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(ProjectionMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "ViewMatrix"), 1, GL_FALSE, glm::value_ptr(ViewMatrix));
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
