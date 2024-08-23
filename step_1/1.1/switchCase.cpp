#include <bits/stdc++.h>
using namespace std;

double switchCase(int choice, vector<double> &arr)
{
    switch (choice)
    {
    case 1:
    {
        return M_PI * pow(arr.at(0), 2);
    }

    case 2:
    {
        return arr.at(0) * arr.at(1);
    }
    }
}
int main(int argc, char *argv[])
{
    vector<double> arr{5};
    cout << switchCase(1,arr);
    return 0;
}