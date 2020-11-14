/*
leetcode NO.860 柠檬水找零
解题思路：贪心算法

时间复杂度：O(n)
空间复杂度：O(1)
*/

class solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (const auto bill : bills) {
            switch (bill) {
                case 5:
                    five++;
                    break;
                case 10:
                    five--;
                    ten++;
                    break;
                case 20:
                    if (ten) {
                        ten--;
                        five--;
                    } else {
                        five -=3;                    
                    }
                    break;
                default:
                    break;
            }

            if (five < 0) return false;
        }

        return true;
    }

};