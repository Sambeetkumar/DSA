#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
       int n = nums.size();
       vector<int> v(n, 0);
       int i=0;
       int j=1;
       /*ptr i always points to +ve numbers and j always points to -ve numbers and as we are
       storing +ve and -ve numbers alternatively each ptr will move 2 positions when required*/
       for(auto it:nums)
       {
        if(it>0)
        {
            v[i]=it;
            i+=2;
        }
        else
        {
            v[j]=it;
            j+=2;
        }
       }
       return v; 
    }
int main(int argc, char* argv[]) {
    vector<int> v = {1, 2, 3, -1, -2, -3};
    vector<int> res = rearrangeArray(v);
    for(auto it: res)
    {
        cout << it << " ";
    }
    
    return 0;
}