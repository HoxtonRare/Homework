#include <iostream>
#define SZ 10
#define T int
#define SIZE 1000

using namespace std;

typedef struct{
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

T Stack[SIZE];
int cursor = -1;

bool push(T data)
{
    if (cursor < SIZE)
    {
        Stack[++cursor] = data;
        return true;
    } else
    {
        cout << "Стэк переполнен" << endl;
        return false;
    }
}

T pop()
{
    if (cursor != -1)
    {
        return Stack[cursor--];
    } else
    {
        cout << "Стэк пуст" << endl;
        return -1;
    }
}

void init()
{
    for (int i = 0; i < SZ; ++i)
    {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;
    
    if (items == 0)
    {
        arr[tail++] = node;
        items++;
    }
    else if (items == SZ)
    {
        cout<<"\nОчередь заполнена"<<endl;
        return;
    }
    else
    {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for (i = head; i < tail; ++i)
        {
            idx = i % SZ;
            if (arr[idx] ->pr > pr)
                break;
            else
                idx++;
        }
        flag = idx % SZ;
        i++;
        while (i <= tail)
        {
            idx = i % SZ;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag] = node;
        items++;
        tail++;
    }
}

Node* rem()
{
    int flag = 0;
    Node *tmp;
    
    if (items == 0)
    {
        return NULL;
    }
    else
    {
        int max_pr = 0;
        int idx = 0;
        for (int i = head; i < tail; ++i)
        {
            idx = i % SZ;
            if (arr[idx]->pr >= max_pr)
            {
                max_pr = arr[idx]->pr;
                flag = idx;
            }
        }
    }
    tmp = arr[flag];
    arr[flag] = NULL;
    items--;
    tail--;
    return tmp;
}

void printQueue()
{
    cout<<("[ ");
    for (int i = 0; i < SZ; ++i)
    {
        if (arr[i] == 0)
            cout << ("[*, *] ");
        else
            cout << ("[") << arr[i]->pr << (", ") << arr[i]->dat << ("] ");
    }
    cout << endl;
}

void printStack()
{
    while (cursor != -1)
    {
        cout << pop() << " ";
    }
    cout << endl;
}

void bin(int num)
{
    while(num != 0)
    {
        int t = num %2;
        push(t);
        num = num/2;
    }
}


int main()
{
    //Задание 1
    setlocale(LC_ALL, "Rus");
    init();
    ins(1, 15);
    ins(1, 1);
    ins(2, 6);
    ins(6, 10);
    ins(4, 18);
    ins(5, 22);
    ins(6, 54);
    ins(4, 16);
    ins(6, 64);
    ins(2, 12);
    printQueue();
    rem();
    rem();
    printQueue();
    
    //Задание 2
    int num;
    cout << "Введите число: " << endl;
    cin >> num;
    bin(num);
    cout << "Число " << num << " в двоичной системе счисления: ";
    printStack();
    return 0;
}
