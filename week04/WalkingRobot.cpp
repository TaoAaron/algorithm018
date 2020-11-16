/*
leetcode NO.874 模拟机器人行走
思路：
    1、如何定义：东南西北四个方向
    2、左转右转对应的坐标变化

时间复杂度：O(N+K) N是commands长度，K是obstacles的长度
空间复杂度：O(N) N是障碍物集合的大小
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //定义北、东、南、西 四个方向
        int dirX[] = {0,1,0,-1};
        int dirY[] = {1,0,-1,0};

        set<pair<int, int>> obstacleSet; //存储障碍点
        for (auto obstacle : obstacles) {
            obstacleSet.insert(pair(obstacle[0],obstacle[1]));
        }

        int curX = 0;
        int curY = 0;
        int curDir = 0;
        int ans = 0;

        //根据commands 行走
        for (auto command : commands) {
            if (command == -1) {    //右转90度，顺时针 + 1
                curDir = (curDir + 1) % 4;
            } else if (command == -2) { //左转90度， 顺时针 + 3
                curDir = (curDir + 3) % 4;
            } else {
                //每走1步都要检测是否遇到障碍
                for (int i = 0; i < command; i++) {
                    int newX = curX + dirX[curDir];
                    int newY = curY + dirY[curDir];

                    //判断是否是障碍点
                    if (obstacleSet.find(pair(newX,newY)) == obstacleSet.end()) {
                        curX = newX;
                        curY = newY;
                        ans = max(curX*curX + curY*curY, ans);
                    } else {
                        break;
                    }
                } 
            }
        }
        return ans;
    }
};