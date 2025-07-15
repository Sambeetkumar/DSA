#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;//if no change is req
        int m = image.size();
        int n = image[0].size();
        int orgClr = image[sr][sc];//store the original color
        /*consider image[sr][sc] as source and perform bfs, mark the visited nodes
        color as new color,during bfs we can only move to a node having orgClr*/
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            //mark all the visited cells so that they will be not be considered in 
            //any other island
            if (temp.first + 1 < m &&
                image[temp.first + 1][temp.second] == orgClr) {
                image[temp.first + 1][temp.second] = color;
                q.push({temp.first + 1, temp.second});
            }
            if (temp.first - 1 >= 0 &&
                image[temp.first - 1][temp.second] == orgClr) {
                image[temp.first - 1][temp.second] = color;
                q.push({temp.first - 1, temp.second});
            }
            if (temp.second + 1 < n &&
                image[temp.first][temp.second + 1] == orgClr) {
                image[temp.first][temp.second + 1] = color;
                q.push({temp.first, temp.second + 1});
            }
            if (temp.second - 1 >= 0 &&
                image[temp.first][temp.second - 1] == orgClr) {
                image[temp.first][temp.second - 1] = color;
                q.push({temp.first, temp.second - 1});
            }
        }
        return image;
    }
};