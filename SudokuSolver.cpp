#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> board, int row, int col, char num)
{
	for(int i = 0; i < 9; i++)
	{
		if(board[row][i] == num)
			return false;
		if(board[i][col] == num)
			return false;
		if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
			return false;
	}
	return true;
}

bool solve(vector<vector<char>> &board)
{
	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j] == '.')
			{
				for(char num = '1'; num <= '9'; num++)
				{
					if(isValid(board, i, j, num))
					{
						board[i][j] = num;

						if(solve(board) == true)
						{
							return true;
						}
						else
						{
							board[i][j] = '.';
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}
void solveSudoku(vector<vector<char>>& board)
{
    solve(board);
}

int main()
{
	vector<vector<char>> board{{'.','.','.','.','3','6','4','.','.'},{'.','.','9','.','.','.','5','.','.'},{'.','.','.','1','.','.','.','3','8'},{'9','.','.','.','4','.','.','.','.'},{'.','.','1','5','.','7','.','.','.'},{'.','4','.','2','.','3','.','.','.'},{'8','.','.','.','.','.','.','1','2'},{'.','.','.','.','.','5','7','.','.'},{'6','.','3','.','2','.','.','.','.'}};
	solveSudoku(board);
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[i].size(); j++)
		{
			cout<<board[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}