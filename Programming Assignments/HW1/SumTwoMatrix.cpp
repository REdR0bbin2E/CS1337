#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
//including my preprocessor directives and the namespace std

const int ROW = 3;           // Number of divisions & declaring const vars for columns and rows
const int COL = 3;

// write the prototypes for the two functions
void addMatrix(double [][COL], double [][COL], double [][COL]);
void printResult(double [][COL], double [][COL], double [][COL], char);

int main()
{
    int seed;
    cout << "Enter a seed value: "; //getting the seed value from user
    cin >> seed;
    srand(seed);
    
    double matrix1[ROW][COL] = {0}; //creating my matrix's 2D arrays
    double matrix2[ROW][COL] = {0};
    
    //code your program here
    cout << "Matrix1 is : \n";
    for (int i = 0; i < ROW; i++) //assigning a random number from 0-49 for each element in the array matrix1
    {
        for (int z = 0; z < COL; z++)
        {
            matrix1[i][z] = rand() % 50;
            cout << setw(4) << matrix1[i][z];
        }
        cout << endl;
    }

    cout << "Matrix2 is : \n";
    for (int i = 0; i < ROW; i++)  //assigning a random number from 0-49 for each element in the array matrix2
    {
        for (int z = 0; z < COL; z++)
        {
            matrix2[i][z] = rand() % 50;
            cout << setw(4) << matrix2[i][z];
        }
        cout << endl;
    }
    
    double resultMatrix[ROW][COL] = {0}; //creating the third matrix
    // Add two matrices and print the result
    addMatrix(matrix1, matrix2, resultMatrix);
    cout << "The addition of the matrices is " << endl;
    printResult(matrix1, matrix2, resultMatrix, '+');
}

/** The method for adding two matrices */
void addMatrix(double m1[][COL], double m2[][COL], double m3[][COL])
{
    // code to add matrix1 and 2
    for (int i = 0; i < ROW; i++)
    {
        for (int z = 0; z < COL; z++)
        {
            m3[i][z] = m1[i][z] + m2[i][z];
        }
    }
}

/** Print result - Follow this logic so that you have a proper display as in test cases */
void printResult(double m1[][COL], double m2[][COL], double m3[][COL], char op)
{
    // code to display matrix1
    for (int i = 0; i < ROW; i++)
    {
        // Matrix 1 output
        for (int z = 0; z < COL; z++)
        {
            cout << setw(4) << m1[i][z];
        }

        if (i == ROW / 2)
            cout << "  " << op << "  ";
        else
            cout << "     ";

        // Matrix 2 output
        for (int z = 0; z < COL; z++)
        {
            cout << setw(4) << m2[i][z];
        }

        if (i == ROW / 2)
            cout << "  " << "=" << "  ";
        else
            cout << "     ";

        // Matrix 3 output
        for (int z = 0; z < COL; z++)
        {
            cout << setw(4) << m3[i][z];
        }

        cout << endl;
    }
}
