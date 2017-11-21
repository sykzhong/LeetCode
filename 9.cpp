#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        vector<vector<int> > vecnum(10);
//        if(x < 0 && x != numeric_limits<int>::min())
//        	x *= -1;
//        else if(x == numeric_limits<int>::min())
//        	return false;
		if(x < 0)
			return false;
        for(int i = 0; x != 0; x/=10, i++)
        	vecnum[x%10].push_back(i);
        int core = -1;
        int tmp = 0;
        for(int i = 0; i < 10; i++)
        {
        	int length = vecnum[i].size();
        	int gap = length%2==0 ? length/2 : length/2 + 1;
        	for(int j = 0; j < gap; j++)
        	{
        		tmp = vecnum[i][j] + vecnum[i][length - 1 - j];
        		if(core == -1)
        			core = tmp;
        		else if(core != tmp)
        			return false;
        	}
        }
        return true;
    }
};

int main()
{
	Solution test;
	cout << test.isPalindrome(-2147483648) << endl;
} 
