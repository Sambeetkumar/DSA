#include <bits/stdc++.h>
using namespace std;
//this solution gives tle as it uses recursion (optimal - DP)
void generate(unordered_set<string> &st, int ind, string seq, string s)
{
    if (ind == s.size())
    {
        //ignoring subsequences of length 0
        if (seq.size() != 0)
            st.insert(seq);

        return;
    }
    // not including char at index ind
    generate(st, ind + 1, seq, s);
    // including char at index ind
    seq.push_back(s[ind]);
    generate(st, ind + 1, seq, s);
}
string betterString(string str1, string str2)
{
    // code here
    unordered_set<string> st1;
    unordered_set<string> st2;
    string s = "";
    generate(st1, 0, s, str1);
    generate(st2, 0, s, str2);
    if (st1.size() >= st2.size())
        return str1;
    else
        return str2;
}
int main(int argc, char *argv[])
{
    string s = betterString("saeee", "seijal");
    cout << s;
    return 0;
}