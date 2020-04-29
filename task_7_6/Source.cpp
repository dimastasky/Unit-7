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
	cards()
	{}
	void set (int n, Suit s)
	{
		suit = s;
		number = n;
	}
	void display();
};

void cards::display()
{
	if (number >= 2 && number <= 10)
		cout << number;
	else
	{
		switch (number)
		{
			case jack: cout << 'J'; break;
			case queen: cout << 'Q'; break;
			case king: cout << 'K'; break;
			case ace: cout << 'A'; break;
		}
	}
	switch (suit)
	{
	case clubs: wcout << L'\x2663'; break;
	case diamonds: wcout << L'\x2666'; break;
	case hearts: wcout << L'\x2665'; break;
	case spades: wcout << L'\x2660'; break;
	}
}

int main()
{
	//setlocale(LC_ALL, "Russian");

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
	cout << "Исходная колода: \n";
	for (j = 0; j < 52; j++)
	{
		deck[j].display();
		cout << "  ";
		if ( !((j+1) %13))
		{
			cout << endl;
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
		if (m == 0) cout << "\nКарты игрока № " << ++n << endl;
		if (j < 13)
		{
			p1[m] = deck[j];
			p1[m].display();
			cout << " ";
		}
		if (j > 12 && j < 26)
		{
			p2[m] = deck[j];
			p2[m].display();
			cout << " ";
			
		}
		if (j > 25 && j < 39)
		{
			p3[m] = deck[j];
			p3[m].display();
			cout << " ";
		}
		if (j > 38 && j < 52)
		{
			p4[m] = deck[j];
			p4[m].display();
			cout << " ";
		}
	}

	return 0;
}