#pragma once
#include <glm.hpp>
#include "Shader.h"
#include <vector>
#include <GLFW/glfw3.h>
#include<string>  

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

enum direction { FORWARD = 0, BACKWARD, LEFT, RIGHT };

class Camera
{
public:
    Camera();

    void Update(GLFWwindow* window);

    void SetCameraPos(glm::vec3 CP) { Camera_position = CP; }
    void SetWorldUp(glm::vec3 WU) { World_up = WU; }
    void SetCamFront(glm::vec3 CF) { Camera_front = CF; }
    void SetViewMatrix(glm::mat4 VM) { View_matrix = VM; }
    void SetProjectionMatrix(glm::mat4 PM) { Projection_matrix = PM; }

    void MoveCamera(glm::vec3 CP) { Camera_position += CP; }
    void RotateCamera(glm::vec3 r) { yaw += r.x; pitch += r.y; }

    glm::vec3 GetCameraPos() { return Camera_position; }
    glm::vec3 GetWorldUp() { return World_up; }
    glm::vec3 GetCamFront() { return Camera_front; }
    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix() { return Projection_matrix; }

    void move(const float& dt, const int direction);

    void updateMouseInput(const float& dt, const double& offsetX, const double& offsetY);
    void updateInput(const float& dt, const int direction, const double& offsetX, const double& offsetY);

private:
    void updateCameraVectors();

private:
    glm::vec3 Camera_position = glm::vec3(0.0f, 0.f, 0.0f);
    glm::vec3 World_up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 Camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::mat4 View_matrix = glm::mat4(1.0f);
    glm::mat4 Projection_matrix = glm::mat4(1.0f);

    float Field_of_view = 90.0f;
    float Near_plane = 0.1f;
    float Far_plane = 1000.f;

    GLfloat  yaw =  -90;
    GLfloat  pitch = 0;
    GLfloat  roll = 0;

    glm::vec3 right = glm::vec3(0.f);
    glm::vec3 up;

    GLfloat Movement_speed = 3.f;
    GLfloat sensitivity = 5.f;
};

