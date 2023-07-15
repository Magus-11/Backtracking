#include<bits/stdc++.h>
using namespace std;
string getPermutation(int n, int k)
{
    vector<int> Num;
    int fact = 1;
    for(int i = 1; i < n; i++)
    {
    	fact *= i;
        Num.push_back(i);
    }
    Num.push_back(n);
    k = k - 1;
    string ans = "";
    while(true)
    {
	    ans += to_string(Num[k / fact]);
	    Num.erase(Num.begin() + (k / fact));
	    if(Num.size() == 0)
	    	break;
	    k = k % fact;
	    fact = fact / Num.size();
    }
    return ans;
}
int main()
{
	int n = 3;
	int k = 3;
	cout<<getPermutation(n, k);
	return 0;
}