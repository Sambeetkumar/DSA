#include <bits/stdc++.h>
using namespace std;
//function that returns longest palindromic sub string of odd length
string oddLength(string s)
{
    int n = s.size();
    string longestOdd = "";
    /*consider ptr i points to the center of palindrome and expand in both sides*/
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        /*expand untill we reach either one end of the string or condition for palindrome
        fails*/
        while (i - cnt >= 0 && i + cnt < n && s[i - cnt] == s[i + cnt])
        {
            if (longestOdd.size() < (2 * cnt + 1))
                longestOdd = s.substr(i - cnt, 2 * cnt + 1);

            cnt++;
        }
        /*when while loop breaks we got the max length substr which is palindrome with center
        pointed by i, now check the same by moving i ahead*/
    }
    return longestOdd;
}
//function that returns longest palindromic sub string of even length
string evenLength(string s)
{
    int n = s.size();
    string longestEven = "";
    /*consider ptr i points to the start of palindrome,ptr j points
    to the end and expand in both sides*/
    for (int i = 0, j = 1; j < n; i++, j++)
    {
        int cnt = 0;
        /*expand untill we reach either one end of the string or condition for palindrome
        fails*/
        while (i - cnt >= 0 && j + cnt < n && s[i - cnt] == s[j + cnt])
        {
            if (longestEven.size() < (j - i + (2 * cnt) + 1))
                longestEven = s.substr(i - cnt, j - i + (2 * cnt) + 1);

            cnt++;
        }
    }
    return longestEven;
}
string longestPalindrome(string s)
{
    string ans = oddLength(s).size() < evenLength(s).size() ? evenLength(s) : oddLength(s);
    return ans;
}
int main(int argc, char *argv[])
{
    cout << longestPalindrome("ababac");
    return 0;
}