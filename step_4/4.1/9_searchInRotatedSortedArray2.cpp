#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    int s=0, e=A.size()-1;
    while(s<=e)
    {
        int mid= (s+e)/2;

        //if mid lands on the target return true
        if(A[mid]==key)
        {
            return true;
        }

        /*if mid, start and end are equal, as neither are equal to the target reduce the search space
        increasing start by 1 and decreasing end by 1*/

        else if(A[s]==A[mid] && A[mid]==A[e])
        {
            s = s + 1;
            e = e - 1;
        }

        //if the left half is sorted
        else if(A[s]<=A[mid])
        {
            //key lies in the left half
            if(key>=A[s] && key <= A[mid])
            e=mid-1; //eliminate the right half

            else
            s=mid+1; //eliminate the left half
        }
        else
        {
            //key lies in the right half
            if(key>=A[mid] && key <= A[e])
            s=mid+1; //eliminate the left half

            else
            e=mid-1; //eliminate the right half
        }
    
    }
    return false;
}
int main(int argc, char* argv[]) {
    vector<int> v = {1,0,1,1,1};
    cout << searchInARotatedSortedArrayII(v, 3);
    return 0;
}