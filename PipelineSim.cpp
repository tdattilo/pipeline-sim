//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include "SimProcessor.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ofstream OutFile;
	OutFile.open("output.txt");
	SimProcessor sim;
	string output=sim.run();
	OutFile<<output;
	cout<<output;
	OutFile.close();
	return 0;
}