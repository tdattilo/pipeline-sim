//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include "MEMWBReg.h"
using namespace std;
	MEMWBReg::MEMWBReg(){
		MemToReg=0;
		RegWrite=0;
		LWDataValue=0;
		ALUResult=0;
		WriteRegNum=0;	
	}
	void MEMWBReg::setData(bool a, bool b, int c, int d, short e){
		MemToReg=a;
		RegWrite=b;
		LWDataValue=c;
		ALUResult=d;
		WriteRegNum=e;	
	}
	bool MEMWBReg::getMemToReg(){
		return MemToReg;
	}
	bool MEMWBReg::getRegWrite(){
		return RegWrite;
	}
	int MEMWBReg::getLWDataValue(){
		return LWDataValue;
	}
	int MEMWBReg::getALUResult(){
		return ALUResult;
	}
	short MEMWBReg::getWriteRegNum(){
		return WriteRegNum;
	}
	const MEMWBReg& MEMWBReg::operator=(const MEMWBReg& other){
		MemToReg=other.MemToReg;
		RegWrite=other.RegWrite;
		LWDataValue=other.LWDataValue;
		ALUResult=other.ALUResult;
		WriteRegNum=other.WriteRegNum;		
		return *this;
	}
	ostream& operator<<(ostream& output, const MEMWBReg& memwb){
		output<<"MemToReg: "<<"\t\t"<<memwb.MemToReg<<endl;
		output<<"RegWrite: "<<"\t\t"<<memwb.RegWrite<<endl;
		output<<"LWDataValue: "<<"\t\t"<<memwb.LWDataValue<<endl;
		output<<"ALUResult: "<<"\t\t"<<memwb.ALUResult<<endl;
		output<<"WriteRegNum: "<<"\t\t"<<memwb.WriteRegNum<<endl;	
		return output;	
	}