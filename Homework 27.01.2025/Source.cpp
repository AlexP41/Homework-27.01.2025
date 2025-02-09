#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <utility>
#include <vector>
#include <limits>

//#include <boost/pfr.hpp>

enum MyConstants {
    // FOR EXERCISE 1 , 2 , 3
    LOW_EDGE_FOR_GENERATION = -10,
    HIGH_EDGE_FOR_GENERATION = 10,

    // FOR EXERCISE 4
    LIMIT_OF_CONUCTS = 4
};


// Struct for execise 4
//typedef struct 
//{
//    string number;
//    string name;
//
//} ContuctNumber;


using namespace std;

#pragma region Functions Prototypes

void exercise(int numberOfExercise);

void fullArray(int& rows, int& columns, int** arr);

void fullVector(int& rows, int& columns, vector<vector<int>>& arr);

void outputArray(int& rows, int& columns, int** arr);

void outputVector(int& rows, int& columns, vector<vector<int>>& arr);

void newOutput(int& rows, int& columns, int** arr);

void addNewRow(int& rows, int& columns, int& rowNumber, int**& arr);

int userInputRowAndColumnNumber(string& someText, int& numberOfRowsInArray);

int userInputNumber(string& someText);

void outputArrayWithColor(int& rows, int& columns, int coloredRowNumber, int** arr);

void deleteRowInVector(int& rows, int& columns, int& rowToDelete, vector<vector<int>>& arr);

int userInputRowAndColumnNumberToDelete(string& someText, int& numberOfRowsInArray);

int userChoiceForExerciseThree();

void twoDimensialToOneDimensial(int& rows, int& columns, vector<vector<int>>& arr);

void oneDimensialToTwoDimensial(int& rows, int& columns, vector<vector<int>>& arr);

void outputDataOfStructure(int& numberOfExistedContucts, string** data);

void searchByContactName(int& numberOfExistedContucts, string& request, string** data);

string userInputData(string& someText);

void searchByNumber(int& numberOfExistedContucts, string& request, string** data);

string userInputContactNumber(string& someText);

void addNewContact(int& numberOfExistedContucts, string**& data);

void deleteDataInPhoneBook(int& numberOfExistedContucts, string**& data);

void changeData(int& numberOfExistedContucts, string**& data);

void clearScreen();

int userChoiceForExerciseFourPhoneBook();

#pragma endregion

/*

    ================
    РОБОТА з РЯДКАМИ
    ================

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

    int row2, col2;

    string textForNumberOfRows2 = "Input rows: ";
    row2 = userInputNumber(textForNumberOfRows2);

    cout << endl;

    string textForNumberOfColumns2 = "Input columns: ";
    col2 = userInputNumber(textForNumberOfColumns2);


    vector<vector<int>> pArr2(row2, vector<int>(col2));

    fullVector(row2, col2, pArr2);

    cout << endl;

    cout << "\033[033mВиведення масиву: \033[0m" << endl;

    outputVector(row2, col2, pArr2);

    int userNumForDelRow2;

    string textForNumberOfRowsExOne2 = "Введіть номер рядка для видалення: ";
    userNumForDelRow2 = userInputRowAndColumnNumberToDelete(textForNumberOfRowsExOne2, row2);

    deleteRowInVector(row2, col2, userNumForDelRow2, pArr2);

    cout << endl << "\033[032mРезультат з видаленим \033[035m" << userNumForDelRow2 << "\033[032m рядком.\033[0m" << endl;
    outputVector(row2, col2, pArr2);

    cout << endl;


#pragma endregion

#pragma region Exercise 3

    exercise(3);
    /*
    №3
    Напишіть функцію для перетворення одновимірного масиву в 2-вимірний і навпаки.
    */


    /*   WRITE YOUR FURTHER CODE HERE  */

    int row3, col3;

    string textForNumberOfRows3 = "Input rows: ";
    row3 = userInputNumber(textForNumberOfRows3);

    cout << endl;

    string textForNumberOfColumns3 = "Input columns: ";
    col3 = userInputNumber(textForNumberOfColumns3);


    vector<vector<int>> pArr3(row3, vector<int>(col3));

    fullVector(row3, col3, pArr3);

    cout << endl;

    cout << "\033[033mВиведення масиву: \033[0m" << endl;

    outputVector(row3, col3, pArr3);

    cout << endl;




    bool isContinue = true;
    while (isContinue)
    {
        int userChoice = userChoiceForExerciseThree();

        /*
        void twoDimensialToOneDimensial(int& rows, int& columns, vector<vector<int>>& arr);

        void oneDimensialToTwoDimensial(int& rows, int& columns, vector<vector<int>>& arr);
        */


        switch (userChoice)
        {
        case 0:
            isContinue = false;
            cout << endl << "\033[042mУВАГА:\033[0m \033[032m Ви успішно вийшли з меню завдання 3 !\033[0m" << endl;
            break;


        case 1:
            // TO DO  1 -> 2
            if (row3 != 1)
            {
                cout << endl << "\033[041mПОПЕРЕДЖЕННЯ:\033[0m  масив і так двовимірний! \n\t       Операція перетворення одновимірного масиву в двовимірній зайва." << endl;
                break;
            }
            oneDimensialToTwoDimensial(row3, col3, pArr3);
            outputVector(row3, col3, pArr3);

            break;

        case 2:
            // TO DO 2 -> 1
            if (row3 == 1)
            {
                cout << endl << "\033[041mПОПЕРЕДЖЕННЯ:\033[0m  масив і так одновимірний! \n\t       Операція перетворення двовимірного масиву в одновимірній зайва." << endl;
                break;
            }
            twoDimensialToOneDimensial(row3, col3, pArr3);
            outputVector(row3, col3, pArr3);

            break;

        default:
            break;
        }

    }
    cout << endl;

