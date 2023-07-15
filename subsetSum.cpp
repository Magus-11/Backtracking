#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& arr, int i, int sum, vector<int>& temp)
{
	if(i == arr.size())
	{
		temp.push_back(sum);
		return;
	}
	solve(arr, i + 1, sum + arr[i], temp);
	solve(arr, i + 1, sum, temp);
}
vector<int> subsetSum(vector<int> arr)
{
	vector<int> ans;
	solve(arr, 0, 0, ans);
	return ans;
}
int main()
{
	vector<int> arr{};
	arr = subsetSum(arr);
	for(auto i : arr)
		cout<<i<<" ";
	return 0;
}