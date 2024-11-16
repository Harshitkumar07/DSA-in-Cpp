** Leetcode Problem 1552:- **

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i].
Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.

Example 1:
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

Example 2:
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.

** Code :- **

class Solution {
public:
    bool isPossible(vector<int>& position, int m, int minAllowed) {
        int balls = 1, lastBasket = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastBasket >= minAllowed) {
                balls++;
                lastBasket = position[i];
            }
            if (balls == m) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int st = 1, end = position.back() - position.front(), ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isPossible(position, m, mid)) {
                ans = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

** Time Complexity **
Sorting the position Array: Sorting the array takes O(nlogn), where n is the number of elements in the position array.

Binary Search: The binary search is performed on the range of possible minimum distances, which spans from 1 to maxAllowed, where: maxAllowed=position.back()−position.front()
The binary search has a time complexity of O(log(maxAllowed)).
Feasibility Check with isPossible: For each binary search iteration, the isPossible function is called, which traverses the position array. This takes O(n) time.

Overall time complexity: O(nlogn)+O(log(maxAllowed)⋅n)
Since log(maxAllowed) is typically much smaller than n, the sorting step dominates for large n. Thus, the time complexity can be approximated as: O(nlogn)

** Space Complexity **
The algorithm uses O(1) extra space since no additional data structures are used apart from a few variables for binary search and iteration.
Sorting is performed in-place, requiring no additional memory.
Thus, the space complexity is: O(1)
