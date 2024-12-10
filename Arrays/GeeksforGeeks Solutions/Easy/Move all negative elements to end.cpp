** Problem :- **

Given an unsorted array arr[ ] having both negative and positive integers. 
The task is to place all negative elements at the end of the array without changing the order of positive elements and negative elements.

Note: Don't return any array, just in-place on the array.

Examples:

1. Input : arr[] = [1, -1, 3, 2, -7, -5, 11, 6 ]
Output : [1, 3, 2, 11, 6, -1, -7, -5]
Explanation: By doing operations we separated the integers without changing the order.

2. Input : arr[] = [-5, 7, -3, -4, 9, 10, -1, 11]
Output : [7, 9, 10, 11, -5, -3, -4, -1]

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

** Code :- **

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
    int n = arr.size(),pos= 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            ans[pos++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            ans[pos++] = arr[i];
        }
    }
    arr = ans;
    }
};

** Time Complexity :- **
  
Positive Element Segregation:
The loop iterates through the array once, O(n).
Negative Element Segregation:
The second loop also iterates through the array once, O(n).
Copy Back to Input Array:
Assigning arr = ans is O(n).

Overall Time Complexity: O(n)
  
** Space Complexity :- **
  
Auxiliary Array ans:
Requires O(n) space to store rearranged elements.
Other Variables:
Constant space for variables like n and pos.
  
Overall Space Complexity: O(n)
