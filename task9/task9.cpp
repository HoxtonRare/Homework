#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Stack
{
	Node* head;
	int size;
};

void initStack(Stack* stack)
{
	stack->head = nullptr;
	stack->size = 0;
}

bool push(Stack* stack, int value)
{
	Node* tmp = new Node;
	if (tmp == nullptr)
	{
		cout << "\nStack overflow\n";
		return false;
	}
	tmp->data = value;
	tmp->next = stack->head;

	stack->head = tmp;
	stack->size++;
	return true;
}

int pop(Stack* stack)
{
	if (stack->size == 0)
	{
		return -1;
	}
	Node* tmp = stack->head;
	int data = stack->head->data;
	stack->head = stack->head->next;
	delete tmp;
	stack->size--;
	return data;
}


const int n = 6;
int matrix[n][n] = {
	{0,1,1,0,0,0},
	{0,0,0,1,1,1},
	{0,0,0,0,0,1},
	{1,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,1,0},
};
int visited[n];

void depthTravers(int st)
{
	Stack* stack = new Stack;
	initStack(stack);
	int r;
	for (int k = 0; k < n; k++)
	{
		for (r = n - 1; r >= 0; r--)
		{
			if (matrix[st][r] == 1 && !visited[r])
			{
				push(stack, r);
			}
		}
		cout << st;
		visited[st] = 1;
		st = pop(stack);
		if (st == -1)
		{
			break;
		}
	}
	while (pop(stack) >= 0)
	{
		pop(stack);
	}
	delete stack;
}

void resetArr()
{
	for (int k = 0; k < n; k++)
	{
		visited[k] = 0;
	}
}

int countingConnections(int len, int vertex)
{
	if (len == vertex)
	{
		return 0 + countingConnections(len - 1, vertex);
	}
	else if (matrix[len][vertex] == 1 && len >= 0)
	{
		return 1 + countingConnections(len - 1, vertex);
	}
	else if (len < 0)
	{
		return 0;
	}
	else
	{
		return 0 + countingConnections(len - 1, vertex);
	}
}

void countAllVertices()
{
	for (int k = 0; k < n; k++)
	{
		cout << countingConnections(n, k);
	}
}

void countTraversVertices(int st)
{

	Stack* stack = new Stack;
	initStack(stack);
	int r;
	for (int k = 0; k < n; k++)
	{
		for (r = n - 1; r >= 0; r--)
		{
			if (matrix[st][r] == 1 && !visited[r])
			{
				push(stack, r);
			}
		}
		cout << countingConnections(n, st);
		visited[st] = 1;
		st = pop(stack);
		if (st == -1)
		{
			break;
		}
	}
	while (pop(stack) >= 0)
	{
		pop(stack);
	}
	delete stack;
	cout << endl;
}

int main()
{
	//Задание 1
	
	depthTravers(0);
	resetArr();
	cout << endl;
	depthTravers(2);
	resetArr();
	cout << endl;
	depthTravers(1);
	resetArr();

	cout << endl << endl;


	//Задание 2
	cout << "All vertices:\n\n";
	countAllVertices();
	cout << endl;

	cout << "\nTravers end count vertices:\n\n";
	countTraversVertices(0);
	resetArr();
	countTraversVertices(2);
	resetArr();
	countTraversVertices(1);
	resetArr();

	cout << endl;

	return 0;
}
