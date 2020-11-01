/*
剑指offer 59 /主站 239
滑动窗口最大值
思路：
    通过维护一个单调的双端队列来求解
    头部大尾部小，每次取得的front就是滑动窗口的最大值
    重点：双端队列存储的是数组的index而不是值

时间复杂度：O(n)


*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;    //用来存结果的vector
        deque<int> dq;     
        
        for(int i=0; i<nums.size(); ++i)
        {   
            //step1：检查头部,是否pop
            if (!dq.empty() && dq.front()<i-k+1) {  //头部的index值 小于窗口边界
                dq.pop_front();
            }

            //step2: 检查尾部,是否pop
            while (!dq.empty() && nums[i]>nums[dq.back()]) {
                dq.pop_back();
            }

            //step3：加入尾部
            dq.push_bakc(i);
            
            //step4：返回最大值
            if(i>=k-1)  res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
