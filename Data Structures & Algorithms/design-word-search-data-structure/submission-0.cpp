class WordDictionary {
public:
    struct trieNode {
        bool isEnd;
        trieNode* children[26];
    };

    trieNode* getnode() {
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;

        for (int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }

        return newNode;
    }

    trieNode* root;
    WordDictionary() {
        root = getnode();
    }

    void addWord(string word) {
        trieNode* crawler = root;

        for (char c : word) {
            int i = c - 'a';

            if (crawler->children[i] == nullptr) {
                crawler->children[i] = getnode();
            }

            crawler = crawler->children[i];
        }

        crawler->isEnd = true;
    }

    bool dfs(trieNode* crawler, string& word, int idx) {
        if (idx == word.size()) {
            return crawler->isEnd;
        }

        char c = word[idx];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (crawler->children[i] != nullptr) {
                    if (dfs(crawler->children[i], word, idx + 1)) {
                        return true;
                    }
                }
            }

            return false;
        }

        int i = c - 'a';

        if (crawler->children[i] == nullptr) {
            return false;
        }

        return dfs(crawler->children[i], word, idx + 1);
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};