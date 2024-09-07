#include <iostream>
using namespace std;

void bubble(int arr[],int n)
{
    if(n==1) return;
    int noOfSwap = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if(arr[i]>arr[i+1])
        {
          swap(arr[i], arr[i + 1]);
          noOfSwap++;
        }
        if(noOfSwap==0) break;
    }
    bubble(arr, n - 1);
}
int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubble(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}