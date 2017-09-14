#include "CreatureStatistics.h"
#include "SimulationData.h"
#include <fstream>
#include <string>

CreatureStatistics::CreatureStatistics() {
	this->id = 0;
	this->attacksNumber = 0;
	this->traveledDistace = 0;
	this->eatenFood = 0.0;
	this->fissionsNumber = 0;
	this->lifeTime = 0;
	this->genomeComlexity = 0;
	this->conjugationsNumber = 0;

}

void CreatureStatistics::updateGenomeComlexity(const GenomePtr genome) {
	for (auto chromosome : genome->chromosomes) {
		for (auto gene : chromosome->genes) {
			genomeComlexity++;
		}
	}

}

CreatureStatistics::~CreatureStatistics() {
}

void CreatureStatistics::setCreatureId(const int _id) {
	this->id = _id;
}

void CreatureStatistics::incrementAttacksNumber() {
	this->attacksNumber++;
}
void CreatureStatistics::incrementTraveledDistace() {
	this->traveledDistace++;
}

void CreatureStatistics::incrementEatenFood(const double creatureBait) {
	this->eatenFood += creatureBait;
}

void CreatureStatistics::incrementFissionsNumber() {
	this->fissionsNumber++;
}

void CreatureStatistics::incrementLifetime() {
	this->lifeTime++;
}

void CreatureStatistics::incrementConjugationNumber() {
	conjugationsNumber++;
}
void CreatureStatistics::writeStatistics() {

	std::string outputPath = SimulationData::getInst()->outputPath + "output.txt";
	std::ofstream out(outputPath, std::ios::out | std::ios::app);
	out << "creature id: " << id << " lifetime " << lifeTime;
	out << " attacks: " << attacksNumber << " moved: " << traveledDistace << " eated: " << eatenFood;
	out << " fission number: " << fissionsNumber << " genome complexity: " << genomeComlexity << " conjugation: "
			<< conjugationsNumber << std::endl;

	out.close();

}
