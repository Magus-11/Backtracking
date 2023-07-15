#include<bits/stdc++.h>
using namespace std;
int getMin(string s)
{
	stack<char> st;
	for(int i = 0; i < s.size(); i++)
	{
		if(!st.empty() and s[i] == ')' and st.top() == '(')
		{
			st.pop();
		}
		else if(s[i] == '(' or s[i] == ')')
			st.push(s[i]);
	}
	return st.size();
}

// void solve(string s, int count, set<string> &res)
// {
// 	if(count == 0)
// 	{
// 		if(getMin(s) == 0)
// 			res.insert(s);
// 		return;
// 	}
// 	for(int i = 0; i < s.size(); i++)
// 	{
// 		string left = s.substr(0, i);
// 		string right = s.substr(i + 1);
// 		if(getMin(left + right) < count)
// 			solve(left + right, count - 1, res);
// 	}
// }
void solve(string s, int count, vector<string> &res)
{
	if(mp[s] != 0)
		return ;
	else
		mp[s] = 1;
	if(count == 0)
	{
		if(getMin(s) == 0)
			res.push_back(s);
		return ;
	}
	for(int i = 0; i < s.size(); i++)
	{
		string left = s.substr(0, i);
		string right = s.substr(i + 1);
		if(getMin(left + right) < count)
			solve(left + right, count - 1, res);
	}
}
vector<string> removeInvalidParentheses(string s) 
{
     set<string> res;
     int count = getMin(s);
     vector<string> ans;
     solve(s, count, res);
     for(auto i : res)
     	ans.push_back(i);
     return ans;
}
int main()
{
	string s =")()m)(((()((()((((";
	cout<<getMin(s)<<endl;
	vector<string> ans = removeInvalidParentheses(s);
	for(auto i : ans)
		cout<<i<<endl;
	return 0;
}