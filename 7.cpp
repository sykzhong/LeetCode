#include <iostream>
#include <stdio.h>
#include <limits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
		int flag = 1;
		int result = 0;
		long long int tmp = 0;
		if(x < 0)
		{
			flag = -1;
			x *= -1;
		}
		
		while(x > 0)
		{
			tmp = (long long int)result*10 + x%10;
			if(tmp > (numeric_limits<int>::max)())
				return 0;
			else
				result = (int)tmp;
			x /= 10;	
		}
		return flag*result;
    }
};

int main()
{
	Solution test;
	cout << test.reverse(1534236469) << endl;
	cout << (int)964632435*10;
} 
