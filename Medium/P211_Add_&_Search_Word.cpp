struct Node {
    map<char, Node*> children;
    bool end = false;
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (auto c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }
        curr->end = true;
    }
    
    bool dfs(string word, Node* start) {
        Node* curr = start; 
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (auto x : curr->children) {
                    if (dfs(word.substr(i + 1, word.size() - i - 1), x.second)) {
                        return true;
                    }
                }
                return false;
            } else if (!curr->children.count(word[i])) {
                return false;
            } 
            curr = curr->children[word[i]];
        }
        return curr->end;
    }

    bool search(string word) {
        return dfs(word, root);
    }
};