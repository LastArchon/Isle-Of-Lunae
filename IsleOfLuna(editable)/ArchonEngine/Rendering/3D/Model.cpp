#include "Model.h"



Model::Model(GLuint shaderProgram_) : subMeshes(std::vector<Mesh*>())
{
	shaderProgram = shaderProgram_;
}


Model::~Model()
{

	for (auto m : subMeshes) {

		delete m;
		m = nullptr;

	}

	subMeshes.clear();
	subMeshes.shrink_to_fit();


}

void Model::Render() {
	glUseProgram(shaderProgram);
	for (auto m : subMeshes) {

		m->Render();

	}

}

void Model::addMesh(Mesh* mesh_) {

	subMeshes.push_back(mesh_);

}