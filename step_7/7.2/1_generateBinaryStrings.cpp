#include <bits/stdc++.h>
using namespace std;
//desc - generate binary strings of length n without adjacent zeros
void generate(string s, char lastChar, int n, vector<string> &ans)
{
    // storing s in a temporary string
    string temp = s;
    // if s has reahced the given size store it and return(no need to expand further)
    if (n == s.size())
    {
        ans.push_back(s);
        return;
    }
    /*if last char is '0' then we can expand it by adding '1' at the end*/
    if (lastChar == '0')
    {
        temp += "1";
        generate(temp, '1', n, ans);
    }
    /*if last char is '1' then we can expand it by adding '0' or '1' at the end*/
    else
    {
        temp += "1";
        generate(temp, '1', n, ans);
        s += "0";
        generate(s, '0', n, ans);
    }
}
vector<string> validStrings(int n)
{
    vector<string> ans;
    // generating all possible strings starting with 1
    string s = "1";
    generate(s, '1', n, ans);
    // generating all possible strings starting with 0
    s = "0";
    generate(s, '0', n, ans);

    return ans;
}
int main(int argc, char *argv[])
{
    vector<string> ans = validStrings(3);
    for(auto it: ans)
    {
        cout << it << " ";
    }
    return 0;
}