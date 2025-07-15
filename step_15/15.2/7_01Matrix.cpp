#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
       this prblem is simillar to rotten oranges, consider all the 0's as rotten oranges
       push them all to queue and perform bfs, here we maintain a count variable
       to keep track of levels, when a 1 is encountered the nearest dist for it will
       be equal to cnt as we are starting bfs considering 0's as source
    */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        //to store the ans, it will be also used to keep track of visited nodes
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        //push all the zeros to queue and mark their dist as 0
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int cnt=1;
        while(!q.empty())
        {
            //count no of el in q before popping, because we will pop levelwise
            int s=q.size();
            for(int i=0; i<s; i++)
            {
                pair<int,int> front=q.front();
                q.pop();
                int cr = front.first;
                int cc = front.second;
                //we can only move to adj node only if its dist is not calculated
                if(cr+1<m && ans[cr+1][cc]==-1)//move down
                {
                    ans[cr+1][cc]=cnt;
                    q.push({cr+1,cc});
                }
                if(cr-1>=0 && ans[cr-1][cc]==-1)//move up
                {
                    ans[cr-1][cc]=cnt;
                    q.push({cr-1,cc});
                }
                if(cc+1<n && ans[cr][cc+1]==-1)//move right
                {
                    ans[cr][cc+1]=cnt;
                    q.push({cr,cc+1});
                }
                if(cc-1>=0 && ans[cr][cc-1]==-1)//move left
                {
                    ans[cr][cc-1]=cnt;
                    q.push({cr,cc-1});
                }
            }
            //increase the level
            cnt++;
        }
        return ans;
    }
};