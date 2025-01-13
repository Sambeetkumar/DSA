#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B) {
    unordered_map<int,int> m;
    int count=0;
    int xr=0;
    for(int i=0; i<A.size(); i++)
    {
        xr^=A[i];//updating xr variable by xoring the elements of the array starting from index 0
        if(xr==B)//if xr==target, we have found a sub array with xor value B, so incr count by 1
        { count++; }
        /*finding the required xor value which gives the current xor value when xored with B*/
        int rem = B^xr;
        if(m.find(rem)!=m.end())
        {
            /*the required xor value is obtained before the increase the value of count
            by the number of times required xor obtained before*/
            count+=m[rem];
        }
        m[xr]++;//hasing xor value with its frequency
        
    }
    return count;
}
int main(int argc, char* argv[]) {
    vector<int> v = {4, 2, 2, 6, 4};
    int ans = solve(v, 6);
    cout << ans;

    return 0;
}