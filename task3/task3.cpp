#include <iostream>

using namespace std;

void DecToBin(int a)
{
    if (a < 2)
    {
        cout << a;
    }
    else
    {
        DecToBin(a / 2);
        cout << a % 2;
    }
}

int Degree(int c, int b)
{
    if (b < 0)
    {
        return 1/Degree(c, -b);
    }
    if (b == 0)
    {
        return 1;
    }
    return c*Degree(c, b-1);
}

int DegPar(int c, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b % 2 == 1)
    {
        return DegPar(c, b - 1) * c;
    }
    else
    {
        int a = DegPar(c, b / 2);
        return c * c;
    }
}

int routes (int** arr, int x, int y)
{
    if (x == 0 && y == 0)
    {
        return 0;
    }
    else if (arr[x][y] == 1)
    {
        return 0;
    }
    else if (x == 0)
    {
        if (routes(arr, x, y - 1) == 0 && y != 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if ( y == 0)
    {
        if (routes(arr, x - 1, y) == 0 && x != 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return routes(arr, x - 1, y) + routes(arr, x, y - 1);
}

int main()
{
    setlocale (LC_ALL, "Rus");
    int num;
    int deg;
    cout << "Введите число: " << endl;
    cin >> num;
    DecToBin (num);
    cout << "\nВведите степень: " << endl;
    cin >> deg;
    cout << "Результат возведения в степень рекурсивно: " << Degree(num, deg) << endl;
    cout << "Результат возведения в степень используя свойство четности: " << DegPar(num, deg) << endl;
    
    
    int x = 0;
    int y = 0;
    cout << "Введите X: " << endl;
    cin >> x;
    cout << "Введите Y: " << endl;
    cin >> y;
    int** arr = new int*[y+1];
    arr[0] = new int[((x+1)*(y+1))];
    for (size_t i = 0; i <= y; i++)
    {
        arr[i] = arr[0] + (x+1) * i;
    }
    for (size_t i = 0; i <= y; i++)
    {
        for (size_t j = 0; j <= x; j++)
        {
            arr[i][j] = 0;
        }
    }
    arr[1][1] = 1;
    arr[3][3] = 1;
    cout << "Количество путей: " << routes(arr, y, x) << endl;
    
    delete [] arr[0];
    delete [] arr;
    arr = nullptr;
    
    return 0;
}
