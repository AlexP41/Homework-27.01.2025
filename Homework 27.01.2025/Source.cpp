#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <utility>

enum MyConstants {
    LOW_EDGE_FOR_GENERATION = -10,
    HIGH_EDGE_FOR_GENERATION = 10,
};

using namespace std;

#pragma region Functions Prototypes

void exercise(int numberOfExercise);

void fullArray(int rows, int columns, int** arr);

void outputArray(int rows, int columns, int** arr);

int arrayConvertion(int rows, int columns, int** arr);

void newOutput(int rows, int columns, int** arr);

void addNewRow(int& rows, int& columns, int& rowNumber, int**& arr);

int userInputRowAndColumnNumber(string& someText, int& numberOfRowsInArray);

int userInputNumber(string& someText);

void outputArrayWithColor(int rows, int columns, int coloredRowNumber, int** arr);


#pragma endregion

/*

    ================
    РОБОТА з РЯДКАМИ
    ================


№3
    Напишіть функцію для перетворення одновимірного масиву в 2-вимірний і навпаки.

№4
    Створіть динамічний масив, що зберігає в першому рядку ім'я, а в другому — телефон.
    Організуйте пошук за ім'ям і за номером телефону та можливість введення і зміни даних.




Навчальний матеріал можете знайти за посиланням
    https://materials.itstep.org/content/f1811e94-507b-44c2-bfbe-ac7ac02a7178/uk

Результат роботи: посилання на GitHub
*/


int main()
{
    system("chcp 1251>null");
    srand(time(0));



#pragma region Exercise 1
    /*
    №1
    Написати функцію, що додає рядок двовимірному масиву в зазначену позицію. (new/delete)
    */

    exercise(1);

    int row, col;

    string textForNumberOfRows1 = "Input rows: ";
    row = userInputNumber(textForNumberOfRows1);

    cout << endl;

    string textForNumberOfColumns1 = "Input columns: ";
    col = userInputNumber(textForNumberOfColumns1);


    int** pArr1 = new int* [row];

    fullArray(row, col, pArr1);

    cout << endl;

    cout << "\033[033mВиведення масиву: \033[0m" << endl;

    outputArray(row, col, pArr1);

    int userNumForNewRow;

    string textForNumberOfRowsExOne = "Введіть номер нового рядка: ";
    userNumForNewRow = userInputRowAndColumnNumber(textForNumberOfRowsExOne, row);

    addNewRow(row, col, userNumForNewRow, pArr1);

    cout << endl << "\033[032mРезультат з доданим новим \033[035m" << userNumForNewRow << "\033[032m рядком.\033[0m" << endl;
    outputArrayWithColor(row, col, userNumForNewRow-1, pArr1);
    
    cout << endl;

    exercise(2);

#pragma endregion 

#pragma region Exercise 2

    /*
   №2
    Написати функцію, що видаляє рядок двовимірного масиву за вказаним номером. (vector)
    */

  

    exercise(2);



#pragma endregion 

    for (int i = 0; i < row; i++) {
        delete[] pArr1[i];
    }
    delete[] pArr1;

    return 0;
}

#pragma region Functions


void exercise(int numberOfExercise)
{
    cout << endl << endl << "\t\t\t\t\033[032mExercise " << numberOfExercise << "\033[0m" << endl << endl;
}

void fullArray(int rows, int columns, int** arr)
{
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = LOW_EDGE_FOR_GENERATION + rand() % HIGH_EDGE_FOR_GENERATION;

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

void outputArrayWithColor(int rows, int columns, int coloredRowNumber, int** arr)
{
    for (int i = 0; i < rows; i++) // Ітерація по РЯДКАХ
    {
        for (int j = 0; j < columns; j++) // Ітерація по СТОВПЦЯХ
        {
            if (i == coloredRowNumber)
            {
                cout << "\033[035m" << setw(4) << arr[i][j] << "\033[0m"; // Фіолетовий колір
            }
            else
            {
                cout << setw(4) << arr[i][j]; // Звичайний вивід
            }
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

void addNewRow(int& rows, int& columns,int& rowNumber, int**& arr)
{
    rows++;

    int** newArr = new int* [rows];
    for (size_t i = 0; i < rows; i++)
    {
        newArr[i] = new int[columns];
    }

    for (size_t row = 0; row < rows; row++)
    {
            for (size_t col = 0; col < columns; col++)
            {
                if (row < rowNumber-1)
                {
                    newArr[row][col] = arr[row][col];
                }
                else if(row == rowNumber-1)  newArr[row][col] = LOW_EDGE_FOR_GENERATION + rand() % HIGH_EDGE_FOR_GENERATION;
                else
                {
                    newArr[row][col] = arr[row - 1][col];
                }
            }
    }

    for (size_t i = 0; i < rows - 1; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArr;  
}

int userInputRowAndColumnNumber(string& someText, int& numberOfRowsInArray)
{
    int userNum;

    while (true)
    {
        cout << endl << "\033[033m" << someText << "\033[0m";
        cin >> userNum;

        if (cin.fail())
        {
            cout << endl << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userNum < 1 || userNum > numberOfRowsInArray)
        {
            cout << endl << "\033[031m Будь ласка введіть число у діапазоні \033[035m від 1 до " << numberOfRowsInArray << ".\033[0m" << endl;
            continue;
        }

        break;
    }

    return userNum;
}

int userInputNumber(string& someText)
{
    int userNum;

    while (true)
    {
        cout << endl << "\033[033m" << someText << "\033[0m";
        cin >> userNum;

        if (cin.fail())
        {
            cout << endl << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userNum < 0)
        {
            cout << endl << "\033[031m Будь ласка введіть число більше\033[035m 0.\033[0m" << endl;
            continue;
        }

        break;
    }

    return userNum;
}

#pragma endregion