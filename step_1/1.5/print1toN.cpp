#include <iostream>
using namespace std;
//printing numbers from 1 to N
void printNos(int i,int N){
    if(i>N) return; 

    cout << i << " ";
    printNos(i+1,N);
}
int main(int argc, char* argv[]) {
    int num,i = 1;
    cout << "enter a number : ";
    cin >> num;
    printNos(i, num);

    return 0;
}