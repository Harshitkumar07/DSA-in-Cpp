class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int ans;
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }
        ans = n * (n + 1) / 2 - sum;
        return ans;
    }
};
