#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int findPages(vector<int> &arr, int n, int m)
{
    /*if the no of students is more than the no of books then allocation fails*/
    if(m>n) return -1;
    /*bs range will be max no pages to sum of all pages(if we try to assign all books to one student)*/
    int s = *max_element(arr.begin(), arr.end());
    int e = accumulate(arr.begin(), arr.end(), 0);
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int sum = 0, count = 1;
        for (int j = 0; j < n; j++)
        {
            /*if adding number of pages at ind j goes out of capacity*/
            if (sum + arr[j] > mid)
            {
                count++;
                sum = arr[j];
            }
            else
            {
                sum += arr[j];
            }
        }
        cout << " s = " << s << " e = " << e << endl;
        cout << "mid = " << mid << " count = " << count<<endl;
        /*if considering mid as max capacity we can assign books to students more than required,
        we need to increase our capacity so eliminate left half*/
        if (count > m)
            s = mid + 1;
        else
        {
            //otherwise right half
            e = mid - 1;
        }
    }

    return s;
}
int main(int argc, char *argv[])
{
    vector<int> v = {12, 34, 67, 90};
    cout << findPages(v, 4,2);

    return 0;
}