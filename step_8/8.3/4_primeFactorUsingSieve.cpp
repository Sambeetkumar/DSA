#include <bits/stdc++.h>
using namespace std;
vector<int> countPrimes(int n)
{
    // Write your code here.
    vector<int> prime(n+1,1);
    for(int i=2; i*i<=n; i++){
        if(prime[i]){
            long long j = (long long)i*i;
            while(j<=n){
                prime[j]=0;
                j+=i;
            }
        }
    }
    vector<int> ans;
    for(int i=2; i<=n; i++){
        if(n%i==0 && prime[i]){
            ans.push_back(i);
        }
    }
    return ans;
}