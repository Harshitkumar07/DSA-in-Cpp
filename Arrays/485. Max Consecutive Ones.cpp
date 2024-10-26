class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //Two pointer
        int count = 0;
        int notCount = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                notCount++;
            } else {
                count = max(count, notCount);
                notCount = 0;
            }
        }
        count = max(count, notCount);
        return count;
    }
};
