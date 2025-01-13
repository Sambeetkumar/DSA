#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&v,int n)
{
    int cnt = 0;
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n;j++)
        {
            if(v[min]>v[j])
                min = j;
        }
        if(min!=i) cnt++;
        swap(v[min], v[i]);
    }
}
int main(int argc, char* argv[]) {
    vector<int> v = {24,18,38,43,14,40,1,4};
    selectionSort(v, 8);
    for(auto it:v)
    {
        cout << it << " ";
    }
    return 0;
}