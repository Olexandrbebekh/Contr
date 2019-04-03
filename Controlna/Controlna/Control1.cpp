#include<iostream>
#include<math.h>
#include <stdio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, c, i=0;
	cout << "¬ведите число: ";
	cin >> a;
	b = a;
	while (a > 10) {
		a = a / 10;
		i++;
	}

	while (i < 1) {
		c = b % 10;
		b = b / 10;
		a = pow(a, c);
		i--;

	}
	cout << a << endl;
	
	}