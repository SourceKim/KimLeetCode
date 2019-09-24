/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (44.76%)
 * Likes:    1027
 * Dislikes: 363
 * Total Accepted:    270.2K
 * Total Submissions: 602.8K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being 
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 * 
 * 
 */

// #include <vector>
// #include <stdio.h>
// #include <iostream>
// using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {

        const int len = 9;
        const int numCount = 10;

        bool row[len][numCount] = {false};
        bool col[len][numCount] = {false};
        bool sb[len][numCount] = {false};

        for (int i=0; i<len; i++) { // col
            for (int j=0; j<len; j++) { // row
            // c[]
                char c = board[i][j]; // 第 i 行，第 j 列
                if (c == '.') {
                    continue;
                }
                int intFromC = c - 48;
                // cout << i << "," << j << endl;
                // cout << intFromC << endl;

                // row check
                bool rowRes = row[i][intFromC];
                if (rowRes) {
                    // cout << i << " == c == " << j << endl;
                    return false;
                } else {
                    row[i][intFromC] = true;
                }

                // col check
                bool colRes = col[j][intFromC];
                if (colRes) {
                    // cout << i << " == b == " << j << endl;
                    return false;
                } else {
                    col[j][intFromC] = true;
                }

                // sub-box check
                bool sbRes = sb[j / 3 * 3 + i / 3][intFromC];
                // cout << i << " == " << j / 3 * 3 + i / 3 << " == " << j << endl;
                if (sbRes) {
                    // cout << i << " ==  == " << j << endl;
                    return false;
                } else {
                    sb[j / 3 * 3 + i / 3][intFromC] = true;
                }
            }
        }

    // for (int i=0; i<9; i++) {

        // for (int j=0; j<10; j++) {
        //     cout << col[0][j] << endl;
        // }
    // }
        
        return true;
    }

};

// int main(int argc, char const *argv[])
// {
//     char test[9][9] = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
//     vector<vector<char> > b;
//     for (int i=0; i<9; i++) {

//         vector<char> tb;
//         for (int j=0; j<9; j++) {

//             tb.push_back(test[i][j]);
//         }
//         b.push_back(tb);

//     }
//     Solution *sol = new Solution();
//     bool res = sol->isValidSudoku(b);
//     cout << res << endl;

//     return 0;
// }

