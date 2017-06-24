#ifndef GENETICS_XMLGELOMELOADER_H_
#define GENETICS_XMLGELOMELOADER_H_

#include <vector>
#include <tinyxml.h>
#include "../Creature.h"
#include <string>

class XmlGelomeLoader {
public:
	XmlGelomeLoader();
	virtual ~XmlGelomeLoader();
	void readXml(const char* fileName);
	void readGenomeSection(TiXmlElement *section, std::ofstream &);
};

#endif
