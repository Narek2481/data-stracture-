#include <iostream>
using namespace std;

class Node {
public:
    int kay;
    int data;
    Node *next;
    Node *prev;
    Node(){
        this->kay = 0;
        this->data = 0;
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int k, int d){
        this->kay = k;
        this->data = d;
    }
};

class Doubly_link_list{
public:
    Node *head;

    Doubly_link_list(){
        this->head = NULL;
    }

    Doubly_link_list(Node *n){
        this->head = n;
    }
    
    Node* node_exists(int k ){
        Node *temp = NULL;
        Node *ptr = this->head;
        while(ptr!=NULL){
            if(ptr->kay==k){
                temp = ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }

    void append_node(Node* n){
        if(node_exists(n->kay)!=NULL){
            cout<< n->kay<< "arten ka "<< endl;
        }else{
            if(this->head==NULL){
                this->head = n;
            }else{
                Node* ptr=this->head;
                while(ptr->next!=NULL){
                    ptr = ptr->next;
                }
                ptr->next=n;
                n->prev=ptr;
                cout<< "Node-y kcac e";
            }
        }
    }

    void prepend_node(Node* n){
        if(node_exists(n->kay)!=NULL){
            cout<< n->kay<< "arten ka "<< endl;
        }else{
            if(this->head==NULL){
                this->head = n;
            }else{
                this->head->prev=n;
                n->next = this->head;

                this->head = n;
                cout<< "Node-y kcac e";
            }
        }
    }

    void insert_node_after(int k ,Node* n){
        Node* ptr = node_exists(k);
        if(ptr==NULL){
            cout<< "trvac kay ov element chka"<< endl;
        }else{
            if(node_exists(n->kay)!=NULL){
                cout<< n->kay<<"poxancac elementy arten ka"<< endl;
            }else{
                if(node_exists(n->kay)!=NULL){
                    cout<< "node-y goyutyun chuni "<< n->kay <<endl;
                }else{
                    cout<< "inserting" << endl;
                    Node *next_node = ptr->next;
                    if(next_node== NULL){
                        ptr->next=n;
                        n->prev=ptr;
                        cout<< "node -y drvec verchun "<< endl;
                    }else{
                        n->next=next_node;
                        next_node->prev=n;
                        n->prev=ptr;
                        ptr->next=n;
                        cout<<"node-y drvec nranc mijev"<<endl;
                    }
                }
            }
        }
    }

    void delete_node_by_kay(int k ){
        Node *ptr= node_exists(k);
        if(ptr==NULL){
            cout<< k << "ayspisi kay-ov element chka"<< endl;
        }else{
            if(this->head->kay ==k){
                this->head = this->head->next;
            
            }else{
                
                Node *next_node = ptr->next;
                Node *prev_node = ptr->prev;
                if(ptr->next != NULL){
                    prev_node->next = next_node;
                    next_node->prev = prev_node;
                }else{
                    prev_node->next = NULL;
                }
                   
                
            }
        }
    }

    void printList() {
    if (this->head == NULL) {
      cout << "datark e";
    }else {
      cout << endl << "Doubly Linked List arjeqnery : "<<endl;
      Node *temp = this->head;

      while (temp != NULL) {
        cout<< temp->kay<<"  kay,"<< temp->data<<"  data,"<< "<-->"<<endl;
        temp = temp->next;
      }
    }

  }


};

int main(){
    Doubly_link_list obj;
    obj.append_node(new Node(1,10));
    obj.append_node(new Node(2,22));
    obj.append_node(new Node(3,22));
    obj.append_node(new Node(3,12));
    obj.insert_node_after(2,new Node(4,12));
    obj.prepend_node(new Node(5,19));
    obj.delete_node_by_kay(2);
    obj.printList();
    


    return 0;
}