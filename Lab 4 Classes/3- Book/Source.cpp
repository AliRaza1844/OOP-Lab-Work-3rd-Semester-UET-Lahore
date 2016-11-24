//  Name   :   Ali Raza				01-9-2016
//  Registration No:  2015-cs-52
//  This function will work as a library function you can add a book,
//  read any exiting book details, search a book by title and auther...

#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<fstream>
#include"book.h";
using namespace std;

int getValuesFromFile(book []);

int main()
{
	book book1;
	book* bookArray = new book[10];
	int num = getValuesFromFile(bookArray);
	char ch = 'y';
	int x;

	cout << "\t\t\t...Welcome to the Library...\n\n";
	while (ch == 'y')
	{
		cout << "\n How can we help you?\n "
			<< "1- Add a book.\n 2- Show details of a book.\n 3- Search a book by title."
			<<"\n 4- Search a book by auther's name\n   ";
		cin >> x;

		switch (x)
		{
			case 1:
			{	
				cout << "\n  Enter the name of the book";
				book1.addBook();
				break;
			}
			case 2:
			{
				char* title = new char[100];
				cout << "\n Enter the title of the book you want to display details.\n  ";
				cin.getline(title, 100, '.');
				int n;
				n = book1.searchBookbyTitle(bookArray, title, num);
				book1.showDetails();
				delete[] title;
				break;
			}
			case 3:
			{
				char* title = new char[100];
				cout << "\n  Enter the title of the book you want to search for.\n  ";
				cin.getline(title, 100, '.');
				int n;
				n = book1.searchBookbyTitle(bookArray, ++title, num);
				if (n == 0)
					cout << "\n Sorry we don't have record of the book you entered.\n";
				else
					book1.showDetails();

				delete[] --title;
				break;
			}

			case 4:
			{
				char* auther = new char[100];
				cout << "\n  Enter the auther's name of the book you want to search for.\n  ";
				cin.getline(auther, 100, '.');
				int n;
				n = book1.searchBookbyAuther(bookArray, ++auther, num);
				if (n == 0)
					cout << "\n Sorry we don't have record of the book you entered.\n";
				else
					book1.showDetails();
				
				delete[] --auther;
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

	delete[] bookArray;
	_getch();
	return 0;
}

// Getting values from a file in an array of book...
int getValuesFromFile(book arr[])
{
	string str[2];
	int num = 0;
	char* title = new char[100];
	char* auther = new char[100];
	int price, pages;
	fstream openFile;
	openFile.open("book.txt");
	if (openFile)
	{
		getline(openFile, str[0]);
		getline(openFile, str[1]);
		while (!openFile.eof())
		{
			//openFile << endl;
			openFile.getline(title, 100, '.');
			openFile << endl;
			openFile.getline(auther, 100, '.');
			openFile >> price >> pages;
			arr[num].readBook(title, auther, price, pages);
			num++;
		}
	}
	delete[] title;
	delete auther;
	openFile.close();
	return num;
}
