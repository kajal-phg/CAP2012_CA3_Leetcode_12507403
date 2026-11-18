
class MyLinkedList {
    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = NULL;
        }
    };
    Node* head;

public:
    MyLinkedList() {
        head = NULL;
    }
    int get(int index) {
        Node* current = head;

        for (int i = 0; i < index; i++) {
            if (current == NULL) return -1;
            current = current->next;
        }
        if (current == NULL) return -1;

        return current->val;
    }
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
       Node* current = head;

        for (int i = 0; i < index - 1; i++) {
            if (current == NULL) return;
            current = current->next;
        }
        if (current == NULL) return;

        Node* newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;
    }
    void deleteAtIndex(int index) {
        if (head == NULL) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            if (current == NULL) return;
            current = current->next;
        }
        if (current == NULL || current->next == NULL) return;

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
};
