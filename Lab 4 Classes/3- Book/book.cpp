#include"book.h";

// Prototypes of supporting fuctions...
int strcmp_s(const char*, const char*);
int strlen_s(const char*);

// Constructer
book::book()
{
	title = new char[100];
	auther = new char[100];
}

// Destructer
book::~book()
{
	delete[]title;
	delete[]auther;
}

// Member function to add the details of a book...
void book::addBook()
{
	cin.getline(title, 100, '.');
	cout << "\n Now enter the auther's name, price and pages of the book. ";
	cin.getline(auther, 100, '.');
	cin >> price >> pages;
	while (price < 0 || pages < 0)			// Validating the values of price and pages
	{
		if (price < 0)
		{
			cout << "\n Price of a book can not be a negative value. Please enter a valid number.\n ";
			cin >> price;
		}
		if (pages < 0)
		{
			cout << "\n The pages of a book can not be a negative value. Please enter a valid number.\n ";
			cin >> pages;
		}
	}

	fstream write;
	write.open("book.txt", ios::app);
	write << title<<"\t\t\t" << auther <<"\t"<< price<<"\t" << pages;
	write.close();
}

// Member function to show the details of a book...
void book::showDetails()
{
	cout << "\n  The  Details of the book are given below.";
	cout << "\n  Title  :   " << title<<"\n  Auther  :"<<++auther
		<<"\n  Price  :   "<<price<<"$\n  Pages  :   "<<pages;

}

// Member function to read the details of a book...
void book::readBook(char* t, char* a, int pr, int page)
{
	int i = 0;
	while (t[i] != '\0')
	{
		title[i] = t[i];
		i++;
	}
	title[i] = '\0';
	int j = 0;
	while (a[j] != '\0')
	{
		auther[j] = a[j];
		j++;
	}
	auther[j] = '\0';

	price = pr;
	pages = page;
}

// Searching a book by title...
int book::searchBookbyTitle(book arr[], char* t , int num)
{
	for (int i = 0; i < num; i++)
	{
		if (!strcmp_s(arr[i].title, t))
		{
			title = arr[i].title;
			auther = arr[i].auther;
			price = arr[i].price;
			pages = arr[i].pages;
			return 1;
		}
	}
	return 0;
}

// Searching a book by Auther...
int book::searchBookbyAuther(book arr[], char* t, int num)
{
	for (int i = 0; i < num; i++)
	{
		arr[i].auther += 3;
		if (!strcmp_s(arr[i].auther, t))
		{
			title = arr[i].title;
			auther = arr[i].auther;
			price = arr[i].price;
			pages = arr[i].pages;
			return 1;
		}
	}
	return 0;
}



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

int strlen_s(const char* str)
{
	int i = 0;
	while (*str++ != '\0')
		i++;
	return i;
}
