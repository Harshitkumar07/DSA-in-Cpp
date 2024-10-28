class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != ptr) {
                    swap(nums[i], nums[ptr]);
                }
                ptr++;
            }
        }
    }
};
