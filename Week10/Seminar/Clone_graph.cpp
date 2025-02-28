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
        if(!node)
            return node;
        unordered_map<Node*, Node*> visited;

        Node* head = new Node(node->val);
        queue<Node*> q;
        
        q.push(node);
        visited[node] = head;
        while(!q.empty())
        {
            Node* current = q.front();
            Node* newCurrent = visited[current];
            q.pop();
            for(int j = 0; j < current->neighbors.size(); j++)
            {
                Node* newNode;
                if(!visited.count(current->neighbors[j]))
                {
                    newNode = new Node(current->neighbors[j]->val);
                    visited[current->neighbors[j]] = newNode;
                    q.push(current->neighbors[j]);
                }
                else
                {
                    newNode = visited[current->neighbors[j]];
                }
                newCurrent->neighbors.push_back(newNode);
                //newNode->neighbors.push_back(newCurrent);
            }
        }
        return head;
    }
};