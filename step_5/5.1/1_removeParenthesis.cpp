#include <iostream>
using namespace std;
string removeOuterParentheses(string s) {
        string ans;
        int cnt=0;
        for(int i=0; i<s.size(); i++)
        {
            /*increase count if opening bracket occurs as number of closing bracket required
            to make it a valid string increases*/
            if(s[i]=='(')
            cnt++;
            else 
            cnt--;
            /*if cnt is not zero, then we are inside a valid string,push it except where cnt
            is 1 and i points to opening bracket as it is starting of valid string*/
            if(cnt!=0 && !(cnt==1 && s[i]=='('))
            ans.push_back(s[i]);
        }
        return ans;
    }
int main(int argc, char* argv[]) {
    string s = "(()(()))((()))";

    for(auto it:removeOuterParentheses(s))
    {
        cout << it << " ";
    }
    return 0;
}