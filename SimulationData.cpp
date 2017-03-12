#include "SimulationData.h"

#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
using namespace boost::program_options;
using namespace std;
SimulationData::SimulationData(){
	readConfigParameters();
	world=new World (mapHeightToSet,mapWidthToSet);






}

//@ можно написать изящнее
void SimulationData::readConfigParameters() {
	std::string config_filename = "config.ini";
		options_description desc;
		desc.add_options()
				("World.height", value<int>()->default_value(5))
				("World.width", value<int>()->default_value(5))

				("AIWorker.isAvailable",value<bool>()->default_value(true))
				("CreatureRemoveWorker.isAvailable",value<bool>()->default_value(true))
				("CreatureSpawnWorker.isAvailable",value<bool>()->default_value(true))
				("ResourceWorker.isAvailable",value<bool>()->default_value(true))
				("VideoWriterWorker.isAvailable",value<bool>()->default_value(true))
				("VisualWorker.isAvailable",value<bool>()->default_value(true))
				("WaiterWorker.isAvailable",value<bool>()->default_value(true))

				("WaiterWorker.timeToWait", value<int>()->default_value(1000))
				("ResourceWorker.gainPerCell",value<double>()->default_value(0.0));

		variables_map vm;
		std::ifstream config_stream(config_filename.c_str());
		store(parse_config_file(config_stream, desc), vm);
		notify(vm);
		mapHeightToSet = vm["World.height"].as<int>();
		mapWidthToSet = vm["World.width"].as<int>();
		timeToWait = vm["WaiterWorker.timeToWait"].as<int>();
		gainResourcePerCell = vm["ResourceWorker.gainPerCell"].as<double>();

		 AIWorkerIsAvailable =vm["AIWorker.isAvailable"].as<bool>();
		 CreatureRemoveWorkerIsAvailable =vm["CreatureRemoveWorker.isAvailable"].as<bool>();
		 CreatureSpawnWorkerIsAvailable =vm["CreatureSpawnWorker.isAvailable"].as<bool>();
		 ResourceWorkerIsAvailable =vm["ResourceWorker.isAvailable"].as<bool>();
		 VideoWriterWorkerIsAvailable =vm["VideoWriterWorker.isAvailable"].as<bool>();
		 VisualWorkerIsAvailable =vm["VisualWorker.isAvailable"].as<bool>();
		 WaiterWorkerIsAvailable =vm["WaiterWorker.isAvailable"].as<bool>();




}

