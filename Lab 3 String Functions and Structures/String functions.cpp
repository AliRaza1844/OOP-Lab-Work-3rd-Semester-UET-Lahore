// Name             :  Ali Raza				21-9-2016
// Registration No. :  2015cs52
//This program will perform some function on strings...
//--------------------------------------------------\\

// Header files and global consts...
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

//------------------------------------------------------\\
// Protypes of String functions...
char* strcpy_s(char*, const char*); 
char* strcat_s(char*, const char*);
int strlen_s(const char*);
int strcmp_s(const char*, const char*);
const char* strchr_s(const char*, int);
char* strtok_s(char*, const char*);
//const char* strstr_s(const char*, const char*);
//-------------------------------------------------------\\

//-------------------------------------------------------\\
//-------------mian function strarts from here-----------\\

int main()
{
	char *str1 ;
	char *str2 ;
	int x=0;
	char t='y';
	cout << "\t\t\t/////String Functions/////\n";
	while (t == 'y') 
	{
		cout << "\n Which of the following functions do you want to apply on strings?\n";
		cout << " 1- String copy\n 2- String Cancatination\n 3- String compare\n 4- String Length\n "
			<<"5- Find an character from the given string.\n ";
		cin >> x;

		switch (x) {
			case 1 : 								// String Copy
			{
				int x;
				cout << "\n Enter the length of the string you want to copy...\n ";
				cin >> x;
				str1 = new char[x+1];
				str2 = new char[x+1];
				cout << " Enter the string you want to copy...\n ";
				cin>>str2;
				while (strlen_s(str2) > x)
				{
					cout << "\a\n Sorry for the trouble but you can not enter a string having length gteater than "<<x;
					cout << " \a\n Please enter a string with correct length...\n";
					cin >> str2;
				}
				
				cout << "\n\n After coping  :   " << strcpy_s(str1, str2) << endl;

				delete[] str1;
				delete[] str2;
				break;
			}
			case 2: 								// String Cancatination
			{
				int x;
				cout << "\n Enter the maximum length of the string you want to enter...\n";
				cin >> x;
				str1 = new char[x];
				str2 = new char[x];
				cout << " Now enter the two strings(First in which you want to cancatinate).\n ";
				cin >> str1 >> str2;
				while (strlen_s(str1) > x || (strlen_s(str2) / 2) > x)				// Check that wether the size of any string is greater than the given size... 
				{
					cout << "\a\n Sorry for the trouble but you can not enter any string having length gteater than " << x;
					cout << " \a\n Please enter the strings again with correct length...\n";
					cin >> str1 >> str2;
				}
				str1=strcat_s(str1, str2);
				cout << "\n\n After canctination the first string is :   " << str1 << endl;
				delete[] str1;
				delete[] str2;
				break;
			}
			case 3:											// String Compare
			{
				int n;
				cout << "\n Enter the maximum length of the string you want to enter...\n";
				cin >> n;
				str1 = new char[n];
				str2 = new char[n];
				cout << " Now enter the two strings you want to compare.\n ";
				cin >> str1 >> str2;
				while (strlen_s(str1) > n || strlen_s(str2) > n)			// Check that wether the size of any string is greater than the given size... 
				{
					cout << "\n One of your string is greater than the size you given.  i.e "<<n
						<<"\n Please enter the strings with correct length...";
					cin >> str1 >> str2;
				}
				int x = strcmp_s(str1, str2);
				if (x == 0)
					cout << "\n Both the strings are equal.\n ";
				else if (x == 1)
					cout << "\n First string is greater than the second.\n ";
				else if(x == -1)
					cout << "\n Second string is greater than the first.\n ";
				delete[] str1;
				delete[] str2;
				break;
			}
			case 4:										//String Length
			{
				str1 = new char[50];
				cout << "\n Enter the String.\n ";
				cin>>str1;
				int length = strlen_s(str1);
				cout << "\n The length of the string you entered is :  "<<length;
				delete[] str1;
				break;
			}
			case 5:										// String Character
			{
				int n;
				char character;
				cout << "\n Please enter the length of the string you want to enter.\n ";
				cin >> n;
				char* str = new char[n + 1];
				cout << " \n Now enter the string...\n";
				cin >> str;
				
				while (strlen_s(str) > n)			// Check that wether the size of any string is greater than the given size... 
				{
					cout << "\a\n Sorry for the trouble but you can not enter a string having length gteater than " << x;
					cout << " \a\n Please enter a string with correct length...\n";
					cin >> str;
				}
				
				cout << "\n Now enter the character you want to search.\n ";
				cin >> character;
				
				if (strchr(str,static_cast<int>(character)))
					cout << "\n\n The character you entered exists in the string.\n ";
				else
					cout << "\n\n The character you entered does not exists in the string. ";
				cout <<"\n The string returned from the strchr function  :  "<< strchr(str, static_cast<int>(character));
				
				delete[] str;
				break;
			}
	
			default: 
			{
				cout << "\n\a Your input is not valid...\n Please try again with a valid input...\n ";
				continue;
			}
		}
		
		cout << "\n\n Do you want to continue or not (Enter y to continue and n to not)?\n ";
		cin >> t ;
	}

	_getch();
	return 0;
}
//-------------------------------------------------------------\\

