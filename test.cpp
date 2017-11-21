
#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"
using namespace std;
int Comp(int first, int second)
{
	return first > second;
}

vector<vector<int> > Solution(int n, int m, vector<int> array)
{
	vector<vector<int> > isinclude(n, vector<int> (m+1));
	vector<int> d(m+1, 0);
	for(int i = 0; i < n; i++)
		for(int j = m; j >= array[i]; j--)
			if(d[j-array[i]] + array[i] >= d[j])
			{
				d[j] = d[j-array[i]]+array[i];
				isinclude[i][j] = 1;
			}
	vector<int> tmpresult;
	vector<vector<int> > result;
	int C = m, lastindex = n - 1;
	int index = lastindex;
	while(1)
	{
		C = m;
		int sum = 0;
		index = lastindex;
		tmpresult.clear();
		while(1)
		{
			if(isinclude[index][C] == 1)
			{
				tmpresult.push_back(array[index]);
				sum += array[index];
				C -= array[index];
			}
			index--;
			if(index < 0)
				break;
		}
		if(sum == m)
			result.push_back(tmpresult);
		lastindex--;
		if(lastindex < 0)
			break;
	}
	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<int> array(n);
	for(int i = 0; i < n; i++)
		cin >> array[i];
	vector<vector<int> > result;
	result = Solution(n, m, array);
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
