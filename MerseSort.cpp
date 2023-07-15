#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int>& v, int s, int mid, int l)
{
	vector<int> merge;
	int i = s, j = mid + 1, k = 0;
	while(i <= mid and j <= l)
	{
		if(v[i] < v[j])
		{
			merge.push_back(v[i]);
			i++;
		}
		else
		{
			merge.push_back(v[j]);
			j++;
		}
	}
	while(j <= l)
	{
		merge.push_back(v[j]);
		k++;
		j++;
	}
	while(i <= mid)
	{
		merge.push_back(v[i]);
		k++;
		i++;
	}
	k = 0;
	for(int i = s; i <= l; i++)
	{
		v[i] = merge[k];
		k++;
	}
}
void MergeSort(vector<int> &v, int s, int l)
{
	if(s >= l)
	{
		return;
	}
	int mid = (s + l)/2;
	MergeSort(v, s, mid);
	MergeSort(v, mid + 1, l);
	Merge(v, s, mid, l);
}

int main()
{
	vector<int> v{5, 2, 4, 1, 3, 6, 2, 7, 4, 6, 3, 8};
	MergeSort(v, 0, 11);
	for(auto i : v)
	    cout<<i<<" ";
	return 0;
}