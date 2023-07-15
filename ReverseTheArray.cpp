#include<bits/stdc++.h>
using namespace std;
void Reverse(int *arr, int i, int n)
{
	if(i > n/2)return ;
	swap(arr[i], arr[n - i - 1]);
}
int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	Reverse(arr, 0, 5);
	for(int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}