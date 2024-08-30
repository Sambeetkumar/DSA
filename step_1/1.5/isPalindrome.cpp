#include <iostream>
#include <algorithm>
using namespace std;

string truncate(string s)
{
    string str;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalnum(s[i]))
        {
            str.push_back((char)tolower(s[i]));
        }
    }
    return str;
}

bool isPalindrome(string s)
{
    string str = truncate(s);
    string str2 = str;
    reverse(str.begin(), str.end());
    if (str2 == str)
        return true;
    else
        return false;
}
int main(int argc, char *argv[])
{
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);
    return 0;
}