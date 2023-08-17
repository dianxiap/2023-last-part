#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        //��ͳ��a+b���ֵĴ���
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                mp[a + b]++;
            }
        }

        int count = 0;
        //����c��d
        //0-��c+d������a+b����a+b�Ƿ��ڹ�ϣ���г��ֹ���������ֹ����ͼ��ϳ��ֵĴ���
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                if (mp.find(0 - (c + d)) != mp.end())
                    count += mp[0 - (c + d)];
            }
        }
        return count;
    }
};