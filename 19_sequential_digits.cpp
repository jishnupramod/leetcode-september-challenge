/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
*/



class Solution {
private:
    int cntDigs(int low) {
        string s = to_string(low);
        return s.length();
    }
    int getAddOn(int digits) {
        int addOn = 0;
        for (int i=0; i<digits; ++i)
            addOn = addOn * 10 + 1;
        return addOn;
    }
    int getFirst(int low, int digits, int& addOn) {
        int first = 0;
        for (int i=1; i<=digits; ++i)
            first = first * 10 + i;
        while (first < low) {
            if (first % 10 == 0) {
                addOn = addOn * 10 + 1;
                return getFirst(low, digits+1, addOn);
            }
            first += addOn;
        }
        return first;
    }
    int findBase(int digits) {
        int base = 1;
        for (int i=0; i<digits-1; ++i)
            base *= 10;
        return base;
    }

public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> seq;
        int digits = cntDigs(low), addOn = getAddOn(digits), first = getFirst(low, digits, addOn);
        int num = first, base = findBase(digits);
        while (num <= high) {
            if (num % 10 == 0) {
                base *= 10;
                addOn += base;
                num = getFirst(low, ++digits, addOn);
            } else {
                seq.push_back(num);
                num += addOn;
            }
        }
        return seq;
    }
};
