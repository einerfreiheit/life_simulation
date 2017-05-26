#include "Genome.h"

Genome::Genome()
{

}

Genome::~Genome()
{
  for ( size_t i = 0; i < chromosomes.size(); i++ )
    {
      if ( chromosomes[i] )
        {
          delete chromosomes[i];
        }
    }
    if (plasmide->genes.size()){
        delete plasmide;
    }
}
