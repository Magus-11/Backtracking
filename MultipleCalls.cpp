#include<bits/stdc++.h>
using namespace std;
int Fibonacci(int n)
{
	if(n <= 1)
		return n;
	if(n == 2)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main()
{
	int n = 5;
	cout<<Fibonacci(n);
	return 0;
}