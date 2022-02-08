#include <iostream>
#include <math.h>

using namespace std;


int **arrInit(int numRows, int numCols)
{
    int **arr = new int*[numRows];
    for (int i = 0; i < numRows; ++i)
    {
        arr[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j)
            arr[i][j] = rand() % 10 +1;
    }
    return arr;
}


void arrPrint(int **arr, int numRows, int numCols)
{
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
            cout << " " << arr[i][j];
        cout << endl;
    }
}

void sort (int **arr, int numRows, int numCols)
{
    for (int i = 0; i < numCols; ++i)
    {
        for (int j = 0; j < numRows; ++j)
        {
            for (int k = 0;k < numCols; ++k)
            {
                for (int a = 0; a < numRows; ++a)
                {
                    if(arr[i][j] < arr[k][a])
                    {
                        int temp = arr[i][j];
                        arr[i][j] = arr[k][a];
                        arr[k][a] = temp;
                        
                    }
                }
            }
        }
    }
}

void fillArr(int arr[], int size)
{
    int a;
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void invArr(int arr[], int size)
{
    for (int i = 0; i < size/2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n" << endl;
}

void calc(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        int x = arr[i];
        int c = sqrt(fabs(x)) + 5 * pow(x, 3);
        if (c > 400)
        {
            cout << "Результат рассчета элемента " << i << " превышает 400" << endl;
        }
    }
}

int main()
{
    //Задание 1
    const int numRows = 3;
    const int numCols = 3;
    int **arr = arrInit(numRows, numCols);
    arrPrint (arr, numRows, numCols);
    cout << endl;
    sort (arr, numRows, numCols);
    arrPrint (arr, numRows, numCols);
    
    //Задание 2
    int size = 11;
    int seq[size];
    fillArr(seq, size);
    invArr(seq, size);
    calc(seq, size);
    return 0;
}
