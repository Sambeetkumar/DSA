#include <iostream>
#include <vector>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/ceiling-in-a-sorted-array_1825401

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int low=0,high=n-1,floor=-1,ceil=-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==x)
		{
			//if a[mid] is same as target return the target as floor and ceil
			return {a[mid],a[mid]};
		}
		else if(a[mid]>x)
		{
			//if a[mid] >x then store mid as ceil and shrink the array to left
			high=mid-1;
			ceil=mid;
		}
		else{
			//if a[mid] < x then store mid as floor and shrink the array to right
			low=mid+1;
			floor=mid;
		}
	}
    if(floor==-1)
        return {floor,a[ceil]};
    else if(ceil==-1)
        return {a[floor], ceil};
    else
        return {a[floor], a[ceil]};
}

int main(int argc, char* argv[]) {

    vector<int> v = {3, 4, 4, 7, 8, 10};
    pair<int, int> p = getFloorAndCeil(v, 6, 2);
    cout << p.first<<endl;
    cout << p.second << endl;
    return 0;
}