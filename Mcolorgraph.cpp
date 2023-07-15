#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	static bool isValid(int Node, int c, int n, int color[], bool graph[101][101])
	{
		for(int k = 0; k < n; k++)
		{
			if(k != Node and graph[k][Node] == 1 and color[k] == c)
				return false;
		}
		return true;
	}
	static bool solve(int Node, int color[], int m, int n, bool graph[101][101])
	{
		if(Node ==  n)
			return true;
		for(int i = 1; i <= m; i++)
		{
			if(isValid(Node, i, n, color, graph))
			{
				color[Node] = i;
				if(solve(Node + 1, color, m, n, graph))
				{
					return true;
				}
				color[Node] = 0;
			}
		}
		return false;
	}
	static bool graphColoring(bool graph[101][101], int m, int n)
	{
		int color[n] = {0};
        if(solve(0, color, m, n, graph)) return true;
        return false;
    }
};
int main()
{
	bool graph[101][101];
	int n;
	int size;
	int m;
	cin>>n>>m>>size;
	for(int i = 0; i < size; i++)
	{
		int x, y;
		cin>>x>>y;
		graph[x - 1][y - 1] = 1;
		graph[y - 1][x - 1] = 1;
	}
	cout<<Solution::graphColoring(graph, m, n);
	return 0;
}