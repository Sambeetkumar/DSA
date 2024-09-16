#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums)
{
    int res = 0;
    for (int i = 0; i <=nums.size() - 1; i++)
    {
        res = (res ^ nums[i]);
    }
    return res;
}
int main(int argc, char* argv[]) {
    vector<int> v = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(v);
    return 0;
}