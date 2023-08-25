#include <iostream>
using namespace std;
#define size 50

int pool[size], poolSize = 0;

bool isEmpty()
{
    if (poolSize != 0)
        return false;
    else
        return true;
}

void push(int dat)
{
    if (poolSize < size)
    {
        pool[poolSize] = dat;
        poolSize++;
    }
    else
    {
        cout << "Stack Penuh" << endl;
    }
}

void clear()
{
    if (!isEmpty())
    {
        poolSize = 0;
    }
    else
        cout << "Stack is Empty" << endl;
}
void pop(int &dat)
{
    if (!isEmpty())
    {
        dat = pool[poolSize - 1];
        poolSize--;
    }
    else
        cout << "Stack is Empty" << endl;
}

void print()
{
    if (!isEmpty())
    {
        for (int i = 0; i < poolSize; i++)
            cout << "Stack ke-" << i + 1 << " : " << pool[i] << endl;
    }
    else
        cout << "Stack is Empty!!" << endl;
}

void topEl(int &dat)
{
    if (!isEmpty())
    {
        dat = pool[poolSize - 1];
    }
    else
        cout << "Stack is Empty" << endl;
}

int main()
{
    int data;
    for (int i = 0; i < 10; i++)
        push(rand());
    print();
    cout << endl;

    clear();
    print();
    return 0;
}