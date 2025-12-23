// Form 1 - Fixed Sized Template :

// Initialise all the necessary markers, necessary data structures to keep track of the data and the solution variables/data structures.
// while (right < nums.size()) :
    // Step 1 : For the current left and the right markers, update the data structures.
    // Step 2 : Shrink the left marker when needed and update the impact on the data structure
    // Step 3 : If the window is k-sized, update the solution.
    // Step 4 : Increment the right marker.
// Return the solution in the required format

Problem 1. Maximum Average Subarray.

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0; int right = 0;
        int currSum = 0; int maxSum = INT_MIN; 

        while(right < nums.size()) {
            // Step 1 : Allow always
            currSum += nums[right];
            
            // Step 2 : Can we remove..!?
            if(right >= k) {
                currSum -= nums[left];
                left++;
            }
            
            // Step 3 : Is it k-sized 
            if(right - left + 1 == k) {
                maxSum = max(maxSum, currSum);
            }
            right++;
        }
        return (double) maxSum / k;
    }
}; 

// TC : O(nums.size())
// SC : O(1)

Problem 2. Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        deque<int> deque; // keep the indices of the elements in the decreasing order
        vector<int> maxList;

        while(right < nums.size()) {
            while(!deque.empty() && nums[deque.back()] < nums[right]) {
                deque.pop_back();
            }

            deque.push_back(right);

            if(right >= k) {
                if(!deque.empty() && deque.front() == left) {
                    deque.pop_front();
                }
                left++;
            }

            if(right - left + 1 == k) {
                maxList.push_back(nums[deque.front()]);
            }

            right++;
        }
        return maxList;
    }
};

// TC : O(nums.size())
// SC : O(k); // The deque stores atmost k elements. We can ignore considering the space for maxList

Problem 3. First Negative Number of each subarray.
    
class Solution {
public:
    vector<int> solve(vector<int>& nums, int k) {
        int left = 0; 
        int right = 0;
        
        deque<int> deque;
        vector<int> list;

        while(right < nums.size()) {
            if(nums[right] < 0) {
                deque.push_back(right);
            }

            if(right >= k) {
                if(!deque.empty() && deque.front() == left) {
                    deque.pop_front();
                }
                left++;
            }

            if(right - left + 1 == k) {
                list.push_back(nums[deque.front()]);
            }
            
            right++;
        }
        return list;
    }
};

// TC : O(nums.size())
// SC : O(k); // The deque stores atmost k elements. We can ignore considering the space for maxList

Problem 4. Count the occurences of the anagrams 

// Input : text = "forxxorfxdofr", pattern = "for"
// Output : 3

class Solution {
  public:
    int search(string &pat, string &text) {
        // code here
        int k = pat.size();
        int left = 0; int right = 0;
        unordered_map<char, int> charFreq;
        for(char c : pat) charFreq[c]++;
        int countDistinct = charFreq.size();
        int anagramOccurences = 0;
        
        while(right < text.size()) {
            if(charFreq.find(text[right]) != charFreq.end()) {
                charFreq[text[right]]--;
                if(charFreq[text[right]] == 0) countDistinct--;
            }
            
            if(right >= k) {
               if(charFreq.find(text[left]) != charFreq.end()) {
                   charFreq[text[left]]++;
                   if(charFreq[text[left]] == 1) countDistinct++;
               } 
               left++;
            }
            
            if(right - left + 1 == k) {
                if(countDistinct == 0) {
                    anagramOccurences++;
                }
            }
            right++;
        }
        return anagramOccurences;
    }
};

// TC : O(pat.size() + text.size())
// SC : O(pat.size())

// Discussion - Form 2 :
// ---------------------
Problem 1. Find the longest subarray of all 1s with atmost k flips. 

// Longest - ask (It could be longest, shortest, count, sum of length).
// Subarray - what needs to be found (It could be subarray, max - min (gap)).
// atmost k flips - criteria (It could be any monotonic criteria) 
// Criteria - No. of 0s in (L -> R) <= k
//          - Also true for (L+1 -> R) <= k
//          - Criteria proved monotonic.

// Brute Force is O(n ^ 2).

// [0, 1, 0, 1, 0, 0, 1, 1, 0] 
// Head = -1; Tail = 0; Because we need the initial length to be zero.
// Think of a snake, it moves forward (head) and eats as many elements as it can.

// A. Template (TC : O(n))
// 1. For each position of tail, as long as it can contain atmost k 0s, keep incrementing the head unless you reach the end.
// 2. Calculate your answer for the range [Tail, Head].
// 3. For next iteration, move Tail one step ahead.

// B. Decide the Data structure.
// This is needed in order to quickly check if we can eat the next element or not.
// Here, a variable count should be enough for this problem.

// C. Decide the Answer :
// Here, max length is the ans. 
// So, ans = max(ans, Head - Tail + 1)

int solve(int[] nums, int k) {
    int head = -1; 
    int tail = 0;
    int count = 0; 
    int sol = 0;
    
    while(tail < nums.size() {
        // Step 1 : Keep eating as much as you can.
        while(head+1 < nums.size() && (count < k || (count == k && nums[head+1] == 1)) {
            head++;
            if(nums[head] == 0) count++;
        }

        // Step 2 : Update the answer
        sol = max(sol, head - tail + 1);

        // Step 3 : Move tail one step forward.
        if(tail <= head) {
            if(nums[tail] == 0) count--;
            tail++;
        } else {
            tail ++;
            head = tail - 1;
            count = 0; // Resetting the data structure.
        }
    }
    return sol;
}

// TC : O(nums.size())
// SC : O(1)
