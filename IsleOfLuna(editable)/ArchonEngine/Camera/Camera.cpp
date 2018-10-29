#include "Camera.h"
#include "../Core/ArchonEngine.h"

std::unique_ptr<Camera> Camera::cameraInstance = nullptr;

Camera::Camera() : position(glm::vec3()), perspective(glm::mat4()), orthographic(glm::mat4()), fieldOFView(0.0f), yaw(0.0f), pitch(0.0f), forwardVector(glm::vec3()),
upVector(glm::vec3()), rightVector(glm::vec3()), worldUp(glm::vec3()), nearPlane(0.0f), farPlane(0.0f)
{
	fieldOFView = 45.0f;
	forwardVector = glm::vec3(0.0f, 0.0f, -1.0f);
	upVector = glm::vec3(0.0f, 1.0f, 0.0f);
	worldUp = upVector;
	nearPlane = 2.0f;
	farPlane = 50.0f;
	yaw = -90.0f;

	//perspective = glm::perspective(fieldOFView, ArchonEngine::GetInstance()->GetScreenSize().x / ArchonEngine::GetInstance()->GetScreenSize().y, nearPlane, farPlane);
	//orthographic = glm::ortho(0.0f, ArchonEngine::GetInstance()->GetScreenSize().x, 0.0f, ArchonEngine::GetInstance()->GetScreenSize().y, -1.0f, 1.0f);
	updateCameraVectors();
}


Camera::~Camera()
{
}

Camera* Camera::GetInstance()
{
	if (cameraInstance.get() == nullptr)
	{
		cameraInstance.reset(new Camera);
	}
	return cameraInstance.get();
}
void Camera::SetPosition(glm::vec3 position_)
{
	position = position_;
}
void Camera::SetRotation(GLfloat yaw_, GLfloat pitch_)
{
	yaw = yaw_;
	pitch = pitch_;
	updateCameraVectors();
}
glm::mat4 Camera::GetView() const
{
	return glm::lookAt(position, position + forwardVector, upVector);
}
glm::mat4 Camera::GetPrespective() const
{
	//has to change if we want a resizable window
	return perspective;
}
glm::mat4 Camera::GetOrthographic() const
{
	//has to change if we want a resizable window
	return orthographic;
}
void Camera::updateCameraVectors()
{
	forwardVector.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forwardVector.y = sin(glm::radians(pitch));
	forwardVector.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	forwardVector = glm::normalize(forwardVector);

	rightVector = glm::normalize(glm::cross(forwardVector, worldUp));
	upVector = glm::normalize(glm::cross(rightVector, forwardVector));
}