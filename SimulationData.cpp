#include "SimulationData.h"
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
using namespace boost::program_options;
using namespace std;
SimulationData::SimulationData() {
	readConfigParameters();

}

//@ можно написать изящнее
void SimulationData::readConfigParameters() {
	std::string config_filename = "config.ini";
	options_description desc;
	desc.add_options()
	("World.height", value<int>(&mapHeightToSet)->default_value(5))
	("World.width", value<int>(&mapWidthToSet)->default_value(5))
	("AIWorker.use", value<bool>(&useAIWorker)->default_value(true))
	("CreatureActionWorker.use", value<bool>(&useCreatureActionWorker)->default_value(true))
	("CreatureRemoveWorker.use",value<bool>(&useCreatureRemoveWorker)->default_value(true))
	("CreatureSpawnWorker.use",value<bool>(&useCreatureSpawnWorker)->default_value(true))
	("ResourceWorker.use",value<bool>(&useResourceWorker)->default_value(true))
	("VisualWorker.use",value<bool>(&useVisualWorker)->default_value(true))
	("VideoWriterWorker.use",value<bool>(&useVideoWriterWorker)->default_value(true))
	("WaiterWorker.use",value<bool>(&useWaiterWorker)->default_value(true))
	("WaiterWorker.timeToWait", value<int>(&timeToWait)->default_value(1000))
	("ResourceWorker.gainPerCell", value<double>(&gainResourcePerCell)->default_value(0.0));
	variables_map vm;
	std::ifstream config_stream(config_filename.c_str());
	store(parse_config_file(config_stream, desc), vm);
	notify(vm);


}

