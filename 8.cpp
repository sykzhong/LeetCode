#include <string>
#include <iostream>
#include <limits>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        long long int result = 0;
        int sign = 0;
        int numflag = 0;
        if(str.length() == 0)
        	return 0;
		
		for(int i = 0; i < str.length(); i++)
        {
        	if(str[i] <= '9' && str[i] >= '0')
        	{
        		result = result*10 + str[i] - '0';
        		if(result > (long long int)(numeric_limits<int>::max)() + 1)
        			break;
        		numflag = 1;
        	}
        	else if((str[i] == '-' || str[i] == '+') && numflag == 0)
	        {
	        	if(sign == 1 || sign == -1)
	        		return 0;
	        	else
	        		sign = str[i] == '-' ? -1 : 1;
	        	numflag = 1;
	        }	
        	else if(str[i] == ' ' && numflag == 0)
        		continue;
        	else break;
        }
        if(sign == 0)
        	sign = 1;
        if(result*sign > (numeric_limits<int>::max)())
			return (numeric_limits<int>::max)();
		else if(result*sign < (numeric_limits<int>::min)())
			return (numeric_limits<int>::min)();
        else return result*sign;
    }
};

int main()
{
	Solution test;
	
	cout << test.myAtoi("   - 321");
}
