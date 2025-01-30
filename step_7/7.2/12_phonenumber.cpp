#include <bits/stdc++.h>
using namespace std;
void func(vector<string> &ans, string digits, unordered_map<char, string> mp, string s, int ind)
{
    //if we reach at the end index of digits push s into ans
    if (ind == digits.size())
    {
        ans.push_back(s);
        return;
    }
    char temp = digits[ind];
    for (int i = 0; i < mp[temp].size(); i++)
    {
        s += mp[temp][i];
        func(ans, digits, mp, s, ind + 1);
        s.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> res;
    if (digits == "")
        return res;
    unordered_map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    string str = "";
    func(res, digits, mp, str, 0);
    return res;
}
int main(int argc, char *argv[])
{
    vector<string> ans = letterCombinations("235");
    for(auto it:ans)
    {
        cout << it << endl;
    }
    return 0;
}