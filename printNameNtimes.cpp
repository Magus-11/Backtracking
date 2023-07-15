#include<bits/stdc++.h>
using namespace std;
void print(int i, int n){
	if(n == i) return;
	cout<<"I'll gonna become the best coder in the world and richest person of the Universe"<<endl;
	print(i + 1, n);
}
int main()
{
	int n = 5;
	print(0, n);
	return 0;
}