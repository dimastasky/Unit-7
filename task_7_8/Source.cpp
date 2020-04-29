#include <iostream>

using namespace std;

const int LIMIT = 100; //размер массива

class safearray
{
private:
	int element[LIMIT];
public:
	void putel(int index, int el)
	{
		if (index >= 0 && index <= (LIMIT - 1))
		{
			element[index] = el;
		}
		else
		{
			cout << "Wrong index!" << endl;
			exit(1);
		}
	}
	int getel(int index)
	{
		if (index >= 0 && index <= (LIMIT - 1))
		{
			return element[index];
		}
		else
		{
			cout << "Wrong index!" << endl;
			exit(1);
		}
	}
};

int main()
{
	safearray sa1;
	char yesno;
	int ind, temp, temp2;
	do
	{
		cout << "Input index: ";
		cin >> ind;
		cout << "Input element: ";
		cin >> temp;
		sa1.putel(ind, temp);

		cout << "Continue? (y/n): ";
		cin >> yesno;
	} while (yesno != 'n');

	do
	{
		cout << "Input index: ";
		cin >> ind;
		temp2 = sa1.getel(ind);
		cout << "Your element: " << temp2 << endl;

		cout << "Continue? (y/n): ";
		cin >> yesno;
	} while (yesno != 'n');

	return 0;
}