#pragma endregion

#pragma region Exercise 4

    /*
    №4
    Створіть динамічний масив, що зберігає в першому рядку ім'я, а в другому — телефон.
    Організуйте пошук за ім'ям і за номером телефону та можливість введення і зміни даних.
    */

    exercise(4);

    int row4 = LIMIT_OF_CONUCTS;
    int col4 = 2;
    int currentFreePosition = 0;


    string** contactListArray = new string * [row4];
    for (int i = 0; i < row4; ++i) {
        contactListArray[i] = new string[col4];
    }

    // Ініціалізуємо масив
    contactListArray[currentFreePosition][0] = "12345";
    contactListArray[currentFreePosition][1] = "John Doe";
    currentFreePosition++;

    contactListArray[currentFreePosition][0] = "67890";
    contactListArray[currentFreePosition][1] = "Jane Smith";
    currentFreePosition++;

    contactListArray[currentFreePosition][0] = "54321";
    contactListArray[currentFreePosition][1] = "Emily Johnson";
    currentFreePosition++;

    bool isWork = true;
        while (isWork)
        {
            int userChoiceForManipulationWithPhoneBook = userChoiceForExerciseFourPhoneBook();

            string textForRequest = "Введіть ім'я контакту: ";
            string request;

            string textForContactNumber = "Введіть номер контакту: ";
            string requestNumber;

            switch (userChoiceForManipulationWithPhoneBook)
            {
            case 0:
                isWork = false;
                cout << endl << "\033[042mУВАГА:\033[0m \033[032m Ви успішно вийшли з меню завдання 4 - телефонної книги !\033[0m" << endl;
                break;
    
    
            case 1:
                outputDataOfStructure(currentFreePosition, contactListArray);
                break;
    
            case 2:
                cout << endl << endl << "\t\033[045m Пошук контакту за ім'ям \033[0m" << endl;
                request = userInputData(textForRequest);
                searchByContactName(currentFreePosition, request, contactListArray);
    
                break;
                  
            case 3:
                cout << endl << endl << "\t\033[045m Пошук контакту за номером телефону \033[0m" << endl;
                requestNumber = userInputContactNumber(textForContactNumber);
                searchByNumber(currentFreePosition, requestNumber, contactListArray);

                break;

            case 4:
                addNewContact(currentFreePosition, contactListArray);

                break;

            case 5:
                deleteDataInPhoneBook(currentFreePosition, contactListArray);


                break;

            case 6:
                changeData(currentFreePosition, contactListArray);

                break;

            case 7:
                clearScreen();
                break;

            default:
                break;
            }
    
        }
        cout << endl;


  
#pragma endregion

