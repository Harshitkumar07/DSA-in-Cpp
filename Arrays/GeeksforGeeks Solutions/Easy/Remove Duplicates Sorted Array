** Problem :- **

Given a sorted array arr. Return the size of the modified array which contains only distinct elements.
Note:
1. Don't use set or HashMap to solve the problem.
2. You must return the modified array size only where distinct elements are present and modify the original array such that all the distinct elements come at the beginning of the original array.

Examples :

1. Input: arr = [2, 2, 2, 2, 2]
Output: [2]
Explanation: After removing all the duplicates only one instance of 2 will remain i.e. [2] so modified array will contains 2 at first position. 
You should return 1 after modifying the array, the driver code will print the modified array elements.

2. Input: arr = [1, 2, 4]
Output: [1, 2, 4]
Explation:  As the array does not contain any duplicates so you should return 3.

** Code :- **

class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        if (arr.empty()){
            return 0;
        }
        int idx = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=arr[idx]){
                idx++;
                arr[idx] = arr[i];
            }
        }
        return idx+1;
    }
};

** Time Complexity :- **

Iteration Through the Array:
The loop iterates through the array once, performing O(1) operations for each element.

Overall Time Complexity: O(n) Where n is the size of the input array.

** Space Complexity :- **

In-Place Modification:
The algorithm modifies the input array directly without using extra space.
Auxiliary Space:
Only a few integer variables are used, resulting in O(1) auxiliary space.

Overall Space Complexity: O(1)
