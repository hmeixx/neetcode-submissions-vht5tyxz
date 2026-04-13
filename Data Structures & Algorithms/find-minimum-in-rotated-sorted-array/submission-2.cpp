class Solution {
public:
    int findMin(vector<int> &nums) {
        // 因為旋轉後的陣列仍然具有部分排序性，可以視為兩段遞增序列拼接而成，
        // 而最小值位於兩段的分界點，因此可以透過比較中間值與邊界值來縮小搜尋範圍，達到 O(log n)。
        
        int left = 0;
        int right = nums.size()-1;
        int mid = (left+right)/2;
        // nums[mid] > nums[right] → 往右找
        // nums[mid] < nums[right] → 往左找
        // nums[mid+1]>nums[mid]
        while(left!=right){
            if(nums[mid]>nums[right]){
                left=mid+1;
            }
            else if(nums[mid]<nums[right]){
                right=mid;
            }
            mid = (left+right)/2;
        }
        
        
        return nums[mid];      
    }
};
