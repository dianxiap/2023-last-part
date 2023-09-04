#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int table[256] = { 0 };
        for (auto ch : s)
            table[ch]++;
        int count = 0;
        for (int i = 0; i < 256; i++)
        {
            if (table[i] % 2)count++;
            if (count > 1)return false;
        }
        return true;
    }

};