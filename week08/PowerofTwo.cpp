/*
leetcode 231 2的幂

时间复杂度O(1)
空间复杂度O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public :
    bool isPowerOfTwo(int n) {
        return n > 0 && (n && (n-1)) == 0;
    }
};

