#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &m, int x, int y, vector<vector<int>> dir, string path, vector<string> &res, vector<vector<bool>> &vis)
{
	if(x == m.size() - 1 and y == m.size() - 1)
	{
		res.push_back(path);
		return ;
	}
	string d = "DLRU";
	for(int i = 0; i < dir.size(); i++)
	{
		int x1 = x + dir[i][0];
		int y1 = y + dir[i][1];
		if(x1 >= 0 and (x1 < m.size()) and y1 >= 0 and (y1 < m.size()) and !vis[x1][y1] and m[x1][y1] == 1)
		{
			vis[x1][y1] = 1;
			solve(m, x1, y1, dir, path + d[i], res, vis);
			vis[x1][y1] = 0;
		}
	}
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
	vector<string> res;
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	vector<vector<int>> dir{{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
	vis[0][0] = 1;
	if(m[0][0] == 1) solve(m, 0, 0, dir, "", res, vis);
	return res;
}
int main()
{
	vector<vector<int>> maze{{1, 1},{1, 1}};
	vector<string> ans;
	ans = findPath(maze, maze.size());
	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<endl;
}