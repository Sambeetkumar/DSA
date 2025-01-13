#include <bits/stdc++.h>
using namespace std;

//function to find nCr
int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr - IMPORTANT:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    /*in Pascal triangle elements for ith row goes like iC0,iC1,iC2..... ici*/
    for (int i = 0; i < numRows; i++)
    {
        vector<int> v;
        //for Loop to find all elements of ith row of the pascal triangle
        for (int j = 0; j <= i; j++)
        {
            int temp = nCr(i, j);
            v.push_back(temp);
        }
        //pushing the ith row
        res.push_back(v);
    }
    return res;
}
int main(int argc, char *argv[])
{
    vector<vector<int>> v = generate(5);
    for(auto it:v)
    {
        for(auto it:it)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}