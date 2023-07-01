/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> checked;

public:
    Node* cloneGraph(Node* node) {
        //dfs: create a node if not there already
        // use recursion to continue the copy
        if (node == NULL) { //empty graph
            return NULL;
        }
        
        if (checked.find(node) == checked.end()) { //node not yet copied
            checked[node] = new Node;
            checked[node]->val = node->val;
            for (int i = 0; i < node->neighbors.size(); i++) {
                checked[node]->neighbors.push_back(cloneGraph(node->neighbors.at(i)));
            }
        }
        
        return checked[node];
    }
};