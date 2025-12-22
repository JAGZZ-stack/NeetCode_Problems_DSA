1. Concatenation of Array.
// https://leetcode.com/problems/concatenation-of-array/

// Input: nums = [1,2,1]
// Output: [1,2,1,1,2,1]

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> concatenatedArray(nums.size() * 2); 

        for(int i = 0; i < nums.size(); i++) {
            concatenatedArray[i] = nums[i];
            concatenatedArray[i+nums.size()] = nums[i];
        }

        return concatenatedArray;
    }
}; 

// TC : O(nums.size())
// SC : O(2 * nums.size()) // O(nums.size());

2. Contains Duplicates
// https://leetcode.com/problems/contains-duplicate/description/

// Input: nums = [1,2,3,1]
// Output: true
// Explanation:
// The element 1 occurs at the indices 0 and 3.

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int, int> freqMap;

//         for(int i = 0; i < nums.size(); i++) {
//             freqMap[nums[i]]++;
//             if(freqMap[nums[i]] > 1) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// Recommended Approach (HashSet) :
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (int i = 0; i < nums.size(); i++) {
            // Check if the current number is already in our set
            if (set.count(nums[i])) {
                return true;
            }
            // Add the current number to the set for future checks
            set.insert(nums[i]);
        }

        return false;
    }
};

TC : O(nums.size())
SC : O(nums.size())

3. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/

// Input: s = "anagram", t = "nagaram"
// Output: true

// Three important things to ensure a valid anagram:
// -- Lengths should be equal
// -- No characters should be uncommon
// -- Counts should be the same

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> map;
        for(char c : s) {
            map[c]++;
        }

        int countDistinct = map.size();

        for(char c : t) {
            if(map.find(c) == map.end()) {
                return false;
            } else {
                map[c]--;
                if(map[c] == 0) countDistinct--;
            }
        }
        if(countDistinct == 0) return true;
        return false;
    }
};

// TC : O(s.size() + t.size())
// SC : O(countDistinct)

4. Two Sum (Returning the pair of indices)
// https://leetcode.com/problems/two-sum/submissions/1862279977/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];

            if(map.find(remaining) != map.end()) {
                return {map[remaining], i};
            }

            map[nums[i]] = i;
        }
        return {};
    }
};

// TC : O(nums.size())
// SC : O(nums.size())

5. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/description/

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
    
// Vertical scanning Approach :
// -- Take the first string as a reference.
// -- Compare characters column-wise, stop at the first mismatch.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs[0].size(); i++) {
            char curr = strs[0][i]; // 0 - first string. 
                                    // 1 - ith char of that string

            for(int j = 1; j < strs.size(); j++) {
                // Case 1 : If i is greater than the current string length.
                if(i >= strs[j].size()) {
                    return strs[0].substr(0, i);
                }

                // Case 2 : If the characters do not match.
                if(curr != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

// TC : O(strs[0].size() * strs.size());
// SC : O(1)
