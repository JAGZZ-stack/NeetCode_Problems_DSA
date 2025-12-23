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

5. Count the occurences of the anagrams 

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
