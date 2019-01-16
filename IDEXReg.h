//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include <iostream>
#ifndef IDEXREG
#define IDEXREG

class IDEXReg{
	private:
		bool RegDst;
		bool ALUSrc;
		short ALUOp;
		bool MemRead;
		bool MemWrite;
		bool MemToReg;
		bool RegWrite;
		int ReadReg1Value;
		int ReadReg2Value;
		short SEOffset;
		int WriteReg_20_16;
		int WriteReg_15_11;
		short Function;
	public:
		IDEXReg();
		void setValues(bool, bool, short, bool, bool, bool, bool, int, int, short, int, int, short);
		const IDEXReg& operator=(const IDEXReg&);
		bool getRegDst();
		bool getALUSrc();
		short getALUOp();
		bool getMemRead();
		bool getMemWrite();
		bool getMemToReg();
		bool getRegWrite();
		int getReadReg1Value();
		int getReadReg2Value();
		short getSEOffset();
		int getWriteReg_20_16();
		int getWriteReg_15_11();
		short getFunction();
		friend std::ostream& operator<<(std::ostream&, const IDEXReg&);
};

#endif