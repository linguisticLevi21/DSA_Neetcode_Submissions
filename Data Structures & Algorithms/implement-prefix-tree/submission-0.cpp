class PrefixTree {
public:
    struct trieNode {
        trieNode* children[26];
        bool isEndOfword;
    };

    trieNode* getnode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfword = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    trieNode* root;
    PrefixTree() { root = getnode(); }

    void insert(string word) {
        trieNode* crawler = root;
        for (char c : word) {
            int i = c - 'a';
            if (crawler->children[i] == NULL) {
                crawler->children[i] = getnode();
            }
            crawler = crawler->children[i];
        }
        crawler->isEndOfword = true;
    }

    bool search(string word) {
        trieNode* crawler = root;
        for (char c : word) {
            int i = c - 'a';
            if (crawler->children[i] == NULL) {
                return false;
            }
            crawler = crawler->children[i];
        }
        return crawler->isEndOfword;
    }

    bool startsWith(string prefix) {
        trieNode* crawler = root;
        int i = 0;
        for (; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';

            if (crawler->children[idx] == NULL) {
                return false;
            }

            crawler = crawler->children[idx];
        }
        if (i == prefix.length())
            return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */