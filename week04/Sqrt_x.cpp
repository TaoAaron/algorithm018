/*
leetcode 69 x的平方根

思路1：直接用二分查找，确定其范围0~x之间， 选择上限x,下限0
    mid*mid 去 匹配targe x
    注意：题目只要求返回整数部分

    时间复杂度：O(logn) n为二分查找需要查找的次数
    空间复杂度：O(1)
*/

class soltion {
public:
    int mySqrt(int x) {
        //边界检测
        if (x == 0 || x ==1) return x;

        long left = 0, right = x; //左右边界

        while (left <= right) {
            long mid = left + (right-left)/2;

            if (mid*mid <= x) {
                left = mid + 1;
            } else {
                right = mid -1;
            }
        }
        return (int)right;
    }
};