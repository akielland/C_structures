// type of linked list: singly linked list or a doubly linked list
# include <iostream>

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

class LinkedList {
    // Class that implement ...

private:
    Node* head;
    Node* tail;


        
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr; // No need for this yet
    }

    ~LinkedList() {
        Node* current;
        current = head;
        Node* temp;
        while (current != nullptr) {
            temp = (*current).next;
            delete current;        
            // why not pack out the node here with *? 
            // destroy array and non-array(pointer) objects which are created by new expression
            // Pointer to object is not destroyed, value or memory block pointed by pointer is destroyed
            current = temp;
        }   
    }

    int lenght() {
        int len;
        len = 0;
        Node* current;
        current = head;

        while (current != nullptr) {
            len++;
            current = (*current).next;
        }
        return len;
    };

    void append(int val) {
        if (head == nullptr) {
            head = new Node(val);
            return;
        }

        Node* current;
        current = head;
        while ((*current).next != nullptr) {
            current = (*current).next;
        }
        (*current).next = new Node(val);
    }

    // void print() {
    //     Node* current = head;
    //     while(current->next != nullptr) {
    //         std::cout << (*current).value <<"  ";
    //         current = (*current).next;
    //     }
    //     std::cout<< current -> value << std::endl; 
    // }

    void print() {
        Node *current;
        current = head;
        for (int i=0; i<lenght(); i++) {
            std::cout << (*current).value <<" ";
            current = current -> next;
        }
        std::cout<<std::endl;
    }

    int& operator[](int index){
        if (index < 0 || index >= lenght()) { // why not just >?
            throw std::range_error("IndexError: index out of range. Either before or after the list");
        }
        Node* current = head;
        for (int i; i<index; i++) {
            current = current->next;
        }
        return current->value;
    }

    void insert(int index, int value) {
        if (head == nullptr) {
            throw std::length_error("list contains no elemnts; use append to add new element");
        }
        if (index < 0 || index > lenght()) {
            throw std::range_error("IndexError: index out of range. Either before or after the list");
        }

        int i = 0;
        Node *current;
        current = head;

        while (i < index) {
            i++;
            current = (*current).next;
        }

        // Node* next = current->next;
        // current->next = new Node(value, next);
        
        Node* temp_next = current->next;
        current->next = new Node(value);
        current = current->next;
        current->next = temp_next;
    }
    
void remove(int index) {
    if (index<0 or index > lenght()) {
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

int pop(int index) {
    if (index<0 or index > lenght()) {
    throw std::range_error("IndexError: index out of range");
    }
    int i = 0;
    Node* current = head;
    while (i<index) {
        current = (*current).next;
        i++;
    }
    
    Node* next_Node = (*current).next;
    int value_current = next_Node->value;
    (*current).next   = next_Node->next;
    delete next_Node;

    return value_current;
}

int pop() {
    Node* current = head;
    for (int i = 0; i<(lenght()-1); i++) {
        std::cout <<current->value <<std::endl;
        current = (*current).next;
    }
    std::cout << "out of loop" << std::endl;

    int value_current = current->value;
    std::cout << "adress of current is: "<< current->value <<std::endl;
    delete current;

    return value_current;
}

};


int main () {
    
    LinkedList list_1;
    list_1.append(5);
    list_1.append(36);
    list_1.append(8);
    list_1.append(100);
    list_1.append(500);
    list_1.print();

    list_1.insert(2,55);
    list_1.print();
    std::cout << list_1.pop() <<std::endl;
    list_1.print();
    std::cout <<"end of main"<<std::endl;
    return 0;
}