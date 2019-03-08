template<typename type>
class Stack{
    struct Node{
        type item;
        struct Node* next;
    };
public:
    Stack(){head=new Node;head->next=NULL;}
    ~Stack(){}
    void push(type item);
    type pop();
    bool isEmpty();
    type top();
private:
    Node* head;
    Node* Top;
};

template<typename type>
void Stack<type>::push(type item){
    Node* newNode=new Node;
    newNode->next=head->next;
    head->next=newNode;
}

template<typename type>
type Stack<type>::pop(){
    Node* ptr=head->next;
    head->next=ptr->next;
    type res=ptr->item;
    delete ptr;
    return res;
}

template<typename type>
bool Stack<type>::isEmpty(){
    return head->next==NULL?true:false;
}

template<typename type>
type Stack<type>::top(){
    return head->next->item;
}