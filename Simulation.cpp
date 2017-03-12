#include "SimulationRunner.h"

using namespace std;

int main()
{
    SimulationRunner runner;
    runner.init();//@ вызов метода init можно спокойно внести в конструктор раннера (зачем выносить сор из избы?)
    runner.run();
    return 0;
}

