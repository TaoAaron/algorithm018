/*
NO.49 字母异位词 分组
对strs里的每个字符串进行排序，排序后的字符串作为k，排序前的字符串作为指，生成hash map

    时间复杂度：O(NKlogK)，其中N 是strs 的长度，而K是 strs 中字符串的最大长度。
    空间复杂度：O(NK)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> map;

        for (auto&s : strs) {
            string t = s;

            sort(t.begin(),t.end());

            map[t].push_back(s); //排序后的t作key, 原s作值            
        }

        for (auto&n : map) {
            res.push_back(n.second);
        }
    
        return res;
    }
    
};