#pragma region Deleting Arrays And Vectors

    /* For exercise 1*/
    for (int i = 0; i < row; i++) {
        delete[] pArr1[i];
    }
    delete[] pArr1;


    /* For exercise 2*/
    pArr2.clear();


    /* For exercise 3*/
    pArr3.clear();


    /* For exercise 4*/
    for (int i = 0; i < row4; i++) {
        delete[] contactListArray[i];
    }
    delete[] contactListArray;

#pragma endregion


    return 0;
}





#pragma region Functions


void exercise(int numberOfExercise)
{
    cout << endl << endl << "\t\t\t\t\033[032mExercise " << numberOfExercise << "\033[0m" << endl << endl;
}

void fullArray(int& rows, int& columns, int** arr)
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

void fullVector(int& rows, int& columns, vector<vector<int>>& arr)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = LOW_EDGE_FOR_GENERATION + rand() % HIGH_EDGE_FOR_GENERATION;
        }
    }
}

void outputArray(int& rows, int& columns, int** arr)
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

void outputVector(int& rows, int& columns, vector<vector<int>>& arr)
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

void outputArrayWithColor(int& rows, int& columns, int coloredRowNumber, int** arr)
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

void newOutput(int& rows, int& columns, int** arr)
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

int userInputRowAndColumnNumberToDelete(string& someText, int& numberOfRowsInArray)
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

        if (userNum < 1 || userNum > numberOfRowsInArray + 1)
        {
            cout << endl << "\033[031m Будь ласка введіть число у діапазоні \033[035m від 1 до " << numberOfRowsInArray + 1<< ".\033[0m" << endl;
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

void deleteRowInVector(int& rows, int& columns, int& rowToDelete, vector<vector<int>>& arr)
{

    rows--;
    vector<vector<int>> newVector(rows, vector<int>(columns));

    int newRow = 0;
    for (int row = 0; row < rows + 1; row++) {
        if (row == rowToDelete-1) {
            continue;
        }

        for (int col = 0; col < columns; col++) {
            newVector[newRow][col] = arr[row][col];
        }
        newRow++;
    }

   
    arr.clear();

    arr = newVector;
}

int userChoiceForExerciseThree()
{
    int userChoice;

    while (true) {
        cout << endl;
        cout << "\t\t\t\t\033[42mMENU\033[0m" << endl;
        cout << "\t\t\033[032m[1]\033[0m - Одновимірний у двовимірний" << endl;
        cout << "\t\t\033[032m[2]\033[0m - Двовимірний у одновимірний" << endl;
        cout << "\t\t\033[031m[0]\033[0m - вийти з меню" << endl;
        cout << "\033[033mВведіть ціле число\033[0m" << endl;
        cout << "\033[033mВведіть ваш вибір: \033[0m";
        cin >> userChoice;

     
        if (cin.fail()) {
            cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            continue;
        }

        if (userChoice != 1 && userChoice != 2 && userChoice != 0)
        {
            cout << "\033[031m Помилка! Будь ласка, введіть 1 або 2.\033[0m\n";
            continue;
        }
       
       break;
        
    }

    return userChoice;
}

void twoDimensialToOneDimensial(int& rows, int& columns, vector<vector<int>>& arr)
{
    vector<int>oneDimArray;
    oneDimArray.reserve(rows * columns);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            oneDimArray.push_back(arr[i][j]);
        }
    }

    arr.clear();
    arr.push_back(oneDimArray);

    rows = 1;
    columns = oneDimArray.size();
}

void oneDimensialToTwoDimensial(int& rows, int& columns, vector<vector<int>>& arr)
{
    string textForNewCols = "Введіть нову кількість рядків для нового масиву(кількість колонок буде визначення автоматино): ";

    int totalElements = arr[0].size();


    int newRows;
    while (true)
    {
        newRows = userInputNumber(textForNewCols);
        if (newRows > totalElements)
        {
            cout << endl << "\t\033[041mУВАГА!\033[0m\033[031m   Ви ввели кількість рядків, яка перебільшує кількість символів у масиву. Спробуйте знову.\033[0m" << endl;
            continue;
        }
        if (totalElements % newRows != 0)
        {
            cout << endl << "\t\033[041mУВАГА!\033[0m\033[031m   Ви ввели кількість рядків, не ділиться націло на кількість елементів масиву. Спробуйте знову.\033[0m" << endl;
            continue;
        }

        break;
    }
    int newColumns = totalElements / newRows;

    vector<vector<int>> newArr(newRows, vector<int>(newColumns));

    for (int i = 0; i < totalElements; i++) {
        newArr[i / newColumns][i % newColumns] = arr[0][i]; 
    }

    arr = newArr;
    rows = newRows;
    columns = newColumns;
}


