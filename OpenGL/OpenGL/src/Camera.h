#pragma once
#include "libs.h"
class Camera
{
public:
    Camera(GLuint& program);
    void Update(GLuint& program, GLFWwindow* window, int& frame_buffer_width, int& frame_buffer_height);
    void SetCameraPos(glm::vec3 CP) { camPostion = CP; }
    void MoveCamera(glm::vec3 CP) { camPostion += CP; }
    void SetWorldUp(glm::vec3 WU) { worldUp = WU; }
    void SetCamFront(glm::vec3 CF) { camFront = CF; }
    void SetViewMatrix(glm::mat4 VM) { ViewMatrix = VM; }
    void SetProjectionMatrix(glm::mat4 PM) { ProjectionMatrix = PM; }
    void RotateCamera(glm::vec3 r) { yaw += r.x; pitch += r.y; }
    glm::vec3 GetCameraPos() { return camPostion; }
    glm::vec3 GetWorldUp() { return worldUp; }
    glm::vec3 GetCamFront() { return camFront; }
    glm::mat4 GetViewMatrix() { return ViewMatrix; }
    glm::mat4 GetProjectionMatrix() { return ProjectionMatrix; }
private:
    void updateCameraVectors();
private:
    glm::vec3 camPostion;
    glm::vec3 worldUp;
    glm::vec3 camFront;
    glm::mat4 ViewMatrix;
    glm::mat4 ProjectionMatrix;

    float fov = 90.0f;
    float nearPlane = 0.1f;
    float farPlane = 1000.f;

    GLfloat  yaw =  -90;
    GLfloat  pitch = 0;
    GLfloat roll;

    glm::vec3 right;
    glm::vec3 up;
};

