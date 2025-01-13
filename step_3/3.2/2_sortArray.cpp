#include <bits/stdc++.h>
using namespace std;
// Dutch National flag Algo 
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0;
    int high = n - 1;
    /*we are sorting an array which contain elements of exactly 3 types. here they are 0,1 and 2.
    we will use three pointer low,mid and high. pointer low will point to the el just after all 0s.
    pointer mid will point to the el just after all 1s and pointer high will point to the el just
    before all 2s*/
    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            /*swap and incr low and high each by one as 0 comes to the place pointed by low and
            1 comes to the place pointed by mid*/
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1)
        {
            //incr mid as 1 is in it's right position
            mid++;
        }
        else
        {
            //swap and decr high by one as 2 comes to the place pointed by high
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main(int argc, char* argv[]) {
    vector<int> v = {2,0,2,1,1,0};
    sortColors(v);
    return 0;
}