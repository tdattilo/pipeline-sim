//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include <string>
#include "IFIDReg.h"
#include "IDEXReg.h"
#include "EXMEMReg.h"
#include "MEMWBReg.h"
#ifndef PROCESSOR
#define PROCESSOR

class Processor{
	private:
		int Main_Mem[1024];
		int Regs[32];
		IFIDReg ifidWrite;
		IFIDReg ifidRead;
		IDEXReg idexWrite;
		IDEXReg idexRead;
		EXMEMReg exmemWrite;
		EXMEMReg exmemRead;
		MEMWBReg memwbWrite;
		MEMWBReg memwbRead;
		int instructions[12];
		int clockCount;
	public:
		Processor();
		void IF_stage();
		void ID_stage();
		void EX_stage();
		void MEM_stage();
		void WB_stage();
		std::string Print_out_everything();
		void Copy_write_to_read();
};


#endif