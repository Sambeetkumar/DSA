#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++)
        {
            //if there is no prev asteroid or upcoming asteroid is positive
            //collision will never happen so push it onto the stack
            if(st.empty()) st.push(asteroids[i]);
            else if(asteroids[i]>0)
            st.push(asteroids[i]);
            else
            {
                // while prev asteroid is positive and upcoming asteroid is negative and bigger in size
                //collision wil happen
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i]))
                {
                    st.pop();
                }
                //if it destroys all prev asteroids or prev asteroid is negative
                if(st.empty() || st.top()<0 )
                st.push(asteroids[i]);
                //if both are of same size ans opposite sign both will get destroyed
                else if(st.top()==abs(asteroids[i]))
                {
                    st.pop();
                }
                            
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};