//Thomas Dattilo Assignment 3
//MET CS471
//4/22/2017


#include <iostream>
#ifndef IFIDREG
#define IFIDREG

class IFIDReg{
	private:
		int instruction;
	public:
		IFIDReg();
		void setIFID(int);
		int getIFID();
		const IFIDReg& operator=(const IFIDReg&);
		friend std::ostream& operator<<(std::ostream&, const IFIDReg&);
};
#endif