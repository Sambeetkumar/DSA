#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        int m= a.size();
        int n = b.size();
        vector<int> res;
        int i=0, j=0;
        while((i<m) && (j<n))
        {
            if(a[i]<=b[j])
        {
            if(res.size()==0 || res.back()!=a[i])
            res.push_back(a[i]);
            i++;
        }
        else
        {
            if(res.size()==0 || res.back() != b[j])
            res.push_back(b[j]);
            j++;
        }  
        }
        while(i<m)
        {
            if(res.back() != a[i])
            res.push_back(a[i]);
            i++;
        }
        while(j<n)
        {
            if(res.back() != b[j])
            res.push_back(b[j]);
            j++;
        }
        return res;
    }
int main(int argc, char* argv[]) {

    vector<int> a = {-7,8};
    vector<int> b = {-8,-7,-3,8};

    vector<int> v =findUnion(a, b);
    for(auto it:v)
    {
        cout << it << " ";
    }

    return 0;
}