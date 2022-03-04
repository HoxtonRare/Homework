#include <iostream>

using namespace std;

int Hash(char* in)
{
	int sum = 0;
	while (*in != 0)
	{
		sum += *in;
		in++;
	}
	return sum;
}


void calc(int* money, int size, int sum)
{
	int coins = 0;
	int tmp = 0;
	for (int i = 0; i < size; i++)
	{
		coins = 0;
		tmp = money[i];
		coins += sum / tmp;
		sum %= tmp;
		cout << tmp << " копеек - " << coins << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	//Задание 1
	char string[100];
	cout << "Введите строку: " << endl;
	cin >> string;
	cout << "Хэш строки: " << Hash(string) << endl;;

	//Задание 2
	int coins[5] = { 50, 10, 5, 2, 1 };
	calc(coins, 5, 98);
	return 0;
}