#include <iostream>
using namespace std;
int romanToInt(string s)
{
    int n = s.size();
    int ans=0;
    for (int i = 0; i < n; i++)
    {

        switch (s[i])
        {
        case 'I':
        {
            if (i != n - 1 && s[i + 1] == 'V')
            {
                ans += 4;
                i++;
            }
            else if (i != n - 1 && s[i + 1] == 'X')
            {
                ans += 9;
                i++;
            }
            else
            {
                ans += 1;
            }
            break;
        }
        case 'V':
        {
            ans += 5;
            break;
        }
        case 'X':
        {
            if (i != n - 1 && s[i + 1] == 'L')
            {
                ans += 40;
                i++;
            }
            else if (i != n - 1 && s[i + 1] == 'C')
            {
                ans += 90;
                i++;
            }
            else
            {
                ans += 10;
            }
            break;
        }
        case 'L':
        {
            ans += 50;
            break;
        }
        case 'C':
        {
            if (i != n - 1 && s[i + 1] == 'D')
            {
                ans += 400;
                i++;
            }
            else if (i != n - 1 && s[i + 1] == 'M')
            {
                ans += 900;
                i++;
            }
            else
            {
                ans += 100;
            }
            break;
        }
        case 'D':
        {
            ans += 500;
            break;
        }
        case 'M':
        {
            ans += 1000;
            break;
        }
        }
    }
    return ans;
}
    int main(int argc, char *argv[])
    {
        string ans = "MCMXCIV";
        cout << romanToInt(ans);

        return 0;
    }