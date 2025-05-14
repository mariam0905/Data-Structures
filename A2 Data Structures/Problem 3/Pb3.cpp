#include <iostream>
#include <fstream>
using namespace std;

int flipped(int Arr[],int s, int k) {
    int operations = 0;
    for(int i=0;i<s-(k-1);i++) {
        if(Arr[i]==0) {
            for(int j=0;j<k;j++) {
                Arr[i+j]= 1-Arr[i+j];
            }
            operations++;
        }
    }
    for (int i = 0; i < s; i++) if (Arr[i] == 0) return -1;
    return operations;
}

int main(){
    ifstream inputFile;
    inputFile.open("BinaryInput.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    cout<<"================================\n";
    while (true){
        int s,k;

        inputFile >> s;
        int arr[s] = {0};
        for (int i = 0; i < s; i++) {
            inputFile >> arr[i]; // Read array elements from file
        }

        inputFile >> k;

        cout << "arr = [";
        for (int i = 0; i < s; i++) {
            cout << arr[i] << ", ";
        }
        cout << "\b\b]" << endl;
        cout << "k = " << k << endl;

        cout << flipped(arr, s, k) << endl;
        cout << "================================\n";

        int choice;
        inputFile >> choice;

        if (choice == 2) break;
    }

    return 0;
}
