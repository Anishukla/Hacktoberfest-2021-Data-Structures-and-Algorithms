/* C++ implementation of LRU Cache */
/* Author: Rohit-Varma */
/* LRU Cache stands for least recently used cache */
/* Time complexity : O(1) for get operation since we use hash map for look up.
					 O(1) for each put operation, so if n times put is called it takes O(n) (amortized O(1) time) */
class LRUCache {

	private:
    list <int> nodes; //a linkedList container "nodes"
    
    /* To improve the time complexity of searching for a key through above list, 
	   we store the key-> (value,address) mappings in a map */
    unordered_map<int,pair<int,list<int>::iterator> > address_map;
    int capacity; //maximum capacity of the cache
    
    
    public:
    //Initialising the LRU cache	
    LRUCache(int max_size)
    {
        capacity=max_size;
    }
    //Checks if a key is present in the cache and returns its corresponding value.
    int get(int key) 
    {
        if(address_map.find(key)!=address_map.end())
        {
            nodes.erase(address_map[key].second);
            nodes.push_front(key);
            address_map[key].second=nodes.begin();
            return address_map[key].first;
        }
        else
            return -1;
    }
    
    // Inserts a {key,value} pair in the cache if its not already present, 
	// else brings that pair to the front of cache (core idea behind LRU page replacement algorithm).
    void put(int key, int value)
    {
        if(address_map.find(key)!=address_map.end())
        {
            nodes.erase(address_map[key].second); 
        }
        else
        {
            if(nodes.size()==capacity)
            {
                int last=nodes.back();
                nodes.pop_back();
                address_map.erase(last);
            }
        }
        nodes.push_front(key);
        address_map[key]={value,nodes.begin()}; 
    }
};
/**
  LRUCache object will be instantiated and called as follows:

  LRUCache* lru_Cache = new LRUCache(capacity);
  int param_1 = lru_Cache->get(key);
  lru_Cache->put(key,value);
  
 */
