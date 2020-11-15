/*
leetcode NO.45 跳跃游戏 Ⅱ
思路：贪心算法
重点在于何时去记录，跳跃的次数

时间复杂度：O(n)
空间复杂度：O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0;
        int ans = 0;    //记录走的步数
        int nextCover = 0; //下一步的覆盖范围

        for (int i = 0; i < nums.size() - 1; i++) {
            nextCover = max(i + nums[i], nextCover);

            if (i == nextCover) {
                curDistance = nextCover;
                ans++;  //记录步数
            }
        }
        return ans;
    }
};
