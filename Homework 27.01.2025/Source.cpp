#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void fullArray(int rows, int columns, int** arr);

void outputArray(int rows, int columns, int** arr);

int arrayConvertion(int rows, int columns, int** arr);

void arrayWithoutNulls(int rowsOld, int rowsNew, int columns, int** oldArray);

void matrix(int rows, int columns, int** arr);

void newOutput(int rows, int columns, int** arr);

int main()
{
    system("chcp 1251>null");
    srand(time(0));

    int row, col;

    cout << "Input rows: ";
    cin >> row;

    cout << endl;
    cout << "Input columns: ";
    cin >> col;


    int** pArr = new int* [row];

    fullArray(row, col, pArr);

    cout << endl;

    cout << "\033[033mВиведення масиву: \033[0m" << endl;

    outputArray(row, col, pArr);

  

    for (int i = 0; i < row; i++) {
        delete[] pArr[i];
    }
    delete[] pArr;

    return 0;
}

void fullArray(int rows, int columns, int** arr)
{
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = -5 + rand() % 11;

        }
    }
}

void outputArray(int rows, int columns, int** arr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(4) << arr[i][j];

        }
        cout << endl;
    }
}

void newOutput(int rows, int columns, int** arr)
{
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << setw(4) << arr[j][i];

        }
        cout << endl;
    }
}

int arrayConvertion(int rows, int columns, int** arr)
{
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] == 0)
            {
                count++;
                break;
            }
        }
    }

    return count;
}

void matrix(int rows, int columns, int** arr)
{
    const int amount = rows * columns;
    int* auxArr = new int[amount];

    int index = 0;


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            auxArr[index] = arr[i][j];
            index++;
        }
    }

    cout << endl << "\033[033mМасив матриця:\033[0m" << endl;
    index = 0;
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << setw(5) << auxArr[index];
            index++;

        }
        cout << endl;
    }
    cout << endl;


    delete[] auxArr;
}

void matrixWithoutAuxiliaryArray(int rows, int columns, int** arr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

        }
        cout << endl;
    }
}

void arrayWithoutNulls(int rowsOld, int rowsNew, int columns, int** oldArray)
{
    int** newArray = new int* [rowsNew];

    int index = 0;

    for (int i = 0; i < rowsOld; i++)
    {
        int zero = 0;
        for (int j = 0; j < columns; j++)
        {
            if (oldArray[i][j] == 0)
            {
                zero = 1;
                break;
            }

        }
        if (zero == 0)
        {
            newArray[index] = new int[columns];
            for (int n = 0; n < columns; n++)
            {
                newArray[index][n] = oldArray[i][n];
            }
            index++;
        }
    }

    cout << endl << "Масив без нуликів: " << endl;
    outputArray(rowsNew, columns, newArray);

    for (int i = 0; i < rowsOld; i++) {
        delete[] newArray[i];
    }
    delete[]  newArray;
}