// type of linked list: singly linked list or a doubly linked list
# include <iostream>

struct Node {
    int value;
    Node *next;

    Node(int n) {
        value = n;
        next = nullptr;
    }

    // Node(int n, Node *p) {
    //     value = n;
    //     next = p;
    // }
};

class LinkedList {
    private:
        Node *head;
        Node *tail;
    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
    }

    int lenght() {
        return size();
    }

    void append(int val) {
        if (head == nullptr) {
            head = new Node(val);
            return;

        Node *current;
        current = head;
        while ((*current).next != nullptr) {
            current = (*current).next;
        }
        }
    }
};


int main () {
    LinkedList();
    return 0;
}