#include<iostream>
using namespace std;
class Computer
{
	private:
		char* manufacturer;
		char* processor;
		int	ram;
		int	screenSize;
		char* wifi;
	public:
		Computer();
		~Computer();
		void addDetails();
		void showDetails();
		void readComputer(char*, char*, int, int, char*);
		int searchbyProcesser(Computer[], char*, int);
		int searchbyRam(Computer[], int, int);
};