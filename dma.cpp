#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void search(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element found at position: " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Element not found!" << endl;
    }

    void delete_node(int key) {
        if (head == NULL) return;

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Element not found!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Initial List: ";
    list.display();

    list.insert_at_beginning(5);
    cout << "After Insert at Beginning: ";
    list.display();

    list.search(20);

    list.delete_node(20);
    cout << "After Deletion: ";
    list.display();

    list.reverse();
    cout << "After Reversing: ";
    list.display();

    return 0;
}