** Problem :- **

Given an array arr[] of positive integers and another integer target. Determine whether two elements exist in the array whose sum is exactly target or not.
Return a boolean value true if two elements exist in arr[] else return false.

Examples:

1. Input: arr[] = [1, 4, 45, 6, 10, 8], target = 16
Output: true
Explanation: arr[3] + arr[4] = 6 + 10 = 16
  
2. Input: arr[] = [1, 2, 4, 3, 6], target = 11
Output: false
Explanation: None of the pair makes a sum of 11

** Code:- **

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); i++) {
            int first = arr[i], second = target - first;
            if (map.find(second) != map.end()) {
                return true;
            }
            map[first] = i;
        }
        return false;
    }
};

** Time Complexity :- **
  
Traversal of Array:
The algorithm iterates over the array once, making it O(n).
Hash Map Operations:
Both lookup (map.find) and insertion (map[first] = i) operations have an average time complexity of O(1).

Overall Time Complexity: O(n)
  
** Space Complexity :- **
  
Hash Map:
The hash map can store up to n elements in the worst case (when no pair sums to the target).
Space usage is proportional to the input size.
Auxiliary Space:
No significant additional memory usage apart from the hash map.

Overall Space Complexity: O(n)
