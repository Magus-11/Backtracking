#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, int i, int target, vector<int> temp, vector<vector<int>>& ans)
{
	
	if(i == arr.size())
	{
		if(target == 0)
		{
			ans.push_back(temp);
		}
		return ;
	}
	solve(arr, i + 1, target, temp, ans);
	if(target - arr[i] >= 0)
	{
		temp.push_back(arr[i]);
		solve(arr, i, target - arr[i], temp, ans);
	}
}
vector<vector<int>> CombinationalSum(vector<int> arr, int target)
{
	vector<int> temp;
	vector<vector<int>> ans;
	solve(arr, 0, target, temp, ans);
	return ans;
}
int main()
{
	vector<int> v{2, 3, 5};
	vector<vector<int>> ans;
	int target = 7;
	ans = CombinationalSum(v, target);
	for(auto i : ans)
	{
		for(auto j : i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
}