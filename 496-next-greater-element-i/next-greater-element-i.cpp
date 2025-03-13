class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // Mistake: Directly checking nums2[j+1] can go out of bounds.
                // Fix: We need a loop to find the next greater element.
                int nextGreater = -1;
                for (int k = j + 1; k < nums2.size(); k++) { // Find next greater element
                    if (nums2[k] > nums2[j]) {
                        nextGreater = nums2[k];
                        break;
                    }
                }
                nums1[i] = nextGreater; // Store the next greater element
                i++;  
                j = 0; // Mistake: Instead of j++, reset j to 0 to search nums2 from the beginning.
            } 
            else {
                j++; // Continue searching for nums1[i] in nums2
            }
        }

        return nums1;
    }

};