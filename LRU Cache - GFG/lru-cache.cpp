//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    class Node{
        public:
        int val;
        int key;
        Node *prev;
        Node *next;
        Node(int x,int y){
            val=x;
            key=y;
            prev=NULL;
            next=NULL;
        }
    };
    int n;
    Node* head=new Node(0,0);
    Node* tail=new Node(0,0);
    unordered_map<int,Node*> m;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        n=cap;
        head->next=tail;
        tail->prev=head;
    }
    
    //Function to return value corresponding to the key.
    void add(Node* temp){
        temp->next=head->next;
        head->next->prev=temp;
        head->next=temp;
        temp->prev=head;
    }
    void del(Node* temp){
        Node* left=temp->prev;
        Node* right=temp->next;
        left->next=right;
        right->prev=left;
    }
    int GET(int key)
    {
        if(m.find(key)!=m.end()){
            int ans= m[key]->val;
            del(m[key]);
            add(m[key]);
            return ans;
        }
        else{
            return -1;
        }
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(m.find(key)!=m.end()){
            del(m[key]);
            add(m[key]);
            m[key]->val=value;
        }
        else if(n>0){
            Node* temp=new Node(value, key);
            m[key]=temp;
            add(temp);
            n--;
        }
        else{
            Node* temp=tail->prev;
            del(temp);
            m.erase(temp->key);
            delete(temp);
            Node* temp2=new Node(value,key);
            add(temp2);
            m[key]=temp2;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends