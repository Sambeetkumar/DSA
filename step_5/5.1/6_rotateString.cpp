#include <iostream>
using namespace std;
bool rotateString(string s, string goal) {
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        char temp = s[0];//store the first char in temp
        s.erase(s.begin());//remove the first char
        s+=temp;//add it to the end of the string
        if(s==goal)//compare it goal string
            return true;
    }
    return false;
}
int main(int argc, char* argv[]) {
    string a = "abcde";
    string b = "cdeab";
    cout << rotateString(a, b);
    return 0;
}