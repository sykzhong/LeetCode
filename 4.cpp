#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int head1 = 0, tail1 = nums1.size() - 1;
        int head2 = 0, tail2 = nums2.size() - 1;
        int middle1, middle2;
        if(tail1 < 0 || tail2 < 0)
        {
        	// tail1 < 0 ? nums1.push_back(0) : nums2.push_back(0);
        	tail1 < 0 ? nums1 = nums2 : nums2 = nums1;
        	tail1 < 0 ? middle1 = (head2+tail2+1) / 2 : middle1 = (head1+tail1+1) / 2;
        	if(nums1.size()%2 == 0)
        		return double(nums1[middle1] + nums1[middle1 - 1]) / 2;
        	else
        		return nums1[middle1];
        }
        while(head1 <= tail1 || head2 <= tail2)
        {
        	if(head1 <= tail1)
	        	middle1 = (head1+tail1+1) / 2;
			if(head2 <= tail2)
		        middle2 = (head2+tail2+1) / 2;
	        if(nums2[middle2] > nums1[middle1])
	        {
	        	tail2 = middle2 - 1;
	        	head1 = middle1 + 1;
	        }
	        else if(nums2[middle2] < nums1[middle1])
	        {
	        	head2 = middle2 + 1;
	        	tail1 = middle1 - 1;
	        }
	        else
			{
				if(nums1.size()%2 == 0 && nums2.size()%2 == 0)
					return double(nums1[middle1] + max(nums1[middle1 - 1], nums2[middle2 - 1])) / 2;
				break;
			}	        	
        }
        if((nums1.size() + nums2.size())%2 == 0)
        	return double(nums1[middle1] + nums2[middle2]) / 2;
        else
        	return max(nums1[middle1], nums2[middle2]);
    }
};

int main()
{
	int n1[] = {1, 2};
	int n2[] = {3, 4};
	vector<int> nums1(n1, n1+2);
	vector<int> nums2(n2, n2+2);
	Solution test;
	test.findMedianSortedArrays(nums1, nums2);

}