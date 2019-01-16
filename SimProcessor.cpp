//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include "SimProcessor.h"
#include <sstream>

std::string SimProcessor::run(){
	for(int x=0; x<12; x++){
		processSim.IF_stage();
		processSim.ID_stage();
		processSim.EX_stage();
		processSim.MEM_stage();
		processSim.WB_stage();
		output<<processSim.Print_out_everything();
		processSim.Copy_write_to_read();
	}
	return output.str();
}