#include <bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans=-1;
        int maxNoOfOnes=-1;
        //traversing the each row of the matrix
        for(int i=0; i<arr.size(); i++)
        {
            /*performing bs on indivisual row to find no of ones as each row is
            sorted in non decreasing order*/
            int s=0,e=arr[i].size()-1;
            while(s<=e)
            {
                int mid = s+(e-s)/2;
                if(arr[i][mid]==1)
                {
                    e=mid-1;
                }
                else
                {
                    s=mid+1;
                }
            }
            /*at the end of bs ptr s points the index of first occurence of 1, if no one
            is present then s points to the end+1 of the row, so x stores no of ones in a row*/
            int x=arr[i].size()-s;
           
            if(x!=0 && x>maxNoOfOnes)
            {
                maxNoOfOnes=(arr[i].size()-s);
                ans=i;
            }
        }
        return ans;
}
int main(int argc, char* argv[]) {
    vector<vector<int>> v = {{0, 0, 1, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    cout << rowWithMax1s(v);
    return 0;
}