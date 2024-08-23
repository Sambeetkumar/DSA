#include <iostream>
using namespace std;
//https://practice.geeksforgeeks.org/problems/while-loop-printtable-java/1
int printTable(int n){
    int i = 10;
    while(i>0){
        cout << n * i << " ";
        i--;
    }
}
int main(int argc, char* argv[]) {
    printTable(2);
    return 0;
}