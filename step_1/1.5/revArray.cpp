#include <iostream>
#include <array>
#include <vector>
using namespace std;
void revArray(int arr[], int start, int end)
{
    if (start > end)
    {
        return;
    }
    else
    {
        swap(arr[start], arr[end]);
        revArray(arr, start + 1, end - 1);
    }
}
void printArray(int arr[],int n)
{
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main(int argc, char *argv[])
{
    int arr[] = {2, 34, 21, 55, 3, 8};
    cout << "\nexisting array : ";
    printArray(arr, 6);
    revArray(arr, 0, 5);
    cout << "\nreversed array : ";
    printArray(arr, 6);
    return 0;
}