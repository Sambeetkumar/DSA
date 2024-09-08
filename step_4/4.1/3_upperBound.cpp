#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*avoid bubble sort because of time limit(comolexity O(n2))
  use stl sort (complexity O(nlogn))
  
  void bubbleSort(vector <int>& v, int n)
  {
      if(n==1)
      return;
      else
      {
          for(int i=0; i<n-1; i++)
          {
              if(v[i]>v[i+1])
              swap(v[i],v[i+1]);
          }
      }
      bubbleSort(v,n-1);
  }*/
  
  int getFloor(vector <int>& v, int x)
  {
      int low=0,high=v.size()-1,ans=-1;
      while(low<=high)
      {
          int mid =(low+high)/2;
          if(v[mid]<=x)
          {
             ans=mid;
             low=mid+1;
          }
          else
          high=mid-1;
      }
      if(ans==-1)
      return -1;
      else
      return v[ans];
  }
  
  int getCeil(vector <int>& v, int x)
  {
      int low=0,high=v.size()-1,ans=-1;
      while(low<=high)
      {
          int mid=(low+high)/2;
          if(v[mid]>=x)
          {
              ans=mid;
              high=mid-1;
          }
          else
          {
              low=mid+1;
          }
      }
      if(ans==-1)
      return -1;
      else
      return v[ans];
      
  }
  
  vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int> v;
        v.push_back(getFloor(arr,x));
        v.push_back(getCeil(arr,x));
        return v;
    
    }

int main(int argc, char* argv[]) {
    vector<int> v = {5, 6, 8, 8, 6, 5, 5, 6};
    cout << getFloorAndCeil(10, v).front()<<endl;
    cout << getFloorAndCeil(10, v).back() << endl;
    return 0;
}