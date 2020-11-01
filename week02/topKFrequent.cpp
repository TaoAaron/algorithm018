/*
NO.347 前K个高频元素
    hash map 存储：key 元素； value 元素出现的次数
    优先队列：最小堆装载map里内容
    大于K后，开始pop掉小的


    时间复杂度：O(Nlogk)，其中 N为数组的长度。我们首先遍历原数组，并使用哈希表记录出现次数，每个元素需要 O(1) 的时间，
    共需 O(N) 的时间。随后，我们遍历「出现次数数组」，由于堆的大小至多为 k，因此每次堆操作需要 (logk) 的时间，
    共需O(Nlogk) 的时间。O(Nlogk)。
    空间复杂度：O(N)。哈希表的大小为 O(N)，而堆的大小为 O(k)，共计为 O(N)。
    

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (auto i : nums) map[i]++;   // key：nums中的值， value：出现的频次

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;

        for (auto it : map) {
            if (que.size() == k) {
                if (it.second > que.top().first) {  //出现的频次进行比较
                    que.pop();  //等于k后，pop掉最小的
                    que.push(make_pair(it.second,it.first));
                }
            } else {
                que.push(make_pair(it.second,it.first));
            }      
        }

        vector<int> res;

        while (que.size()) {
            res.push_back(que.top().second);
            que.pop();
        }

        return vector<int>(res.rbegin,res.rend());  //因为小顶堆先弹出的是最小的，所以倒叙来输出到数组，频次最高的放前面
    }

};