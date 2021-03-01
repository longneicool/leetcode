/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 ) {
                break;
            }

            int front = i + 1;
            int back = nums.size() - 1;
            while(front < back) {
                if(front != i + 1 && nums[front] == nums[front-1]) {
                    front++;
                    continue;
                }

                if(back != nums.size() - 1 && nums[back] == nums[back+1]) {
                    back--;
                    continue;
                }

                int sum = nums[i] + nums[front] + nums[back];
                if(sum == 0) {
                    vector<int> v = vector<int>{nums[i], nums[front], nums[back]}; 
                    res.push_back(v);
                    front++;
                    back--;
                } else if (sum < 0) {
                    front++;
                } else {
                    back--;
                }
            }

        }

        return res;
    }
};
// @lc code=end

