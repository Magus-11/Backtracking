#include<bits/stdc++.h>
using namespace std;
bool solve(int x, int y, vector<vector<int>> move, vector<vector<int>> &board, int count)
{
	if(count == board.size()*board.size())
	{
		return true;
	}
	for(int i = 0; i < move.size(); i++)
	{
		int x1 = x + move[i][0];
		int y1 = y + move[i][1];
		if(x1 >= 0 and (x1 < board.size()) and y1 >= 0 and (y1 < board.size()))
		{
			if(board[x1][y1] != -1)
			{
				board[x1][y1] = count + 1;
				if(solve(x1, y1, move, board, count + 1))
					return true;
				board[x1][y1] = -1;
			}
		}
	}
	return false;
}
bool KnightTour(int x, int y, int n)
{
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> move{{2, 1},{1, 2},{-1, 2},{-2, 1},{-2, -1},{-1, -2},{1, -2},{2, -1}};
	return solve(x, y, move, board, 0);
}
int main()
{
	int n = 8;
	int x = 0;
	int y = 0;
	cout<<KnightTour(0, 0, n); 
	return 0;
}