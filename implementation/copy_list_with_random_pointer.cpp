/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    class ListValue {
    public:
        int val;
        int next;
        int random;
        ListValue(int val, int next, int random)
        : val(val), next(next), random(random) { }
    };
public:
    int getDistance(Node *from) {
        int dist = 0;
        while(from != nullptr) {
            from = from->next;
            dist++;
        }

        return dist;
    }
    int listSize(Node* head) {
        int size = 0;
        while(head != nullptr) {
            head = head->next;
            size++;
        }

        return size;
    }
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }

        Node* forSize = head;
        int size = listSize(forSize);

        vector<ListValue> v;
        vector<Node*> newNodes;
        int nowIdx = 1;
        while(head != nullptr) {
            int val = head->val;
            int next = head->next == nullptr ? -1 : nowIdx++;
            int random = head->random == nullptr ? -1 : 0;

            if(random == 0) {
                Node* forDistance = head->random;
                random = size - getDistance(forDistance);
            }

            newNodes.emplace_back(new Node(val));
            v.emplace_back(ListValue(val, next, random));
            

            head = head->next;
        }

        Node* newHead = newNodes[0];
        Node* iter = newHead;
        for(int i=0; i<v.size(); i++) {
            iter->val = v[i].val;
            iter->next = v[i].next == -1 ? nullptr : newNodes[v[i].next];
            iter->random = v[i].random == -1 ? nullptr : newNodes[v[i].random];

            iter = iter->next;
        }
        return newHead;
    }
};
