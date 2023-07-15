#include<bits/stdc++.h>
using namespace std;
void subsequence(vector<int> v, int i, vector<int> temp, int n)
{
	if(i == n)
	{
		for(int i = 0; i < temp.size(); i++)
		{
			cout<<temp[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	//Not take
	subsequence(v, i + 1, temp);
	temp.push_back(v[i]);
	//Take
	subsequence(v, i + 1, temp);
}
int main()
{
	vector<int> v{1, 2, 3};
	vector<int> ans;
	subsequence(v, 0, ans);
	return 0;
}