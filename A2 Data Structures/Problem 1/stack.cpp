#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Stack Implementation Using Linked List
struct Node {
    string data;
    Node* next;
    Node(string d) : data(d), next(nullptr) {}
};

class Stack {
private:
    Node* Top;
    int size;

public:
    Stack() : Top(nullptr), size(0) {}

    void push(const string& value) {
        Node* newNode = new Node(value);
        newNode->next = Top;
        Top = newNode;
        size++;
    }

    void pop() {
        if (Top != nullptr) {
            Node* temp = Top;
            Top = Top->next;
            delete temp;
            size--;
        }
    }

    string top() {
        if (Top != nullptr) {
            return Top->data;
        }
        return "";
    }

    bool isEmpty() {
        return Top == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    int getSize() {
        return size;
    }

    void print(const string& StackType) {
        cout << StackType << ": ";
        if (isEmpty()) {
            cout << "(empty stack)" << endl;
            return;
        }

        Node* temp = Top;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        clear();
    }
};


class History {
private:
    Stack backStack;
    Stack forwardStack;
    string currentUrl;

public:
    History(const string& homepage) {
        currentUrl = homepage;
        backStack.push(homepage);
    }

    void visit(const string& url) {
        forwardStack.clear();
        backStack.push(url);
        currentUrl = url;
       
    }

    void goBack() {
        if (backStack.getSize() <= 1) {
            cout << "Cannot go back. You are at the first page." << endl;
            return;
        }

        forwardStack.push(currentUrl);
        backStack.pop();
        currentUrl = backStack.top();
        cout << "go back to: " << currentUrl << endl;
    }

    void goForward() {
        if (forwardStack.isEmpty()) {
            cout << "Cannot go forward. You are at the latest page." << endl;
            return;
        }

        string nextUrl = forwardStack.top();
        forwardStack.pop();
        backStack.push(nextUrl);
        currentUrl = nextUrl;
        cout << "go forward to: " << currentUrl << endl;
    }

    void printState() {
        cout << "Current URL: " << currentUrl << endl;
        backStack.print("BackStack");
        forwardStack.print("ForwardStack");
    }
};


int main() {
    History browser("homePage.com");

    ifstream File("URL.txt");
    if (!File) {
        cout << "Error: Cannot open URL.txt" << endl;
        return 1;
    }

    string line;
    while (getline(File, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        int choice;
        ss >> choice;

        string url;

        switch (choice) {
            case 3:  // Visit URL
                ss >> url;
                cout << "\nchoice: Visit " << url << endl;
                browser.visit(url);
                break;

            case 1:  // Go back
                cout << "\nchoice: Go Back" << endl;
                browser.goBack();
                break;

            case 2:  // Go forward
                cout << "\nchoice: Go Forward" << endl;
                browser.goForward();
                break;

            case 4:  // Exit
                cout << "\nchoice: Exit" << endl;
              
                return 0;

            default:
                cout << "\nInvalid choice: " << choice << endl;
        }

        
        browser.printState();
    }

    File.close();
    return 0;
}
