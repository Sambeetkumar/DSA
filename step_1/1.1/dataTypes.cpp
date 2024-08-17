#include <iostream>
using namespace std;
//https://www.geeksforgeeks.org/problems/data-type-1666706751/1
int dataTypeSize(string str)
{
    if (str == "Character")
        return 1;
    else if (str == "Integer")
        return 4;
    else if (str == "Long")
        return 8;
    else if (str == "Float")
        return 4;
    else if (str == "Double")
        return 8;
    else
        return -1;
}
int main(int argc, char *argv[])
{

    cout << dataTypeSize("Long") << endl;
    return 0;
}