#ifndef CELL_H_
#define CELL_H_

class Cell {
public:
	Cell();
	double food;
	virtual ~Cell();
	double heightValue=2;
	bool heightComputed=false;
};

#endif
