#ifndef WORKERS_VISUALWORKER_H_
#define WORKERS_VISUALWORKER_H_
#include "WorldWorker.h"
#include "../Visualization/SimpleVisualization.h"
#include "../Visualization/VisualOutput.h"

#include <vector>

class VisualWorker: public WorldWorker
{
public:
    VisualWorker();
    virtual ~VisualWorker();
    void work ( World *world ) override;
private:

    SimpleVisualization *simpleVisualization;
    std::vector<VisualOutput *> visualOutput;
    



};

#endif
