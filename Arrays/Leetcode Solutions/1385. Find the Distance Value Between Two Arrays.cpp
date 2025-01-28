** Leetcode Problem 1385 :- **

Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.
The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

Example 1:
Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2
Explanation: 
For arr1[0]=4 we have: 
|4-10|=6 > d=2 
|4-9|=5 > d=2 
|4-1|=3 > d=2 
|4-8|=4 > d=2 
For arr1[1]=5 we have: 
|5-10|=5 > d=2 
|5-9|=4 > d=2 
|5-1|=4 > d=2 
|5-8|=3 > d=2
For arr1[2]=8 we have:
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2

Example 2:
Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
Output: 2

Example 3:
Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
Output: 1

** Code :- **

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (int num : arr1) {
            int left = 0, right = arr2.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr2[mid] < num - d) {
                    left = mid + 1;
                } else if (arr2[mid] > num + d) {
                    right = mid - 1;
                } else {
                    break;
                }
            }
            if (left > right) {
                cnt++;
            }
        }
        return cnt;
    }
};

** Time Complexity :- **
    
Sorting arr2 takes O(mlogm) where m is the size of arr2.
Binary Search for Each Element in arr1 :
For each element in arr1 (size n), a binary search is performed on arr2.
Binary search takes O(logm) time for each element.
Total Time Complexity for this step: O(n⋅logm)
Total Time Complexity :
Best Case: O(mlogm+n⋅logm)
Worst Case: O(mlogm+n⋅logm) as both sorting and binary search steps are always performed.

** Space Complexity :- **
    
In-Place Sorting :
Sorting arr2 is performed in place, so it uses O(1) additional space.
Auxiliary Variables :
The algorithm uses a few integer variables (cnt, left, right, mid) for computation.
Space Complexity: O(1)
Total Space Complexity :
Best Case: O(1)
Worst Case: O(1) since memory usage remains constant regardless of input size.
