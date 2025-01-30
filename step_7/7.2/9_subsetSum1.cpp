#include <bits/stdc++.h>
using namespace std;
void func(vector<int> &ans, int sum, int ind, vector<int> arr)
{
    if (ind == arr.size())
    {
        ans.push_back(sum);
        return;
    }
    // generating subsets excluding arr[ind]
    func(ans, sum, ind + 1, arr);
    // generating subsets including arr[ind]
    sum += arr[ind];
    func(ans, sum, ind + 1, arr);
}
vector<int> subsetSums(vector<int> &arr)
{
    // code here
    vector<int> sum;
    func(sum, 0, 0, arr);
    return sum;
}
int main(int argc, char *argv[])
{
    vector<int> v = {1, 2, 3};
    vector<int> ans = subsetSums(v);
    for(auto it:ans)
    {
        cout << it << " ";
    }
    return 0;
}