#include "OpenCVData.h"
#include "../SimulationData.h"

OpenCVData::OpenCVData(World *world) {
	output = cv::Mat::zeros(world->map.size(), world->map[0].size(),
	CV_8UC3);
	getHeightsRange(world);

}

OpenCVData::~OpenCVData() {

}

const cv::Mat* OpenCVData::getVisiulization(){
	return &output;
}
void OpenCVData::update(World *world) {

	for (int y = 0; y < world->map.size(); y++) {
		for (int x = 0; x < world->map[0].size(); x++) {

			float height = world->map[y][x].height;
			double water = world->map[y][x].water;

			uchar *blue = &output.at < uchar > (y, 3 * x);
			uchar *green = &output.at < uchar > (y, 3 * x + 1);
			uchar *red = &output.at < uchar > (y, 3 * x + 2);
			uchar intensity = (height - minHeight) / heightsRange * 255;

			*blue = intensity;
			*green = intensity;
			*red = intensity;

			if (water > (SimulationData::getInst()->soilWater)) {
				*red = 0;
				*green = 0;
			}
		}
	}

	for (auto creature : world->creatures) {
		int y = creature->y;
		int x = creature->x;
		uchar *blue = &output.at < uchar > (y, 3 * x);
		uchar *green = &output.at < uchar > (y, 3 * x + 1);
		uchar *red = &output.at < uchar > (y, 3 * x + 2);

		*red = (creature->isHungry() ? creature->energy * 255.0 / 100.0 : 255);
		*blue = 0;
		*green = 0;
	}

}

void OpenCVData::getHeightsRange(World *world) {
	float maxHeight = world->map[0][0].height;
	minHeight = world->map[0][0].height;
	float cellHeight = 0;
	for (int i = 0; i < world->map.size(); i++) {
		for (int j = 0; j < world->map[0].size(); j++) {
			cellHeight = world->getCell(i, j)->heights[0][0];
			maxHeight = std::max(maxHeight, cellHeight);
			minHeight = std::min(minHeight, cellHeight);
		}
	}
	heightsRange = maxHeight - minHeight;

	if (maxHeight - minHeight < 0.000001) {
		throw std::runtime_error("float map, all heights are equal");
	}

}
