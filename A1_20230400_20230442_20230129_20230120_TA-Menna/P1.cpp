#include <iostream>
using namespace std;

class Guest {
private:
    string name;
    string contact;
    string iftar_date;

public:
    // Default Constructor
    Guest() : name(""), contact(""), iftar_date("") {}

    // Parameterized Constructor
    Guest(string name, string contact, string iftar_date) {
        this->name = name;
        this->contact = contact;
        this->iftar_date = iftar_date;
    }

    // Setters
    void setName(string name) { this->name = name; }
    void setContact(string contact) { this->contact = contact; }
    void setDate(string iftar_date) { this->iftar_date = iftar_date; }

    // Getters
    string getName() { return name; }
    string getContact() { return contact; }
    string getDate() { return iftar_date; }

    // Display guest details
    void display_guest() {
        cout << "Guest Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "Iftar Date: " << iftar_date << endl;
    }

    // Update invitation date
    void update_invitation(string newDate) {
        iftar_date = newDate;
    }
};

class IftarManager : public Guest {
private:
    Guest* guest_list;
    int capacity;
    int no_guests;

    // Resize method
    void resize() {
        capacity *= 2;
        Guest* new_list = new Guest[capacity];
        for (int i = 0; i < no_guests; i++) {
            new_list[i] = guest_list[i];
        }
        delete[] guest_list;
        guest_list = new_list;
    }

public:
    // Constructor & Destructor
    IftarManager(int cap = 2) : no_guests(0), capacity(cap) {
        guest_list = new Guest[capacity];
    }

    ~IftarManager() {
        delete[] guest_list;
    }

    // Add a guest
    void add_guest(Guest guest) {
        if (no_guests >= capacity) {
            resize();
        }
        guest_list[no_guests++] = guest;
    }

    // Remove a guest by name
    void remove_guest(string name) {
        for (int i = 0; i < no_guests; i++) {
            if (guest_list[i].getName() == name) {
                for (int j = i; j < no_guests - 1; j++) {
                    guest_list[j] = guest_list[j + 1];
                }
                no_guests--;
                cout << "Guest " << name << " has been removed." << endl;
                return;
            }
        }
        cout << "Guest not found!" << endl;
    }

    // Display all guests
    void display_all_guests() const {
        cout << "\nGuest List:\n";
        for (int i = 0; i < no_guests; i++) {
            guest_list[i].display_guest();
            cout << "---------------------" << endl;
        }
    }

    // Enhanced Update Guest Invitation (interactive)
    void update_guest_invitation() {
        string name;
        cout << "Enter the name of the guest to update: ";
        cin >> name;
        bool found = false;

        for (int i = 0; i < no_guests; i++) {
            if (guest_list[i].getName() == name) {
                found = true;
                cout << "Current details:\n";
                guest_list[i].display_guest();

                string confirm;
                cout << "Do you want to update the invitation date? (yes/no): ";
                cin >> confirm;

                if (confirm == "yes" || confirm == "Yes") {
                    string new_date;
                    cout << "Enter new Iftar date (YYYY-MM-DD): ";
                    cin >> new_date;
                    guest_list[i].update_invitation(new_date);
                    cout << "Invitation date updated for " << name << "." << endl;
                } else {
                    cout << "Update canceled." << endl;
                }
                return;
            }
        }
        if (!found) {
            cout << "Guest not found!" << endl;
        }
    }

    // Send reminders to guests for a specific date
    void send_reminder(string iftar_date) {
        cout << "Sending reminders for Iftar on " << iftar_date << ":" << endl;
        bool found = false;
        for (int i = 0; i < no_guests; i++) {
            if (guest_list[i].getDate() == iftar_date) {
                cout << "Reminder sent to " << guest_list[i].getName() << "!" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No guests invited on this date." << endl;
        }
    }

    // Sort guest list by iftar date
    void sort_guest_list() {
        for (int i = 0; i < no_guests - 1; i++) {
            for (int j = 0; j < no_guests - i - 1; j++) {
                if (guest_list[j].getDate() > guest_list[j + 1].getDate()) {
                    Guest temp = guest_list[j];
                    guest_list[j] = guest_list[j + 1];
                    guest_list[j + 1] = temp;
                }
            }
        }
        cout << "Guest list sorted by date." << endl;
    }
};

// Main with Menu
int main() {
    IftarManager manager;

    // Add 5 initial guests
    manager.add_guest(Guest("Ali", "123456789", "2025-04-01"));
    manager.add_guest(Guest("Habiba", "987654321", "2025-04-03"));
    manager.add_guest(Guest("Ahmed", "555666777", "2025-04-02"));
    manager.add_guest(Guest("Adham", "888999000", "2025-04-01"));
    manager.add_guest(Guest("Malek", "777888999", "2025-04-04"));

    int choice;
    do {
        cout << "\n--- Iftar Invitation Manager ---\n";
        cout << "1. Add Guest\n";
        cout << "2. Remove Guest\n";
        cout << "3. Display Guest List\n";
        cout << "4. Sort Guest List by Iftar Date\n";
        cout << "5. Send Reminder\n";
        cout << "6. Update Guest Invitation\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            string name, contact, date;
            cout << "Enter guest name: ";
            cin >> name;
            cout << "Enter contact number: ";
            cin >> contact;
            cout << "Enter Iftar date (YYYY-MM-DD): ";
            cin >> date;
            manager.add_guest(Guest(name, contact, date));
            break;
        }
        case 2: {
            string name;
            cout << "Enter the name of the guest to remove: ";
            cin >> name;
            manager.remove_guest(name);
            break;
        }
        case 3:
            manager.display_all_guests();
            break;
        case 4:
            manager.sort_guest_list();
            break;
        case 5: {
            string date;
            cout << "Enter the Iftar date to send reminders for (YYYY-MM-DD): ";
            cin >> date;
            manager.send_reminder(date);

            break;
        }
        case 6:
            manager.update_guest_invitation();
            break;
        case 7:
            cout << "Exiting..May your Iftar gatherings be full of warmth and blessings!\n";
            break;
        default:
            cout << "Invalid option. Please choose again.\n";
        }

    } while (choice != 7);

    return 0;
}
