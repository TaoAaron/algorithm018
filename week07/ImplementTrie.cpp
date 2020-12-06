/*
leetcode 208 实现前缀树 
前缀树也就是字典树

时间复杂度：O(n)
空间复杂度：O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;

        for (char c : word) {
            if (node->next[c-'a'] == NULL) {
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;

    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node->next[c-'a'];
            if(node == NULL) return false;
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;

        for (char c : prefix) {
            node = node->next[c-'a'];
            if (node == NULL) return false;
        }
        return true;
    }
};