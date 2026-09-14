class Solution {
public:
    vector<vector<int>> result;
    //backtrack() 負責的是：「目前已經選了一些數字，接下來還能怎麼選？」
    //nums    → 有哪些數字可以選
    //target  → 目標，例如 9
    //sum     → 目前加到多少，例如 4
    //cur     → 目前選了什麼，例如 [2,2]
    /*backtrack()：負責「找答案 + 找到後存進 result」
    combinationSum()：負責「啟動搜尋 + 最後把 result 回傳」*/
    void backtrack(vector<int>& nums,int target, int sum, vector<int>& cur, int start) {
        // 1. sum == target 要做什麼？
        if(sum == target) {
            result.push_back(cur); 
            return;
        }
        // 2. sum > target 要做什麼？
        if(sum > target) {
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            // 做選擇 ①把 nums[i] 放進 cur。sum 加上 nums[i]
            cur.push_back(nums[i]);
            sum+=nums[i];
            // 往下搜尋 ②呼叫 backtrack
            backtrack(nums,target,sum,cur,i);
            // 撤銷選擇 ③backtrack 回來後，把剛才放進 cur 的數字拿掉
            sum-=nums[i];
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) { 
        vector<int> cur;

        // 從 sum = 0、start = 0 開始搜尋
        backtrack(nums, target, 0, cur, 0);

        return result;
    }
};
