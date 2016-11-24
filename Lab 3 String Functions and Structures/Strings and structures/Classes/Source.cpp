// Ali Raza...                         15-9-2016
// Introduction to inheritance


#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class publication {
public:
	string title;
	int price;
	void getData(string t, int p) {
		title = t;
		price = p;
	}

};

class sales {
public:
	float sale[3];
	void getData(float a, float b, float c) {
		sale[0] = a;
		sale[1] = b;
		sale[2] = c;
	}
};

class book : public publication, public sales {
public:
	int page_count;
	void getData(int c) {
		page_count = c;
	}
	void showData() {
		cout << " The title of the book is " << title << "\n and its price is " << price << endl
			<< " and book has " << page_count << " pages...\n";
		cout << " The last three month sales are given as \n Month             Sales\n";
		for (int i = 0; i<3; i++) {
			cout << "  " << i + 1 << "                  " << sale[i] << "$\n";
		}
	}
};

class tape : public publication, public sales {
public:
	int time;
	void getData(int t) {
		time = t;
	}
	void showData() {
		cout << fixed;
		cout << " The title of the cassette is " << title << "\n and its price is " << price << endl
			<< " and its playing time is " << time << " mints...\n";
		cout << " The last three month sales are given as \n Month             Sales\n";
		for (int i = 0; i < 3; i++) {
			cout << "  " << i + 1 << "                  " << sale[i] << "$"<<endl ;
		}
	}
};

	int main()
	{
		book b;
		tape t;
		b.publication::getData("OOP in C++", 320);
		b.getData(780);
		//b.sales::getData(2000,58000,100000);
		t.publication::getData("OOP in C++", 100);
		t.getData(30);
		//t.sales::getData(58210,65200,254000);
		b.showData();
		t.showData();

		_getch();
	}