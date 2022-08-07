class Node
{
    public:
    int data;
    Node *next;
    static int j;

    Node(int data)
    {
        this->data=data;
        next=NULL;
        j++;
    }
};
int Node ::j=0;