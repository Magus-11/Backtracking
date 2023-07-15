#include<bits/stdc++.h>
using namespace std;
int Fact(int n)
{
	if(n < 1)
	{
	    return 0;
	}
	return n * Fact(n - 1);
}
int main()
{
	cout<<Fact(10);
	return 0;
}