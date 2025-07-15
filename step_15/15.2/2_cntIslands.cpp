#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void spread(int m, int n, int i, int j, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            //mark all the visited cells so that they will be not be considered in 
            //any other island
            if (temp.first + 1 < m &&
                grid[temp.first + 1][temp.second] == '1') {
                grid[temp.first + 1][temp.second] = '2';
                q.push({temp.first + 1, temp.second});
            }
            if (temp.first - 1 >= 0 &&
                grid[temp.first - 1][temp.second] == '1') {
                grid[temp.first - 1][temp.second] = '2';
                q.push({temp.first - 1, temp.second});
            }
            if (temp.second + 1 < n &&
                grid[temp.first][temp.second + 1] == '1') {
                grid[temp.first][temp.second + 1] = '2';
                q.push({temp.first, temp.second + 1});
            }
            if (temp.second - 1 >= 0 &&
                grid[temp.first][temp.second - 1] == '1') {
                grid[temp.first][temp.second - 1] = '2';
                q.push({temp.first, temp.second - 1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size(); 
        /*traverse each cell and if it is '1', then try expanding from it in order
        to maximize the area of current island and mark all the visited cells*/
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    spread(m, n, i, j, grid);
                }
            }
        }
        /*basically we are counting the number of components in a graph*/
        return cnt;
    }
};