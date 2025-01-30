#include <bits/stdc++.h>
using namespace std;
void func(vector<vector<int>> &ans,vector<int> v,vector<int> arr,int sum,int index, int target)
    {
        if(index==arr.size() || sum>=target)
        {
            if(sum==target)
            {
                ans.push_back(v);
            }
            return;
        }
        //the number of times we can include arr[index]
        int temp = (target/arr[index])+1;
        //adding arr[index] to v each time and calling recursion
        for(int i=0; i<temp; i++)
        {
            func(ans,v,arr,sum,index+1,target);
            v.push_back(arr[index]);
            sum+=arr[index];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        func(ans,v,candidates,0,0,target);

        return ans;
    }
int main(int argc, char* argv[]) {

    vector<int> v = {2, 3, 6, 7};
    vector<vector<int>> ans = combinationSum(v, 7);
    for(auto it:ans)
    {
        for(auto it2:it)
        {
            cout << it2;
        }
        cout << endl;
    }
    return 0;
}