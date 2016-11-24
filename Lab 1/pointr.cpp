// Ali Raza
// This is to review the thing we have learnt in last semester...
 
#include <iostream>
using namespace std;

// Swaping two integer values with pointers...
void swap(int *a, int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
	//cout<<*a<<"  "<<*b<<endl;
}

// Swaping two floating point numbers with pointers
void swap(float *a, float *b)
{
	float c;
	c=*a;
	*a=*b;
	*b=c;
	//cout<<*a<<"  "<<*b<<endl;
}

// Sorting an array of flaoting point numbers...
float sort(float a[], int n)
{
	for(int i=0; i<n; i++)
		{
			int c=i;
			for(int j=i; j<n-1 ;j++)
				{
					if(a[c]>a[j+1])
							c=j+1;
				}
			swap(&a[i],&a[c]);
		}
}

// Sorting an array of integers...
int sort(int a[],int n)
{
	for(int i=0; i<n; i++)
		{
			int c=i;
			for(int j=i; j<n-1 ;j++)
				{
					if(a[c]>a[j+1])
							c=j+1;
				}
			swap(&a[i],&a[c]);
		}
}

// Functions for printing array values...
void print(int a[], int n)
{
	for(int i=0; i<n ; i++)
		cout<<a[i]<<"  ";
}
void print(float a[], int n)
{
	for(int i=0; i<n ; i++)
		cout<<a[i]<<"  ";
}

int main()
{
	int a=4;
	int d=5;
	cout<<a<<"  "<<d<<endl;
	swap(&a,&d);
	cout<<a<<"  "<<d<<endl;
	double b=3.5;
	char c='r';
	
	int *ap=&a;
	double *bp=&b;
	char * cp=&c;
	cout<<*ap<<"    "<<ap<<endl
	<<*bp<<"    "<<bp<<endl<<*cp<<"    "<<cp<<endl;
	
	//Selection Sort of an integer array
	int array[10]={4,7,6,2,3,1,5,8,9,10};
	cout<<"Values of array before sorting:  ";
	print(array, 10);
	cout<<endl;
	sort(array,10) ;
	cout<<"Values of array after sorting:  ";
	print(array,10);
	cout<<endl;
	//Selection sort of an array having floating point values.
	float array1[10]={4.4,7.6,6.3,2.7,3.7,1.8,5.3,8.5,9.6,10.35};
	cout<<"Values of array before sorting:  ";
	print(array1, 10);
	cout<<endl;
	sort(array1,10) ;
	cout<<"Values of array after sorting:  ";
	print(array1,10);
}

