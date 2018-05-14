/**
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

//time complexity: O(2n) = O(n), in worst case, each element will be visited twice; space complexity: O(m), m is the max_length of sub-string
//called sliding window approach
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if (0 == s.size()) {
            return 0;
        }
        
        unordered_set<char> h;
        int start_idx = 0;
        int end_idx = 0;
        int max_sub_len = 0;
        
        while (end_idx < s.size()) {
            //未找到说明不是最长子串，将新字符加入堆
            if (h.find(s[end_idx]) != h.end()) {
                //更新最长子串长度
                if (h.size() > max_sub_len) {
                    max_sub_len = h.size();
                }
                
                //将所有可能带来重复的字符去重
                while (h.find(s[end_idx]) != h.end()) {
                    h.erase(s[start_idx++]);
                }
            }
            h.insert(s[end_idx++]);
        }
        
        //最后再更新最长子串长度
        if (h.size() > max_sub_len) {
            max_sub_len = h.size();
        }
        
        return max_sub_len;
    }
};

//=======to do
//to realize optimized sliding window approach
