/*
leetcode 387 字符串中的第一个唯一字符
采用map的思想
    计算每个字母出现的频次
    找出出现的第一个频次为1的字母
时间复杂度：O(n)
空间复杂度：O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int result[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            result[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (result[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }

};