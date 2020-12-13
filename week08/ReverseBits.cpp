/*
leetcode 190 颠倒二进制位

时间复杂度：O(1)
空间付啊都：O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBit(uint32_t n) {
        uint32_t m = 0;

        for (int i = 31; i >= 0; i--) {
            m |= ((n >> (31-i)) & 1) << i;
        }
        return m;
    }

};