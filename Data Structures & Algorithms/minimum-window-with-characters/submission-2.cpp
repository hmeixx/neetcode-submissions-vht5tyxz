class Solution {
public:
    string minWindow(string s, string t) {
        int l=0; int have=0; int minLen=INT_MAX;
        int start=0;
        unordered_map<char, int> need, window;
        for(char c:t){
            need[c]++;
        }
        
        for(int r=0;r<s.size();r++){
            window[s[r]]++;
            //如果window達標（這個"字元"是不是我們需要的和這個"字元"的數量剛好達標）e
            if(need.count (s[r]) && window[s[r]]== need[s[r]]){
                have++;
            }
            //所有條件滿足 ex:have=3（有a也有b也有c）
            while(have==need.size()){
                //記錄答案及是否更新答案
                if(r-l+1<minLen){
                    minLen= r-l+1;
                    start=l;
                }
                //嘗試縮小左邊
                window[s[l]]--;
                //檢查這個字元是不是原本剛好達標但現在被破壞了
                if(need.count(s[l]) && window[s[l]] < need[s[l]]){
                    have--;//因此跳出迴圈
                }
                l++;
            }
        }
        return minLen ==INT_MAX ? "" : s.substr(start,minLen);
    }
};
