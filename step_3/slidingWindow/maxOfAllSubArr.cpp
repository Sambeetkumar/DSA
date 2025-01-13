#include <bits/stdc++.h>
using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B) {
    deque<int> q;
    vector<int> res;
    int n = A.size();
    //if window size is more than array size then return the max el of the array
    if(B>n)
    {
    res.push_back(*max_element(A.begin(), A.end()));
    return res;
    }
    int i=0,j=0;
    while(j<n)
    {
        /*pop elements from the end of the queue that are smaller than A[j] as they will be
        of no use in finding maximum element*/
        while( !q.empty() && A[q.back()]<A[j] )
        {
            q.pop_back();
        }
        //then push the index j to the queue
        q.push_back(j);
        if(j-i+1==B)
        {
            /*when we hit window size the maximum el will be at the front of the queue*/
            res.push_back(A[q.front()]);

            //before removing i check if el pointed by i is the max el or not
            if(q.front()==i)
            {
                q.pop_front();
            }
            i++;
        }
        j++;
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<int> v = {1, 5, 3, 4, 7, -2, 0, -4};
    vector<int> res = slidingMaximum(v, 4);

    for(auto it:res)
    {
        cout << it << " ";
    }

    return 0;
}