** Problem : -**

Given an array arr. Find the majority element in the array. If no majority exists, return -1.
A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.

Examples:

1. Input: arr[] = [3, 1, 3, 3, 2]
Output: 3
Explanation: Since, 3 is present more than n/2 times, so it is the majority element.

2. Input: arr[] = [7]
Output: 7
Explanation: Since, 7 is single element and present more than n/2 times, so it is the majority element.

3. Input: arr[] = [2, 13]
Output: -1
Explanation: Since, no element is present more than n/2 times, so there is no majority element.

** Code :- **

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        if(arr.size() == 1) {
            return arr[0];
        }
        for (int i=0; i<arr.size(); i++){
            int count=1;
            int n=arr.size()/2;
            for(int j=0; j<arr.size(); j++){
                if(i==j) {
                    continue;
                }
                if(arr[i]==arr[j]) {
                    count++;
                }
                if(count > n) {
                    return arr[i];
                }
            }
        }
        return -1;
    }
};

** Time Complexity : - **
  
Outer Loop:
The outer for loop iterates through all elements of the array, i.e., O(n).
Inner Loop:
For each iteration of the outer loop, the inner loop checks all other elements to count occurrences. This takes O(n) for each iteration of the outer loop.

Overall Complexity:
The combined complexity of the nested loops is: O(n)×O(n)=O(n2)
Inefficiency:
The implementation is inefficient due to the nested loops, making it impractical for large arrays.

** Space Complexity :- **
  
Auxiliary Variables:
A few integer variables (count, n, and loop counters) are used, which require constant space: O(1).
No Additional Data Structures:
The algorithm does not use extra memory for data structures.

Overall Space Complexity:
The total space complexity is: O(1)
