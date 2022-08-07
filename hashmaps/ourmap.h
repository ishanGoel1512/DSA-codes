#include<string>
using namespace std;
template<typename V>
class mapNode
{
   
   public:
   string key;
   V value;
   mapNode *next;
    
    mapNode(string key , V value)
    {
        this->key = key ;
        this->value = value ;
        next = NULL;
    }
    ~mapNode()
    {
        delete next;
    }
};


template<typename V>
class ourmap
{
    mapNode<V>



};
