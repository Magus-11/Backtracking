#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> v, int sum, int i, int k, vector<int> temp)
{
	if(i == v.size())
	{
		if(sum == k)
		{
			return 1;
		}
		return 0;
	}
	return solve(v, sum + v[i], i + 1,  k, temp) + solve(v, sum, i + 1, k, temp);
}
int main()
{
	vector<int> v{1, 2, 1};
	vector<int> ans;
	solve(v, 0, 0, 2, ans);
	return 0;
}