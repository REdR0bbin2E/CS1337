#include <iostream>
using namespace std;

int main()
{
    int sum = 0;

    // Getting the size of the array from the user
    int arraySize = 0;
    cin >> arraySize;

    int n[arraySize]; // Declare the array with the correct size

    // Getting the elements of the array from the user
    for (int i = 0; i < arraySize; i++)
    {
        cin >> n[i];
    }

    // Calculate the sum of the array elements
    for (int i = 0; i < arraySize; i++)
    {
        sum += n[i];
    }

    // Check for any index whose element matches the sum of all other elements
    for (int i = 0; i < arraySize; i++)
    {
        if (n[i] == (sum - n[i]))
        {
            cout << "Index " << i << " has the sum";
            return 0;
        }
    }

    cout << "No index has the sum";

    return 0;
}
