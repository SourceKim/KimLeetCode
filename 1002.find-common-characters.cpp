/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (68.75%)
 * Likes:    1724
 * Dislikes: 158
 * Total Accepted:    117.9K
 * Total Submissions: 171.4K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given a string array words, return an array of all characters that show up
 * in all strings within the words (including duplicates). You may return the
 * answer in any order.
 * 
 * 
 * Example 1:
 * Input: words = ["bella","label","roller"]
 * Output: ["e","l","l"]
 * Example 2:
 * Input: words = ["cool","lock","cook"]
 * Output: ["c","o"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] consists of lowercase English letters.
 * 
 * 
 */

/*
以第一个单词为准（最小频率基准），然后再遍历各个单词，更新出现最小频率表，比如：

bella & label & roller

设 minFreq 为各个字符出现的最小频率

首先获取第 1 个单词(bella)的字符频率，作为最小频率，得 freq = minFreq = 1a 1b 1e 2l

然后获取第 2 个单词(label)的字符频率，得 freq = 1a 1b 1e 2l，
更新最小频率 minFreq = 1a 1b 1e 2l

然后获取第 3 个单词(roller)的字符频率，得 freq = 1e 1o 2r 2l (0a)
更新最小频率 minFreq = 0a 0b 1e 2l 0o 0r

最后还原 minFreq = 1e 2l => ["e", "l", "l"]
*/

#include "helper/helper.hpp"

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<string> res;

        vector<int> minFreq (26, 0); // 字符最小频率的 map

        for (int i=0; i<words.size(); i++) { // 遍历每个单词

            vector<int> freq (26, 0); // （当前单词）每个字符出现的频率

            // 遍历每个单词的每个字符，并且统计每个字符出现的频率
            for (int j=0; j<words[i].size(); j++) { 
                freq[words[i][j] - 'a'] += 1;
            }

            //
            for (int k=0; k<26; k++) {
                // 最小频率以第一个单词为基准
                // 统计出每个字符的最小出现频率
                if (i==0) {
                    minFreq[k] = freq[k];
                } else {
                    minFreq[k] = min(minFreq[k], freq[k]);
                }
            }
        }

        // 最后从自小频率表，转化成 result，输出
        for (int i=0; i<26; i++) {
            for (int j=0; j<minFreq[i]; j++) {
                string str (1, i + 'a');
                res.push_back(str);
            }
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<string> words = { "bella","label","roller" };
    Solution *sol = new Solution();
    vector<string> res = sol->commonChars(words);
    return 0;
}

