#include <bits/stdc++.h>
using namespace std;
 void rotate(vector<vector<int>>& matrix) {
        //finding transpose
        int m=matrix.size();
        for(int i=0; i<m; i++)
        {
            for(int j=i+1; j<m;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //swapping columns
        int temp = (m - 1) / 2;
        for(int i=0; i<m; i++)
        {
            for (int j = 0; j < temp; j++)
            {
                swap(matrix[i][j], matrix[i][m - j-1]);
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
int main(int argc, char* argv[]) {
    vector<vector<int>> v = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
    rotate(v);
    return 0;
}