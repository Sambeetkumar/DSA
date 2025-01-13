#include<bits/stdc++.h>

using namespace std;
int maxLen(vector<int>& arr) {
        // code here
        unordered_map<int,int> m;
        int sum=0;
        int len=0;
        int maxLength = 0;
        for(int i=0; i<arr.size(); i++)
        {
            sum += arr[i];
            if(sum==0)//if sum ==0 update maxLength as sub arr is from index 0 to i
            {
                maxLength = i+1;
            }
            if(m.find(sum)!=m.end())
            {
                /*if we find the same sum value before then summation of elements in between will be zero,
                calculate the length and update maxlength accordingly*/
                len = i-m[sum];
                maxLength = max(len,maxLength);
            }
            if(m.find(sum)==m.end())//hashing sum value to index
            m[sum]=i;
        }
        return maxLength;
}

int main()
{
    vector<int> v = {15, -2, 2, -8, 1, 7, 10, 23};
    int ans = maxLen(v);
    cout << ans << endl;
}