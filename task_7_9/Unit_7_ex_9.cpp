/*
FIFO
� ���� ������� ���������� ������� ����� ������� � ������� �������.
������, ������������ � ������� ����� �������� ��������� �������, �.�. ������ �
����� ������� ����������� �� ���� ������ � �� �������.


*/


#include <iostream>

class Queue //�����, ����������� �������
{
private:
	static const int MAX = 5; //���������� ��������� � �������
	int qu[MAX];
	int head; // ������ �������
	int tail; // ����� �������

	int length;
	
public:
	Queue()
	{
		head = 0;
		tail = -1;
		length = 0;
	}

	void put(int);// �������� ������� � �������
	int get();//�������� ������� �� ������ �������
};

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Queue q1;
	char action;
	int variable;
	cout << "p - �������� ���������� \ng - ������� ���������� \nn - ����� \n";
	do
	{
		cout << "Input action: ";
		cin >> action;
		switch (action)
		{
		case('p'):
			cout << "������� �������: ";
			cin >> variable;
			q1.put(variable);
			break;
		case('g'):
			cout << "�����: " << q1.get()<<endl;
			break;
		default:
			break;
		}
	} while (action!='n');
	return 0;
}


void Queue::put(int var)
{
	// ���� ����� ����������� �������� ����� ������� ��������� � ������ �������,
	// �� ������������� ����� ������� � ������ �������

	if (tail == MAX - 1)
		tail = -1;
	qu[++tail] = var;
	length++;
}
int Queue::get()
{
	if (length == 0)
	{
		cout << "������ �������!";
		exit(1);
	}


	int var = qu[head++];
	length--;
	// ���� ����� ���������� �������� �� ������� ������ ������ ������� �����
	// �� ����� �������, ���������� ��� � ������ �������
	if (head == MAX)
		head = 0;

	return var;
}