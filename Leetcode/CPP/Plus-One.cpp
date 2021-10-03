// done by nikhildev23

//problem statement

/* You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits. */

// solution

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i] += carry;
                return digits;
            }
            else
            {
                digits[i] = 0;
                carry = 1;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};