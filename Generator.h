//-*-c++-*-
#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <string>
#include <map>
#include "Range.h"

class Generator {
	std::string content;
	std::vector<Range> rvec;
	std::vector<int> memory;

	int memidx;
	
	
	void analyze(const std::string & txt);

	int mkrng(std::map<int, int> &cnt,
	          std::vector<Range> & rv,
	          int correction,
	          bool real);
		

public:
	Generator(const std::string & txt);
	virtual ~Generator();
};

#endif //GENERATOR_H
