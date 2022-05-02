class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size() - 1;        
        digits[size] += 1;
        
        // if the value keeps adding up to or above 10, add 1 to the previous element
        while(size > 0 && digits[size] >= 10) {
            digits[size] = digits[size] % 10;
            size--;
            digits[size] += 1;
            
        }
        
        // if the first element is more than or equal to 10, add 1 to the beginning 
        // of vector
        if(digits[0] >= 10) {
            digits.insert(digits.begin(), 1, 1);
            digits[1] = digits[1] % 10;
        }
        
        return digits;
    }
};