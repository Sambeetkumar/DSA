#include <bits/stdc++.h>
using namespace std;
void func(vector<vector<int>> &ans,vector<int> v, int ind, int n, int k)
    {
        /*if we have reached the limit of how many digits can we use*/
        if(k==0)
        {
            if(n==0)
            {
                ans.push_back(v);
            }
            return;
        }
        //if at any point digits used exceed 9 return
        if(ind>9) return;
        //not including ind, so neither n nor k changes
        func(ans,v,ind+1,n,k);
        //including ind, value of n decreases and also decrease k by 1
        v.push_back(ind);
        func(ans,v,ind+1,n-ind,k-1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        func(ans,v,1,n,k);
        return ans;
    }
int main(int argc, char* argv[]) {
    vector<vector<int>> ans = combinationSum3(3, 9);
    for(auto it:ans)
    {
        for(auto it2:it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}