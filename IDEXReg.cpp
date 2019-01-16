//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include "IDEXReg.h"
using namespace std;
IDEXReg::IDEXReg(){
	RegDst=0;
	ALUSrc=0;
	ALUOp=0;
	MemRead=0;
	MemWrite=0;
	MemToReg=0;
	RegWrite=0;
	ReadReg1Value=0;
	ReadReg2Value=0;
	SEOffset=0;
	WriteReg_20_16=0;
	WriteReg_15_11=0;
	Function=0;
}
void IDEXReg::setValues(bool a, bool b, short c, bool d, bool e, bool g, bool h, int i, int j, short k, int l, int m, short n){
	RegDst=a;
	ALUSrc=b;
	ALUOp=c;
	MemRead=d;
	MemWrite=e;
	MemToReg=g;
	RegWrite=h;
	ReadReg1Value=i;
	ReadReg2Value=j;
	SEOffset=k;
	WriteReg_20_16=l;
	WriteReg_15_11=m;
	Function=n;
}
const IDEXReg& IDEXReg::operator=(const IDEXReg& other){
	RegDst=other.RegDst;
	ALUSrc=other.ALUSrc;
	ALUOp=other.ALUOp;
	MemRead=other.MemRead;
	MemWrite=other.MemWrite;
	MemToReg=other.MemToReg;
	RegWrite=other.RegWrite;
	ReadReg1Value=other.ReadReg1Value;
	ReadReg2Value=other.ReadReg2Value;
	SEOffset=other.SEOffset;
	WriteReg_20_16=other.WriteReg_20_16;
	WriteReg_15_11=other.WriteReg_15_11;
	Function=other.Function;
	return *this;
}
bool IDEXReg::getRegDst(){
	return RegDst;
}
bool IDEXReg::getALUSrc(){
	return ALUSrc;
}
short IDEXReg::getALUOp(){
	return ALUOp;
}
bool IDEXReg::getMemRead(){
	return MemRead;
}
bool IDEXReg::getMemWrite(){
	return MemWrite;
}
bool IDEXReg::getMemToReg(){
	return MemToReg;
}
bool IDEXReg::getRegWrite(){
	return RegWrite;
}
int IDEXReg::getReadReg1Value(){
	return ReadReg1Value;
}
int IDEXReg::getReadReg2Value(){
	return ReadReg2Value;
}
short IDEXReg::getSEOffset(){
	return SEOffset;
}
int IDEXReg::getWriteReg_20_16(){
	return WriteReg_20_16;
}
int IDEXReg::getWriteReg_15_11(){
	return WriteReg_15_11;
}
short IDEXReg::getFunction(){
	return Function;
}
ostream& operator<<(ostream& output, const IDEXReg& idex){
	output<<"RegDst: "<<"\t\t"<<idex.RegDst<<endl;
	output<<"ALUSrc: "<<"\t\t"<<idex.ALUSrc<<endl;
	output<<"ALUOp: "<<"\t\t"<<hex<<idex.ALUOp<<endl;
	output<<"MemRead: "<<"\t\t"<<idex.MemRead<<endl;
	output<<"MemWrite: "<<"\t\t"<<idex.MemWrite<<endl;
	output<<"MemToReg: "<<"\t\t"<<idex.MemToReg<<endl;
	output<<"RegWrite: "<<"\t\t"<<idex.RegWrite<<endl;
	output<<"ReadReg1Value: "<<"\t\t"<<hex<<idex.ReadReg1Value<<endl;
	output<<"ReadReg2Value: "<<"\t\t"<<hex<<idex.ReadReg2Value<<endl;
	output<<"SEOffset: "<<"\t\t"<<idex.SEOffset<<endl;
	output<<"WriteReg_20_16: "<<"\t\t"<<idex.WriteReg_20_16<<endl;
	output<<"WriteReg_15_11: "<<"\t\t"<<idex.WriteReg_15_11<<endl;
	output<<"Function: "<<"\t\t"<<hex<<idex.Function<<endl;
	return output;
}