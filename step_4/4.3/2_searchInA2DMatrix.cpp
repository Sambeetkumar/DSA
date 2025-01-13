#include <bits/stdc++.h>
using namespace std;
//using bs find the row in which target lies
int targetRow(vector<vector<int>>& matrix, int target)
{
    int s = 0, e = matrix.size();
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        int n = matrix[mid].size()-1;
        if(target>=matrix[mid][0] && target<=matrix[mid][n])
        {
            return mid;
        }
        else if(target<matrix[mid][0])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
//using bs check whether the target lies in the target row or not
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = targetRow(matrix, target);
    if(row==-1)
        return false;
    int n = matrix[row].size() - 1;
    int s = 0, e = matrix[row][n];
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        if(matrix[row][mid]==target)
        {
            return true;
        }
        else if(matrix[row][mid]>target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return false;
}
int main(int argc, char* argv[]) {
  
  
  return 0;
}