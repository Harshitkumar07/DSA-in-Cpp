class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //By Binary Search Method
        int n = nums.size();
        int m = n + 1;
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (mid == 0 || mid == n - 1) {
                break;
            }
            if (nums[mid] != nums[mid + 1] && nums[mid - 1] != nums[mid]) {
                break;
            }        
            if (mid % 2 == 0) {
                if (nums[mid + 1] == nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (nums[mid - 1] == nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return nums[mid];
    }
};
  OR
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //By XOR method
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};
