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
	("Workers.useAIWorker", value<bool>(&useAIWorker)->default_value(true))
	("Workers.useCreatureActionWorker", value<bool>(&useCreatureActionWorker)->default_value(true))
	("Workers.useCreatureRemoveWorker",value<bool>(&useCreatureRemoveWorker)->default_value(true))
	("Workers.useCreatureSpawnWorker",value<bool>(&useCreatureSpawnWorker)->default_value(true))
	("Workers.useResourceWorker",value<bool>(&useResourceWorker)->default_value(true))
	("Workers.useVisualWorker",value<bool>(&useVisualWorker)->default_value(true))
	("Workers.useVideoWriterWorker",value<bool>(&useVideoWriterWorker)->default_value(true))
	("Workers.useWaiterWorker",value<bool>(&useWaiterWorker)->default_value(true))
	("WaitingTime.timeToWait", value<int>(&timeToWait)->default_value(1000))
	("Resources.gainPerCell", value<double>(&gainResourcePerCell)->default_value(0.0))
	("CreatureParameters.creatureOneBait",value<double>(&creatureOneBait)->default_value(1.0))
	("CreatureParameters.energyToMove",value<double>(&energyToMove)->default_value(1.0))
	("CreatureParameters.energyFromFood",value<double>(&energyFromFood)->default_value(1.0));


	variables_map vm;
	std::ifstream config_stream(config_filename.c_str());
	store(parse_config_file(config_stream, desc), vm);
	notify(vm);


}

