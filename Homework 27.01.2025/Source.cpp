#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <utility>
#include <vector>
#include <limits>

//#include <boost/pfr.hpp>

enum MyConstants {
    LOW_EDGE_FOR_GENERATION = -10,
    HIGH_EDGE_FOR_GENERATION = 10,
    LIMIT_OF_CONUCTS = 100
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

#pragma endregion

/*

    ================
    ������ � �������
    ================

���������� ������� ������ ������ �� ����������
    https://materials.itstep.org/content/f1811e94-507b-44c2-bfbe-ac7ac02a7178/uk

��������� ������: ��������� �� GitHub
*/


int main()
{
    system("chcp 1251>null");
    srand(time(0));



#pragma region Exercise 1
    /*
    �1
    �������� �������, �� ���� ����� ����������� ������ � ��������� �������. (new/delete)
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

    cout << "\033[033m��������� ������: \033[0m" << endl;

    outputArray(row, col, pArr1);

    int userNumForNewRow;

    string textForNumberOfRowsExOne = "������ ����� ������ �����: ";
    userNumForNewRow = userInputRowAndColumnNumber(textForNumberOfRowsExOne, row);

    addNewRow(row, col, userNumForNewRow, pArr1);

    cout << endl << "\033[032m��������� � ������� ����� \033[035m" << userNumForNewRow << "\033[032m ������.\033[0m" << endl;
    outputArrayWithColor(row, col, userNumForNewRow-1, pArr1);
    
    cout << endl;

    exercise(2);

#pragma endregion 

#pragma region Exercise 2

    /*
   �2
    �������� �������, �� ������� ����� ����������� ������ �� �������� �������. (vector)
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

    cout << "\033[033m��������� ������: \033[0m" << endl;

    outputVector(row2, col2, pArr2);

    int userNumForDelRow2;

    string textForNumberOfRowsExOne2 = "������ ����� ����� ��� ���������: ";
    userNumForDelRow2 = userInputRowAndColumnNumberToDelete(textForNumberOfRowsExOne2, row2);

    deleteRowInVector(row2, col2, userNumForDelRow2, pArr2);

    cout << endl << "\033[032m��������� � ��������� \033[035m" << userNumForDelRow2 << "\033[032m ������.\033[0m" << endl;
    outputVector(row2, col2, pArr2);

    cout << endl;


#pragma endregion

#pragma region Exercise 3

    exercise(3);
    /*
    �3
    �������� ������� ��� ������������ ������������ ������ � 2-������� � �������.
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

    cout << "\033[033m��������� ������: \033[0m" << endl;

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
            cout << endl << "\033[042m�����:\033[0m \033[032m �� ������ ������ � ���� �������� 3 !\033[0m" << endl;
            break;


        case 1:
            // TO DO  1 -> 2
            if (row3 != 1)
            {
                cout << endl << "\033[041m������������:\033[0m  ����� � ��� ����������! \n\t       �������� ������������ ������������ ������ � ��������� �����." << endl;
                break;
            }
            oneDimensialToTwoDimensial(row3, col3, pArr3);
            outputVector(row3, col3, pArr3);

            break;

        case 2:
            // TO DO 2 -> 1
            if (row3 == 1)
            {
                cout << endl << "\033[041m������������:\033[0m  ����� � ��� �����������! \n\t       �������� ������������ ����������� ������ � ���������� �����." << endl;
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
    �4
    ������� ��������� �����, �� ������ � ������� ����� ��'�, � � ������� � �������.
    ���������� ����� �� ��'�� � �� ������� �������� �� ��������� �������� � ���� �����.
    */

    exercise(4);

    int row4 = LIMIT_OF_CONUCTS;
    int col4 = 2;
    int currentFreePosition = 0;


    string** contactListArray = new string * [row4];
    for (int i = 0; i < row4; ++i) {
        contactListArray[i] = new string[col4];
    }

    // ���������� �����
    contactListArray[currentFreePosition][0] = "12345";
    contactListArray[currentFreePosition][1] = "John Doe";
    currentFreePosition++;

    contactListArray[currentFreePosition][0] = "67890";
    contactListArray[currentFreePosition][1] = "Jane Smith";
    currentFreePosition++;

    contactListArray[currentFreePosition][0] = "54321";
    contactListArray[currentFreePosition][1] = "Emily Johnson";
    currentFreePosition++;

    outputDataOfStructure(currentFreePosition, contactListArray);


    string textForRequest = "������ ��'� ��������: ";
    string request = userInputData(textForRequest);

    searchByContactName(currentFreePosition, request, contactListArray);

    string textForContactNumber = "������ ��'� ��������: ";
    string requestNumber = userInputContactNumber(textForContactNumber);


    searchByNumber(currentFreePosition, requestNumber, contactListArray);





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
    for (int i = 0; i < rows; i++) // �������� �� ������
    {
        for (int j = 0; j < columns; j++) // �������� �� ��������
        {
            if (i == coloredRowNumber)
            {
                cout << "\033[035m" << setw(4) << arr[i][j] << "\033[0m"; // Գ�������� ����
            }
            else
            {
                cout << setw(4) << arr[i][j]; // ��������� ����
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
            cout << endl << "\033[031m �������! ���� �����, ������ �����.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userNum < 1 || userNum > numberOfRowsInArray)
        {
            cout << endl << "\033[031m ���� ����� ������ ����� � ������� \033[035m �� 1 �� " << numberOfRowsInArray << ".\033[0m" << endl;
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
            cout << endl << "\033[031m �������! ���� �����, ������ �����.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userNum < 1 || userNum > numberOfRowsInArray + 1)
        {
            cout << endl << "\033[031m ���� ����� ������ ����� � ������� \033[035m �� 1 �� " << numberOfRowsInArray + 1<< ".\033[0m" << endl;
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
            cout << endl << "\033[031m �������! ���� �����, ������ �����.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userNum < 0)
        {
            cout << endl << "\033[031m ���� ����� ������ ����� �����\033[035m 0.\033[0m" << endl;
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
        cout << "\t\t\033[032m[1]\033[0m - ����������� � ����������" << endl;
        cout << "\t\t\033[032m[2]\033[0m - ���������� � �����������" << endl;
        cout << "\t\t\033[031m[0]\033[0m - ����� � ����" << endl;
        cout << "\033[033m������ ���� �����\033[0m" << endl;
        cout << "\033[033m������ ��� ����: \033[0m";
        cin >> userChoice;

     
        if (cin.fail()) {
            cout << "\033[031m �������! ���� �����, ������ �����.\033[0m\n";
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            continue;
        }

        if (userChoice != 1 && userChoice != 2 && userChoice != 0)
        {
            cout << "\033[031m �������! ���� �����, ������ 1 ��� 2.\033[0m\n";
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
    string textForNewCols = "������ ���� ������� ����� ��� ������ ������(������� ������� ���� ���������� ����������): ";

    int totalElements = arr[0].size();


    int newRows;
    while (true)
    {
        newRows = userInputNumber(textForNewCols);
        if (newRows > totalElements)
        {
            cout << endl << "\t\033[041m�����!\033[0m\033[031m   �� ����� ������� �����, ��� ��������� ������� ������� � ������. ��������� �����.\033[0m" << endl;
            continue;
        }
        if (totalElements % newRows != 0)
        {
            cout << endl << "\t\033[041m�����!\033[0m\033[031m   �� ����� ������� �����, �� ������� ������ �� ������� �������� ������. ��������� �����.\033[0m" << endl;
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

void outputDataOfStructure(int& numberOfExistedContucts, string** data)
{
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
        cout << "\033[031mContuct hasn't been found! \033[0m" << endl;

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
        cout << "\033[031mContuct hasn't been found! \033[0m" << endl;

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
            cout << endl << "\033[031m �������! ���� �����, ������ ��'� ��������.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userStr.empty())
        {
            cout << endl << "\033[031m ���� ����� ������ �����.\033[0m" << endl;
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
            cout << endl << "\033[031m �������! ���� �����, ������ ����� ��������.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userStr.empty())
        {
            cout << endl << "\033[031m ���� ����� ������ �����.\033[0m" << endl;
            continue;
        }

        break;
    }

    return userStr;
}


#pragma endregion