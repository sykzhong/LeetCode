#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> result;
        int flag = 1;
        for(int i = 0; i < size - 1; i++)
        {
        	for(int j = i + 1; j < size; j++)
        	{
        		if(nums[i] + nums[j] == target)
        		{
        			result.push_back(i);
        			result.push_back(j);
        			flag = 0;
        			break;
        		}
        	}
            if(flag == 0)
                break;
        }
       	return result;
    }
};

int main()
{
	Solution syk;
}