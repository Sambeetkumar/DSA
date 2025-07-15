#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //copy the wordlist to a set
        unordered_set<string> st(wordList.begin(),wordList.end());
        //queue to perform bfs
        queue<pair<string,int>> q;
        //push the beginWord with initial level as 1 
        q.push({beginWord,1});
        /*beginWord might be present in the wordlist, so erase it as it is visited*/
        st.erase(beginWord);

        while(!q.empty())
        {
            pair<string,int> front = q.front();
            q.pop();
            string word = front.first;
            int cnt = front.second;
            if(word==endWord) return cnt;
            /*chnage each letter of word and search for it in set, if found then, 
            that word word will lie in next level*/
            for(int i=0; i<word.size(); i++)
            {
                char temp = word[i];//to restore the oroginal char
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end()) {
                        q.push({word,cnt+1});
                        //erase the found word as it is visited
                        st.erase(word);
                    }
                }
                word[i]=temp;
            }
        }
        //after performing bfs if end word is not found return 0
        return 0;
    }
};