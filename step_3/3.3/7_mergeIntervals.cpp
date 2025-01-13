#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int n = intervals.size();
       if(n==1) return intervals;
       vector<vector<int>> res;
       int i=0,j=1;
       sort(intervals.begin(),intervals.end());
       //initializing the range to first el of intervals
       int el1=intervals[0][0];
       int el2=intervals[0][1];
       while(j<n)
       {
        /*if j->interval expands or contained in the existing, 
        update the maximum range of existing interval*/
        if((intervals[j][0]>=el1)&&(intervals[j][0]<=el2))
        {
            //updating max rng
            el2=max(el2,intervals[j][1]);
            j++;
        }
        //store the exisitng interval and start fresh from interval pointed by j
        else
        {
            res.push_back({el1,el2});
            i=j;
            j=j+1;
            el1=intervals[i][0];
            el2=intervals[i][1];
        }
       }
       res.push_back({el1,el2});
       return res; 
    }
int main(int argc, char* argv[]) {
    vector<vector<int>> v = {{4, 5}, {6, 6}, {3, 5}, {5, 9}, {10, 12}};
    vector<vector<int>> res = merge(v);
    for(auto it:res)
    {
        for(auto it2:it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    return 0;
}