/*
leetcode  NO.455 分配饼干
贪心算法：用尺寸最小的饼干尝试去满足胃口最小的
胃口值 g
饼干尺寸 s

时间复杂度：O(nlogn)
空间复杂度：O(1)
*/

class solutions {
public:
    int findContentChildren(vector<int>& g,m vector<int>& s) {
        
        int content = 0;
        int i = 0, j = 0;

        //first：对g,s排序
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while (i < g.size() && j < s.size()){ 
            if (g[i] <= s[i]) {
                i++;
                j++;
                content++;
            } else {
                j++; //换大的饼干
            }

        }
        return content;
    }
};