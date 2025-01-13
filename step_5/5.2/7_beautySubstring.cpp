#include <bits/stdc++.h>
using namespace std;
int beautySum(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        vector<int> freq('z' + 1, 0);//track the freq of elments between i and j
        for (int j = i; j < s.size(); j++)
        {
            freq[(int)s[j]]++;//update freq as j moves
            int mini = INT_MAX;
            int maxi = INT_MIN;
            //for each movement of j calc min and max freq, find their diff and add to sum
            for (int j = 0; j < freq.size(); j++)
            {
                if (freq[j] == 0)
                    continue;
                mini = min(mini, freq[j]);
                maxi = max(maxi, freq[j]);
            }
            sum += (maxi - mini);
        }
    }
    return sum;
}
int main(int argc, char *argv[])
{
    string s = "abbcaade";
    cout << beautySum(s);
    return 0;
}