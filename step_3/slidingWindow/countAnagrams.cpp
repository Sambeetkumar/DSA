#include <bits/stdc++.h>
using namespace std;
int search(string pat, string txt)
{
    // code here
    unordered_map<char, int> map;
    int m = pat.size();
    int n = txt.size();
    //hashing all the chars of pat with its freq
    for (int i = 0; i < m; i++)
    {
        map[pat[i]]++;
    }
    int count = map.size();//keep track of number of unique chars present in map
    int res = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        if (map.find(txt[j]) != map.end())
        {
            /*serach char pointed by j in map, if found decrease its freq by 1*/
            map[txt[j]]--;
            /*if freq after decreasing becomes zero, decr count by 1 as no of unique chars
            left in map is decreased by one*/
            if(map[txt[j]]==0)
            {
               count--;
            }
        }
        if (j - i + 1 == m)
        {
            /*when we hit window size if count value is zero,then we have fully utilised all 
            chars that were in the map, so this is an anagram*/
            if (count==0)
            {
                res++;
            }
            
            /*before removing ith char we need to incr its freq if it is present in the map,
             as it increases the availability of that char by one*/
            if (map.find(txt[i]) != map.end())
            {
                /*and also if its freq is zero incr count by one as that unique char is
                available now*/
                if(map[txt[i]]==0)
                {
                   count++;
                }
                map[txt[i]]++;
            }
            i++;
        }
        j++;
    }
    return res;
}
int main(int argc, char *argv[])
{
    string pat = "aaba";
    string txt = "aabaabaa";
    cout << search(pat, txt);

    return 0;
}