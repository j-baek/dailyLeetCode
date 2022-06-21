class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int curr = nums[0];
      
        // looked at the solution.
        /* bitwise XOR operator. Example shown below:
        nums = [4, 1, 2, 1, 2]
        4 = 0100
        1 = 0001
        2 = 0010
        
        4^1 = 0101 = 5
        5^2 = 0111 = 7
        7^1 = 0110 = 6
        6^2 = 0100 = 4
        
        If the same number appears twice, due to bitwise XOR, the bits that were 1 become 0.
        Therefore, the number that only appers once will survive.
        */
        
        for(int i = 1; i < nums.size(); i++) {
            curr = curr^nums[i];
        }
        
        return curr;
    }
};
