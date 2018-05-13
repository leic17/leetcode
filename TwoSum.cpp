/********************************
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*********************************/

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //time complexity: O(n), space complexity: O(n)
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            hash.emplace(nums[i], i);
            auto iter = hash.find(target - nums[i]);
            if (iter != hash.end() && iter->second != i) {
                result.push_back(i);
                result.push_back(iter->second);
                return result;
            }
        }
        
        return result;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //time complexity: O(n^2), space complexity: O(1)
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        
        return result;
    }
};