// For Exercise 4

void outputDataOfStructure(int& numberOfExistedContucts, string** data)
{
    cout << endl << endl << "\t\033[045m Виведення інформації телефонної книги: \033[0m" << endl << endl;

    for (size_t i = 0; i < numberOfExistedContucts; i++)
    {
        
            cout << "\033[033mContact number:\033[035m " << data[i][0] << "\033[0m" << endl;
            cout << "\033[033mContact name:\033[035m " << data[i][1] << "\033[0m" << endl;
            cout << endl;
            cout << "-----------------------------------" << endl;
            cout << endl;
    }
}

void toLowerCase(string& str) {
    for (char& c : str) {
        c = tolower(c);
    }
}

void searchByContactName(int& numberOfExistedContucts, string& request, string** data)
{

    string* contuctNames = new string[numberOfExistedContucts];

    for (int i = 0; i < numberOfExistedContucts; i++)
    {
        contuctNames[i] = data[i][1];
    }

    toLowerCase(request);
    //cout << request << endl;

    bool hasFound = false;
    string foundName;
    int showResultCount = 0;
    for (int i = 0; i < numberOfExistedContucts; i++)
    {
        string lowerContuctName = contuctNames[i];
        toLowerCase(lowerContuctName);
        /*cout << lowerContuctName << endl;*/

        if (request == lowerContuctName)
        {
            hasFound = true;
            foundName = contuctNames[i];
            break;
        }
        showResultCount++;
    }

    if (hasFound)
    {
        cout << "\033[032mContact has successfully been found: \033[0m" << endl << endl;
        cout << "\t\033[033mContact number:\033[035m " << data[showResultCount][0] << "\033[0m" << endl;
        cout << "\t\033[033mContact name:\033[035m " << data[showResultCount][1] << "\033[0m" << endl;
        cout << endl;
        cout << "\t-----------------------------------" << endl;
        cout << endl;
    }
  
    else
        cout << "\033[031mКонтакт не знайдено!\033[0m" << endl;

    delete[] contuctNames; 
}

void searchByNumber(int& numberOfExistedContucts, string& request, string** data)
{
    string* Number = new string[numberOfExistedContucts];

    for (int i = 0; i < numberOfExistedContucts; i++)
    {
        Number[i] = data[i][0];
    }

    /*cout << request << endl;*/

    bool hasFound = false;
    string foundName;
    int showResultCount = 0;
    for (int i = 0; i < numberOfExistedContucts; i++)
    {
        string ContuctNumber = Number[i];
        /*cout << ContuctNumber << endl;*/

        if (request == ContuctNumber)
        {
            hasFound = true;
            foundName = Number[i];
            break;
        }
        showResultCount++;
    }

    if (hasFound)
    {
        cout << "\033[032mNumber has successfully been found: \033[0m" << endl << endl;
        cout << "\t\033[033mContact number:\033[035m " << data[showResultCount][0] << "\033[0m" << endl;
        cout << "\t\033[033mContact name:\033[035m " << data[showResultCount][1] << "\033[0m" << endl;
        cout << endl;
        cout << "\t-----------------------------------" << endl;
        cout << endl;
    }

    else
        cout << "\033[031mКонтакт не знайдено!\033[0m" << endl;

    delete[] Number;
}

