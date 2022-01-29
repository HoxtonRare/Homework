#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale (LC_ALL, "Rus");
    int a;
    cout<<"Введите число: "<<endl;
    cin >> a;
    bool isPrime = true;
    if (a == 1 || a == 0)
    {
        isPrime = false;
    }
    else if (a == 2)
    {
        isPrime = true;
    }
    else if (a % 2 == 0)
    {
        isPrime = false;
    }
    else
    {
        for (size_t i = 3; i <= round(sqrt(a)); i += 2)
        {
            if (a % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    if (isPrime)
    {
        cout<< "Число является простым"<<endl;
    }
    else
    {
        cout<< "Число не является простым"<<endl;
    }
}
