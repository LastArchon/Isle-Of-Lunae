#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glew.h>
#include <memory>

class Camera
{
public:

	Camera(const Camera&) = delete;
	Camera(Camera&&) = delete;
	Camera& operator=(const Camera&) = delete;
	Camera& operator=(Camera&&) = delete;
	static Camera* GetInstance();
	void SetPosition(glm::vec3 position_);
	void SetRotation(GLfloat yaw_, GLfloat pitch_);
	glm::mat4 GetView() const;
	glm::mat4 GetPrespective() const;
	glm::mat4 GetOrthographic() const;

private:
	Camera();
	~Camera();
	static std::unique_ptr<Camera> cameraInstance;
	friend std::default_delete<Camera>;

	void updateCameraVectors();

	glm::vec3 position;
	glm::mat4 perspective;
	glm::mat4 orthographic;
	GLfloat fieldOFView;
	GLfloat yaw;
	GLfloat pitch;
	GLfloat nearPlane;
	GLfloat farPlane;
	//where the camera is looking
	glm::vec3 forwardVector;
	//pointing up from the camera
	glm::vec3 upVector;
	//to the right of the camera
	glm::vec3 rightVector;
	//used to get an acurate right vector
	glm::vec3 worldUp;

};

#endif // ! CAMERA_H
