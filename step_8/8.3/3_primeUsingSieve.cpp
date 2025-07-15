#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n,1);//initially mark all as prime
        int cnt=0;
        for(int i=2; i*i<n; i++){
            if(prime[i]==1){
                //mark all multiple of i as false
                //start j from i*i as all multiples of j less than i*i are already marked by previous primes
                long long j=(long long)i*i;
                while(j<n){
                    prime[j]=0;
                    j+=i;
                }
            }
        }
        for(int i=2; i<n; i++){
            if(prime[i]){
                cnt++;
            }
        }
        return cnt;
    }
};