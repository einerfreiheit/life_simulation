#ifndef GENETICS_XMLSIMPLEEXPORTER_H_
#define GENETICS_XMLSIMPLEEXPORTER_H_

#include <string>
#include <tinyxml.h>

class XmlSimpleExporter {
public:

	static TiXmlElement* addElement(TiXmlElement* rootElement, const std::string &elementName);

	template<typename T> static void addAttribure(TiXmlElement* element, const std::string &attribute, T &value) {
		element->SetAttribute(attribute, value);
	}
	
	static void addDoubleAttribute(TiXmlElement* element, const std::string &attribute, double value) {
		element->SetDoubleAttribute(attribute, value);
	}
};

#endif
