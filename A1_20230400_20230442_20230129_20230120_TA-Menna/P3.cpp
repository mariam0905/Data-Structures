#include <iostream>
#include<iomanip>
using namespace std;

/////////////////////PROBLEM 3///////////////////////

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class SortedLinkedList {
    private:
    Node* head;

    public:
    SortedLinkedList() {
        head=nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr|| head->data >= value) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* p = head;
        Node* q = nullptr;
        while (p != nullptr && p->data < value) {
            q = p;
            p = p->next;
        }

        q->next = newNode;
        newNode->next = p;
        /*
        Node* p = head;

        while (p->next != nullptr && p->next->data < value) {
            p = p->next;  // Move to next node
        }

        newNode->next = p->next;
        p->next = newNode;
        */
        //better but not sure if it's considered the same as "insertion sort logic"
    }
    void remove(int index) {
        if (head == nullptr) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        int starting = 0;

        while (starting < index - 1 && current->next != nullptr) {
            current = current->next;
            starting++;
        }

        if (current == nullptr || current->next == nullptr) return;

        Node* temp = current->next;
        current->next = temp->next;
        temp->next = nullptr;
        delete temp;

    }

    friend ostream& operator<<(ostream& os, const SortedLinkedList& list) {
        Node* temp =list.head;
        cout << "[";
        while (temp != nullptr) {
            os << temp->data << ", ";
            temp = temp->next;
        }
        cout << "\b\b]" << endl;
        return os;

    }
    int operator[](int index) {

        if (head == nullptr) throw out_of_range("list is empty");
        if (index < 0) throw out_of_range("index cannot be negative");
        if (index ==0) return head->data;

        Node* current = head;
        int starting = 0;
        while (starting < index && current != nullptr) {
            current = current->next;
            starting++;
        }

        if (current == nullptr) throw out_of_range("index out of range");

        return current->data;
    }

    ~SortedLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

};

int main() {
    SortedLinkedList L;
    L.insert(5); // L = [5]
    L.insert(8); // L = [5, 8]
    L.insert(7); // L = [5, 7, 8]
    L.insert(6); // L = [5, 6, 7, 8]
    L.insert(6); // L = [5, 6, 6, 7, 8]
    cout << L; // Output: [5, 6, 6, 7, 8]

    cout << L[2]<<endl; // Output: 6

    //Out of Range case:
    //cout << L[10]; // Throws out_of_range exception

    L.remove(0); // L = [6, 6, 7, 8]
    cout << L; // Output: [6, 6, 7, 8]
    L.remove(100); // No change (out of bounds)
    cout << L; // Output: [6, 6, 7, 8]
    L.remove(2); // L = [6, 6, 8]
    cout << L; // Output: [6, 6, 8]
    L.remove(2); // L = [6, 6]
    cout << L; // Output: [6, 6]

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.