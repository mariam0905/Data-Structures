#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
int parent(int i)
{
    return floor(i / 2);
}
int left(int i)
{
    return (2 * i);
}
int right(int i)
{
    return (2 * i + 1);
}
class Patient
{
    public:
        Patient()
        {
            name = "Unknown";
            severity = 0;
            arrivalTime = 0;
        }
        Patient(string name, int severity, int arrivalTime)
        {
            this->name = name;
            this->severity = severity;
            this->arrivalTime = arrivalTime;
        }
        string name;
        int severity;
        int arrivalTime;
};
class EmergencyRoom
{
    private:
        Patient* patients; 
        int capacity; // Maximum number of patients the emergency room can hold
        int size; // Actual number of patients in the emergency room
    public:
    EmergencyRoom(int num)
    {
        if(num <= 0)
        {
            cout << "Invalid number of patients. Setting to default value" << endl;
            capacity = 100; 
        }
        capacity = ++num; // Increase size by 1 to accommodate the first patient
        size = 0;
        patients = new Patient[capacity]; // Dynamically allocate memory for the array of patients
        patients[0] = Patient();
    }
    void bubble_up(int i) 
    {
        while (i > 1 && (patients[i].severity > patients[parent(i)].severity ||(patients[i].severity == patients[parent(i)].severity &&patients[i].arrivalTime < patients[parent(i)].arrivalTime))) 
        {
            swap(patients[i], patients[parent(i)]);
            i = parent(i);
        }
    }
    void insert(Patient p) 
    {
        if (size + 1 >= capacity) 
        {
            cout << "Emergency room is full. Cannot insert more patients." << endl;
            return;
        }
        size++;
        patients[size] = p;         
        bubble_up(size);           
    }
    void max_heapify(int i)
    {
        int largest = i;
        int l = left(i);
        int r = right(i);
        if(l <= size && (patients[l].severity > patients[largest].severity || (patients[l].severity == patients[largest].severity && patients[l].arrivalTime < patients[largest].arrivalTime)))
            largest = l;
        if(r <= size && (patients[r].severity > patients[largest].severity || (patients[r].severity == patients[largest].severity && patients[r].arrivalTime < patients[largest].arrivalTime)))
            largest = r;
        if(largest != i)
        {
            swap(patients[i], patients[largest]);
            max_heapify(largest);
        }
    } 
    void print_patients()
    {
        for(int i = 1; i <= size; i++)
        {
            if(patients[i].name != "Unknown")
                cout << "Patient Name: " << patients[i].name << ", Severity: " << patients[i].severity << ", Arrival Time: " << patients[i].arrivalTime << endl;
        }
        cout << endl;
    }
    Patient get_next_patient() 
    {
        if (size == 0) 
        {
            cout << "No patients in the emergency room." << endl;
            return Patient();
        }
        Patient nextPatient = patients[1];
        patients[1] = patients[size];
        patients[size] = Patient(); // Optional: reset
        size--;
        max_heapify(1);
        return nextPatient;
    }

    void peek() 
    {
        if (size == 0) 
        {
            cout << "No patients in the emergency room." << endl;
            return;
        }
        cout << "Next patient: " << patients[1].name << ", Severity: " << patients[1].severity << ", Arrival Time: " << patients[1].arrivalTime << endl;
    }
    ~EmergencyRoom()
    {
        delete[] patients; // Free the dynamically allocated memory
    }
};
int main()
{
    EmergencyRoom er(10); // Create an emergency room 
    ifstream infile("patients2.txt");
    if (!infile) 
    {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    string name;
    int severity, arrivalTime;

    while (infile >> name >> severity >> arrivalTime) 
    {
        er.insert(Patient(name, severity, arrivalTime));
        er.print_patients();
    }

    infile.close();

    for(int i = 1; i < 11 ; i++)
    {
        er.peek(); // Peek at the next patient to be treated
        Patient nextPatient = er.get_next_patient(); // Treat the next patient
        cout << endl;
        //er.print_patients(); // Print all patients after treating one
    }

    return 0;
}