//  Name   :   Ali Raza				01-9-2016
//  Registration No:  2015-cs-52
//  This function will define a class Computer and define its functions...

#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<fstream>
#include"Computer.h";
using namespace std;

int getValueFromFile(Computer[]);

int main()
{
	Computer com;
	Computer* computerArray = new Computer[10];
	int num = getValueFromFile(computerArray);
	char ch = 'y';
	int x;

	cout << "\t\t\t...Welcome to the Computer World...\n\n";
	while (ch == 'y')
	{
		cout << "\n How can we help you?\n "
			<< "1- Show details of a Computer.\n 2- Search a computer by processer."
			<< "\n 3- Search a computer by RAM\n   ";
		cin >> x;

		switch (x)
		{
		case 1:
		{
			char* processer = new char[20];
			cout << "\n Enter the title processer of the computer you want to display details.\n  ";
			cin.getline(processer, 100, '.');
			int n;
			n = com.searchbyProcesser(computerArray, processer, num);
			com.showDetails();
			delete[] processer;
			break;
		}
		case 2:
		{
			int ram;
			cout << "\n  Enter the RAM of the computer you want to search for.\n  ";
			cin >> ram;
			int n;
			n = com.searchbyRam(computerArray, ram, num);
			if (n == 0)
				cout << "\n Sorry we don't have record of this computer.\n";
			else
				com.showDetails();

			break;
		}

		case 3:
		{
			char* processer = new char[20];
			cout << "\n Enter the title processer of the computer you want to display details.\n  ";
			cin.getline(processer, 100, '.');
			int n;
			n = com.searchbyProcesser(computerArray, processer, num);
			if (n == 0)
				cout << "\n Sorry we don't have record that computer.\n";
			else
				com.showDetails();

			delete[] processer;
			break;
		}
		default:
		{
			cout << "\n Your input is not valid.";
			break;
		}
		}
		cout << "\n\n Enter y to continue and n to exit.\n ";
		cin >> ch;

	}

	delete[] computerArray;
	_getch();
	return 0;
}

// Getting values from a file in an array of Computer...
int getValueFromFile(Computer arr[])
{
	string str[2];
	int num = 0;
	char* manufacturer = new char[20];
	char* processer = new char[20];
	char* wifi = new char[5];
	int ram, screenSize;
	fstream openFile;
	openFile.open("Computer.txt");
	if (openFile)
	{
		getline(openFile, str[0]);
		getline(openFile, str[1]);
		while (!openFile.eof())
		{
			openFile>>manufacturer;
			openFile << endl;
			openFile.getline(processer, 100, '.');
			openFile >> ram >> screenSize>>wifi;
			arr[num].readComputer(manufacturer, processer, ram, screenSize,wifi);
			num++;
		}
	}
	delete[] manufacturer;
	delete[] processer;
	delete[] wifi;
	openFile.close();
	return num;
}