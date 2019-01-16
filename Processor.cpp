//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017

#include "Processor.h"
#include <string>
#include <sstream>
using namespace std;

Processor::Processor(){
	instructions[0]=0xa1020000;
	instructions[1]=0x810AFFFC;
	instructions[2]=0x00831820;
	instructions[3]=0x01263820;
	instructions[4]=0x01224820;
	instructions[5]=0x81180000;
	instructions[6]=0x81510010;
	instructions[7]=0x00624022;
	instructions[8]=0x00000000;
	instructions[9]=0x00000000;
	instructions[10]=0x00000000;
	instructions[11]=0x00000000;
	for(int x=0; x<1024; x++){
		Main_Mem[x]=x%0x100;
	}
	for(int x=0; x<32; x++){
		if(x==0)
			Regs[x]=0;
		else
			Regs[x]=0x100+x;
	}
	clockCount=0;
}
void Processor::IF_stage(){
	ifidWrite.setIFID(instructions[clockCount]);
	clockCount++;
}
void Processor::ID_stage(){
	int instruction = ifidRead.getIFID();
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
	WriteReg_20_16=instruction>>16&0b11111;
	WriteReg_15_11=instruction>>11&0b11111;
	ReadReg1Value=Regs[instruction>>21&0b11111];
	ReadReg2Value=Regs[instruction>>16&0b11111];
	Function=instruction&0b111111;
	SEOffset=(instruction&0b1111111111111111);
	if(instruction!=0){
		if((instruction>>26&0b111111) != 0){
			if(((instruction>>26)&0b111111)==0x20){//lb
				MemRead=true;
				MemWrite=false;
				MemToReg=true;
				RegWrite=true;
				ALUOp=0b00;
				ALUSrc=true;
				RegDst=false;
			}
			if(((instruction>>26)&0b111111)==0x28){//sb
				MemRead=false;
				MemWrite=true;
				MemToReg=false;
				RegWrite=false;
				ALUOp=0b00;
				ALUSrc=true;
				RegDst=false;
			}
		}
		else{
			MemRead=false;
			MemWrite=false;
			MemToReg=false;
			RegWrite=true;
			if(Function==0x20){//add
				ALUOp=0b00;
				ALUSrc=false;
				RegDst=true;
			}
			else if(Function==0x22){//sub
				ALUOp=0b01;
				ALUSrc=false;
				RegDst=true;
			}
		}
	}
	else {
		RegDst=false;
		ALUSrc=false;
		ALUOp=0;
		MemRead=false;
		MemWrite=false;
		MemToReg=false;
		RegWrite=false;
		ReadReg1Value=0;
		ReadReg2Value=0;
		SEOffset=0;
		WriteReg_20_16=0;
		WriteReg_15_11=0;
		Function=0;
	}
	idexWrite.setValues(RegDst, ALUSrc, ALUOp, MemRead, MemWrite,
	MemToReg, RegWrite, ReadReg1Value, ReadReg2Value, SEOffset,
	WriteReg_20_16, WriteReg_15_11, Function);
}
void Processor::EX_stage(){
	bool regDst=idexRead.getRegDst();
	bool ALUSrc=idexRead.getALUSrc();
	short ALUOp=idexRead.getALUOp();
	int readReg1Value=idexRead.getReadReg1Value();
	int readReg2Value=idexRead.getReadReg2Value();
	int SEOffset=idexRead.getSEOffset();
	int writeReg_20_16=idexRead.getWriteReg_20_16();
	int writeReg_15_11=idexRead.getWriteReg_15_11();
	short function=idexRead.getFunction();
	int ALUResult;
	int SWValue;
	short WriteRegNum;
	bool MemWrite=idexRead.getMemWrite();
	bool MemRead=idexRead.getMemRead();
	if(function!=0 | MemWrite==true | MemRead==true){
		if(ALUOp==0){
			ALUResult=readReg1Value;
			if(ALUSrc)
				ALUResult+=SEOffset;
			else
				ALUResult+=readReg2Value;
		}
		if(ALUOp==0b01)
				ALUResult=readReg1Value-readReg2Value;
		SWValue=readReg2Value;
		if(regDst)
			WriteRegNum=writeReg_15_11;
		else
			WriteRegNum=writeReg_20_16;
	}
	else{
		ALUResult=SWValue=WriteRegNum=0;
	}
	exmemWrite.setData(MemRead, MemWrite, idexRead.getMemToReg(),
		idexRead.getRegWrite(), ALUResult, SWValue, WriteRegNum);
}
void Processor::MEM_stage(){
	bool memRead = exmemRead.getMemRead();
	bool memWrite = exmemRead.getMemWrite();
	int swValue = exmemRead.getSWValue();
	int ALUResult = exmemRead.getALUResult();
	int lwValue;
	if(memRead){
		lwValue=Main_Mem[ALUResult];
	}
	if(memWrite){
		Main_Mem[ALUResult]=swValue;
	}
	memwbWrite.setData(exmemRead.getMemToReg(), exmemRead.getRegWrite(),
		lwValue, exmemRead.getALUResult(), exmemRead.getWriteRegNum());
}
void Processor::WB_stage(){
	bool memToReg = memwbRead.getMemToReg();
	bool regWrite = memwbRead.getRegWrite();
	int lwDataValue = memwbRead.getLWDataValue();
	int ALUResult = memwbRead.getALUResult();
	short writeRegNum = memwbRead.getWriteRegNum();
	if(regWrite){
		if(memToReg){
			Regs[writeRegNum]=lwDataValue;
		}
		else
			Regs[writeRegNum]=ALUResult;
	}
}
std::string Processor::Print_out_everything(){
	stringstream output;
	output<<"Clock cycle: "<<clockCount<<endl;
	output<<"Register Values: "<<endl;
	for (int x=0; x<32; x++){
		output<<"$"<<dec<<x<<"\t\t"<<hex<<Regs[x]<<endl;
	}
	output<<"Write IFID Register"<<endl<<ifidWrite<<endl;
	output<<"Read IFID Register"<<endl<<ifidRead<<endl;
	output<<"Write IDEX Register"<<endl<<idexWrite<<endl;
	output<<"Read IDEX Register"<<endl<<idexRead<<endl;
	output<<"Write EXMEM Register"<<endl<<exmemWrite<<endl;
	output<<"Read EXMEM Register"<<endl<<exmemRead<<endl;
	output<<"Write MEMWB Register"<<endl<<memwbWrite<<endl;
	output<<"Read MEMWB Register"<<endl<<memwbRead<<endl;
	return output.str();
}
void Processor::Copy_write_to_read(){
	ifidRead=ifidWrite;
	idexRead=idexWrite;
	exmemRead=exmemWrite;
	memwbRead=memwbWrite;
}