#include"computer.h";

// Prototypes of supporting fuctions...
int strcmp_s(const char*, const char*);
int strlen_s(const char*);

// Constructer
Computer::Computer()
{
	manufacturer = new char[20];
	processor = new char[10];
	wifi = new char[5];
}

// Destructer
Computer::~Computer()
{
	delete[] manufacturer;
	delete[] processor;
	delete[] wifi;
}

// Add Details by user...
void Computer::addDetails()
{
	cin >> manufacturer;
	cin.getline(processor, 10, '.');
	cin >> ram >> screenSize >> wifi;
}

// Add details from file...
void Computer::readComputer(char* m, char* pro, int r, int sz, char* wi)
{
	manufacturer = m;
	processor = pro;
	ram = r;
	screenSize = sz;
	wifi = wi;
}

// Display details...
void Computer::showDetails()
{
	cout << "\n  The detail of this computer are given as  \n";
	cout << "\n  Manufacturer  :   "<<manufacturer<<"\n  Processor  :   "
		<<processor<<" GH\n  RAM   :    "<<ram<<"GB\n  Screen Size  :   "<<screenSize
		<<"\"\n  Wifi   :    "<<wifi;
}

// Search by Processer...
int Computer::searchbyProcesser(Computer arr[], char* pro, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (!strcmp_s(arr[i].processor, pro))
		{
			manufacturer = arr[i].manufacturer;
			processor = arr[i].processor;
			ram = arr[i].ram;
			screenSize = arr[i].screenSize;
			wifi = arr[i].wifi;
			return 1;
		}
	}
	return 0;
}

// Search by RAM...
int Computer::searchbyRam(Computer arr[], int ram, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (arr[i].ram==ram)
		{
			manufacturer = arr[i].manufacturer;
			processor = arr[i].processor;
			ram = arr[i].ram;
			screenSize = arr[i].screenSize;
			wifi = arr[i].wifi;
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