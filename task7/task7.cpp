#include <iostream>
#define T char
#define SIZE 100

using namespace std;

typedef struct Node {
    T dat;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} Stack;

void init (Stack *stack)
{
    stack->head = NULL;
    stack->size = 0;
}

bool push(Stack *stack, T value)
{
    Node *tmp = new Node;
    if (tmp == NULL)
    {
        cout << "Стэк переполнен" << endl;
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;
    
    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack *stack)
{
    if (stack->size == 0)
    {
        cout << "Стэк пуст" << endl;
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    stack->size--;
    return data;
}
bool check(Stack* stack, char* arr)
{
    char tmp;
    for (int i = 0; i < strlen(arr); i++)
    {
        switch (arr[i])
        {
            case '(':
                push(stack, arr[i]);
                break;
            case '{':
                push(stack, arr[i]);
                break;
            case '[':
                push(stack, arr[i]);
                break;
            case ')':
                tmp = pop(stack);
                if (tmp == '(')
                {
                break;
                }
                else{
                    cout << "Скобочное выражение написано неверно" << endl;
                    return false;
                }
            case '}':
                tmp = pop(stack);
                if (tmp == '{')
                {
                break;
                }
                else{
                    cout << "Скобочное выражение написано неверно" << endl;
                    return false;
                }
            case ']':
                tmp = pop(stack);
                if (tmp == '[')
                {
                break;
                }
                else{
                    cout << "Скобочное выражение написано неверно" << endl;
                    return false;
            }
        }
    }
    if (stack->size > 0)
    {
        cout << "Скобочное выражение написано неверно" << endl;
        return false;
    }
    else
    {
        cout << "Скобочное выражение написано верно" << endl;
        return true;
    }
}

void ins(Stack* ls, T data)
{
    Node* text = new Node;
    text->dat = data;
    text->next = NULL;
    
    Node* current = ls->head;
    if (current == NULL)
    {
        ls->head = text;
        ls->size++;
        return;
    }
    else
    {
        while (current->next)
        {
            current = current->next;
        }
        current->next = text;
        ls->size++;
    }
}

void print(Stack* ls)
{
    Node* current = ls->head;
    if (current == NULL)
    {
        cout << "Лист пуст" << endl;
    }
    else
    {
        do
        {
            cout << current->dat << " ";
            current = current->next;
        }while(current);
    }
    cout << endl;
}

T getNodeData(Node* n)
{
    if (n == NULL)
    {
        return -1;
    }
    return n->dat;
}

void copy(Stack* ls_1, Stack* ls_2)
{
    Node* current = ls_1->head;
    
    if (current == NULL)
    {
        cout << "Лист пуст" << endl;
        return;
    }
    while (current)
    {
        ins(ls_2,getNodeData(current));
        current = current->next;
    }
    cout << endl;
}

bool checkSort(Stack* ls)
{
    Node* current = ls->head;
    int temp = getNodeData(current);
    current = current->next;
    int equal = 0;
    int count = 0;
    
    while (current)
    {
        if(temp < getNodeData(current))
        {
            count++;
            temp = getNodeData(current);
            current = current->next;
        }
        else if(temp == getNodeData(current))
        {
            equal++;
            temp = getNodeData(current);
            current = current->next;
        }
        else
        {
            cout << "Список не отсортирован" << endl;
            return false;
        }
        
    }
    if (count == (ls->size - 1) || (count + equal) == (ls->size - 1))
    {
        cout << "Список отсортирован" << endl;
        return true;
    }
    else
    {
        cout << "Список не отсортирован" << endl;
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    //Задание 1
    Stack *st = new Stack;
    init(st);
    char arr[100];
    cout << "Введите скобочное выражение: " << endl;
    cin >> arr;
    check(st, arr);
    
    //Задание 2
    Stack* ls_1 = new Stack;
    init(ls_1);
    Stack* ls_2 = new Stack;
    init (ls_2);
    ins(ls_1, 'T');
    ins(ls_1, 'A');
    ins(ls_1, 'S');
    ins(ls_1, 'K');
    cout << "Лист 1:" << endl;
    print(ls_1);
    cout << "Лист 2: " << endl;
    print(ls_2);
    copy(ls_1, ls_2);
    cout << "Лист 2 после копирования:" << endl;
    print(ls_2);
    
    //Задание 3
    cout << "\n\n";
    Stack* ls_3 = new Stack;
    ins(ls_3, '1');
    ins(ls_3, '2');
    ins(ls_3, '4');
    ins(ls_3, '3');
    checkSort(ls_3);
    return 0;
}
