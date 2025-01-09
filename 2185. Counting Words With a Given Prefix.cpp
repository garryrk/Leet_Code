class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;
        for (auto& it : words) {
            trie.insert(it);
        }
        return trie.checkPre(pref);
    }

private:
    class TrieNode {
    public:
        TrieNode* children[26];
        int cnt;

        TrieNode() {
            cnt = 0;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    class Trie {
    private:
        TrieNode* root;

    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(const string& s) {
            TrieNode* cur = root;
            for (auto& ch : s) {
                int index = ch - 'a';
                if (cur->children[index] == nullptr) {
                    cur->children[index] = new TrieNode();
                }
                cur = cur->children[index];
                cur->cnt++;
            }
        }

        int checkPre(const string& prefix) {
            TrieNode* cur = root;
            for (auto& ch : prefix) {
                int index = ch - 'a'; 
                if (cur->children[index] == nullptr) {
                    return 0; 
                }
                cur = cur->children[index];
            }
            return cur->cnt; 
        }
    };
};
