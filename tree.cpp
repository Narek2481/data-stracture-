#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(){
        this->data = 0;
        this->left = NULL;
        this->right= NULL;
    }
    Node(int d){
        this->data = d;
    }
};

class tree{

	struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

	Node* make_empty(Node* start) {
        if(start == NULL)
            return NULL;
        {
            make_empty(start->left);
            make_empty(start->right);
            delete start;
        }
        return NULL;
    }

	Node* insert(int value , Node* start) {
        if(start == NULL) {
            start = new Node;
            start->data = value;
            start->left = start->right = NULL;
        }
        else if(value < start->data) start->left = insert(value, start->left);
        else if(value > start->data) start->right = insert(value, start->right);
        return start;
    }

	Node* find_min(Node* start) {
		if(start == NULL) {
			return NULL;
		} else if(start->left == NULL) {
			return start;
		}
		return find_min(start->left);
	}


	Node* find_max(Node* start) {
		if(start == NULL) {
			return NULL;
		} else if(start->right == NULL) {
			return start;
		}
		return find_max(start->right);
	}

    void print_all(Node* start) {
        if(start == NULL) {
			return;
		}
        print_all(start->left);
        cout<< start->data<< endl;
        print_all(start->right);
    }

    Node* find(Node* start, int data) {
        if(start == NULL) {
			return NULL;
		} else if(start->left->data < data) {
			return find(start->right, data);
		}else {
            return find(start->left, data);
        }
    }

    Node* remove(int x, Node* t) {
        Node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = find_min(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }
public:
    tree() {
        root = NULL;
    }

    ~tree() {
        root = make_empty(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void console_log() {
        print_all(root);
    }

    void search(int data) {
        root =  find(root, data);
    }

};



int main() {
	tree x;
    x.insert(10);
    x.insert(9);
    x.insert(15);
    x.insert(17);
    x.insert(6);
    x.remove(10);
    x.console_log();
	return 0;
}