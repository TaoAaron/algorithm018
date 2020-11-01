/*
NO.242 有效的字母异位词

解法：把字母的值 当成哈希表的key 存入或取出 哈希表
    时间复杂度：O(n)
    空间复杂度：O(1)

    将字符串s,t分别排序，然后compare
    时间复杂度：O(nlogn) 排序算法sort的复杂度是nlogn的
    空间复杂度：O(1)

*/

bool isAnagram(char * s, char * t) {
    int m = strlen(s);
    int n = strlen(t);

    if (m != n) return false;

    int ch[26] = {0};

    for (int i=0; i<m; i++) {
        ch[s[i]-'a']++;
        ch[t[i]-'a']--;
    }

    for (int i=0; i<26; i++) {
        if( ch[i] != 0) return false;
    }

    return true;
}