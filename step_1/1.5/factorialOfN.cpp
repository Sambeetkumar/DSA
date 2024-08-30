#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseArray(int arr[], int n)
{
    int i, j = n - 1;
    for (i = 0; i <= j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    printArray(arr, n);
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);

    return 0;
}