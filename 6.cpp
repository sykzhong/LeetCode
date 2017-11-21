#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string convert(const string s, int numRows) {
    	vector<string> vecstring(numRows);
    	int gap = 2*numRows - 2;
    	if(gap == 0)
    		return s;
		for(int i = 0; i < s.length(); i++)
    	{
    		if(i%gap >=0 && i%gap < numRows)
    			vecstring[i%gap] += s[i];
    		else
    			vecstring[2*numRows - i%gap - 2] += s[i];
    	}
    	string result = "";
    	for(int i = 0; i < vecstring.size(); i++)
    	{
    		result += vecstring[i];
    		cout << vecstring[i] << endl;
    	}
    	return result;
    }
};

int main()
{
	Solution test; 
	string input = "PAYPALISHIRING";
	int numRows = 3;
	cout << test.convert(input, numRows);
}
