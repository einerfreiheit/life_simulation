#ifndef SIMPLECONFIGURATION_H
#define SIMPLECONFIGURATION_H

#include <string>
#include <boost/program_options.hpp>

class SimpleConfiguration {
public:
	void load(std::string pathToConfig);
protected:
	void setSection(std::string nextSection);
	virtual void addParams();

	template<typename T> void add(std::string paramName, T &ret, T def) {
		params.add_options()(	(section + "." + paramName).c_str(),
								boost::program_options::value<T>(&ret)->default_value(def));
	}
private:
	void readParams(std::string pathToConfig);

	boost::program_options::options_description params;
	std::string section;
};

#endif // SIMPLECONFIGURATION_H
