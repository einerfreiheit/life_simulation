#ifndef CELL_H_
#define CELL_H_

class Cell {
public:
	Cell();
	double food;
	bool isCreatureHere;
	virtual ~Cell();
	void setCellFood();
};

#endif /* CELL_H_ */
