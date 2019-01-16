//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include <iostream>
#ifndef MEMWBREG
#define MEMWBREG

class MEMWBReg{
	private:
		bool MemToReg;
		bool RegWrite;
		int LWDataValue;
		int ALUResult;
		short WriteRegNum;
	public:
		MEMWBReg();
		void setData(bool, bool, int, int, short);
		bool getMemToReg();
		bool getRegWrite();
		int getLWDataValue();
		int getALUResult();
		short getWriteRegNum();
		const MEMWBReg& operator=(const MEMWBReg&);
		friend std::ostream& operator<<(std::ostream&, const MEMWBReg&);
};
#endif