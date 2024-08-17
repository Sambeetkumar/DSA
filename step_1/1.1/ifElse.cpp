#include <iostream>
using namespace std;

string compareNM(int n, int m){
        if (n > m) return "greater";
        else if (n == m) return "equal";
        else return "lesser";
    }
int main(int argc, char* argv[]) {
    cout << compareNM(5, 8)<< endl;

    return 0;
}