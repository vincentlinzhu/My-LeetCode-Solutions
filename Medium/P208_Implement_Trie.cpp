struct Node {
    map<char, Node*> children;
    bool end = false;
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->children.count(word[i])) {
                curr->children[word[i]] = new Node();
            } 
            curr = curr->children[word[i]];
        }
        curr->end = true;
    }

    bool search(string word) {
        //Needs to also be the end of the word
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->children.count(word[i])) {
                return false;
            } 
            curr = curr->children[word[i]];
        }
        return curr->end;
    }

    bool startsWith(string prefix) {
        //Does not need to be the end of the word
        Node* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!curr->children.count(prefix[i])) {
                return false;
            } 
            curr = curr->children[prefix[i]];
        }
        return true;
    }
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/