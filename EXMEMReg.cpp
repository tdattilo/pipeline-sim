//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include "EXMEMReg.h"
using namespace std;
	EXMEMReg::EXMEMReg(){
		MemRead=0;
		MemWrite=0;
		MemToReg=0;
		RegWrite=0;
		ALUResult=0;
		SWValue=0;
		WriteRegNum=0;
	}
	void EXMEMReg::setData(bool a, bool b, bool d, bool e, int h, int i, short j){
		MemRead=a;
		MemWrite=b;
		MemToReg=d;
		RegWrite=e;
		ALUResult=h;
		SWValue=i;
		WriteRegNum=j;	
	}
	bool EXMEMReg::getMemRead(){
		return MemRead;
	}
	bool EXMEMReg::getMemWrite(){
		return MemWrite;
	}
	bool EXMEMReg::getMemToReg(){
		return MemToReg;
	}
	bool EXMEMReg::getRegWrite(){
		return RegWrite;
	}
	int EXMEMReg::getALUResult(){
		return ALUResult;
	}
	int EXMEMReg::getSWValue(){
		return SWValue;
	}
	short EXMEMReg::getWriteRegNum(){
		return WriteRegNum;
	}
	const EXMEMReg& EXMEMReg::operator=(const EXMEMReg& other){
		MemRead=other.MemRead;
		MemWrite=other.MemWrite;
		MemToReg=other.MemToReg;
		RegWrite=other.RegWrite;
		ALUResult=other.ALUResult;
		SWValue=other.SWValue;
		WriteRegNum=other.WriteRegNum;
		return *this;
	}
	ostream& operator<<(ostream& output, const EXMEMReg& exmem){
		output<<"MemRead: "<<"\t\t"<<exmem.MemRead<<endl;
		output<<"MemWrite: "<<"\t\t"<<exmem.MemWrite<<endl;
		output<<"MemToReg: "<<"\t\t"<<exmem.MemToReg<<endl;
		output<<"RegWrite: "<<"\t\t"<<exmem.RegWrite<<endl;
		output<<"ALUResult: "<<"\t\t"<<hex<<exmem.ALUResult<<endl;
		output<<"SWValue: "<<"\t\t"<<hex<<exmem.SWValue<<endl;
		output<<"WriteRegNum: "<<"\t\t"<<exmem.WriteRegNum<<endl;	
		return output;
	}