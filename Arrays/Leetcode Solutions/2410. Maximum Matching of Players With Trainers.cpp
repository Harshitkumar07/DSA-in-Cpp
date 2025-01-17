** Leetcode Problem 2410 :- **

You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. 
You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.
The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity.
Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.
Return the maximum number of matchings between players and trainers that satisfy these conditions.

Example 1: 
Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.

Example 2: 
Input: players = [1,1,1], trainers = [10]
Output: 1
Explanation:
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.

** Code :- **

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int playerIdx = 0, trainerIdx = 0, matches = 0;
        while (playerIdx < players.size() && trainerIdx < trainers.size()) {
            if (players[playerIdx] <= trainers[trainerIdx]) {
                matches++;
                playerIdx++;
            }
            trainerIdx++;
        }
        return matches;
    }
};

** Time Complexity :- **
    
Sorting :
Sorting the players and trainers arrays individually requires: O(m⋅logm)+O(n⋅logn) where m is the size of the players array and n is the size of the trainers array.
Two-Pointer Traversal :
The algorithm uses a two-pointer approach to traverse the sorted arrays.
Each pointer moves at most once for each element, resulting in a linear traversal of both arrays: O(m+n)
Total Time Complexity :
Best Case: O(m⋅logm+n⋅logn)
Sorting dominates the time complexity.
Worst Case: O(m⋅logm+n⋅logn)

** Space Complexity :- **
    
Sorting :
Sorting the arrays is usually implemented with in-place algorithms (e.g., quicksort or heapsort), requiring: O(1)
additional space for the sorting process.
Auxiliary Variables :
The algorithm uses three integer variables (playerIdx, trainerIdx, matches), requiring: O(1)
Total Space Complexity :
Best Case: O(1)
Worst Case: O(1)
