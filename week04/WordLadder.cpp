/*
leetcode NO.127 单词接龙
解题思路：广度优先搜索
    需要使用map记录 访问过的单词 以及 目前路径的深度

    时间复杂度：O(N*C^2) N是wordlist长度 C为单词的平均长度
    空间复杂度：O(N*C^2)
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //提速 将vector<string> 转成 set
        unordered_set<string> wordSet(wordList.begin(),wordList.end());

        //根据题意判定 endWord 不在wordList中直接return
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        //广度优先搜索定义队列
        queue<string> que;
        //记录visited 建立map
        unordered_map<string,int> map;

        que.push(beginWord);
        map.insert(pair<string,int>(beginWord,1)); //记录beginWord 为 visited

        while (!que.empty()) {
            string word = que.front(); //取队首
            que.pop();  //弹出
            int path = map[word]; //当前路径深度

            for (int i = 0; i < word.size(); i++) {     //遍历word的每个字母去替换
                string newWord = word;
                for (int j = 'a'; j <= 'z'; j++) {
                    newWord[i] = j;

                    if (newWord == endWord) return path + 1; //找到结尾了

                    //如果newWord 存在字典中 且 未被访问过 则 加入队列
                    if (wordSet.find(newWord) != wordSet.end() && map.find(newWord) == map.end()) {
                        que.push(newWord);
                        map.insert(pair<string,int>(newWord,path+1));
                    }
                }

            }
        }
        return 0;
    }

};