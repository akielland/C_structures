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
            // why not pack out the node here with *?
            // destroy array and non-array(pointer) objects which are created by new expression
            // Pointer to object is not destroyed, value or memory block pointed by pointer is destroyed
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
            std::cout << (*current).value <<" ";
            current = current -> next;
        }
        std::cout<<(*current).value;
        std::cout<<std::endl;
    }

    int& operator[](int index){
        Node* current = head;
        for (int i=0; i<index; i++) {
            current = current->next;
        }
        return current->value;
    }

    int pop(int index) {


        int i = 0;
        Node* current = head;
        Node* temp_current = nullptr;
        while (i<index) {
            i++;
            temp_current = current;
            current = (*current).next;

        }

        if (current == head){
          int pop_value = (*head).value;
          Node* current = head;
          while ((*current).next != head) {
              current = (*current).next;
        }
          (*current).next=(*head).next;
          Node* temp_head = (*head).next;
          delete head;
          head = temp_head;
          return pop_value;
        }
        Node* pop_Node = (*temp_current).next;
        int pop_value = pop_Node->value;
        (*temp_current).next = pop_Node->next;
        delete pop_Node;
        return pop_value;
    }



    vector<int> jeosephus_sequence(int k) {
      vector<int> output;
      int counter=0;
      while ((*head).next != head){

        int x = pop(counter);
        //output.push_back(pop(counter));
        cout<< x;

      }
      cout <<pop(0);

      return output;




    }

};

int main() {
  CircLinkedList test (6);
  test.print();
  vector<int> x = test.jeosephus_sequence(3);
  //return 0;;
}
