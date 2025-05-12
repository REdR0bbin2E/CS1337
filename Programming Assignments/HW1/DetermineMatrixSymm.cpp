#include <iostream>
using namespace std; //including my preprocessor directive

void isSymmetrical(int arr[][10], int rows, int columns); //creating the isSymmetrical prototype

int main()
{
    int mrow, mcol; //declaring and initializing mrow and mcol
    cin >> mrow >> mcol;
    
    while (mrow != mcol) // input validation for user input
    {
        cin >> mrow >> mcol;
    }
    

    int userMatrix[10][10]; // Fixed size for array ease to allow passing dimensions to the function

    for (int i = 0; i < mrow; i++)
    {
        for (int z = 0; z < mcol; z++)
        {
            cin >> userMatrix[i][z];
        }
    }

    isSymmetrical(userMatrix, mrow, mcol); //calling my func isSymmetrical

    return 0;
}

void isSymmetrical(int arr[][10], int rows, int columns) //checks if userInput array equals its transposed counterpart
{
    int transposedMatrix[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int z = 0; z < columns; z++)
        {
            transposedMatrix[i][z] = arr[z][i];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int z = 0; z < columns; z++)
        {
            if (arr[i][z] != transposedMatrix[i][z])
            {
                cout << "The matrix is not symmetrical." << endl;
                return;
            }
        }
    }

    cout << "The matrix is symmetrical." << endl;
}
