/*
    leetcode NO.55 跳跃游戏

    贪心算法：将问题模型转换，从最后一步往前看，看是否能跳回位置0

    时间复杂度：O(n)
    空间复杂度：O(1)
*/

class Solution{
public：
    bool canJump(vector<int>& nums) {
        int canReach = nums.size() - 1;

        //倒序 看
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] + i >= canReach) { //可以到达
                canReach = i;
            }
        }

        return canReach == 0;
    }
};