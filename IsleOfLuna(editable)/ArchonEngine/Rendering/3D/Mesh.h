#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>


struct Vertex
{

	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 textCords;
	glm::vec3 color;

};


struct Texture {
	unsigned int id;
	std::string type;
};

class Mesh
{
public:
	/*  Mesh Data  */
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	Mesh(std::vector<Vertex> vertices_, std::vector<unsigned int> indices_, std::vector<Texture> textures_);
	~Mesh();
	
	void Render();

private:
	GLuint VAO, VBO, EBO;
	//std::vector<Vertex> vertexList;
	void generateBuffers();
	void setupMesh();
	//functions
	

};

#endif // MESH_H

