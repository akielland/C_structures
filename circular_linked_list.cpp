// type of linked list: singly linked list or a doubly linked list
# include <iostream>
# include <vector>
using namespace std;

struct Node {
    // Implements Nodes types;
    // used to make the building block objects of in the linked_list class
    int value;
    Node* next;

    Node(int n) {
        value = n;
        next = nullptr;
    }
    Node(int n, Node* p) {
        value = n;
        next = p;
    }
};

class CircLinkedList {
    // Class that implement ...
private:
    Node* head;

public:
    CircLinkedList() {
        head = nullptr;
    }

    CircLinkedList(int n) {
        head = nullptr;

        for (int i=1; i<=n; i++) {
          append(i);

        }
    }

    ~CircLinkedList() {
        Node* current;
        current = head;
        Node* temp;
        while ((*current).next != head) {
            temp = (*current).next;
            delete current;
            current = temp;
        }
        delete current;

    }

    void append(int val) {
        if (head == nullptr) {
            head = new Node(val);
            (*head).next = head;
            return;
        }

        Node* current = head;
        while ((*current).next != head) {
            current = (*current).next;

        }
        (*current).next = new Node(val,head);
    }

    void print() {
        int i;
        Node *current = head;
        while ((*current).next != head) {
            cout << (*current).value <<" ";
            current = current -> next;
        }
        cout<<(*current).value;
        cout<<endl;
    }

    int& operator[](int index){
        Node* current = head;
        for (int i=0; i<index; i++) {
            current = current->next;
        }
        return current->value;
    }

    int pop_jeos(int index) {
        int i = 0;
        Node* current = head;
        Node*  previous = nullptr;   // temp_current
        
        while (i<index) {
            i++;
            previous = current;     // temp_current
            current = (*current).next;
        }

        if (current == head){
          int pop_value = (*head).value;
        //   Node* current = head;
          while ((*current).next != head) {
              current = (*current).next;
            }
          (*current).next=(*head).next;
          Node* temp_head = (*head).next;
          delete head;
          head = temp_head;
          cout<<"head is: "<< head << endl;
          return pop_value;
        }

        Node* pop_Node = current;  // (*temp_current).next;
        int pop_value = pop_Node->value;
        previous->next = pop_Node->next;   // temp_current
        head = pop_Node->next;
        delete pop_Node;
        cout<<"head is: "<< head << endl;
        return pop_value;
    }

    vector<int> jeosephus_sequence(int k) {
      vector<int> output;
      while ((*head).next != head){
        int x = pop_jeos(k-1);
        output.push_back(x);
        cout<<x<<endl;
      }

      int x = head->value; //  pop_jeos(0);
      output.push_back(x);

      return output;
    }

};

int main() {
  CircLinkedList test(6);
  vector<int> x = test.jeosephus_sequence(3);
  cout<<x.back()<<endl;
}
