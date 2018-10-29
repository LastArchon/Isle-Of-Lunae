#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"



class Model
{
public:
	Model(GLuint shaderProgram_);
	virtual ~Model();
	void Render();
	void addMesh(Mesh* mesh_);

protected:
	std::vector<Mesh*> subMeshes;
	GLuint shaderProgram;

};

#endif // !MODEL_H

