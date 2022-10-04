class MyLinkedList {
public:
    struct Node
    {
       int data;
       struct Node *next;
       Node(int val)
       {
           data = val;
           next = NULL;
       }   
    };  

    Node *head;
    int size;
  
    MyLinkedList() 
    {
        size = 0;
        head = NULL;
    }
    
    int get(int index) 
    {   
        if(index<0 or index>=size)return -1;
        Node *temp = head;
        while(temp and index)
        {
            temp = temp->next;
            index--;
        }
        return temp->data;
    }
    
      
  
    
    void addAtHead(int val) 
    {
       Node *newnode = new Node(val);
       newnode->next = head;
       head = newnode;
       size+=1;
    }
    
       
    void addAtTail(int val) 
    {   
        if(head==NULL)
        {
            head = new Node(val);
            size+=1;
            return;
        }
        Node *temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
        temp = temp->next;
        size+=1;
        return;
    }
   
    /*
    void addAtIndex(int index, int val)
    {        
         if(index < 0 || index >size )
             return;
         
           
        if(index == 0)
        {
            Node *newnode = new Node(val);
            newnode->next = head;
            head = newnode;
            size+=1;
        }
        else
        {
            Node*temp = head;
            Node *prev = head;
            while(index && temp)
            {
                prev = temp;
                temp = temp->next;
                index --;     
            }
            prev->next = new Node(val);
            prev = prev->next;
            prev->next = temp;
            size+=1;          
        }
    }
    */
    void addAtIndex(int index, int val)
    {
        if(index>size or index<0)return;
        if(index==0)
        {
            Node *newnode = new Node(val);
            newnode->next = head;
            head = newnode;
            size+=1;
            return;
        }
        Node *temp = head,*prev = temp;
        while(index and temp)
        {
            prev = temp;
            temp = temp->next;
            index--;
        }
        prev->next = new Node(val);
        prev = prev->next;
        prev->next = temp;
        size+=1;
        return;
    }
    
    /*
    void deleteAtIndex(int index) 
    {  
        if( size < 0 || index > size )
            return;
        
        if(index == 0)
        {
            head = head->next;
            size --;
        }
        else
        {
            Node *prev = head;
            Node *temp = head;
            
            while(index and temp)
            {
               prev = temp;
               temp = temp->next;
               index--;
            }
            prev->next = temp->next;
            delete temp;
            size -= 1;
     
        }
       
    }
    */
    void deleteAtIndex(int index) 
    {   
        if(index<0 or index>=size)return;
        if(index==0)
        {   
            head = head->next;
            size-=1;
            return;
        }
        Node *temp = head,*prev=NULL;
        while(index and temp)
        {
            prev = temp;
            temp = temp->next;
            index--;
        }
        prev->next = temp->next;
        delete temp;
        size -= 1;
        return;
    }

};
