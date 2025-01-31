** Leetcode Problem 3194:- **

You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.
You repeat the following procedure n / 2 times:
Remove the smallest element, minElement, and the largest element maxElement, from nums.
Add (minElement + maxElement) / 2 to averages.
Return the minimum element in averages. 

Example 1:

Input: nums = [7,8,3,4,15,13,4,1]
Output: 5.5
Explanation:

step	nums	averages
0	[7,8,3,4,15,13,4,1]	[]
1	[7,8,3,4,13,4]	[8]
2	[7,8,4,4]	[8,8]
3	[7,4]	[8,8,6]
4	[]	[8,8,6,5.5]
The smallest element of averages, 5.5, is returned.

Example 2:

Input: nums = [1,9,8,3,10,5]
Output: 5.5
Explanation:

step	nums	averages
0	[1,9,8,3,10,5]	[]
1	[9,8,3,5]	[5.5]
2	[8,5]	[5.5,6]
3	[]	[5.5,6,6.5]

Example 3:

Input: nums = [1,2,3,7,8,9]
Output: 5.0
Explanation:

step	nums	averages
0	[1,2,3,7,8,9]	[]
1	[2,3,7,8]	[5]
2	[3,7]	[5,5]
3	[]	[5,5,5]

** Code :- **

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        double minAvg = INT_MAX;
        while (i < j) {
            double sum = nums[i] + nums[j];
            double avg = (sum / 2);
            minAvg = min(minAvg, avg);
            i++;
            j--;
        }
        if (i == j) 
            minAvg = min(minAvg, (nums[i] + nums[j]) / 2);
        return minAvg;
    }
};

** Time Complexity :- **
    
Sorting the Array :
Sorting takes O(nlogn) since sort(nums.begin(), nums.end()) uses an efficient sorting algorithm like quicksort or mergesort.
Two-Pointer Traversal :
The while loop runs at most O(n) since it moves both pointers (i and j) towards the center. 
Total Time Complexity :
Best Case: O(nlogn) if sorting dominates.
Worst Case: O(nlogn) due to sorting.

** Space Complexity :- **
    
In-Place Sorting :
Sorting is done in-place, using O(1) extra space.
Few Integer and Double Variables :
The algorithm uses a few integer and double variables (i, j, minAvg, sum, avg), which take constant space.
Total Space Complexity :
Best Case: O(1)
Worst Case: O(1) since no extra memory is allocated except for variables.
