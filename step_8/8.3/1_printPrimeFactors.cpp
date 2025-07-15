#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  //approach 1 - Time Complexity O(sqrt(n)*sqrt(n))
    // bool isPrime(int n){
    //     if(n==1) return false;
    //     for(int i=2; i<=sqrt(n); i++){
    //         if(n%i==0)
    //         return false;
    //     }
    //     return true;
    // }
    // vector<int> AllPrimeFactors(int N) {
    //     // Code here
    //     vector<int> ans;
    // loop till srt(n) as if i is a factor then n/i is also a factor
    //     for(int i=1; i<=sqrt(N); i++){
    //         if(N%i==0){
    //             if(isPrime(i)){
    //                 ans.push_back(i);
    //             }
    //             if((N/i!=i) && isPrime(N/i)){
    //                 ans.push_back(N/i);
    //             }
    //         }
    //     }
    //     return ans;
    // }
    //Optimal approach O(sqrt(n)*log(N))
    vector<int> AllPrimeFactors(int N) {
        // Code here
        vector<int> ans;
        /*we don't need to check for prime as we are reducing N by tha maximum number 
        contributed by i if i is a factor of N. for eg */
        for(int i=2; i<=sqrt(N); i++){
            if(N%i==0){
                ans.push_back(i);
                while(N%i==0){
                    N= N/i;
                }
            }
        }
        if(N!=1) ans.push_back(N);
        return ans;
    }
};