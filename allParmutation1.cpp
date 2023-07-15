#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, map<int, int> &m, vector<int> temp, vector<vector<int>>& ans)
{
	// if(ind == arr.size())
	// 	ans.push_back(temp);
	if(temp.size() == arr.size())
		ans.push_back(temp);

	for(int i = 0; i < arr.size(); i++)
	{
		if(m.find(arr[i]) == m.end())
		{
			m[arr[i]] = 1;
			temp.push_back(arr[i]);
			solve(arr, m, temp, ans);
			m.erase(arr[i]);
			temp.pop_back();

		}
	}

}
vector<vector<int>> permutation(vector<int> arr)
{
	vector<int> temp;
	map<int, int> m;
	vector<vector<int>> ans;
	solve(arr, m, temp, ans);
	return ans;
}
int main()
{
	vector<int> v{1, 2, 3};
	vector<vector<int>> ans;
	for(auto i : ans)
	{
		for(auto j : i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}