class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if nums1 size is 0, push everything from nums2 to nums1.
        if(nums1.size() == 0) {
            for(int i = 0; i < m; i++) nums1.push_back(nums2[i]);
            return;
        }        
        
        int size = m + n - 1;
        int n2 = n - 1;
        int n1 = m - 1;
        // if n1 = -1, replace all zeros in nums1 by nums2 elements.
        if(n1 == -1) for(int i = 0; i < n; i++) nums1[i] = nums2[i];
        
        // start filling nums1 from the back
        while(size >= 0) {
            if(n1 < 0 || n2 < 0) {
                if(n2 < 0) return;
                nums1[size] = nums2[n2];
                size--;
                n2--;
            } else if(nums1[n1] < nums2[n2]) { 
                nums1[size] = nums2[n2];
                size--;
                n2--;
            } else {
                nums1[size] = nums1[n1];
                nums1[n1] = nums2[n2];
                size--;
                n1--;
            }
        }
    }
};