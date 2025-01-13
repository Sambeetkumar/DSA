#include <bits/stdc++.h>
using namespace std;
//EXTENDED VERSION of Moore's voting algorithm(where we keep track of only one value)
vector<int> majorityElement(vector<int> &nums)
{
    vector<int> res;
    int n = nums.size();
    /*as we are finding elements that occur more than n/3 times, there can be atmost 2
    elements.so we will keep track of two elements and maintain their respective count*/
    int cnt1 = 0, cnt2 = 0;
    int el1=INT_MIN, el2=INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && nums[i] != el2)//initializing element 1
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != el1)//initializing element 2
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1)//increasing vote for el1
        {
            cnt1++;
        }
        else if (nums[i] == el2)//increasing vote for el2
        {
            cnt2++;
        }
        else//decreasing votes for el1 & el2
        {
            cnt1--;
            cnt2--;
        }
    }
    //now checking the freq of element1 and element2 manually
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (el1 == nums[i])
            cnt1++;
        if (el2 == nums[i])
            cnt2++;
    }
    if (cnt1 > (int)n / 3)
        res.push_back(el1);
    if (cnt2 > (int)n / 3)
        res.push_back(el2);

    return res;
}
int main(int argc, char *argv[])
{
    vector<int> v = {0, 0, 0};
    vector<int> res = majorityElement(v);
    for(auto it:res)
    {
        cout << it << " ";
    }

    return 0;
}