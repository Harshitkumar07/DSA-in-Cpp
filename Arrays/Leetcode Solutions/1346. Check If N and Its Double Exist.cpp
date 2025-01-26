** Leetcode Problem 1346:- **

Given an array arr of integers, check if there exist two indices i and j such that :
i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

Example 1:
Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

Example 2:
Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.

** Code :- **

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set;
        for (int num : arr) {
            if (set.count(num * 2) || (num % 2 == 0 && set.count(num / 2))) 
                return true;
            set.insert(num);
        }
        return false;
    }
};

** Time Complexity :- **

Single Pass Over the Array :
The algorithm iterates through the arr vector once using a for-each loop.
For each element, it checks if either num * 2 or num / 2 (if even) exists in the hash set, both of which are constant-time operations.
Time Complexity: O(n) where n is the number of elements in arr.
Insertion and Lookup in Hash Set :
Inserting an element and checking for its presence in the unordered_set both take constant time on average.
Thus, for each element, operations are performed in: O(1)
Total Time Complexity :
Best Case: O(n) when a valid pair is found early, resulting in an early termination of the loop.
Worst Case: O(n) if no pairs are found and the entire array is processed.

** Space Complexity :- **

Hash Set Storage :
The algorithm uses an unordered_set to store elements from the input array.
In the worst case, the set stores all in elements.
Space Complexity: O(n)
Input Array :
The input array arr does not contribute to additional space usage as it is not modified.
Total Space Complexity :
Best Case: O(1) if the function returns early without storing many elements.
Worst Case: O(n) if all elements are stored in the hash set.
