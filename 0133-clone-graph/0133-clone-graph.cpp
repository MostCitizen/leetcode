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
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, Node*> map;
        unordered_map<int, bool> visits;
        Node* res = new Node(node->val);
        map[node] = res;
        clone(node, res, map, visits);
        return res;
    }
    void clone(Node* node, Node* res, unordered_map<Node*, Node*>& map, unordered_map<int, bool>& visits){
        if(visits[node->val]) return;
        visits[node->val] = true;
        for(int i=0;i<node->neighbors.size();i++){
            Node* cloneNode = node->neighbors[i];
            Node* newNode = nullptr;
            if(map.contains(cloneNode)){
                newNode = map[cloneNode];
            }else {
                newNode = map[cloneNode] = new Node(cloneNode->val);
            }
            res->neighbors.push_back(newNode);
            clone(node->neighbors[i], newNode, map, visits);
        }
    }
};