#include "ObjectManager.h"


ObjectManager::ObjectManager()
{
	numberOfBoxes = 12;
	boxRot =  new glm::vec3[numberOfBoxes];
	boxVertices = new float[210];
	positions = new glm::vec3[numberOfBoxes];
	boxModel = new glm::mat4[numberOfBoxes];
	boxAngle = new float[numberOfBoxes];
	currentBox = 0;
	rotSpeed = new float[numberOfBoxes];

	for (int i = 0; i < numberOfBoxes; i++) {
		rotSpeed[i] = 0.1f;
	}

	for (int i = 0; i < numberOfBoxes; i++)
	{
		boxAngle[i] = 0;
	}

	float a = 1.0f, b = 0.0f, c = 0.0f;

	for (int i = 0; i < numberOfBoxes; i++) {

		boxRot[i] = glm::vec3(a, b, c);

	}

	float box[] = {
		//box
		-0.8f, -1.5f, -0.2f,  0.0f, 0.0f,
		0.8f, -1.5f, -0.2f,  1.0f, 0.0f,
		0.8f,  1.5f, -0.2f,  1.0f, 1.0f,
		0.8f,  1.5f, -0.2f,  1.0f, 1.0f,
		-0.8f,  1.5f, -0.2f,  0.0f, 1.0f,
		-0.8f, -1.5f, -0.2f,  0.0f, 0.0f,

		-0.8f, -1.5f,  0.2f,  0.0f, 0.0f,
		0.8f, -1.5f,  0.2f,  1.0f, 0.0f,
		0.8f,  1.5f,  0.2f,  1.0f, 1.0f,
		0.8f,  1.5f,  0.2f,  1.0f, 1.0f,
		-0.8f,  1.5f,  0.2f,  0.0f, 1.0f,
		-0.8f, -1.5f,  0.2f,  0.0f, 0.0f,

		-0.8f,  1.5f,  0.2f,  1.0f, 0.0f,
		-0.8f,  1.5f, -0.2f,  1.0f, 1.0f,
		-0.8f, -1.5f, -0.2f,  0.0f, 1.0f,
		-0.8f, -1.5f, -0.2f,  0.0f, 1.0f,
		-0.8f, -1.5f,  0.2f,  0.0f, 0.0f,
		-0.8f,  1.5f,  0.2f,  1.0f, 0.0f,

		0.8f,  1.5f,  0.2f,  1.0f, 0.0f,
		0.8f,  1.5f, -0.2f,  1.0f, 1.0f,
		0.8f, -1.5f, -0.2f,  0.0f, 1.0f,
		0.8f, -1.5f, -0.2f,  0.0f, 1.0f,
		0.8f, -1.5f,  0.2f,  0.0f, 0.0f,
		0.8f,  1.5f,  0.2f,  1.0f, 0.0f,

		-0.8f, -1.5f, -0.2f,  0.0f, 1.0f,
		0.8f, -1.5f, -0.2f,  1.0f, 1.0f,
		0.8f, -1.5f,  0.2f,  1.0f, 0.0f,
		0.8f, -1.5f,  0.2f,  1.0f, 0.0f,
		-0.8f, -1.5f,  0.2f,  0.0f, 0.0f,
		-0.8f, -1.5f, -0.2f,  0.0f, 1.0f,

		-0.8f,  1.5f, -0.2f,  0.0f, 1.0f,
		0.8f,  1.5f, -0.2f,  1.0f, 1.0f,
		0.8f,  1.5f,  0.2f,  1.0f, 0.0f,
		0.8f,  1.5f,  0.2f,  0.0f, 1.0f,
		-0.8f,  1.5f,  0.2f,  1.0f, 1.0f,
		-0.8f,  1.5f, -0.2f,  1.0f, 0.0f,
		//plane

		- 10.0f, 0.0f, -10.0f,  0.0f, 0.0f,
		10.0f, 0.0f, -10.0f,  1.0f, 0.0f,
		-10.0f,  0.0f, 10.f,  1.0f, 1.0f,
		-10.f,  0.0f, 10.f,  1.0f, 1.0f,
		10.0f,  0.0f, 10.0f,  0.0f, 1.0f,
		10.f, 0.0f, -10.0f,  0.0f, 0.0f,

	};

	

	for (int i = 0; i < 210; i++) {
		
		boxVertices[i] = box[i];

	}


	float offset = 0.0f;

	for (int i = 0; i < numberOfBoxes; i++) {
		positions[i] = glm::vec3(0.0f, 0.0f, offset);
		offset += 2.0f;
	}

	for (int i = 0; i < numberOfBoxes; i++)
	{
		boxModel[i] = glm::translate(boxModel[i], positions[i]);
	}
}


ObjectManager::~ObjectManager()
{
	delete boxRot;
	delete planeVert;
	delete boxVertices;
	delete positions;
	delete boxModel;
	delete boxAngle;
}

float* ObjectManager::getBoxVert()
{
	return boxVertices;
}

glm::vec3 ObjectManager::getPosition(int i)
{
	return positions[i];
}

std::size_t ObjectManager::getVertSize()
{
	std::size_t size = 0;

	for (int i = 0; i < 180; i++) {
		size += sizeof(boxVertices[i]);
	}

	return size;
}

glm::vec3 ObjectManager::getRotation(int i)
{
	return boxRot[i];
}

glm::mat4 ObjectManager::getBoxModel(int i)
{

	if (i<=currentBox && boxAngle[i] <=95.0f) {

		boxModel[i] = glm::translate(boxModel[i], glm::vec3(0.0f, -1.5f, 0.2f));
		boxModel[i] = glm::rotate(boxModel[i], glm::radians(rotSpeed[i]), boxRot[i]);
		boxModel[i] = glm::translate(boxModel[i], glm::vec3(0.0f, 1.5f, -0.2f));

		boxAngle[i] += 0.1f;
	}

	if (boxAngle[currentBox] >= 40) {
		rotSpeed[currentBox] = 0.07f;
		++currentBox;
	}

	return boxModel[i];
}

int ObjectManager::getNumberOfBoxes()
{
	return numberOfBoxes;
}

