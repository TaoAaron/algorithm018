/*
NO 191 位1的个数
位运算
x = x & (x-1) 清零最低位的1
时间复杂度：O(1)
空间复杂度：O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n != 0) {
            n &= n - 1;
            count++;
        }

        return count;
    }
 
};