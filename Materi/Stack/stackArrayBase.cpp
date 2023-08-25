#include <iostream>
#define size 50
using namespace std;

int pool[size], poolSize = 0;

void push(int data)
{
	if (poolSize > size)
		cout << "Stack Full" << endl;
	else
	{
		pool[poolSize] = data;
		poolSize++;
	}
}

bool isEmpty()
{
	if (poolSize != 0)
		return true;
	else
		return false;
}

void clear()
{
	if (isEmpty())
	{
		while (isEmpty())
		{
			pool[poolSize] = 0;
			poolSize--;
		}
		cout << "Stack Clear";
	}
	else
	{
		cout << "Stack is Empty" << endl;
	}
}

void print()
{
	for (int i = 0; i < poolSize; i++)
	{
		cout << "Stack ke-" << i + 1 << " : " << pool[i] << endl;
	}
}

int topEl()
{
	if (isEmpty())
	{
		int value = pool[poolSize - 1];
		return value;
	}
	else
	{
		cout << "Stack is Empty" << endl;
		return 0;
	}
}

int pop()
{
	if (isEmpty())
	{
		int value = pool[poolSize - 1];
		poolSize--;
		return value;
	}
	else
	{
		cout << "Stack is Empty!!" << endl;
		return 0;
	}
}

int main()
{
	for (int x = 0; x < 5; x++)
		push(rand()); // Masukkan Data Random dari 1-5

	print();
	cout << endl;

	if (topEl() == 0)
	{
		cout << "Stack is Empty" << endl;
	}
	else
	{
		cout << "The Top Element is " << topEl() << endl;
	}
	clear();
	return 0;
}