template<typename type>
class Queue{
    struct Node{
        type item;
        struct Node* next;
    };
public:
    Queue(){head=new Node;head->next=NULL;Front=Back=head;}
    ~Queue(){}
    void push(type item);
    type pop();
    type front();
    type back();
    bool isEmpty();
private:
    Node* head;
    Node* Front;
    Node* Back;
};

template<typename type>
void Queue<type>::push(type item){
    Node* newNode=new Node;
    newNode->item=item;
    newNode->next=NULL;
    Back->next=newNode;
    Back=newNode;
    if(head==Front){
        Front=Back;
        head->next=Front;
    }
}

template<typename type>
type Queue<type>::pop(){
    Node* ptr=head->next;
    head->next=ptr->next;
    type res=ptr->item;
    delete ptr;
    return res;
}

template<typename type>
type Queue<type>::front(){
    return head->next->item;
}

template<typename type>
type Queue<type>::back(){
    return back->item;
}

template<typename type>
bool Queue<type>::isEmpty(){
    return head->next==NULL;
}