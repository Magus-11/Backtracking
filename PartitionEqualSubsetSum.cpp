#include<bits/stdc++.h>
using namespace std;
bool solve(int arr[], int n, int i, int sum)
    {
        if(sum == 0)
            return true;
        if(i == n)
            return false;
        bool left = false;
        bool right = false;
        if(sum - arr[i] >= 0)
        left = solve(arr, n, i + 1, sum - arr[i]);
        right = solve(arr, n, i + 1, sum);
        return left || right; 
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += arr[i];
        if(sum % 2 != 0)
        	return false;
        return solve(arr, N, 0, sum / 2);
    }
int main()
{
	int arr[3] = {1, 3, 5};
	cout<<equalPartition(3, arr);
	return 0;
}