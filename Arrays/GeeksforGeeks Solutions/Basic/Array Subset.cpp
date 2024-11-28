** Problem :- **

Given two arrays: a[] and b[], where both arrays may contain duplicate elements. The task is to determine whether array b is a subset of array a. 
It's important to note that both arrays can be unsorted. Additionally, each occurrence of a duplicate element within an array is considered as a separate element of the set.

Examples:

1. Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
Output: Yes
Explanation: b[] is a subset of a[]

2. Input: a[] = [1, 2, 3, 4, 4, 5, 6], b[] = [1, 2, 4]
Output: Yes
Explanation: b[] is a subset of a[]

3. Input: a[] = [10, 5, 2, 23, 19], b[] = [19, 5, 3]
Output: No
Explanation: b[] is not a subset of a[]

** Code :- **

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
       unordered_map<int, int> map;
        
        for (int num : a) {
            map[num]++;
        }
        for (int num : b) {
            if (map[num] > 0) {
                map[num]--;
            } else {
                return false; 
            }
        }
        return true; 
    }
};

** Time Complexity :- **
  
Building the frequency map:
The algorithm iterates through vector a once, adding elements to the unordered_map in O(1) time per element.
Time complexity: O(n), where n is the size of vector a.
Checking the subset condition:
The algorithm iterates through vector b, performing O(1) lookups and updates for each element.
Time complexity: O(m), where m is the size of vector b.
Overall Time Complexity: O(n+m)

** Space Complexity :- **
  
unordered_map storage:
Stores frequencies of elements in a. Worst-case space: O(n).
Auxiliary variables:
Uses constant space for iteration and checks: O(1).
Overall Space Complexity: O(n)
