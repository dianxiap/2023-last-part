#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = { 0 };
        for (auto e : s)
        {
            count[e - 'a']++;
        }
        for (auto e : t)
        {
            count[e - 'a']--;
        }
        for (auto e : count)
        {
            if (e != 0)return false;
        }
        return  true;
    }
};