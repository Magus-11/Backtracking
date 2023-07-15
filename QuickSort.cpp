#include<bits/stdc++.h>
using namespace std;
int f(vector<int> &v, int low, int high)
{
	int pivot = v[low];
	int i  = low;
	int j = high;
	while(i < j)
	{
		while(v[i] <= pivot && i <= high - 1)
		{
			i++;
		}
		while(v[j] > pivot && j >= low - 1)
		{
			j--;
		}
		if(i < j)
		{
			swap(v[i], v[j]);
		}
	}
	swap(v[low], v[j]);
}
void QuickSort(vector<int>& v, int low, int high)
{
	if(low < high)
	{
	int PivotIndex = f(v, low, high);
	QuickSort(v, low, PivotIndex - 1);
	QuickSort(v, PivotIndex + 1, high);
	}
}
int main()
{
	vector<int> v{2, 4, 3, 1, 5};
	QuickSort(v, 0, 4);
	return 0;
}
