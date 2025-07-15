#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findEl(int start,int end,vector<int>&v, int el){
        int s=start,e=end;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(v[mid]==el){
                return mid;
            }
            else if(v[mid]<el){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        vector<int> aux(n);
        for(int i=0; i<n; i++) aux[i]=arr[i];
        
        sort(aux.begin(),aux.end());
        
        for(int i=0; i<n; i++){
            int findInd=findEl(0,n-1,aux,arr[i]);
            if(abs(findInd-i)>k){
                return "No";
            }
        }
        
        return "Yes";
    }
};