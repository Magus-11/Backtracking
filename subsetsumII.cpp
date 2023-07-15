#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& arr, int ind, vector<int> temp, vector<vector<int>> &ans)
{
		ans.push_back(temp);
	for(int i = ind; i < arr.size(); i++)
	{
		if(i > ind and arr[i] == arr[i - 1])
			continue;
		temp.push_back(arr[i]);
		solve(arr, i + 1, temp, ans);
		temp.pop_back();
	// for(auto i : temp)
	// {
	// 	cout<<i <<" ";
	// }
	// cout<<endl;
	}
}
vector<vector<int>> subsetSum(vector<int> arr)
{
	sort(arr.begin(), arr.end());
	vector<int> temp;
	vector<vector<int>> ans;
	// ans.push_back(temp);
	solve(arr, 0, temp, ans);
	return ans;
}
int main()
{
	vector<int> arr{1, 2, 2};
	vector<vector<int>> ans;
	ans = subsetSum(arr);
	for(auto i : ans)
	{
		for(auto j : i)
			cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}