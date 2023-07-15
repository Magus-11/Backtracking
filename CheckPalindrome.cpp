#include<bits/stdc++.h>
using namespace std;
bool Check(string s, int i, int n)
{
	if(i > n/2)
	{
		return true;
	}
	if(s[i] == s[n - i - 1])
		Check(s, i + 1, n);
	else
		return false;
}
int main()
{
	string s = "MADAM";
	cout<<Check(s, 0, 5);
	return 0;
}