//-------------------------------------------------------------\\
//**************Definations of String Functions****************\\

// This function will copy the second string into the first...
char* strcpy_s(char* D, const char* S)
{
	int length_D, length_S;
	length_D = strlen_s(D);
	length_S = strlen_s(S);
	int i = 0;
	if (S == NULL)
		return D;
	else
	{
		while (S[i] != '\0')
		{
			D[i] = S[i];
			i++;
		}
		D[i] = '\0';
	}
	return D;
}

// Cancatination Function stars from here...
char* strcat_s(char* D, const char* S)
{
	int a = strlen_s(D);
	int b = strlen_s(S);
	int j = 0, i = 0;
	if (S == NULL)						// Checking source string...
		return D;
	else
	{
		if (D == NULL)					// Checking that Destination string is Null or not...
		{
			char* temp = new char[b + 1];
			while (S[i] != '\0')
			{
				temp[i] = S[i];
				i++;
				if (S[i] == '\0')
					temp[i] = '\0';
			}
			D = temp;
		}
		else
		{
			char* temp = new char[a + b + 2];
			for ( ; i < a + b + 1; i++)
			{
				if (i < a)
					temp[i] = D[i];
				else if (i == a)
					temp [i] = ' ';
				else
				{
					temp[i] = S[j];
					j++;
				}
			}

			temp[i] = '\0';
			delete[] D;
			D = temp;
		}	
	}
	return D;
}

// String comparison function...
int strcmp_s(const char* str1, const char* str2)
{
	int l1, l2, n;
	l1 = strlen_s(str1);
	l2 = strlen_s(str2);
	if (str1 == NULL)
		return -1;
	else if (str2 == NULL)
		return 1;
	else if (str1 == NULL&&str2 == NULL)
		return 0;
	else
	{
		n = (l1 > l2) ? l1 : l2;
		for (int i = 0; i < n; i++)
		{
			if (str1[i] > str2[i])
				return 1;
			else if (str1[i] < str2[i])
				return -1;
		}
	}
	return 0;
}

// Function for finding the length of the string...
int strlen_s(const char* str)
{
	int i = 0;
	while (*str++ != '\0')
		i++;
	return i;
}


// Finding a character from a given string...
const char* strchr_s(const char* str, int character)
{
	int i = 0;
	while (*str != '\0')
	{
		if (*str++ == character)
			return --str;
	}
	return 0;
}


char* strtok_s(char* str, const char* delimeter)
{
	int i=0;
	while(str[i]!='\0')
	{
		if (str[i] == *delimeter)
		{
			str[i] = '\0';
			break;
		}
		i++;
	}
	return str;
}
//--------------------------------------------------------------------\\
