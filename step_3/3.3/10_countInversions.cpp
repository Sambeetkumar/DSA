#include <bits/stdc++.h>
using namespace std;
/*making modification in merge to keep track of inversion pairs while merging. maintain 
a count variable, when arr[left]>arr[right] incr count by (mid-left+1) as arr[right] can
form pairs with all elments from arr[left] to arr[mid](including)*/
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr
    int cnt=0;
    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            cnt+=(mid-left+1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return cnt;
}
/*making modification in mergeSort to keep track of inversions returned from mergSort
of left half and right half, finall inverions returned from merging of left and right half*/
int mergeSort(vector<int> &arr, int low, int high)
{
    int ans=0;
    if (low >= high)
        return ans;
    int mid = (low + high) / 2;
    ans+=mergeSort(arr, low, mid);      // left half
    ans+=mergeSort(arr, mid + 1, high); // right half
    ans+=merge(arr, low, mid, high);    // merging sorted halves
    return ans;
}
int main(int argc, char* argv[]) {
    vector<int> v = {24,18,38,43,14,40,1,4};
    cout << "printing the array" << endl;
    for(auto it:v)
    {
        cout << it << " ";
    }
    cout << "Number of inversions are " << mergeSort(v, 0, v.size() - 1);
    return 0;
}