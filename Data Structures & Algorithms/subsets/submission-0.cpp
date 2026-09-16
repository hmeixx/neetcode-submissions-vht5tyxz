class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums,int index, vector<int>& cur){
        /*nums  = 所有可以選的數字，例如 [1,2,3]
        index = 現在正在考慮第幾個數字
        cur   = 目前已經選了哪些數字*/
        // ① 所有數字都決定完了
        if(index==nums.size()){
            result.push_back(cur);
            return;
        }
        // ② 不選 nums[index]
        backtrack(nums, index + 1, cur);

        // ③ 選 nums[index]
        cur.push_back(nums[index]);//選
        backtrack(nums, index+1, cur);//// 往下一層
        cur.pop_back();//撤銷選擇
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(nums,0,cur);
        return result;

    }
};
