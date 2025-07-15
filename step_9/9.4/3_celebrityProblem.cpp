#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  //time - O(2*n) , space O(1)
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        //we will try eliminating nodes that can't be celebrity
        int top = 0, down = n-1;
        while(top<down){
            if(mat[top][down]==1){
                //top knows down, top can't be celebrity
                top++;
            }
            else if(mat[down][top]==1){
                //down knows top, down can't be celebrity
                down--;
            }
            else{
                //both can't be celebrity
                top++;
                down--;
            }
        }
        if(top>down) return -1;
        //now we will verify top/down is celebrity or not
        for(int i=0; i<n; i++){
            //topth row should all 0 and topth col shpuld all 1
            if(i==top) continue;
            if(mat[top][i]!=0 || mat[i][top]!=1){
                return -1;
            }
        }
        return top;
    }
};
//time - O(n^2), space - (1)
// class Solution {
//   public:
//     int celebrity(vector<vector<int> >& mat) {
//         // code here
//         /*if we notice the pattern for celebrity node there will be incoming edges from 
//         every other node that and no outgoing edges from that node. that means if ith
//         node is celebrity the ith col will contain all one and the ith row will contain
//         all 0 except to itself*/
//         int n = mat.size();
//         for(int i=0; i<n; i++)
//         {
//             bool flag1 = true,flag2=true;
//             //traverse col wise
//             for(int j=0; j<n; j++){
//                 if(i==j) continue;
//                 if(mat[j][i]!=1){
//                     flag1=false;
//                     break;
//                 }
//             }
//             if(flag1){
//                 //traverse row wise
//                 for(int j=0; j<n; j++){
//                     if(i==j) continue;
//                     if(mat[i][j]!=0){
//                         flag2=false;
//                         break;
//                     }
//                 }
//             }
//             if(flag1 && flag2){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

//time - O(n^2) , space - O(n)
// class Solution {
//   public:
//     int celebrity(vector<vector<int> >& mat) {
//         // code here
//         int n = mat.size();
//         //node --> {indegree,outdegree}
//         unordered_map<int,pair<int,int>> deg;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(i==j) continue;
//                 if(mat[i][j]==1){
//                     deg[j].first++;
//                     deg[i].second++;
//                 }
//             }
//         }
//         for(int i=0; i<n; i++){
//             if(deg[i].first==n-1 && deg[i].second==0){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };