#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        map<char, vector<int> > charclump;
        vector<vector<int> > resultclump(2000);
        int tmp = 0;
        for(int i = 0; i < s.length(); i++)
        {
    		resultclump[i*2].insert(resultclump[i*2].begin()+resultclump.size()/2, i);
    		for(int j = 0; j < charclump[s[i]].size(); j++)
    		{
    			tmp = charclump[s[i]][j] + i;
    			printf("i = %d, s[i] = %c, tmp = %d\n", i, s[i], tmp);
    			if(resultclump[tmp].size() == 0 && i - charclump[s[i]][j] != 1)
    				continue;
    			else if (resultclump[tmp].size() != 0 && i - resultclump[tmp].back() != 1)
	    			continue;
    			resultclump[tmp].insert(resultclump[tmp].begin(), charclump[s[i]][j]);
    			resultclump[tmp].push_back(i);
    		}
        	charclump[s[i]].push_back(i);
        }
        int index = max_element(resultclump.begin(), resultclump.end(), Comp) - resultclump.begin();
        return string(s.begin() + resultclump[index][0], s.begin() + resultclump[index].back());
    }
    static int Comp(const vector<int> first, const vector<int> second)
    {
    	if(first.size() < second.size())
    		return 1;
    	else
    		return 0;
    }

};

int main()
{
	string input = "abcdasdfghjkldcba";
	Solution test;
	cout << test.longestPalindrome(input) << endl;

}