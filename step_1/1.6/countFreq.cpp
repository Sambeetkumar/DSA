#include <iostream>
#include <vector>
#include <map>
using namespace std;

void frequencyCount(vector<int>& arr, int N, int P) {
        // do modify in the given array
        vector<int> ar (arr);
        map<int,int> m;
        for(int i=0; i<ar.size(); i++)
        {
            if(ar[i]<=N)
            ++m[ar[i]];
        }
        for(int i=1; i<=N; i++)
        {
            cout<<m[i]<<endl;
        }
    }
int main(int argc, char* argv[]) {
    vector<int> v{2,3,2,3,5};
    frequencyCount(v, 5, 5);

    return 0;
}