** Problem :- **

You are given an array arr[] consisting of a permutation of the set {1, 2, 3, …, n} for some positive integer n.
The task is to calculate the total distance you must travel starting from the position of 1 in the array, then moving to the position of 2, and so on, until you reach the position of n.
Note: When you travel from arr[i] to arr[j], the distance travelled is | i– j |.

Examples:

1. Input: arr[] = [5, 1, 4, 3, 2]
Output: 7
Explanation: The numbers and their respective indices are given below:
1->1
2->4
3->3
4->2
5->0
Total distance =|4-1|+|3-4|+|2-3|+|0-2| = 3+1+1+2 = 7.
  
2. Input: arr[] = [6, 5, 1, 2, 4, 3]
Output: 8
Explanation: Total distance = |2-3|+|3-5|+|5-4|+|4-1|+|1-0| = 1+2+1+3+1 = 8.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

** Code :- **

class Solution {
  public:
    long long distance(vector<int>& arr) {
        vector<int> index(arr.size() + 1);
        for (int i = 0; i < arr.size(); ++i) {
            index[arr[i]] = i;
        }
        long long totalDist = 0;
        for (int i = 1; i < arr.size(); ++i) {
            totalDist += abs(index[i] - index[i + 1]);
        }
        return totalDist;
    }
};

** Time Complexity :- **

Index Mapping:Building the index array takes O(n).
Distance Calculation:
Iterating through integers from 1 to n−1 takes O(n).
Overall Time Complexity: O(n)
  
** Space Complexity :- **
  
Input Array:
No additional space is used to manipulate the input array.
Auxiliary Storage:
The index array of size n+1 is created.
Overall Space Complexity: O(n)
