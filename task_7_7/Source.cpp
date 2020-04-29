#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

class money
{
private:
	double dollar;
	char in[80];
	char out[80];
public:
	money() { dollar = 0.0; }
	money(double d): dollar(d) {}
	void input()
	{
		cout << "¬ведите сумму: ";
		cin >> in;
	}
	double mstold(char mass[])
	{
		int n = 0, counter =0 ;
		char fr[20];
		double fraction;
		for (int j = 0; j < strlen(mass); j++)
		{
			if ((mass[j] == '$') || (mass[j] == ','))
				continue;
			if (mass[j] == '.')
			{
				j++;
				while (mass[j] != NULL)
				{
					fr[counter++] = mass[j++];
				}
				continue;
			}
			out[n++] = mass[j];
		}
		fraction = atof(fr);
		for(int i =0; i < counter; i++)
		{
			fraction *= 0.1;
		}
		dollar = atof(out);
		dollar += fraction;
		return dollar;
	}
	void display()
	{
		cout << mstold(in);
	}
};

int main()
{
	setlocale(LC_ALL, "");
	int n = 0;
	char ch;
	money m[100];
	do
	{
		m[n++].input();
		cout << "Continue (y/n)?: ";
		cin >> ch;
	} while (ch != 'n');
	for (int j = 0; j < n; j++)
	{
		m[j].display();
		cout << endl;
	}
	return 0;
}
