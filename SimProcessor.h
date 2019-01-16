//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include <string>
#include <sstream>
#include "Processor.h"
#ifndef SIMPROCESSOR
#define SIMPROCESSOR

class SimProcessor{
	private:
		Processor processSim;
		std::stringstream output;
	public:
		std::string run();
};
#endif