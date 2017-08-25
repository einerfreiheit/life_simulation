#include "OpenGLMapData.h"

void OpenGLMapData::getHeightDepth(World *world) {

	float cellHeight = 0.0;
	for (int i = 0; i < world->map.size(); i++) {
		for (int j = 0; j < world->map[0].size(); j++) {
			cellHeight = world->map[i][j].height;
			maxHeight = std::max(maxHeight, cellHeight);
			minHeight = std::min(minHeight, cellHeight);
		}
	}

}

OpenGLMapData::OpenGLMapData() {

}

void OpenGLMapData::computeVertexData(World *world) {
	glGenBuffers(1, &vertexBufferObject);
	glGenBuffers(1, &indexBufferObject);

	GLuint data = 0;
	size_t mapHeight = world->map.size();
	size_t mapWidth = world->map[0].size();

	getHeightDepth(world);
	double intensity = 0.0;
	size_t sizeData = 24 * mapHeight * mapWidth;
	GLuint vertexIndex = 0;

	float vertexZ;
	int offset;
	float vertexPosX;
	float vertexPosY;
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			offset = 20 * (x + y * mapWidth);
			vertexZ = world->map[y][x].height;
			intensity = (vertexZ - minHeight) / (maxHeight - minHeight);
			vertexPosX = (float) x;
			vertexPosY = (float) y;

			vertex v1;
			v1.vertexPosition = glm::vec3(vertexPosX, vertexPosY, vertexZ);
			v1.textureUV = glm::vec2(vertexPosX * textureDecrease, vertexPosY * textureDecrease);

			vertex v2;

			v2.vertexPosition = glm::vec3(vertexPosX+1.0, vertexPosY , vertexZ);
			v2.textureUV = glm::vec2((vertexPosX +1.0)* textureDecrease, (vertexPosY) * textureDecrease);

			vertex v3;
			v3.vertexPosition = glm::vec3(vertexPosX, vertexPosY+1.0, vertexZ);
			v3.textureUV = glm::vec2((vertexPosX) * textureDecrease, (vertexPosY+1.0) * textureDecrease);

			vertex v4;
			v4.vertexPosition = glm::vec3(vertexPosX + 1.0, vertexPosY + 1.0, vertexZ);
			v4.textureUV = glm::vec2((vertexPosX + 1.0) * textureDecrease, (vertexPosY + 1.0) * textureDecrease);

			vertices.push_back(v1);
			vertices.push_back(v2);
			vertices.push_back(v3);
			vertices.push_back(v4);

			vertexIndices.push_back(vertexIndex + 1);
			vertexIndices.push_back(vertexIndex + 2);
			vertexIndices.push_back(vertexIndex);

			vertexIndices.push_back(vertexIndex + 1);
			vertexIndices.push_back(vertexIndex + 2);
			vertexIndices.push_back(vertexIndex + 3);

			vertexIndex += 4;
		}
	}

}

void OpenGLMapData::computeData(World *world){
	computeVertexData(world);
	updateBuffers();
	elementNumber = vertexIndices.size();
}
void OpenGLMapData::updateBuffers() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof( vertexIndices) *vertexIndices.size(), &vertexIndices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

