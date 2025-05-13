#include <iostream>

using namespace std;

int findId(int, int[], int);
int insertId(int, int[], int);

int main()
{
    const int MAX_SIZE = 100;
    int sid[MAX_SIZE] = {1, 3, 6, 8, 10};
    int size = 5, num, id;
    
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> id;
        int index = findId(id, sid, size);
        
        if (index != -1)
        {
            cout << id << " found at position " << index << "\n";
        }
        else
        {
            cout << id << " not found \n";
            size = insertId(id, sid, size);  // Update size after insertion
            cout << id << " inserted into the array\n";
        }
    }

    cout << "The array with all the elements inserted are: ";
    for (int i = 0; i < size; i++)
    {
        cout << sid[i] << " ";
    }
    cout << endl;

    return 0;
}

// Returns the index of val if it is present in the array, otherwise returns -1
int findId(int val, int arrId[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (arrId[i] == val)
        {
            return i;
        }
    }
    return -1;
}

// Inserts a value into the sorted array while maintaining order and returns new size
int insertId(int val, int arrId[], int sz)
{
    int i;
    for (i = 0; i < sz; i++)
    {
        if (val < arrId[i])
        {
            break;
        }
    }

    // Shift elements to the right
    for (int j = sz; j > i; j--)
    {
        arrId[j] = arrId[j - 1];
    }

    // Insert the new value
    arrId[i] = val;

    return sz + 1;  // Return new size
}
