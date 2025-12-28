Simple Traversal Based Problems :

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

Hashmap/Hashset Based Problems : 

1. Contains Duplicates
// https://leetcode.com/problems/contains-duplicate/description/

// Input: nums = [1,2,3,1]
// Output: true
// Explanation:
// The element 1 occurs at the indices 0 and 3.

// Approach 1 : 
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for(int key : nums)
            map[key]++;

        for(auto const& entry  : map) {
            if(entry.second > 1) 
                return true;
        }

        return false;
    }
}; 

// TC : O(nums.size())
// SC : O(nums.size())

// Approach 2 :
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for(int i : nums) {
            map[i]++;
            if(map[i] > 1)
                return true;
        }
        return false;
    }
}; 

// TC : O(nums.size())
// SC : O(nums.size())

// Approach 3 : (Hashset)
// Since we do only focus on if the element already exists, the usage of **hash set** is preferred.
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for(int i : nums) {
            if(set.count(i))
                return true;

            set.insert(i);
        }
        return false;
    }
}; 

// TC : O(nums.size())
// SC : O(nums.size())

2. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/

// Input: s = "anagram", t = "nagaram"
// Output: true

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Criteria 1 : The lengths should be the same
        if(s.size() != t.size()) 
            return false;

        // Criteria 2 : Total number of distinct elements and the cccurences of each distinct 
        //              elements should be the same
        unordered_map<char, int> count;
        for(char c : s) 
            count[c]++;
        
        int countDistinct = count.size(); // Very important setup

        for(char c : t) {
            if(count.find(c) != count.end()) {
                count[c]--;
                if(count[c] == 0) 
                    countDistinct--;
            }
        }

        if(countDistinct == 0) return true;
        return false;
    }
};

// TC : O(s.size() + t.size())
// SC : O(count.size())

Problem 3. Two Sum (Returning the pair of indices)
// https://leetcode.com/problems/two-sum/submissions/1862279977/

// Brute Force Approach : 
// Check for all possible/eligible pairs
// TC : O(n^2), SC : O(1)

// Optimised Approach Using Hashmap : 
// Cue : Store each element with its index in the map.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // Store each element with its index in the map.

        for(int i = 0; i < nums.size(); i++) {
            // Step 1 : For each element, find the need
            int need = target - nums[i]; 

            // Step 2 : Check if the need is present in the map and process accordingly
            if(map.find(need) != map.end()) {
                return {map[need], i};
            }

            // Step 3 : 
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

Problem 13 : Top k frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/submissions/1863622360/

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Cue : "Map the count, flip the pair, sort the air."
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

Problem 14 : Encode and Decode Strings

class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for(string s : strs) {
            for(char c : s) {
                res.push_back(c);
            }
            res.push_back((char)0xFFFFFF);
        }
        return res;
    } // TC : O(strs.size() * k) // SC : O(1)
    
    vector<string> decode(string s) {
        vector<string> res;
        string curr;

        for(char c : s) {
            if(c == (char)0xFFFFFF) {
                res.push_back(curr);
                curr = {};
            } else {
                curr.push_back(c);
            }
        }
        return res;
    } // TC : O(s.size()) // SC : O(s.size())
};

======================================================================================================================
// Prefix Sum and Difference Array concepts.
void prefixSum(const vector<int>& nums, int k) {
    vector<int> prefixSum(nums.size());
    
    prefixSum[0] = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    
    while(k--) {
        int l, r; // Check if this is 1 or 0 based to use accordingly. Also, look at the constraints before accessing them to avoid out of bounds
        cin >> l >> r; 
        
        int subarraySum = prefixSum[r];
        if(l > 0) 
            subarraySum -= prefixSum[l-1];
    }
} // TC : O(N), SC : O(1)

void differenceArray(const vector<int>& nums, int k, int x) {
    vector<int> differenceArray(nums.size());
    
    differenceArray[0] = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        differenceArray[i] = nums[i] - nums[i-1];
    }
    
    while(k--) {
        int l, r; // Check if this is 1 or 0 based to use accordingly. Also, look at the constraints before accessing them to avoid out of bounds
        cin >> l >> r;
        
        differenceArray[l] += x;
        if(r + 1 < nums.size()) 
            differenceArray[r+1] -= x;
    }
    
    // Calculate prefixSum
    vector<int> prefixSum(nums.size());

    prefixSum[0] = differenceArray[0];
    for(int i = 1; i < nums.size(); i++) {
        prefixSum[i] = prefixSum[i-1] + differenceArray[i];
    }
    
    for(int i = 0; i < prefixSum.size(); i++) {
        cout << prefixSum[i] << " ";
    }
    
    cout << endl;
} // TC : O(N + K); SC : O(N)

=========================================================================================================================
Problem 15. Range Sum Query 2D Immutable 

class NumMatrix {
private:
    // Move this to private scope so all methods can see it
    vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        // Construction of prefix sum matrix
        int rows = matrix.size();
        int columns = matrix[0].size();

