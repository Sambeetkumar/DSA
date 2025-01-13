#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        //insert all elements to a set to avoid repeatations
        s.insert(nums[i]);
    }
    
    int cnt = 1;
    int maxCnt = INT_MIN;
    int n = s.size();
    auto it = s.begin();
    auto end = std::prev(s.end());

    while (it != end) {
        /*as the set is ordered, where the next el is one more than current, increase cnt*/
        if(*it+1 == *(++it))
            cnt++;
        else//otherwise set back to 1 as we will again start counting
            cnt = 1;

        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}
int main(int argc, char *argv[])
{
    vector<int> v = {100,4,200,1,3,2};
    
    cout<< longestConsecutive(v);
    return 0;
}