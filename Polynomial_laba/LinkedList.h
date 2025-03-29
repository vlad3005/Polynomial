#include "Term.h"

class Node {
public:
    Term term;
    Node* next;

    Node(int coef, int exp) : term(coef, exp), next(nullptr) {}
    Node(Term other) {
        term = other;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}
    
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void pushFront(Term term) {
        Node* newNode = new Node(term);
        newNode->next = head;
        if (tail == nullptr) {
            tail = newNode;
        }
        head = newNode;
    }

    void pushBack(Term term) {
        Node* newNode = new Node(term);
        if (head == nullptr) {
			pushFront(term);
        }
		tail->next = newNode;
		tail = newNode;
    }

    void pushAt(int index, Term term) {
        Node* tmp = head;
        Node* newNode = new Node(term);
        int i = 0;
        while (tmp && i < index) {
            tmp = tmp->next;
            ++i;
        }
        if (!tmp) {
            throw std::out_of_range("index out of range");
        }
        else {
            if (tmp == tail) {
                pushBack(term);
            }
            else if (tmp == head) {
                pushFront(term);
            }
            else {
                newNode->next = tmp->next;
                tmp->next = newNode;
            }
        }
    }
};

