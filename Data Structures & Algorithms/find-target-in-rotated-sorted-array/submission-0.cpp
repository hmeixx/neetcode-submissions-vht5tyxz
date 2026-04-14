class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (target == nums[mid]) {
                return mid;
            }
             //如果左邊有序
            if (nums[l] <= nums[mid]) {
                //如果target在右邊區間
                if (target > nums[mid] || target < nums[l]) {
                    l = mid + 1;//就找右邊
                } 
                else {
                    r = mid - 1;
                }
            } 
            // 右邊有序
            else {
                if (target < nums[mid] || target > nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};