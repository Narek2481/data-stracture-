#include <iostream>
using namespace std;


template <class T>
class arrayList {
public:
    arrayList() {
        this->data = new T[16];
        this->arrLength = 16;
        this->listSize = 0;
    }

    ~arrayList(){
        delete [] this->data;
    }

    void print(){
        for (int i = 0; i < this->listSize; i++)
        {
            cout<< this->data[i] << "   "<< endl;
        }
    }

    bool contains(T item){
        for (int i = 0; i < this->listSize; ++i)
        {
            if(this->data[i] == item){
                return true;
            }
        }
        return false; 
    }

    int indexOf(T item){
        for (int i = 0; i < this->listSize; ++i)
        {
            if(this->data[i] == item){
                return i;
            }
        }
        return -1;
    }

    int lastIndexOf(T item){
        if(!contains(item)) return -1;
        for (int i = this->listSize - 1; i >= 0; --i)
        {
            if(this->data[i] == item) return i;

        }
    }

    int size(){
        return this->listSize;
    }

    void add(T item) {
        if (needToResize()) {
            resize();
        }
        this->data[this->listSize] = item;
        ++this->listSize;
    }

    void add(int index, T item) {
        if (needToResize()) {
            resize();
        }
        for (int i = this->listSize; i >= index; --i) {
            this->data[this->listSize + 1] = this->data[this->listSize];
        }

        this->data[index] = item;
        ++this->listSize;
    }

    void set(int i, T item){
        if(i == this->listSize ){
            add(item);
            return;
        }
        if(i < this->listSize){
            this->data[i] = item;
            ++this->listSize;
        }else{
            cout << "I dont can "<< endl;
        }
        
    }

    void remove_by_item(T item){
        T *temp = new T[this->arrLength];
        int item_counts = 0;
        int item_index = 0;
        for (int i = 0; i < this->listSize; ++i)
        {
            if(this->data[i]== item){
                ++item_counts;
            }else{
                temp[item_index] = this->data[i];
                ++item_index;
            }
        }
        this->data = temp;
        this->listSize = this->listSize - item_counts; 
    }

    void remove_by_index(int index){
        if(index >= this->listSize){
            return;
        }
       
        T *temp = new T[this->arrLength];
        int check = 0;
        for (int i = 0; i < this->listSize; ++i)
        {
            if(i!=index){
                temp[check] = this->data[i];
            }else{
                --check;
            }
            ++check;
        }
        this->data = temp;
        --this->listSize;
    }
private:
    T *data;
    int arrLength;
    int listSize;

    void resize() {
        T *temp = new T[this->arrLength * 2];
        for (int i = 0; i < this->arrLength; ++i) {
            temp[i] = this->data[i];
        }
        this->data = temp;
        this->arrLength *= 2;
        delete [] temp;
    }

    bool needToResize() {
        return this->arrLength == this->listSize;
    }
};


int main(){
    arrayList<int>x;
    
    x.add(1);
    x.add(5);
    x.add(10);
    x.add(5);
    x.remove_by_item(5);

    // cout<< x.contains(11111)<< "aslf"<< endl;
    // x.remove_by_index(2);
    x.print(); 
    return 0;
};

