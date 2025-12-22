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

TC : O(nums.size())
SC : O(2 * nums.size()) // O(nums.size());

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


