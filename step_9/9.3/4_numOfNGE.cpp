#include <bits/stdc++.h>
using namespace std;

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
    //write your code here
   int cnt;
   int size = arr.size();
   vector<int> ans(queries,0);
   for(int i=0; i<queries; i++)
   {
       cnt=0;
       for(int j=indices[i]; j<size; j++)
       {
           if(arr[indices[i]]<arr[j])
           cnt++;
       }
       ans[i]=cnt;
   }
   return ans;
}