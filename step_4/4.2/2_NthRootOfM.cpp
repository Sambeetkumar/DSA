#include <iostream>
using namespace std;

long long int NthPower(int num, int n, int m)
{
	long long int res = 1;
	for (int i = 0; i < n; i++)
	{
		res = res * num;
		if (res > m) //if res exceeds the number m then return 0
			return 0;
	}
	if (res == m) //if res is same as the number m
		return 1;
	else
		return 2; //if res is less than the number m
}
int NthRoot(int n, int m)
{
	int s = 1, e = m;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		int val = NthPower(mid, n, m);

		/*if val==1 then mid is the nth root of the number, return mid*/
		if (val == 1) 
			return mid;
		//if val==0 then mid^n exceeds the number m, eliminate the right half
		else if (val == 0)
			e = mid - 1;
		//if val==2 then mid^n is less than the target m, eliminate the left half
		else
			s = mid + 1;
	}
	return -1;
}
int main(int argc, char *argv[])
{
	cout << NthRoot(6, 4096);

	return 0;
}