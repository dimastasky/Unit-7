#include <iostream>
#include <ctime>
#include <fcntl.h>
#include <io.h> 

using namespace std;

enum Suit {clubs,diamonds,hearts,spades}; //трефы, бубны, червы, пики
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class cards
{
private:
	int number;
	Suit suit;
public:
	void set(int n, Suit s)
	{
		suit = s;
		number = n;
	}
	void display();
};



void cards::display()
{
	if (number >= 2 && number <= 10)
		wcout << number;
	else
	{
		switch (number)
		{
			case jack: wcout << 'J'; break;
			case queen: wcout << 'Q'; break;
			case king: wcout << 'K'; break;
			case ace: wcout << 'A'; break;
		}
	}
	switch (suit)
	{
	case clubs:    wcout << L'♣'; break; // или L'\x2663' вместо static_cast<char>(5)
	case diamonds: wcout << L'♦'; break; // или L'\x2666' вместо static_cast<char>(4)
	case hearts:   wcout << L'♥'; break; // или L'\x2665' вместо static_cast<char>(3)
	case spades:   wcout << L'♠'; break; // или L'\x2660' вместо static_cast<char>(6)
	}
}

int main()
{
	setlocale(LC_ALL, "");

	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	cards deck[52];
	cards p1[13], p2[13], p3[13], p4[13];
	int j;
	int n = 0;

	for (j = 0; j < 52; j++)
	{
		int num = (j % 13) + 2;
		Suit su = Suit (j / 13);
		deck[j].set(num, su);
	}
	wcout << L"Исходная колода: \n";
	for (j = 0; j < 52; j++)
	{
		deck[j].display();
		wcout << "  ";
		if ( !((j+1) %13))
		{
			wcout << endl;
		}
	}

	srand(time(NULL));
	for (j = 0; j < 52; j++)
	{
		int k = rand() % 52;
		cards temp = deck[j];
		deck[j] = deck[k];
		deck[k] = temp;
	}
	for (j = 0; j < 52; j++)
	{
		int m = j % 13;
		if (m == 0) wcout << L"\nКарты игрока № " << ++n << endl;
		if (j < 13)
		{
			p1[m] = deck[j];
			p1[m].display();
			wcout << " ";
		}
		if (j > 12 && j < 26)
		{
			p2[m] = deck[j];
			p2[m].display();
			wcout << " ";
			
		}
		if (j > 25 && j < 39)
		{
			p3[m] = deck[j];
			p3[m].display();
			wcout << " ";
		}
		if (j > 38 && j < 52)
		{
			p4[m] = deck[j];
			p4[m].display();
			wcout << " ";
		}
	}

	return 0;
}