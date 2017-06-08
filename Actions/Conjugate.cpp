#include "Conjugate.h"
#include <stdlib.h>
#include <vector>
#include "../Factories/GenomeBuilder.h"

Conjugate::Conjugate()
{

}

Conjugate::~Conjugate()
{

}

void Conjugate::act ( World* world, CreaturePtr creature )
{
  int x =creature->getPosX();
  int y= creature->getPosY();
  int currentCreature = creature->getId();
  Cell& cell = world->map[y][x];

  int numberOfCreatures =cell.creaturesInCell.size();

  for ( int i=0; i<numberOfCreatures; i++ )
    {

      if ( cell.creaturesInCell[i]->getId() !=currentCreature && canConjugate(creature,cell.creaturesInCell[i] ) )
        {
          conjugate ( creature, cell.creaturesInCell[i] );
        }


    }
  
  
  
  
}

bool Conjugate::canConjugate ( CreaturePtr firstCreature, CreaturePtr secondCreature )
{
  return firstCreature->phenotype->conjugateEnergy < firstCreature->getEnergy() && secondCreature->getGenome()->plasmide->genes.empty();
}


void Conjugate::conjugate ( CreaturePtr firstCreature, CreaturePtr secondCreature )
{
  GenomePtr firstGenome= firstCreature->getGenome();
  GenomePtr secondGenome = secondCreature->getGenome();
  
  GenomeBuilder::buildPlasmide(firstGenome);
  secondGenome->plasmide = firstGenome->plasmide;
  
  updateGenome(secondCreature);
 
  

}

void Conjugate::updateGenome ( CreaturePtr creature )
{
    GenomePtr genome = creature->getGenome();
    size_t plasmideSize = genome->plasmide->genes.size();
    int &position = genome->plasmide-> position;
    position=0;
    
   while (genome->plasmide->position != plasmideSize ){
    replaceGene(genome,  genome->plasmide->genes[position]);
    position++;
     
   }
    
    
   
}


void Conjugate::replaceGene ( GenomePtr genome, Gene& plasmideGene )
{
    bool isReplaced = false;
    for (ChromosomePtr chromosome: genome->chromosomes){
	for (Gene & gene : chromosome->genes){
	 if (gene.type == plasmideGene.type){
	 changeAllels(plasmideGene,gene);
	   isReplaced=true;
	   break;
	   
	   
	 }
	  
	}
      
    }
    
    if (!isReplaced){
      changeAllels(plasmideGene, GenomeBuilder::getRandomGene(genome));
      
    }
}



void Conjugate::changeAllels ( Gene& geneFirst, Gene& geneSecond )
{
    bool reverseAllel= rand()% 1;
    if (reverseAllel){
      geneSecond.allel1=geneFirst.allel2;
      geneSecond.allel2=geneFirst.allel1;
      
    }
    else {
      
      geneSecond.allel1=geneFirst.allel1;
      geneSecond.allel2=geneFirst.allel2;
    }
}
