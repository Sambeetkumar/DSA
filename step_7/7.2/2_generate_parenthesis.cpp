#include <bits/stdc++.h>
using namespace std;
void generate(int n, int open, int close, string s, vector<string> &ans)
{
    string temp = s;
    // when we have reached our limit add the fulfilling closing parenthesis and return
    if (open == n)
    {
        while (close < n)
        {
            s += ")";
            close++;
        }
        ans.push_back(s);
        return;
    }
    /*first option to expand is to add a new opening parenthesis and increase
    the opening parenthesis count by 1*/
    s += "(";
    generate(n, open + 1, close, s, ans);
    /*we can only expand by adding a closing parenthesis when there are enough opening
    parenthesis to match them*/
    if (open > close)
    {
        temp += ")";
        generate(n, open, close + 1, temp, ans);
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    // starting with a opening parenthesis
    string start = "(";
    generate(n, 1, 0, start, ans);
    return ans;
}
int main(int argc, char *argv[])
{
    vector<string> ans = generateParenthesis(5);
    for(string it:ans)
    {
        cout << it << " ";
    }

    return 0;
}