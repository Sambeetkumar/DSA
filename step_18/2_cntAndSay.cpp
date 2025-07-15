#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string RLE = "1";
        for(int i=2; i<=n; i++)
        {
            int cnt=1;
            string temp="";
            for(int j=0; j<RLE.size()-1; j++)
            {
                if(RLE[j]==RLE[j+1])
                {
                    cnt++;
                }
                else
                {
                    temp+=cnt+'0';
                    temp+=RLE[j];
                    cnt=1;
                }
            }
            temp+=cnt+'0';
            temp+=RLE[RLE.size()-1];
            RLE=temp;
        }
        return RLE;
    }
};