// HERE
string userInputData(string& someText)
{
    string userStr;

    while (true)
    {
        cout << endl << "\033[033m" << someText << "\033[0m";
        //HERE cin.ignore();  OR   cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, userStr);

        if (cin.fail())
        {
            cout << endl << "\033[031m Помилка! Будь ласка, введіть ім'я контакта.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userStr.empty())
        {
            cout << endl << "\033[031m Будь ласка введіть текст.\033[0m" << endl;
            continue;
        }

        break;
    }

    return userStr;
}

string userInputContactNumber(string& someText)
{
    string userStr;

    while (true)
    {
        cout << endl << "\033[033m" << someText << "\033[0m";
        //HERE cin.ignore();  OR   cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, userStr);

        if (cin.fail())
        {
            cout << endl << "\033[031m Помилка! Будь ласка, введіть номер контакта.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userStr.empty())
        {
            cout << endl << "\033[031m Будь ласка введіть текст.\033[0m" << endl;
            continue;
        }

        break;
    }

    return userStr;
}

void checkResult(int& numberOfExistedContucts, string**& data)
{
    int userChoice1;

    while (true) {
        cout << endl;
        cout << "\t\t\t\t\033[42mБажаєете переглянути?\033[0m" << endl;
        cout << "\t\t\033[032m[1]\033[0m - Так" << endl;
        cout << "\t\t\033[032m[2]\033[0m - Ні" << endl;
        cout << "\033[033mВведіть ваш вибір: \033[0m";
        cin >> userChoice1;


        if (cin.fail()) {
            cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userChoice1 != 1 && userChoice1 != 2)
        {
            cout << "\033[031m Помилка! Будь ласка, введіть 1 або 2.\033[0m\n";
            continue;
        }

        break;

    }

    cout << endl;
    switch (userChoice1)
    {
    case 1:
        outputDataOfStructure(numberOfExistedContucts, data);

    case 2:
        break;

    default:
        break;
    }
    cout << endl;
}

void addNewContact(int& numberOfExistedContucts, string**& data)
{
    cout << endl << endl << "\t\033[042m Додавання нового контакту \033[0m" << endl;

    if (numberOfExistedContucts >= LIMIT_OF_CONUCTS)
    {
        cout << endl << "\033[041mУВАГА!\033[0m  \033[031mКількість контактів у телефонній книзі перевищує ліміт - " << LIMIT_OF_CONUCTS << "\033[0m" << endl << endl;
        return;
    }

    string textForRequest = "Введіть ім'я контакту: ";
    string requestName = userInputData(textForRequest);

    string textForContactNumber = "Введіть номер контакту: ";
    string requestNumber = userInputContactNumber(textForContactNumber);

    data[numberOfExistedContucts][0] = requestNumber;
    data[numberOfExistedContucts][1] = requestName;

    numberOfExistedContucts++;

    cout << endl << "\033[42m Контакт був успішно збережений.\033[0m" << endl;
   
    checkResult(numberOfExistedContucts, data);
}

void deleteDataInPhoneBook(int& numberOfExistedContucts, string**& data)
{
    cout << endl << "\t\033[041m ВИДАЛЕННЯ КОНТАКТУ \033[0m" << endl << endl;

    cout << "\033[033mПошук контакту для видалення\033[0m" << endl;

    int userChoice;
    while (true) {
        cout << endl;
        cout << "\t\t\033[032m[1]\033[0m - за іменем контакту" << endl;
        cout << "\t\t\033[032m[2]\033[0m - за номером контакту" << endl;
        cout << "\033[033mВведіть ваш вибір: \033[0m";
        cin >> userChoice;

        if (cin.fail()) {
            cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userChoice != 1 && userChoice != 2) {
            cout << "\033[031m Помилка! Будь ласка, введіть 1 або 2.\033[0m\n";
            continue;
        }

        break;
    }

    int indexToDelete = -1;
    switch (userChoice)
    {
    case 1: {
        string request;
        cout << "Введіть ім'я контакту: ";
        cin.ignore();
        getline(cin, request);

        toLowerCase(request);

        for (int i = 0; i < numberOfExistedContucts; i++) {
            string contactName = data[i][1];
            toLowerCase(contactName);
            if (contactName == request) {
                indexToDelete = i;
                break;
            }
        }
        break;
    }

    case 2: {
        string request;
        cout << "Введіть номер контакту: ";
        cin.ignore();
        getline(cin, request);

        for (int i = 0; i < numberOfExistedContucts; i++) {
            if (data[i][0] == request) {
                indexToDelete = i;
                break;
            }
        }
        break;
    }
    }

    if (indexToDelete == -1) {
        cout << "\033[031mКонтакт не знайдено!\033[0m" << endl;
        return;
    }

    for (int i = indexToDelete; i < numberOfExistedContucts - 1; i++) {
        data[i][0] = data[i + 1][0];
        data[i][1] = data[i + 1][1];
    }

    data[numberOfExistedContucts - 1][0] = "";
    data[numberOfExistedContucts - 1][1] = "";

    cout << endl << "\033[41m Контакт був успішно видалений. \033[0m" << endl << endl;

    numberOfExistedContucts--;

    // CHECKING

    checkResult(numberOfExistedContucts, data);
}

void changeData(int& numberOfExistedContucts, string**& data)
{
    cout << endl << "\t\033[044m ВНЕСЕННЯ ЗМІН \033[0m" << endl << endl;

    cout << "\033[033mПошук контакту для внесення змін\033[0m" << endl;

    int userChoice;
    while (true) {
        cout << endl;
        cout << "\t\t\033[032m[1]\033[0m - за іменем контакту" << endl;
        cout << "\t\t\033[032m[2]\033[0m - за номером контакту" << endl;
        cout << "\033[033mВведіть ваш вибір: \033[0m";
        cin >> userChoice;

        if (cin.fail()) {
            cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userChoice != 1 && userChoice != 2) {
            cout << "\033[031m Помилка! Будь ласка, введіть 1 або 2.\033[0m\n";
            continue;
        }

        break;
    }

    int indexToModify = -1;
    cout << endl;
    switch (userChoice)
    {
    case 1: {
        string request;
        cout << "Введіть ім'я контакту: ";
        cin.ignore();
        getline(cin, request);

        toLowerCase(request);

     
        for (int i = 0; i < numberOfExistedContucts; i++) {
            string contactName = data[i][1];
            toLowerCase(contactName);
            if (contactName == request) {
                indexToModify = i;
                break;
            }
        }
        break;
    }

    case 2: {
        string request;
        cout << "Введіть номер контакту: ";
        cin.ignore();
        getline(cin, request);

        for (int i = 0; i < numberOfExistedContucts; i++) {
            if (data[i][0] == request) {
                indexToModify = i;
                break;
            }
        }
        break;
    }
    }

    if (indexToModify == -1) {
        cout << "\033[031mКонтакт не знайдено!\033[0m" << endl;
        return;
    }
    cout << endl;
    cout << "\033[032mContact has successfully been found: \033[0m" << endl << endl;
    cout << "\t\033[033mContact number:\033[035m " << data[indexToModify][0] << "\033[0m" << endl;
    cout << "\t\033[033mContact name:\033[035m " << data[indexToModify][1] << "\033[0m" << endl;
    cout << endl;
    cout << "\t-----------------------------------" << endl;
    cout << endl;

    string textForRequest = "\033[0mВведіть \033[032mнове\033[0m ім'я контакту: ";
    string requestFORNAME = userInputData(textForRequest);

    string textForContactNumber = "\033[0mВведіть \033[032mновий\033[0m номер контакту: ";
    string requestFORNUMBER = userInputContactNumber(textForContactNumber);

    data[indexToModify][0] = requestFORNUMBER;
    data[indexToModify][1] = requestFORNAME;

    cout << endl << "\033[42m Контакт був успішно змінений. \033[0m" << endl << endl;

    // CHECKING
    checkResult(numberOfExistedContucts, data);
}

void clearScreen() {
    cout << "\033[2J\033[H";  // Очищає екран і переміщує курсор у верхній лівий кут
}

int userChoiceForExerciseFourPhoneBook()
{
    int userChoice;
    cout << endl;
    cout << "\t\t\t\t\033[44m MENU  Робота з телефонною книгою \033[0m" << endl;
    cout << "\t\t\033[032m[1]\033[0m - виведення даних телефонної книги" << endl;
    cout << "\t\t\033[032m[2]\033[0m - пошук контакту за ім'ям" << endl;
    cout << "\t\t\033[032m[3]\033[0m - пошук контакту за номером" << endl;
    cout << "\t\t\033[032m[4]\033[0m - додати новий контакт" << endl;
    cout << "\t\t\033[032m[5]\033[0m - видалити контакт" << endl;
    cout << "\t\t\033[032m[6]\033[0m - зміна даних" << endl;
    cout << endl;
    cout << "\t\t\033[032m[7]\033[0m - очищення екрану" << endl;
    cout << "\t\t\033[031m[0]\033[0m - вийти з меню" << endl;
    cout << endl;

    while (true) {
        cout << "\033[033mВведіть ваш вибір: \033[0m";
        cin >> userChoice;


        if (cin.fail()) {
            cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5 && userChoice != 6 && userChoice != 7 && userChoice != 0)
        {
            cout << "\033[031m Помилка! Будь ласка, введіть ціле значення у діапазоні від 0 до 7(включно).\033[0m\n";
            continue;
        }

        break;

    }

    return userChoice;
}

#pragma endregion