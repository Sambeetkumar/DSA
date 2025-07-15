#include <bits/stdc++.h>
using namespace std;
class Comapre
{
public:
  bool operator()(pair<int, int> &a, pair<int, int> &b)
  {
    if (a.second > a.first && b.second <= b.first)
      return false;
    else if (b.second > b.first && a.second <= a.first)
      return true;
    return a.first < b.first;
  }
};
int findUpperBound(vector<int> &v, int num)
{
  int s = 0, e = v.size() - 1;
  while (s <= e)
  {
    int mid = s + (e - s) / 2;
    if (v[mid] > num)
      e = mid - 1;
    else
      s = mid + 1;
  }
  return s;
}
int solve(vector<int> &arr)
{
  unordered_map<int, int> freq;
  priority_queue<pair<int, int>, vector<pair<int, int>>, Comapre> pq;
  vector<int> v;
  int ans = 0;
  for (int it : arr)
  {
    freq[it]++;
  }
  for (auto it : freq)
  {
    pq.push({it.first, it.second});
  }
  while (!pq.empty())
  {
    pair<int, int> front = pq.top();
    pq.pop();
    int ub = findUpperBound(v, front.first);
    if(ub==v.size())
    {
       if(front.second>front.first)
       {
         ans += front.first;
         v.push_back(front.first);
       }
       else
       {
         ans += 1;
       }
    }
  }
  return ans;
}
int main(int argc, char *argv[])
{

  vector<int> arr = {5,6,7};
  cout<<solve(arr);
  return 0;
}