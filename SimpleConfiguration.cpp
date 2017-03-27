#include "SimpleConfiguration.h"
#include <fstream>
#include <iostream>

void SimpleConfiguration::load(std::string pathToConfig){
    addParams();
    readParams(pathToConfig);
}


void SimpleConfiguration::setSection(std::string nextSection){
    this->section = nextSection;
}


void SimpleConfiguration::addParams(){
        
}

void SimpleConfiguration::readParams(std::string pathToConfig){
    boost::program_options::variables_map vm;
    std::ifstream config_stream(pathToConfig.c_str());
    boost::program_options::store(boost::program_options::parse_config_file(config_stream, params), vm);
    boost::program_options::notify(vm);
}