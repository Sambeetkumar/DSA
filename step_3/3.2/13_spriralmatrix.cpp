#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();
    int imin = 1;
    int imax = m - 1;
    int jmin = 0;
    int jmax = n - 1;
    int count = m * n-1;
    int i = 0, j = 0;
    bool row = false;
    bool inc = true;
    res.push_back(matrix[i][j]);
    while(count--)
    {
        if(row)
        {
            if(inc)
            {
                i++;
                if(i<=imax)
                {
                    res.push_back(matrix[i][j]);
                }
                else
                {
                    i = imax;
                    imax -= 1;
                    row = false;
                    inc = false;
                    count++;
                }
            }
            else
            {
                i--;
                if(i>=imin)
                {
                    res.push_back(matrix[i][j]);
                }
                else
                {
                    i = imin;
                    imin += 1;
                    row = false;
                    inc = true;
                    count++;
                }
            }
        }
        else
        {
            if(inc)
            {
                j++;
                if(j<=jmax)
                {
                    res.push_back(matrix[i][j]);
                }
                else
                {
                    j = jmax;
                    jmax -= 1;
                    row = true;
                    count++;
                }
            }
            else
            {
                j--;
                if(j>=jmin)
                {
                    res.push_back(matrix[i][j]);
                }
                else
                {
                    j = jmin;
                    jmin += 1;
                    row = true;
                    count++;
                }
            }

        }
    }
    return res;
    }
int main(int argc, char *argv[])
{
    vector<vector<int>> v = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
        
        };
    vector<int> v2 = spiralOrder(v);
    for (auto it:v2)
    {
        cout << it << " ";
    }

    return 0;
}