class LRUCache {
public:
    
    class node {
      public:  
      int key;
    int val;
    node *next;
    node *prev;
    
      node(int keey , int vaal)
      {
        key = keey;
        val = vaal;  
      }  
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    int cap;
    unordered_map<int,node*>m;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node * delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int keey) {
        if(m.find(keey)!=m.end())
        {
            node *tempnode = m[keey];
            int res = tempnode->val;
            m.erase(keey);
            deletenode(tempnode);
            addnode(tempnode);
            m[keey]=head->next;
            return res;
        }
        else{
            return -1;
        }
    }
    
    void put(int keey, int value) {
        if(m.find(keey)!=m.end())
        {
            node *existnode = m[keey];
            m.erase(keey);
            deletenode(existnode);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
            
        addnode(new node(keey,value));
        m[keey]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */