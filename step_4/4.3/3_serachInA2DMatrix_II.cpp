#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        /*start searching from the left bottom corner of the matrix as from that corner
        elements in the col are decreasing and el in row are increasing, so we can eliminate
        either one row or one col.... you can also start from top right corner*/
        int row=n-1;
        int col =0;
        while(row>=0 && col<m)//loop until we reach the opposite corner diagonally
        {
            //if we land on target return true
            if(matrix[row][col]==target)
            return true;
            //if target is smaller, eliminate the current row as all el in curr row are in increasing order
            else if(matrix[row][col]>target)
            {
                row--;
            }
            //if target is smaller, eliminate the curr col as all el in curr row are in decreasing order
            else
            {
                col++;
            }
        }
        return false;
    }
int main(int argc, char* argv[]) {
    vector<vector<int>> v = {{1, 4, 7, 11}, {2, 5, 8, 12}, {3, 6, 9, 16}, {10, 13, 14, 17}};
    cout << searchMatrix(v,11);
    return 0;
}