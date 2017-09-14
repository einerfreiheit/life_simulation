#include "XmlSimpleExporter.h"

TiXmlElement* XmlSimpleExporter::addElement(TiXmlElement* rootElement, const std::string &elementName ){
	TiXmlElement *element = new TiXmlElement(elementName);
	rootElement->LinkEndChild(element);
	return element;

}
