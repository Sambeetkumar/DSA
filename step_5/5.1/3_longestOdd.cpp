#include <iostream>
using namespace std;
string largestOddNumber(string num) {
        int i=num.size()-1;//start iterating from the last digit
        while(i>=0)
        {
            //where you encounter an odd digit return the substring from 0 to that index
            if((num[i]-'0')%2!=0)
            return num.substr(0,i+1);

            i--;
        }
        return "";//if every digit is even
    }
int main(int argc, char* argv[]) {
    string num = "123458";
    cout << num;
    return 0;
}