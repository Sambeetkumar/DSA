#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s) {
        int cnt=0,ans=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                //keep track of maximum value cnt have ever reached
                cnt++;
                ans = max(ans,cnt);
            } 
            if(s[i]==')')
            {
                cnt--;
            }
        }
        return ans;
}
int main(int argc, char* argv[]) {
    string s = "()()()(()((())()))";
    cout << maxDepth(s);

    return 0;
}