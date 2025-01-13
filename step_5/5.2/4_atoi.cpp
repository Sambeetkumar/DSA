#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s){
        //storing digits 0 to 9 in a set
        unordered_set<int> digits;
        for(int j=0;j<10; j++)
        {
            digits.insert(j);
        }
        //skipping the initial white spaces
        int n = s.size();
        int i=0;
        while(i<n && s[i]==' ')
        i++;
        //if after skipping white spaces i points to n, then return 0
        if(i==n) return 0; 

        //checking the sign of answer
        bool isPositive=true;
        if(s[i]=='-')
        {
            isPositive=false;
            i++;
        }
        if(s[i]=='+'&& isPositive) i++;

        /*converting to integer by using the formula num = num*10+digit */
        long long num=0;
        while(i<n)
        {
           if(digits.find(s[i]-'0')!=digits.end())
           {
             num=num*10+(s[i]-'0');
             //always check the range of num
             if(num>INT_MAX)
             {
                if(isPositive) return INT_MAX;
                return INT_MIN;
             }
           }
           //if we encounter any non-digit character then our loop ends here
           else
           {
             break;
           }
           i++;
        }
        //return num according to sign
        if(isPositive)
        return num;
        else
        return -num;
    }
int main(int argc, char* argv[]) {

    string s = "   -3456cd76";
    cout << myAtoi(s);
    return 0;
}