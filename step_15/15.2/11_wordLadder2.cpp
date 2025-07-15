#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<string>> ans;
public:
    bool isPossible(string str1, string str2) {
        int cnt = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i])
                cnt++;
        }
        if (cnt <= 1)
            return true;
        return false;
    }
    void func(string src,unordered_map<string, vector<string>> &adjList,unordered_map<string,bool> &visited,vector<string> &temp,string &endWord)
    {
        if(src==endWord)
        {
            while(!ans.empty() && ans.back().size()>temp.size())
            {
                ans.pop_back();
            }
            if(ans.empty() || ans.back().size()==temp.size())
            ans.push_back(temp);
            return;
        }
        for(auto it:adjList[src])
        {
            if(!visited[it])
            {
                temp.push_back(it);
                visited[it]=true;
                func(it,adjList,visited,temp,endWord);
                visited[it]=false;
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       bool isBegFound = false;
        bool isEndFound = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                isEndFound = true;
            }
            if (wordList[i] == beginWord) {
                isBegFound = true;
            }
        }
        if (!isEndFound)
            return ans;
        if (!isBegFound)
            wordList.push_back(beginWord);
        unordered_map<string, vector<string>> adjList; // adjacency list
        unordered_map<string,bool> visited;
        // creating adjList
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (isPossible(wordList[i], wordList[j])) {
                    adjList[wordList[i]].push_back(wordList[j]);
                    adjList[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        vector<string> temp;
        temp.push_back(beginWord);
        visited[beginWord]=true;
        func(beginWord,adjList,visited,temp,endWord);

        return ans;

    }
};