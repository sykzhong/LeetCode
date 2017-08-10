#include <map>
#include <ext/hash_map>
#include <string>
#include <iostream>
using namespace std;
using namespace __gnu_cxx;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	if(s.length() == 0)
    		return 0;
      	map<char, int> substring;
      	map<char, int>::iterator iter;
      	int head = 0;
      	int result = 0;
      	int tmp = 0;
      	for(int i = 0; i < s.length(); i++)
      	{
      		iter = substring.find(s[i]);
      		if(iter == substring.end())
      		{
      			substring[s[i]] = i;
      		}
      		else
      		{
      			if(head <= iter->second)
      			{
      				tmp = i - head;
      				head = iter->second + 1;
      			}
      			substring[s[i]] = i;
      		}
      		if(tmp > result)
      			result = tmp;

      	}
      	tmp = s.length() - head;
      	if(tmp > result)
      		result = tmp;
      	return result;
    }
};

int main()
{
	Solution test;
	string input = "pwwkew";
	int result;
	result = test.lengthOfLongestSubstring(input);
	cout << result << endl;
}