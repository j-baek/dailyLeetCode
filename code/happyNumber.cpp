class Solution {
public:
    bool isHappy(int n) {
        int num = 0;
        unordered_set<int> setNum;
        
        while(num != 1) {
            num = 0;
            while(n > 0) {
                num += pow((n % 10),2);
                n/=10;
            }
            // if num is found in set, that means it is stuck in the infinite loop, so return false
            if(setNum.find(num) == setNum.end()) setNum.insert(num);
            else return false;
            n = num;
        }
        return true;
    }
};