#include "SimulationData.h"
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
using namespace boost::program_options;
using namespace std;

SimulationData::SimulationData(){
	setVariables();
	world =new World;


}

void SimulationData::setVariables() {
	std::string config_filename = "config.ini";
		options_description desc;
		desc.add_options()
				("World.height", value<int>()->default_value(5), "set height")
				("World.width", value<int>()->default_value(5), "set width")
				("WaiterWorker.timeToWait", value<int>()->default_value(1000),"set waiting time")
				("ResourceWorker.gainPerCell",value<double>()->default_value(0.0), "set gain res");

		variables_map vm;
		std::ifstream config_stream(config_filename.c_str());
		store(parse_config_file(config_stream, desc), vm);
		notify(vm);
		height = vm["World.height"].as<int>();
		width = vm["World.width"].as<int>();
		timeToWait = vm["WaiterWorker.timeToWait"].as<int>();
		gainResource = vm["ResourceWorker.gainPerCell"].as<double>();
}

