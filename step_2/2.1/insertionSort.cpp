#include <iostream>
using namespace std;

//function to sort the unsorted part
void insert(int arr[], int i)
{
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        j--;
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        insert(arr, i);
    }
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}