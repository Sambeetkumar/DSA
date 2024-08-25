#include <iostream>
#include <vector>
using namespace std;

vector<long long> lcmAndGcd(long long A, long long B)
{

    long long var1 = A, var2 = B,lcm,hcf;
    while (var1!=0 && var2!=0)
    {
        if (var1 > var2)
            var1 = var1 % var2;
        else
            var2 = var2 % var1;
    }

    if(var1==0)
    hcf = var2;
    else
    hcf = var1;

    lcm = (A * B) / hcf;
    return {lcm, hcf};
}

int main(int argc, char *argv[])
{
    cout << lcmAndGcd(5,9).at(0)<<endl;
    cout << lcmAndGcd(5,9).at(1);
    return 0;
}