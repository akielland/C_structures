// type of linked list: singly linked list
# include <iostream>
# include <vector>

struct Node {
    /* Implements the type Node; the building block objects in the linked_list class
    The Node contains a value of type <int> (set through parameter),
    and a pointer of type <Node pointer>, which is the memory adress of the next Node 
    or nullptr if it is the last Node of list
    
    Parameter
    ----------
    n: value to be stored in Node
    */

    int value;
    Node* next;

    Node(int number) {
        value = number;
        next = nullptr;
    }
};

class LinkedList {
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
    LinkedList() {
        head = nullptr;
    }
    LinkedList(std::vector<int> vec) {
        head = nullptr;

        for (int i=0; i < vec.size(); i++) {
            append(vec[i]);
        }
    }

    ~LinkedList() {
        Node* current;
        current = head;
        Node* temp;
        while (current != nullptr) {
            temp = (*current).next;
            delete current;
            current = temp;
        }
    }

    int length() {
        int len;
        len = 0;
        Node* current;
        current = head;

        while (current != nullptr) {
            len++;
            current = (*current).next;
        }
        return len;
    }

    void append(int value) {
        if (head == nullptr) {
            head = new Node(value);
            return;
        }

        Node* current = head;
        while ((*current).next != nullptr) {
            current = (*current).next;
        }
        (*current).next = new Node(value);
    }

    void print() {
        int i;
        Node *current = head;
        for (i=0; i<length(); i++) {
            std::cout << (*current).value <<" ";
            current = current -> next;
        }
        std::cout<<std::endl;
    }

    int& operator[](int index){
        if (index < 0 || index >= length()) {
            throw std::range_error("IndexError: index out of range. Either before or after the list");
        }
        Node* current = head;
        for (int i=0; i<index; i++) {
            current = current->next;
        }
        return current->value;
    }

    void insert(int index, int value) {
        if (head == nullptr) {
            throw std::length_error("list contains no elemnts; use append to add new element");
        }
        if (index < 0 || index > length()) {
            throw std::range_error("IndexError: index out of range. Either before or after the list");
        }
        int i = 0;
        Node* current = head;
        while (i < index-1) {
            current = current->next; i++;
        }

        Node* next = current->next;
        current->next = new Node(value);
        current = current->next;
        current->next = next;
    }

void remove(int index) {
    if (index<0 or index >= length()) {
        throw std::range_error("IndexError: index out of range");
    }
    int i = 0;
    Node* current = head;
    while (i<index) {
        current = (*current).next;
        i++;
    }

    Node* next_Node = (*current).next;
    (*current).next = (*next_Node).next;
    delete next_Node;
}

int pop() {
    Node* current = head;
    Node* prev;
    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    int value_current = current->value;
    delete current;
    prev->next = nullptr;
    return value_current;
}

int pop(int index) {
    if (index<0 or index >= length()) {
    throw std::range_error("IndexError: index out of range");
    }
    int i = 0;
    Node* current = head;
    while (i<index-1) {
        current = (*current).next;
        i++;
    }

    Node* pop_Node = (*current).next;
    int pop_value = pop_Node->value;
    (*current).next = pop_Node->next;
    delete pop_Node;
    return pop_value;
}
};

int main () {
    std::cout<<std::endl;
    std::cout<<"TESTING linked_list"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Making list with append:"<<std::endl;
    LinkedList list_1;
    list_1.append(1);
    list_1.append(2);
    list_1.append(3);
    list_1.append(4);
    list_1.append(5);
    list_1.print();
    std::cout<<"lenght() claims list_1 contains "<<list_1.length()<<" Nodes"<<std::endl;

    std::cout<<std::endl;
    std::cout<<"Testing insert and remove by inserting and remving 3 at index 2:"<<std::endl;
    list_1.insert(2, 3);
    list_1.print();
    list_1.remove(2);
    list_1.print();
    
    std::cout<<std::endl;
    std::cout <<"POP last element: "<<list_1.pop() <<std::endl;
    list_1.print();
    std::cout<<std::endl;

    std::cout<<"Operator[] oveloading: list_1[2] gives "<<list_1[2]<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Making list with vector as parameter:"<<std::endl;
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    LinkedList list_2(v);
    list_2.print();
    std::cout<<std::endl;

    std::cout<<"POP element at index 7: ";
    std::cout<<list_2.pop(7)<<std::endl;
    list_2.print();
    std::cout<<std::endl;

    return 0;
}
