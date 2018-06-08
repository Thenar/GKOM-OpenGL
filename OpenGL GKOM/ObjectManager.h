#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <iostream>
class ObjectManager
{
private:
	float *boxVertices;
	glm::vec3 *positions;
	float *planeVert;
	glm::vec3 *boxRot;
	glm::mat4 *boxModel;
	float *boxAngle;
	int currentBox;
	int numberOfBoxes;
	float *rotSpeed;

public:
	ObjectManager();
	~ObjectManager();

	float* getBoxVert();

	glm::vec3 getPosition(int i);

	std::size_t getVertSize();

	glm::vec3 getRotation(int i);

	glm::mat4 getBoxModel(int i);

	int getNumberOfBoxes();

	std::size_t getPlaneSize();

	float* getPlaneVert();

};

