class Solution {
public:
    bool backtrack(
    vector<vector<char>>& board,//所有可選擇的
    string& word,
    int row,
    int col,
    int index
){
    // 超出 board 範圍
    if (row < 0 || row >= board.size() ||
        col < 0 || col >= board[0].size()) {
        return false;
    }
    // 不是我要找的
    if(board[row][col]!=word[index]){
        return false;
    }
    // 成功找到
    if(index==word.size()-1){
        return true;
    }
    // 做選擇：標記目前這格已經使用
    char temp = board[row][col];
    board[row][col] = '#';

    // 往上下左右找下一個字
    bool found =
        backtrack(board, word, row - 1, col, index + 1) ||
        backtrack(board, word, row + 1, col, index + 1) ||
        backtrack(board, word, row, col - 1, index + 1) ||
        backtrack(board, word, row, col + 1, index + 1);
    /*還差一個超重要問題，不能這樣：
    A → B
    ↑   ↓
    └── A
    走出去之後又回頭使用同一格。所以我們需要記錄：這格我目前已經走過了。
    最常見的方法之一，是暫 時修改 board，代表這格正在使用中，不准再走。*/
    

    // 撤銷選擇
    board[row][col] = temp;
    // ⑦ 把搜尋結果告訴上一層
    return found;
}
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {

                if (backtrack(board, word, row, col, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
