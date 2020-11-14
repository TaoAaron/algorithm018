/*
leetcode NO.122 买卖股票的最佳时机 Ⅱ
解题思路：
    贪心算法 - 当下最优选择，只要下一天的价格高于当前天就
    进行交易获取利润

时间复杂度：O(n)
空间复杂度：O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                max += prices[i] - prices[i-1];
            }
        }

        return max;
    }
};