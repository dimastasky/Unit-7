/*
FIFO
В этом задании необходимо создать класс очередь с помощью массива.
Массив, используемый в очереди также называют кольцевым буфером, т.к. начало и
конец очереди циркулируют по нему вместе с ее данными.


*/


#include <iostream>

class Queue //Класс, реализующий очередь
{
private:
	static const int MAX = 5; //количество элементов в массиве
	int qu[MAX];
	int head; // Начало очереди
	int tail; // Конец очереди

	int length;
	
public:
	Queue()
	{
		head = 0;
		tail = -1;
		length = 0;
	}

	void put(int);// Добавить элемент в очередь
	int get();//Вытащить элемент из начала очереди
};

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Queue q1;
	char action;
	int variable;
	cout << "p - добавить переменную \ng - возврат переменной \nn - выход \n";
	do
	{
		cout << "Input action: ";
		cin >> action;
		switch (action)
		{
		case('p'):
			cout << "Введите элемент: ";
			cin >> variable;
			q1.put(variable);
			break;
		case('g'):
			cout << "Вывод: " << q1.get()<<endl;
			break;
		default:
			break;
		}
	} while (action!='n');
	return 0;
}


void Queue::put(int var)
{
	// если перед добавлением элемента конец очереди совпадает с концом массива,
	// то перебрасываем конец очереди в начало массива

	if (tail == MAX - 1)
		tail = -1;
	qu[++tail] = var;
	length++;
}
int Queue::get()
{
	if (length == 0)
	{
		cout << "Пустая очередь!";
		exit(1);
	}


	int var = qu[head++];
	length--;
	// если после извлечения элемента из очереди индекс начала очереди вышел
	// за конец массива, перебросим его в начало массива
	if (head == MAX)
		head = 0;

	return var;
}