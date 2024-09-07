#include <iostream>
using namespace std;

int select(int arr[], int i,int n)
    {
        // code here such that selectionSort() sorts arr[]
        int min=i;
        for(int j=i ; j<n ; j++)
        {
            if(arr[min]>arr[j])
            min=j;
        }
        return min;
    }
     
void selectionSort(int arr[], int n)
    {
       for(int i=0; i<n-1; i++)
       {
           int v = select(arr,i,n);
           int temp = arr[i];
           arr[i] = arr[v];
           arr[v] = temp;
       }
    }
int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}