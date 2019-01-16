//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include <iostream>
#ifndef EXMEM
#define EXMEM
	class EXMEMReg{
		private:
			bool MemRead;
			bool MemWrite;
			bool MemToReg;
			bool RegWrite;
			int ALUResult;
			int SWValue;
			short WriteRegNum;
		public:
			EXMEMReg();
			void setData(bool, bool, bool, bool, int, int, short);
			bool getMemRead();
			bool getMemWrite();
			bool getMemToReg();
			bool getRegWrite();
			int getALUResult();
			int getSWValue();
			short getWriteRegNum();
			const EXMEMReg& operator=(const EXMEMReg&);
			friend std::ostream& operator<<(std::ostream&, const EXMEMReg&);
	};
#endif