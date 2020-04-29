#include <iostream>

using namespace std;

const int MAX = 100;

class fraction
{
private:
	int numerator; //числитель
	int denominator; // знаменатель
public:
	fraction() : numerator(0), denominator(1) {}
	void get_fraction()
	{
		cout << "¬ведите числитель: ";
		cin >> numerator;
		cout << "/n¬ведите знаменатель: ";
		cin >> denominator;
	}
	void show_fraction() const
	{
		cout << endl << numerator << "/" << denominator;
	}

	void lowterms();
	void faverage(fraction, int);
	void fadd(fraction, fraction);

};

int main()
{
	setlocale(LC_ALL, "Russian");
	fraction fractionArray[MAX];
	char yesno;
	int counter = 0;
	fraction total, average;


	do
	{
		cout << "\nЁлемент " << counter + 1 << ": ";
		fractionArray[counter].get_fraction();
		total.fadd(fractionArray[counter], total);
		counter++;
		cout << "Continue (y/n)?: ";
		cin >> yesno;
	} while (yesno != 'n' && counter < MAX);
	
	total.lowterms();

	average.faverage(total, counter);
	average.lowterms();
	
	cout << "Average of " << counter<<" elements: ";
	average.show_fraction();
	cin >> yesno;

	return 0;
}


void fraction::lowterms()
{
	long tchis, tznam, temp, gcd;
	tchis = labs(numerator);
	tznam = labs(denominator);
	if (tznam == 0)
	{
		cout << "\nЌедопустимый знаменатель!";
	}

	else if (tchis == 0)
	{
		numerator = 0;
		denominator = 1;
		return;
	}
	while (tchis != 0)
	{
		if (tchis < tznam)
		{
			temp = tchis; tchis = tznam; tznam = temp;
		}
		tchis = tchis - tznam;
	}
	gcd = tznam;
	numerator= numerator/ gcd;
	denominator = denominator/ gcd;
}
void fraction::fadd(fraction ab, fraction cd)
{
	numerator = ab.numerator * cd.denominator + ab.denominator * cd.numerator;
	denominator = ab.denominator * cd.denominator;
}
void fraction::faverage(fraction summ, int num)
{
	numerator = summ.numerator;
	denominator = summ.denominator * num;
}