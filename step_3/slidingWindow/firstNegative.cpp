#include <bits/stdc++.h>
using namespace std;
vector<int> firstNeg(vector<int> v,int k)
{
    int i = 0,j=0;
    int n = v.size();
    vector<int> res;
    /*queue q contains index of negative numbers in order which are present
     inside current window*/
    queue<int> q;
    while(j<n)
    {
        //if el pointed by j is -ve the push j to the queue
        if(v[j]<0)
            q.push(j);
        
        if(j-i+1==k)
        {
            if(q.empty())
            {   //if all el are +ve in the curr window,then q must be empty
                res.push_back(0);
            }   
            else
            {
                /*if not empty then index of first -ve number inside the window,must
                be at the front of the queue as they are in order*/
                res.push_back(v[q.front()]);
            }
            
            /*before removing i from window, if it points to a -ve el then i must at the
            front of the queue, pop an el from q, then increase i*/
            if(v[i]<0)
                q.pop();
            i++;
        }
        j++;
    }
    return res;
}
int main(int argc, char* argv[]) {
    vector<int> v = {12, -1, -7, 8, -15, 30, 18, 28};
    vector<int> ans = firstNeg(v, 3);
    for(auto it:ans)
    {
        cout << it << " ";

    }
    return 0;
}