#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <string>

using namespace std;

struct elem
{
	int rep;
	char ch;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream file("String.txt");

	if (!file)
	{
		cout << "File isn't open. ";
		system("pause");
		exit(1);
	}
	char ch;
	while (file)
	{
		file.get(ch);
		if (file)
		{
			cout << ch;
		}

	}
	file.clear();
	file.seekg(0);
	string s1,s2;
	getline(file, s1);
	getline(file, s2);
	
	elem elems[100];
	for (int i = 0; i < s2.length(); i++)
	{
		elems[i].ch= s2[i];
		elems[i].rep = 0;
	}
	for (int j = 0; j < s1.length(); j++)
	{
		for (int i = 0; i < s2.length(); i++)
		{
			if (s1[j] == elems[i].ch)
			{
				elems[i].rep++;
			}
		}
	}
	cout << endl;
	ofstream resul("Result.txt");
	int m = 0;
	for (int i = 0; i < s2.length(); i++)
	{
		cout << elems[i].ch << " " << elems[i].rep << endl;
	}
	for (int i = 0; i < s2.length()-2; i=i+2)
	{
		if ((elems[i].rep+elems[i+1].rep) % 2 == 1)
		{
			m++;
			resul << "Дужки не збалансовані!";
			break;
		}
	}
	if (m == 0)
	{
		resul << "Дужки збалансовані!";
	}
	resul.close();
	system("pause");
	
	return 0;
}


















/*
using namespace std;


void input_array(int array_1[], int n)
{
	srand(time(NULL));
	for (int a = 0; a < n; a++)
	{
		array_1[a] = rand()%56 - 20;
	}
}

void output_array(int array_1[], int n)
{
	for (int a = 0; a < n; a++)
	{
		cout << setw(4) << array_1[a];
	}
	 cout << endl;
}

void del_digit(int array_1[], int n,int a)
{
	for (a; a < n; a++)
	{
		array_1[a] = array_1[a+1];
	}
}


int main()
{
	int n,b;

	cout << "Input size of array:";
	cin >> n;
	int *array_1 = new int[n];

	input_array(array_1, n);
	output_array(array_1, n);

	cout << "Input digit: ";
	cin >> b;
	for (int a = 0; a < n; a++)
	{
		if (array_1[a] == b)
		{
			del_digit(array_1, n, a);
			n--;
		}
	}
	output_array(array_1, n);

	system("pause");
}*/