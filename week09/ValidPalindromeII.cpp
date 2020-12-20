/*
leetcode 680 验证回文字符串Ⅱ

时间复杂度：O(n)
空间复杂度：O(1)

在删除字母后，考虑删除左边1个字符 和 右边1个字符 
这两种情况
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(string s, int left, int right) {

        while (left < right) {
            if (s[left] != s[right]) return false;
        }
        left++;
        right--;

        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return isPalindrome(s,left+1,right) || isPalindrome(s,left,right-1);
            }
        }
        return true;
    }
};