        // Initialize the member variable
        prefixSum.assign(rows, vector<int>(columns, 0));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                prefixSum[i][j] += matrix[i][j];
                if(i > 0) prefixSum[i][j] += prefixSum[i-1][j];
                if(j > 0) prefixSum[i][j] += prefixSum[i][j-1];
                if(i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int rectangleSum = prefixSum[row2][col2];
        if(row1 > 0) rectangleSum -= prefixSum[row1-1][col2];
        if(col1 > 0) rectangleSum -= prefixSum[row2][col1-1];
        if(row1 > 0 && col1 > 0) rectangleSum += prefixSum[row1-1][col1-1];

        return rectangleSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

// Complexity Check :
// Construction (Time): O(rows * columns);
// Queries (Time) : O(1)
// (Space) : O(rows * columns)

Problem 16. Product of Array Except Self

// Brute Force Approach : (Only works if no input number is 0)

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int prefixProduct = 1;

//         // Construct PrefixProduct
//         for(int i = 0; i < nums.size(); i++) {
//             prefixProduct *= nums[i];
//         }

//         vector<int> productExceptSelf(nums.size());
//         for(int i = 0; i < nums.size(); i++) {
//             productExceptSelf[i] = prefixProduct / nums[i];
//         }

//         return productExceptSelf;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(nums.size());

        // Step 1: Calculate Prefix Products
        // res[i] will contain the product of all elements to the left of i
        res[0] = 1; // Very important
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        // Step 2: Calculate Suffix Products on the fly
        int suffixProduct = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= suffixProduct; // Multiply left product by right product
            suffixProduct *= nums[i]; // Update suffix for the next element
        }

        return res;
    }
};

// TC : O(nums.size())
// SC : O(1)

Problem 18. Longest Consecutive Sequence
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Build the set for O(1) lookups
        unordered_set<int> s(nums.begin(), nums.end()); // This set stores every unique number from the input array
        int longest = 0;

        for(int num : s) {
            if(s.find(num-1) == s.end()) {
                int currNum = num;
                int currentStreak = 1;

                while (s.find(currNum + 1) != s.end()) {
                    currNum += 1;
                    currentStreak += 1;
                }

                longest = max(longest, currentStreak);
            } // else skip it as that number is not the start of the sequence.

        }
        return longest;
    }
};

// TC : O(N) (for set creation) + 
//      O(N) (for 'for' loop) + 
//      O(N) (for 'while' loop as while loop runs only N times across the entire program)

// SC : O(N)

Problem 20. Majority Element ii
// https://leetcode.com/problems/majority-element-ii/description/

Input: nums = [3,2,3]
Output: [3]
    
// Hashmap + Hashset Approach :
// Convert Hashset to Array and return.
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int, int> map;
//         set<int> result;

//         for(int val : nums) {
//             map[val]++;

//             if(map[val] > nums.size()/3) {
//                 result.insert(val);
//             }
//         } 
//         return vector<int>(result.begin(), result.end());
//     }
// };

// TC : O(nums.size())
// SC : O(nums.size())

// Space Optimised Approach : 
// The Underlying Approach: (Elimination Logic)

// -- The Boyer-Moore Majority Vote algorithm is based on a simple observation:

// -- To find an element that appears more than 1/k times, you can at most have k-1 such elements.
// For this specific problem (k=3), we seek elements appearing > n/3 times. There can be at most two such elements.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        // At most two elements can appear more than n/3 times.
        // We initialize two candidates and two counters.
        int cand1 = 0, cand2 = 1; 
        int count1 = 0, count2 = 0;

        // Phase 1: The Elimination Pass
        for (int num : nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                // If slot 1 is empty, current num becomes candidate 1
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                // If slot 2 is empty, current num becomes candidate 2
                cand2 = num;
                count2 = 1;
            } else {
                // We found 3 distinct numbers (cand1, cand2, and current num).
                // "Throw away" one instance of each by decrementing counts.
                count1--;
                count2--;
            }
        }

        // Phase 2: The Verification Pass
        // Boyer-Moore only guarantees that the majority elements (if they exist)
        // will be the survivors. We must check if they actually meet the n/3 limit.
        vector<int> result;
        int verify1 = 0;
        int verify2 = 0;

        for (int num : nums) {
            if (num == cand1) verify1++;
            else if (num == cand2) verify2++;
        }

        if (verify1 > n / 3) result.push_back(cand1);
        if (verify2 > n / 3) result.push_back(cand2);

        return result;
    }
};

// TC : O(n)
// SC : O(1)

Problem 21. Subarray Sum Equals K // (Assume the input might contain negative numbers also)
// Prefix Sum + Hashmap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen[0] = 1;

        int prefix = 0;
        int totalSubarrays = 0;

        for(int val : nums) {
            prefix += val; 

            int need = prefix - k;

            if (seen.find(need) != seen.end()) {
                totalSubarrays += seen[need];
            }

            seen[prefix]++;
        }

        return totalSubarrays;
    }
};

Problem 2 : First Missing Positive
// https://leetcode.com/problems/first-missing-positive/

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

// Approach : 
// "Map the Value to the Index, then find the first misfit."

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Part 1: Place numbers in their correct "buckets"
        for (int i = 0; i < nums.size(); i++) {
            // Use a while loop because the swapped number 
            // also needs to be placed correctly.
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                // Correct position for value x is index x-1
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Part 2: Scan for the first mismatch
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // Part 3: If all numbers 1 to n are present, return n + 1
        return nums.size() + 1;
    }
};

// TC : O(nums.size())
// SC : O(1)
