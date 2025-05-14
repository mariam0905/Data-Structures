#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};



class AVLnode
{
public:
    int ID;
    Contact contact;
    AVLnode *rightptr;
    AVLnode *leftptr;
    int height;

    AVLnode()
    {
        ID = 0;
        rightptr = leftptr = nullptr;
        height = 1;
    }

    AVLnode(int key)
    {
        ID = key;
        rightptr = leftptr = nullptr;
        height = 1;
    }
};

void saveContactsToFile(const string& filename, AVLnode* root);
class AVLtree
{
private:
    AVLnode *myroot;



    int getheight(AVLnode *node)
    {
        if(node == nullptr)return 0;
        return node->height;
    }



    int getbalancefactor(AVLnode *node)
    {
        if(node == nullptr)return 0;

        return (getheight(node->leftptr) - getheight(node->rightptr));
    }



    AVLnode *rightrotation(AVLnode *y)
    {
        AVLnode *x = y->leftptr;
        AVLnode *child = x->rightptr;

        x->rightptr = y;
        y->leftptr = child;

        y->height = max(getheight(y->leftptr) , getheight(y->rightptr)) + 1;
        x->height = max(getheight(x->leftptr) , getheight(x->rightptr)) + 1;

        return x;
    }


    AVLnode *leftrotation(AVLnode *y)
    {
        AVLnode *x = y->rightptr;
        AVLnode *child = x->leftptr;

        x->leftptr = y;
        y->rightptr = child;

        y->height = max(getheight(y->leftptr) , getheight(y->rightptr)) + 1;
        x->height = max(getheight(x->leftptr) , getheight(x->rightptr)) + 1;

        return x;
    }


    AVLnode* insertnode(AVLnode* rootnode, int key, Contact contact, bool &duplicate) {
        if (rootnode == nullptr) {
            AVLnode* newnode = new AVLnode(key);
            newnode->contact = contact;
            return newnode;
        }
    
        if (key < rootnode->ID) {
            rootnode->leftptr = insertnode(rootnode->leftptr, key, contact, duplicate);
        } else if (key > rootnode->ID) {
            rootnode->rightptr = insertnode(rootnode->rightptr, key, contact, duplicate);
        } else {
            duplicate = true; // Duplicate found
            return rootnode;
        }
    
        rootnode->height = max(getheight(rootnode->leftptr), getheight(rootnode->rightptr)) + 1;
        int currentbalance = getbalancefactor(rootnode);
    
        // Rotations
        if (currentbalance > 1 && key < rootnode->leftptr->ID)
            return rightrotation(rootnode);
        if (currentbalance < -1 && key > rootnode->rightptr->ID)
            return leftrotation(rootnode);
        if (currentbalance > 1 && key > rootnode->leftptr->ID) {
            rootnode->leftptr = leftrotation(rootnode->leftptr);
            return rightrotation(rootnode);
        }
        if (currentbalance < -1 && key < rootnode->rightptr->ID) {
            rootnode->rightptr = rightrotation(rootnode->rightptr);
            return leftrotation(rootnode);
        }
    
        return rootnode;
    }
    

    AVLnode *find_min_node(AVLnode *rootnode)
    {
        if(rootnode == nullptr) return nullptr;
        else if(rootnode->leftptr == nullptr) return rootnode;
        else{return find_min_node(rootnode->leftptr);}
    }

    AVLnode *searchh(AVLnode *rootnode , int key)
    {
        if(rootnode==nullptr)return nullptr;

        else if(rootnode->ID==key)
        {
            return rootnode;
        }

        else if(key<rootnode->ID)
        {
            return searchh(rootnode->leftptr,key);
        }

        else if(key >= rootnode->ID)
        {
            return searchh(rootnode->rightptr,key);
        }
    }


    AVLnode* deletenode(AVLnode* rootnode, int key)
    {
        if (rootnode == nullptr)
            return rootnode;

        if (key < rootnode->ID)
            rootnode->leftptr = deletenode(rootnode->leftptr, key);
        else if (key > rootnode->ID)
            rootnode->rightptr = deletenode(rootnode->rightptr, key);
        else {

            if ((rootnode->leftptr == nullptr) || (rootnode->rightptr == nullptr)) {
                AVLnode* temp = rootnode->leftptr ? rootnode->leftptr : rootnode->rightptr;
                if (temp == nullptr) {
                    temp = rootnode;
                    rootnode = nullptr;
                }
                else
                    *rootnode = *temp;
                delete temp;
            }
            else {

                AVLnode* temp = find_min_node(rootnode->rightptr);
                rootnode->ID = temp->ID;
                rootnode->rightptr = deletenode(rootnode->rightptr, temp->ID);
            }
        }

        if (rootnode == nullptr)
            return rootnode;

        // Update height of the current node
        rootnode->height = 1 + max(getheight(rootnode->leftptr),getheight(rootnode->rightptr));

        // Get the balance factor of this node
        int balance = getbalancefactor(rootnode);

        // If this node becomes unbalanced, then there are 4
        // cases

        // Left Left Case
        if (balance > 1 && getbalancefactor(rootnode->leftptr) >= 0)
            return rightrotation(rootnode);

        // Left Right Case
        if (balance > 1 && getbalancefactor(rootnode->leftptr) < 0) {
            rootnode->leftptr = leftrotation(rootnode->leftptr);
            return rightrotation(rootnode);
        }

        // Right Right Case
        if (balance < -1 && getbalancefactor(rootnode->rightptr) <= 0)
            return leftrotation(rootnode);

        // Right Left Case
        if (balance < -1 && getbalancefactor(rootnode->rightptr) > 0) {
            rootnode->rightptr = rightrotation(rootnode->rightptr);
            return leftrotation(rootnode);
        }

        return rootnode;
    }

