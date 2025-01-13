#include <bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int A[], int N, int K)
{
    // Complete the function
    unordered_map<long long,int> m;
    long long sum = 0;
    long long rem = 0;
    int maxLen = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if(sum==K)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum-K;
        if(m.find(rem)!=m.end())
        {
            int len = i - m[rem];
            maxLen = max(len, maxLen);
        }
        if(m.find(sum)==m.end())
        m[sum] = i;
    }
    return maxLen;
}
int main(int argc, char *argv[])
{
    int v[] = {-1,2,3,0,0,0,3,-2};
    cout<<lenOfLongSubarr(v,8,1);
    return 0;
}