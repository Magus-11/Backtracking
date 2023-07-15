#include<bits/stdc++.h>
using namespace std;
bool valid(vector<string> mat, int x, int y)
{
	int i = x, j = y;
	while(i > 0 and j > 0)
	{
		if(mat[i - 1][j - 1] == 'Q')
		{
			return false;
		}
		i--;
		j--;
	}
	i = x;
	j = y;
	while(j > 0)
	{
		if(mat[i][j - 1] == 'Q')
		{
			return false;
		}
		j--;
	}
	i = x;
	j = y;
	while(i < mat.size() and j >= 0)
	{
		if(mat[i][j] == 'Q')
			return false;
		i++;
		j--;
	}
	return true;
}
void solve(vector<string>& mat, int col, int &count)
{
	if(col == mat.size())
	{
		count++;
	}
	for(int row = 0; row < mat.size(); row++)
	{
		// cout<<valid(mat, row, col)<<endl;
		if(valid(mat, row, col))
		{
			mat[row][col] = 'Q';
			solve(mat, col + 1, count);
			mat[row][col] = '.';
		}
	}
}

int solveNQueens(int n) 
{
	vector<string> v(n);
	string s(n, '.');
	for(int i = 0; i < n; i++)
	{
		v[i] = s;
	}
	// v[2][0] = 'Q';
	int count = 0;
	solve(v, 0, count);
	return count;
}

int main()
{
	int n = 4;
	int ans = solveNQueens(n);
	cout<<ans<<endl;
	return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// void solve(vector<string>& mat, int col, int &count, vector<int> &sleeping, vector<int> &slanting, vector<int> &rSlanting)
// {
// 	if(col == mat.size())
// 	{
// 		count++;
// 	}
// 	for(int row = 0; row < mat.size(); row++)
// 	{
// 		// cout<<valid(mat, row, col)<<endl;
// 		if(sleeping[row] == 0 and rSlanting[col + row] == 0 and slanting[mat.size() - 1 + col - row] == 0)
// 		{
// 			mat[row][col] = 'Q';
// 			sleeping[row] = 1;
// 			slanting[mat.size() - 1 + col - row] = 1;
// 			rSlanting[col + row] = 1;
// 			solve(mat, col + 1, count, sleeping, slanting, rSlanting);
// 			mat[row][col] = '.';
// 			sleeping[row] = 0;
// 			slanting[mat.size() - 1 + col - row] = 0;
// 			rSlanting[col + row] = 0;
// 		}
// 	}
// }
// int solveNQueens(int n) 
// {
// 	vector<string> v(n);
// 	string s(n, '.');
// 	for(int i = 0; i < n; i++)
// 	{
// 		v[i] = s;
// 	}
// 	// v[2][0] = 'Q';
// 	int count = 0;
// 	vector<int> sleeping(n, 0);
// 	vector<int> slanting(2*n - 1, 0);
// 	vector<int> rSlanting(2*n - 1, 0);
// 	solve(v, 0, count, sleeping, slanting, rSlanting);
// 	return count;
// }

// int main()
// {
// 	int n = 5;
// 	int ans = solveNQueens(n);
// 	cout<<ans<<endl;
// 	return 0;
// }