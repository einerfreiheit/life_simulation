#include "VisualWorker.h"
#include <iostream>

#include "../Visualization/SimpleDisplay.h"
#include "../Visualization/SimpleVideoRecord.h"

VisualWorker::VisualWorker()
{
  this->name = "VisualWorker";

  simpleVisualization = new SimpleVisualization;

  if ( SimulationData::getInst()->videoRecord )
    {
      visualOutput.push_back ( new SimpleVideoRecord );
    }
  if ( SimulationData::getInst()->displayOutput )
    {
      visualOutput.push_back ( new SimpleDisplay );

    }

}
void VisualWorker::work ( World *world )
{
  simpleVisualization->update ( world );

  for ( VisualOutput * output : visualOutput )
    {
      output->update ( simpleVisualization->getVisualisation() );
    }

}

VisualWorker::~VisualWorker()
{

}

