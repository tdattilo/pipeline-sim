//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include "IFIDReg.h"
using namespace std;
IFIDReg::IFIDReg(){
	instruction=0;
}
void IFIDReg::setIFID(int val){
	instruction=val;
}
int IFIDReg::getIFID(){
	return instruction;
}
const IFIDReg& IFIDReg::operator=(const IFIDReg& other){
		instruction=other.instruction;
		return *this;
	}
ostream& operator<<(ostream& output, const IFIDReg& ifid){
	output<<"Instruction: "<<"\t\t"<<hex<<ifid.instruction<<endl;
	return output;
}