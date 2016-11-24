#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class book 
{
private:
	char* title;
	char* auther;
	int price, pages;
	string chapterNames[10];
public:
	
	book();
	~book();
	void addBook();
	void readBook(char*,char*,int, int);
	int searchBookbyTitle(book[], char*, int);
	int searchBookbyAuther(book[], char*, int);
	void showDetails();
};