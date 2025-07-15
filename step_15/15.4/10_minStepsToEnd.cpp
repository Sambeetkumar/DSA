#include <bits/stdc++.h>
using namespace std;
int minimumOperations(int n, int start, int end, vector<int> &a)
{
    // edge case
    if(start==end) return 0;
    /*the intuition is to consider nodes can range from 0 to 999.
    and the no of operations to reach any node will be its distance. start will
    be the source*/
    /*we are taking queue instead of pq here because our priority is no of steps
    and they are increasing by 1, so q will work fine*/
    //node-steps
    queue<pair<int,int>> q;
    int modu = 1000;
    vector<int> dist(modu,INT_MAX);
    //initially push start with 0 operations to queue and mark its dist as 0
    q.push({start,0});
    dist[start]=0;
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        //try to generate all possible nodes
        for(auto el:a){
            int newNode = (node*el)%modu;
            //if we are reaching any node with lesser operations then update
            if(steps+1<dist[newNode]){
                dist[newNode] = steps+1;
                //when we encounter the end first time steps+1 will be our ans
                //because steps are increasing order in queue
                if(newNode==end) return steps+1;
                q.push({newNode,steps+1});
            }
        }
    }
    return -1;
}