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
        if(node==NULL){
            return NULL;
        }

        Node* nn=new Node(node->val);
        queue<Node*> q;
        map<Node*,Node*> mp;
        mp[node]=nn;
        q.push(node);
        while(!q.empty()){
            Node* rv=q.front();
            q.pop();
            for(Node* nbrs: rv->neighbors){
                if(!mp.contains(nbrs)){
                    Node* clonenode = new Node(nbrs->val);
                    mp[nbrs]=clonenode;
                    q.push(nbrs);
                }
                mp[rv]->neighbors.push_back(mp[nbrs]);
            }
        }
        return nn;
    }
};