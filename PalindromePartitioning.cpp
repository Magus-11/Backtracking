#include<bits/stdc++.h>
using namespace std;
bool pal(string s, int st, int en)
{
	string s1 = "";
	for(int i = st; i <= en; i++)
		s1 += s[i];
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	return s1 == s2;
}
void solve(string s, int ind, vector<string> &path, vector<vector<string>> &res)
{
	if(ind == s.size())
	{
		res.push_back(path);
		return;
	}
	for(int i = ind; i < s.size(); i++)
	{
		if(pal(s, ind, i))
		{
			path.push_back(s.substr(ind, i - ind + 1));
			solve(s, i + 1, path, res);
			path.pop_back();
		}
	}
}
vector<vector<string>> partition(string s)
{
	vector<vector<string>> res;
	vector<string> path;
	solve(s, 0, path, res);
	return res;
}
int main()
{
	string s = "aabb";
	vector<vector<string>> res;
	res = partition(s);
	for(auto i : res)
	{
		for(auto j : i)
			cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}