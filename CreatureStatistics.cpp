#include "CreatureStatistics.h"
#include "SimulationData.h"
#include <fstream>
#include <string>

CreatureStatistics::CreatureStatistics() {
	this->id = 0;
	this->attacksNumber = 0;
	this->distanceMoved = 0;
	this->eatenFood = 0.0;
	this->fissionNumber = 0;
	this->lifeTime = 0;
	this->genomeComlexity=0;
	this->conjugationNumber=0;

}

void CreatureStatistics::updateGenomeComlexity(const GenomePtr genome){
	for (auto chromosome :genome->chromosomes){
		for (auto gene: chromosome->genes){
			genomeComlexity++;
		}
	}

}

CreatureStatistics::~CreatureStatistics() {
	writeStatistics();
}

void CreatureStatistics::setCreatureId(const int _id) {
	this->id = _id;
}

void CreatureStatistics::updateAttacksNumber() {
	this->attacksNumber++;
}
void CreatureStatistics::updateDistanceMoved() {
	this->distanceMoved++;
}
void CreatureStatistics::updateEatenFood(const double creatureBait) {
	this->eatenFood += creatureBait;
}

void CreatureStatistics::updateFissionsNumber() {
	this->fissionNumber++;
}//@ отступы
void CreatureStatistics::updateLifetime() {
	this->lifeTime++;
}
void CreatureStatistics::updateConjugationNumber(){
	conjugationNumber++;
}
void CreatureStatistics::writeStatistics() {

	std::string outputPath = SimulationData::getInst()->outputPath + "output.txt";
	std::ofstream out(outputPath,std::ios::out | std::ios::app);
	out << "creature id: " << id <<" lifetime "<<lifeTime;
	out<<" attacks: "<<attacksNumber<<" moved: "<< distanceMoved<<" eated: "<<eatenFood;//@ автоформаттер
	out<< " fission number: "<<fissionNumber<<" genome complexity: "<<genomeComlexity<<" conjugation: "<<conjugationNumber<<std::endl;

	out.close();

}
