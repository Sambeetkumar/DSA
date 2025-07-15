#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> forward(n,n-1);
        vector<int> backward(n,0);
        stack<int> st1;
        stack<int> st2;
        int maxi = INT_MIN;
        //tracking the maximum distance we can go in forward for heights[i]
        for(int i=0; i<n; i++)
        {
            while(!st1.empty() && heights[st1.top()]>heights[i])
            {
                forward[st1.top()]=i-1;
                st1.pop();
            }
            st1.push(i);
        }
        //tracking the maximum distance we can go in backward for heights[i]
        for(int i=n-1; i>=0; i--)
        {
            while(!st2.empty() && heights[st2.top()]>heights[i])
            {
                backward[st2.top()]=i+1;
                st2.pop();
            }
            st2.push(i);
        }
        //calculating the area for each heights[i]
        for(int i=0; i<n; i++)
        {
            int temp = (forward[i]-backward[i]+1)*heights[i];
            maxi = max(temp,maxi);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> histogram(n,0);
        int maxi = 0;
        /*we will apply the maximum rectangle in histogram logic, but considering each row
        as the base of the histogram*/
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]=='0')
                histogram[j]=0;
                else
                {
                    histogram[j]++;
                }
            }
            //for each row after updating the hustogram, calc the maximum area of rectangle in histogram
            int temp = largestRectangleArea(histogram);
            maxi = max(maxi,temp);
        }
        return maxi;
    }
};