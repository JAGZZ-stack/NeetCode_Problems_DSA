Problem 1. Concatenation of Array.
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

Problem 2. Contains Duplicates
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

Problem 3. Valid Anagram
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

Problem 4. Two Sum (Returning the pair of indices)
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

Problem 5. Longest Common Prefix
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

Problem 6. Remove Element - LeetCode
https://leetcode.com/problems/remove-element/submissions/1863586727/

// Two Requirements :
// -- Array should be modified in such a way that the first k elements do not contain the "val"
// -- Return total number of "non-val" elements.

// Approach :
// Two Pointers 
// (i -> representing the index where the next non-target element should be placed)
// (j -> for array traversal)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

// TC : O(nums.size())
// SC : O(1)

Problem 7. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// CUE : Group of Anagrams = Hashmap[sort[word]]
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string s : strs) {
            string word = s;
            sort(word.begin(), word.end());

            map[word].push_back(s);
        }

        vector<vector<string>> result;

        for(auto it : map) {
            result.push_back(it.second);
        }

        return result;
    }
};

// TC : O(n * k log k)
// SC : O(n * k) (Assuming total number of strings is n and each string has k characters)

Problems 8. Majority Element (The element which appears more than n/2 times)
// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;

        for(int val : nums) {
            map[val]++;
            if(map[val] > nums.size()/2) {
                return val;
            }
        }
        return 0;
    }
};

// TC : O(nums.size())
// SC : O(nums.size())

// Revisit/study during Leisure time
Problem 9 : Design HashMap // Rarely asked in interviews
Problem 10 : Design HashSet // Rarely asked in interviews
Problem 11 : Sort an array // Only study the STL inbuilt function as of now
Problem 12 : Sort Colors // Only study the STL inbuilt function as of now

Problem 13 : Top k frequent Elements LeetCode
// https://leetcode.com/problems/top-k-frequent-elements/submissions/1863622360/

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
    
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int val : nums) {
            map[val]++;
        }

        vector<pair<int, int>> arr;
        for (const auto& p : map) {
            arr.push_back({p.second, p.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;    
    }
};

// TC : O(n log n)
// SC : O(n)

