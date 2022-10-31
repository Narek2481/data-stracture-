#include <bits/stdc++.h>
using namespace std;

class Hash
{
  int BUCKET;
  list<int> *table;

public:

  Hash(int b) {
    this->BUCKET = b;
    table = new list<int>[BUCKET];
  }

  int hash_function(int x) {
    return (x % BUCKET);
  }

  void insert_item(int key) {
    int index = hash_function(key);
    table[index].push_back(key);
  }

  void delete_item(int key) {
    int index = hash_function(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
      if (*i == key) {
        break;
      }

    }

    if (i != table[index].end()) {
      table[index].erase(i);
    }
  }

  void display_hash() {
    for (int i = 0; i < BUCKET; i++) {
      cout << i;
      for (auto x : table[i]) {
        cout << " --> " << x;
      }
      cout << endl;
    }
  }
};

int main()
{
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);

  Hash h(7);

  for (int i = 0; i < n; i++) {
    h.insert_item(a[i]);
  }


  h.delete_item(12);

  h.display_hash();

  return 0;
}