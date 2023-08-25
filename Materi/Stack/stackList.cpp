#include <iostream>
using namespace std;

struct theCell
{
    int data;
    theCell *next;
};

theCell *ptr = NULL;
theCell *top = NULL;

bool isEmpty()
{
    if (top != NULL)
    {
        return false;
    }
    else
        return true;
}

void push(int dat)
{
    ptr = new theCell;
    ptr->data = dat;
    ptr->next = top;
    top = ptr;
}

void pop(int &data)
{
    if (!isEmpty())
    {
        data = top->data;
        ptr = top;
        top = top->next;
        free(ptr);
    }
    else
        cout << "Stack is Empty!" << endl;
}

void topEl(int &data)
{
    if (!isEmpty())
    {
        data = top->data;
    }
    else
        cout << "Stack is Empty!" << endl;
}
void print()
{
    if (!isEmpty())
    {
        int i = 0;
        ptr = top;
        while (ptr != NULL)
        {
            cout << "Stack ke-" << i + 1 << " : " << ptr->data << endl;
            ptr = ptr->next;
            i++;
        }
    }
    else
        cout << "Stack is Empty!!" << endl;
}

void clear()
{
    if (!isEmpty())
    {
        while (top != NULL)
        {
            ptr = top;
            top = top->next;
            free(ptr);
        }
    }
    else
        cout << "Stack is Empty!" << endl;
}
int main()
{
    // Push Data
    for (int i = 0; i < 10; i++)
        push(rand());
    print();

    int data;
    // Pop Data
    pop(data);
    cout << endl
         << data << endl;
    print();

    // Top Element
    topEl(data);
    cout << endl
         << data << endl;

    clear();
    print();
    return 0;
}