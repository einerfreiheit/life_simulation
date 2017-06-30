#include "XmlSimpleEporter.h"

TiXmlElement* XmlSimpleEporter::addElement(TiXmlElement* rootElement, const std::string &elementName ){
	TiXmlElement *element = new TiXmlElement(elementName);
	rootElement->LinkEndChild(element);
	return element;

}
