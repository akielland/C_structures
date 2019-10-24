// type of linked list: singly linked list or a doubly linked list
# include <iostream>
# include <vector>
using namespace std;

struct Node {
   /* Implements the type Node; the building block objects in the circular_linked_list class
    The Node contains a value of type <int> (set through parameter),
    and a pointer of type <Node pointer>, which is the memory adress of the next Node 
    or nullptr if it is the last Node of list
    
    Parameter
    ----------
    n: value to be stored in Node
    */

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
    /* Implements the type <LinkedList>; an order sequence of the types <Node>
    - A LinkedList object can be instantiated with a parameters type < vector<int> > adding the first elemnts of the list
    - A LinkedList object can be instantiated witout Nodes, then it is just a type <Node pointer>
    containing the nullptr adress. The append method can then be used to add list elemnts
    
    Parameter
    ---------
    non: 
    vec: vector object which implements 

    Methods
    -------
    length(): returns the number of Nodes in the list
    append(value): adds one Node to the end of the list
    insert(index, value): inserts at new Node at index location and move downstream Nodes one index step backwards
    remove(): removes at new Node at index location and move downstream Nodes one index step forward
    pop(): removes last Node of the list and return the value of the removed Node
    pop(index): returns the value of a Node at index location. Remove the Node and move downstream Nodes one index step forward
    print(): prints the list
    int& operator[](int index): overloads the square bracket operator to access elements by index
     ~LinkedList: removes all Nodes allocated to memory as a final step when running the program
    */
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
