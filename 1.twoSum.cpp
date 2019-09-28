/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> rtnV;

        for (int i=0; i<nums.size(); i++){ 

            for (int j=i+1; j<nums.size(); j++) {

                if (nums[i] + nums[j] == target) {

                    rtnV.push_back(i);
                    rtnV.push_back(j);
                    return rtnV;
                }
            }
        }

        return rtnV;
    }
};

