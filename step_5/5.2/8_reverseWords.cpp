#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    /*i ptr iterates through the whole string, ptr l points to the start of a word and 
    ptr r points to end+1 of a word*/
    int i = 0, l = 0, r = 0;
    int n = s.size();
    reverse(s.begin(), s.end());//reverse the whole string initially
    while (i < n)
    {
        /*move ahead untill a space is enountered and move ptr r too by asigning s[i] to s[r]*/
        while (i < n && s[i] != ' ')
        {
            s[r] = s[i];
            i++;
            r++;
        }
        /*when a space is enocuntered, reverse the word between ptr l and r, then add a space
        after the word,increase r by one and also move l to r*/
        if (l < r)
        {
            /*the condition l<r prevents adding multiple spaces, when a seq of spaces
            are encountered by ptr i*/
            reverse(s.begin() + l, s.begin() + r);
            s[r] = ' ';
            r++;
            l = r;
        }
        i++;
    }
    //return sub string from 0th index to r-1 length as after r-1 length all are spaces
    return s.substr(0, r - 1);
}
int main(int argc, char *argv[])
{
    string s = "   my name   is sambeet";
    cout << reverseWords(s);

    return 0;
}