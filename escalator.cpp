#include <iostream>
using namespace std;

class StackBase {
public:
    virtual void push(int val) = 0;
    virtual void pop() = 0;
    virtual void top() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

class Stack : public StackBase {
private:
    int arr[10];
    int topIndex;
    int size;

public:
    Stack(int s = 10) {
        size = s;
        topIndex = -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow\n";
        } else {
            topIndex++;
            arr[topIndex] = val;
            cout << "Pushed: " << val << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
        } else {
            cout << "Popped: " << arr[topIndex] << endl;
            topIndex--;
        }
    }

    void top() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
        } else {
            cout << "Top Element: " << arr[topIndex] << endl;
        }
    }

    bool isEmpty() {
        return topIndex == -1;
    }
    bool isFull() {
        return topIndex == size - 1;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Check Empty\n5. Check Full\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.top();
                break;
            case 4:
                if (s.isEmpty())
                    cout << "Stack is Empty\n";
                else
                    cout << "Stack is NOT Empty\n";
                break;
            case 5:
                if (s.isFull())
                    cout << "Stack is Full\n";
                else
                    cout << "Stack is NOT Full\n";
                break;
        }

    } while (choice != 6);

    return 0;
}