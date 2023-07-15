#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, int ind, int target, vector<int> temp, vector<vector<int>> &ans)
{
	if(target == 0)
		{
			ans.push_back(temp);
		return ;
		}
	for(int i = ind; i < arr.size(); i++)
	{
		if(i > ind and arr[i] == arr[i - 1])
			continue;
		if(target < arr[i])
		{
			break;
		}
			temp.push_back(arr[i]);
			solve(arr, i + 1, target - arr[i], temp, ans);
			temp.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
	sort(arr.begin(), arr.end());
	vector<int> temp;
	vector<vector<int>> ans;
	solve(arr, 0, target, temp, ans);
	return ans; 
}
int main()
{
	vector<int> arr{10, 1, 2, 7, 6, 1, 5};
	int target = 8;
	vector<vector<int>> ans;
	ans = combinationSum2(arr, target);
	for(auto i : ans)
	{
		for(auto j : i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
}