class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        string word;
    };

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode->isEnd = false;
        newNode->word = "";

        for (int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }

        return newNode;
    }

    TrieNode* root;

    void insert(string word) {
        TrieNode* crawler = root;

        for (char c : word) {
            int idx = c - 'a';

            if (crawler->children[idx] == nullptr) {
                crawler->children[idx] = getNode();
            }

            crawler = crawler->children[idx];
        }

        crawler->isEnd = true;
        crawler->word = word;
    }

    int m, n;
    vector<string> ans;

    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node) {

        // Boundary check
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;

        // Already visited
        if (board[i][j] == '#')
            return;

        char c = board[i][j];
        int idx = c - 'a';

        // Current character is not a valid Trie prefix
        if (node->children[idx] == nullptr)
            return;

        node = node->children[idx];

        // Complete word found
        if (node->isEnd) {
            ans.push_back(node->word);
            node->isEnd = false;  // Avoid duplicates
        }

        // Mark current cell as visited
        board[i][j] = '#';

        dfs(board, i + 1, j, node);
        dfs(board, i - 1, j, node);
        dfs(board, i, j + 1, node);
        dfs(board, i, j - 1, node);

        // Restore original character
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        root = getNode();
        ans.clear();

        m = board.size();
        n = board[0].size();

        // Insert all words into Trie
        for (string word : words) {
            insert(word);
        }

        // Start DFS from every board cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};