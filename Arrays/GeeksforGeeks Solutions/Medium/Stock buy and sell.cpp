** Problem :- **

Given an array are denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.
Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.

Examples:

1. Input: arr[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210 Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655 Maximum Profit  = 210 + 655 = 865

2. Input: arr[] = [4, 2, 2, 2, 4]
Output: 2
Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2

3. Input: arr[] = [4, 2]
Output: 0
Explanation: Don't Buy the stock.

** Code :- **

class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        vector<vector<int>> ans;
        for(int i=1;i<n;i++) {
            if(A[i]>A[i-1]){
                ans.push_back({i-1,i});
            }
        }
        return ans;
    }
};

** Time Complexity :- **

Single Pass through the Array:
The for loop iterates through the array A from index 1 to n−1, performing a constant-time comparison A[i]>A[i−1] and potentially adding a pair to the ans vector.
This operation takes O(n), where n is the size of the array.
Push Operation for Profitable Transactions:
Each profitable transaction (if found) involves a O(1) operation to add a pair of indices to the ans vector.

Overall Time Complexity:
The overall time complexity is: O(n)

** Space Complexity :- **

Auxiliary Space for the Result Vector (ans):
The ans vector stores pairs of indices for all profitable transactions. In the worst case (strictly increasing prices), the vector would store n−1 pairs, requiring O(n) space.
No Additional Data Structures:
Apart from the ans vector, the function uses a constant amount of extra space for variables like loop counters.

Overall Space Complexity:
The total space complexity is: O(n)