    void inorder(AVLnode* rootnode)
    {
        if (rootnode != nullptr) {
            inorder(rootnode->leftptr);
            cout << "ID: " << rootnode->ID << ", Name: " << rootnode->contact.name
            << ", Phone: " << rootnode->contact.phone
            << ", Email: " << rootnode->contact.email << endl;
            inorder(rootnode->rightptr);
        }
    }

public:
    AVLtree()
    {
        myroot = nullptr;
    }

    void Add(int data, Contact contact) {
        bool duplicate = false;
        myroot = insertnode(myroot, data, contact, duplicate);
        if (duplicate) {
            cout << "Error: A contact with ID " << data << " already exists.\n";
        } else {
            cout << "Contact added successfully.\n";
            saveContactsToFile("contacts.txt", myroot);
        }
    }
    

    void Remove(int data)
    {
        myroot = deletenode(myroot , data);
    }

    bool searchh(int key)
    {
        AVLnode *result = searchh(myroot,key);
        if(result==nullptr)return false;
        else return true;
    }

    void printinordertraversal()
    {
        inorder(myroot);
        cout<<"\n";
    }

    void displayTree(AVLnode* root, int space = 0, int height = 6) {
        if (root == nullptr) return;

        space += height;

        displayTree(root->rightptr, space, height);

        cout << endl;
        for (int i = height; i < space; i++)
            cout << " ";
        cout << root->ID;

        displayTree(root->leftptr, space, height);
    }


    void menu() {
        int choice;
    
        while (true) {
            cout << "\nAddress Book Application\n------------------------\n";
            cout << "1. Add New Contact\n";
            cout << "2. Search for Contact\n";
            cout << "3. Delete Contact\n";
            cout << "4. List All Contacts (Sorted by ID)\n";
            cout << "5. Display Current Tree Structure\n";
            cout << "6. Exit\n";
            cout << "------------------------\nEnter operation (1-5): ";
            cin >> choice;
    
            if (choice == 1) {
                Contact contact;
                int id;
                cout << "Enter unique ID (integer): ";
                cin >> id;
                cin.ignore();
                cout << "Enter name: ";
                getline(cin, contact.name);
                cout << "Enter phone: ";
                getline(cin, contact.phone);
                cout << "Enter email: ";
                getline(cin, contact.email);
                Add(id, contact);
            }
    
            else if (choice == 2) {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                AVLnode* result = searchh(myroot, id);
                if (result) {
                    cout << "Contact found:\nID: " << result->ID
                        << "\nName: " << result->contact.name
                        << "\nPhone: " << result->contact.phone
                        << "\nEmail: " << result->contact.email << endl;
                } else {
                    cout << "Contact not found.\n";
                }
            }
    
            else if (choice == 3) {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                if (searchh(myroot, id)) {
                    myroot = deletenode(myroot, id);
                    cout << "Contact with ID " << id << " has been deleted.\n";
                    saveContactsToFile("contacts.txt", myroot);
                } else {
                    cout << "Error: Contact with ID " << id << " not found.\n";
                }
            }
            
            else if (choice == 4) {
                if (!myroot)
                    cout << "Address Book is empty.\n";
                else {
                    cout << "Contacts in Address Book (sorted by ID):\n";
                    inorder(myroot);
                }
            }
    
            else if (choice == 5) {
                cout << "Current AVL Tree:\n";
                displayTree(myroot);
            }

            else if (choice == 6) {
                cout << "Exiting Address Book. Goodbye!\n";
                break;
            }
    
            else {
                cout << "Invalid option.\n";
            }
        }
    }
    
};

void loadContactsFromFile(const string& filename, AVLtree& tree) {
    ifstream infile(filename);
    if (!infile) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    int id;
    Contact contact;
    while (infile >> id >> contact.name >> contact.phone >> contact.email) {
        tree.Add(id, contact);
    }

    infile.close();
}

void saveContactsToFile(const string& filename, AVLnode* root) {
    ofstream outfile(filename);
    if (!outfile) {
        cout << "Error: Could not open file for writing: " << filename << endl;
        return;
    }

    function<void(AVLnode*)> writeInOrder = [&](AVLnode* node) {
        if (!node) return;
        writeInOrder(node->leftptr);
        outfile << node->ID << " " << node->contact.name << " " 
                << node->contact.phone << " " << node->contact.email << endl;
        writeInOrder(node->rightptr);
    };

    writeInOrder(root);
    outfile.close();
}



int main() {
    AVLtree t;

    loadContactsFromFile("contacts.txt", t);  

    t.menu();
}

