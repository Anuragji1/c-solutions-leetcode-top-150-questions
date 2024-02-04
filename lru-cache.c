**LRU Cache**

Problem Statement 68) Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.

-----------------------------------------------------------------------------------------------------
SOLUTION = #define HASH_SIZE 10001 // Based on key

typedef struct qnode {
    struct qnode *prev;
    struct qnode *next;
    int key;
    int data;
} Qnode;


typedef struct queue {
    Qnode *head;
    Qnode *tail;
    int count;
} Queue;



typedef struct {
    
    int capacity;
    Queue *queue;
    Qnode **hash;
} LRUCache;


Qnode *createnewnode(int key, int data)
{
      Qnode *temp = (Qnode *)malloc(sizeof(Qnode));
      temp->prev = NULL;
      temp->next = NULL;
      temp->key = key;
      temp->data = data;
      return temp;
}


Queue* createqueue(int numberofframes)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    // head and tail are dummy nodes
    queue->head = createnewnode(-1,0); 
    queue->tail = createnewnode(-1,0);
    queue->head->next = queue->tail;
    queue->tail->prev = queue->head;
    queue->count = 0;
    
    return queue;
}

Qnode ** createhash(int size)
{
    Qnode **hash = (Qnode **)malloc(size * sizeof(Qnode *));
    
    memset(hash, 0, size *sizeof(Qnode *)); // Initialize to NULL
    
    return hash;
}


void removeNode(LRUCache *cache, Qnode *node)
{
    Qnode *prev = node->prev;
    Qnode *next = node->next;
    
    prev->next = next;
    next->prev = prev;
}
// Add new node
void addNode(LRUCache *cache, Qnode *node)
{
    node->prev = cache->queue->head;
    node->next = cache->queue->head->next;
    
    cache->queue->head->next->prev = node;
    cache->queue->head->next = node;  
}

void movetohead(LRUCache *cache, Qnode *node)
{
    removeNode(cache,node);
    addNode(cache,node);
    
}

Qnode* popTail(LRUCache *cache)
{
    Qnode *node = cache->queue->tail->prev;
    removeNode(cache,node);
    return node;
}



LRUCache* lRUCacheCreate(int capacity) {
    
    LRUCache *lru = (LRUCache *)malloc(sizeof(LRUCache));
    lru->hash = createhash(HASH_SIZE);
    lru->queue = createqueue(capacity);
    lru->capacity = capacity;
    
    return lru;
}

int lRUCacheGet(LRUCache* obj, int key) {
  
    if(obj->hash[key] != NULL)
    {
        Qnode *node = obj->hash[key];
        int data = node->data;
        movetohead(obj,node);
        return data;
    }
    
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
  
   Qnode *node = obj->hash[key];
    
   if(!node)
   {
       node = createnewnode(key,value);
       obj->hash[key] = node;
       addNode(obj,node);
       obj->queue->count++;
       
       if(obj->queue->count > obj->capacity)
       {
           Qnode *tail = popTail(obj);
           obj->hash[tail->key] = NULL;
           obj->queue->count--;
       }
       
   }
   else{
        
       node->data = value; // update node value
       movetohead(obj,node);
    }
    
    
}

void lRUCacheFree(LRUCache* obj) {
    
    while(obj->queue->head)
    {
        Qnode * temp = obj->queue->head;
        obj->queue->head = obj->queue->head->next;
        free(temp);
    }
    
    free(obj->queue);
    free(obj->hash);
    free(obj);
    
}

----------------Explanation :-
