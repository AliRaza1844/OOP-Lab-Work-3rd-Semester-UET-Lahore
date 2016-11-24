// Name             :  Ali Raza										22-9-2016
// Registration No. :  2015cs52
// This function will illustrate the structures in C++...
// Their formation, defination and usage...
//-----------------------------------------------------\\

// Header files...
#include<iostream>
#include<conio.h>
using namespace std;

// Structure defination...
struct Student {
	char registrationNo[20];
	char name[20];
	int id;
};

// Prototypes of user defined functions...
void printStudent(Student&);
Student readStudent();
int findStudent(const Student [], int, int);
int findStudent(const Student[], char*,int);
char* findStudentDegreeName(Student);
char* findStudentSession(Student);
int strlen_s(const char*);
int strcmp_s(const char*, const char*);

// main Function...
int main()
{
	int num,x;
	char t = 'y';
	cout << "\n  Before starting the things first tell me that how many\n  students are there in the given list...\n  ";
	cin >> num;
	Student* S_list=new Student[num];				// Defining an array of class Student of user defined size...

	for (int i = 0; i < num; i++)					// for loop for passing values to the array S_list...
		S_list[i] = readStudent();

	while (t == 'y')
	{
		cout << "\n Now tell me that which of the following functions you want to\n perform on the list of students?\n";
		cout << "\t\t1-  Show details of a specific student\n\t\t2-  Find Session of a specifid student\n"
			<<"\t\t3-  Find Degree name of a specifc student\n\t\t4-  Find a specific student from the list of students by student id.\n  "
			<<"\t\t5-  Find a specific student from the list of students by Registration Number.\n  ";
		cin >> x;
		
		switch (x)
		{
			case 1:
			{
				char* rgno = new char[20];
				cout << "\n  Enter the registration number of the student.\n  ";
				cin >> rgno;
				int index = findStudent(S_list, rgno, num);
				if (index == -1)
					cout << "\n  Sorry this student is not in the list.";
				else
				{
					cout << "  The details of the student you searched for are given as.\n  ";
					printStudent(S_list[index]);
				}
				delete[] rgno;
				break;
			}
			
			case 2:
			{
				int id;
				cout << "\n  Enter the id of the student.\n  ";
				cin >> id;
				int index = findStudent(S_list, id, num);
				if (index == -1)
					cout << "\n  Sorry this student is not in the list.";
				else
				{
					cout << "\n  The session of the student you searched for is  :   ";
					char* session = findStudentSession(S_list[0]);
					cout << session<<endl;
					delete[] session;
				}
				break;
			}
			
			case 3:
			{
				int id;
				cout << "\n  Enter the id of the student.\n  ";
				cin >> id;
				int index = findStudent(S_list, id, num);
				if (index == -1)
					cout << "\n  Sorry this student is not in the list.";
				else
				{
					cout << "\n  The degree name of the student you searched for is  :   ";
					char* degree_name = findStudentDegreeName(S_list[index]);
					cout << degree_name<<endl;
					delete[] degree_name;
				}
				break;
			}
			
			case 4:
			{
				int id;
				cout << "\n  Enter the id of the student you want to search for.\n  ";
				cin >> id;
				int index = findStudent(S_list, id, num);
				if (index == -1)
					cout << "\n  Sorry this student is not in the list.";
				else
				{
					cout << "\n  The details of the student you searched for are given as.\n  ";
					printStudent(S_list[index]);
				}
				break;	
			}

			case 5:
			{
				char* rgno=new char[20];
				cout << "\n  Enter the registration of the student you want to search for.\n  ";
				cin >> rgno;
				int index = findStudent(S_list, rgno, num);
				if (index == -1)
					cout << "\n  Sorry this student is not in the list.";
				else
				{
					cout << "\n  The details of the student you searched for are given as.\n  ";
					printStudent(S_list[index]);
				}
				break;
			}
			
			default: 
			{
				cout << "\n\a Your input is not valid...\n Please try again with a valid input...\n ";
				break;
			}
			
		}

		cout << "\n\n  Do you want to continue or not(Enter y for yes and n for no)?\n  ";
		cin >> t;
	}
	delete[] S_list;
	_getch();
	return 0;
}

//**************Definations of Functions****************\\

// Function for printing Student struct...
void printStudent(Student& c)
{
	cout << "\n\n  Name of Student  :  "<<c.name
		<<"\n  ID         :  "<<c.id<<"\n  Registration Number  :  "<<c.registrationNo;
}

// Function for reading Student struct...
Student readStudent()
{
	static int x = 0;
	Student std;

	cout << " \n  Enter name of Student "<<x+1<<"\n  ";
	cin>>std.name;
	cout<<"\n  Now enter the id and registration number of Student "<<x+1<<"\n  ";
	cin >> std.id >> std.registrationNo;
	x++;
	return std;
}

// Functoin for finding a given student from the list of students...
int findStudent(const Student std[], char* registration_number, int num)
{
	int i=0;
	for ( ; i < num; i++)
	{
		if (!strcmp_s(std[i].registrationNo , registration_number))
			return i;
	}
	return -1;
}

// Function for finding an Student with id;
int findStudent(const Student list[], int id, int num)
{
	int i = 0;
	for ( ; i < num; i++)
	{
		if (list[i].id == id)
			return i;
	}
	return -1;
}

// Function for extracting student's degree name from its registration number...
char* findStudentDegreeName(Student std)
{
	char* degree_name = new char[10];
	char a;
	int i = 0, j = 0;
	while (std.registrationNo[i] != '\0')
	{
		a = std.registrationNo[i];
		if ((a > 64 && a < 91) || (a > 96 && a < 123))
		{
			degree_name[j] = a;
			j++;
		}
		i++;
	}
	degree_name[j] = '\0';
	return degree_name;
}

// Function for finding student's session by registration number...
char* findStudentSession(Student std)
{
	char* session = new char[5];
	int i = 0;
	while (std.registrationNo[i] < 58 && std.registrationNo[i] > 47)
	{
		session[i] = std.registrationNo[i];
		i++;
	}
	session[i] = '\0';
	return session;
}

//  Function for comaring strings...
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
