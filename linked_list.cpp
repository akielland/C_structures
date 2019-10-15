// type of linked list: singly linked list or a doubly linked list
# include <iostream>

struct Node {
    int value;
    Node *next;

    Node(int n) {
        value = n;
        next = nullptr;
    }
    Node(int n, Node *p) {
        value = n;
        next = p;
    }
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
            int len;
            len = 0;
            Node *current;
            current = head;

            for (current != nullptr) {
                len++;
                current = current.next;
            }
            return len;
        };

        void append(int val) {
            if (head == nullptr) {
                head = new Node(val);
                return;

            Node *current;
            current = head;
            while ((*current).next != nullptr) {
                current = (*current).next;
            }
            (*current).next = new Node(val);
            }
        }

        void print() {
            Node *current;
            current = head;
            while(current != nullptr) {
                std::cout << current.value <<" ";
                current = current.next
            std::cout<< current.value;
            }
        }

        void print() {
            Node *current;
            current = head;
            for (int i; i<=lenght(); i++) {
                std::cout << current.value <<" ";
                current = current.next
            }
        }
        int &operator[](int index){
            if (index < 0 or index >= size) {
                throw range_error("IndexError: index out of range");
            }
            Node *current = head;
            for (int i; i<=index; i++){
                current = current.next;
            }
            return current.value;
        }
};

int main () {
    list_1 = LinkedList();
    list_1.append(5);

    return 0;
}