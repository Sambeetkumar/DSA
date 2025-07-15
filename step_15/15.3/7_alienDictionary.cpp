#include <bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<char,vector<char>> adjList;
    unordered_map<char,int> inDeg;
  public:
    bool makeList(string &str1,string &str2)
    {
        //compare both the words char by char,when the differ update th adjList
        //"abc"-"adj", then b should come before d, so there is a edge b--->d
        int i=0,j=0;
        while(i<str1.size() && j<str2.size()) {
            if(str1[i]!=str2[j])
            break;
            i++;
            j++;
        }
        if(i<str1.size() && j<str2.size()) {
          adjList[str1[i]].push_back(str2[j]);
          inDeg[str2[j]]++;
        }
        //if cases occur like "abcd" - "abc", then ordering is not possible because
        //"abc" is supposed to appear before "abcd"
        if(i<str1.size() && j>=str2.size())
        return true;
        else
        return false;
    }
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        vector<int> alpha(26,0);
        for(int i=0; i<n-1; i++) {
           //compare every two adj words in the list
           bool check = makeList(words[i],words[i+1]);
           //if ordering not possible immediately return false
           if(check)
           return "";
        }
        //mark all the chars that are used to create dictionary
        for(int i=0; i<n; i++) {
            for(auto ch:words[i]) {
                alpha[ch-'a']=1;
            }
        }
        queue<char> q;
        int totChars=0;
        for(int i=0; i<26; i++) {
            if(alpha[i]==1) {
                totChars++;
                if(inDeg[char(i+'a')]==0)//if a char is present and its indegree is 0,push it to queue
                q.push(char(i+'a'));
            }
        }
        string res;
        while(!q.empty()) {
            char front = q.front();
            q.pop();
            //reduce all the adj nodes indegree by 1 and if indegree becomes 0, push the nbr node to queue
            for(char ch:adjList[front]) {
                inDeg[ch]--;
                if(inDeg[ch]==0) {
                    q.push(ch);
                }
            }
            res.push_back(front);
        }
        //if the topo ordering contains all used chars, then only ordering is possible
        return res.size()==totChars?res:"";
        
    }
};