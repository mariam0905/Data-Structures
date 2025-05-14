#include <iostream>
#include<iomanip>

using namespace std;

/////////////////////PROBLEM 5///////////////////////

template<typename T>
class StatisticalCalculations {
    private:
        T* data;
        int size;
    public:
    StatisticalCalculations(int size_m) {
        size = size_m;
        data = new T[size_m];
    }
    ~StatisticalCalculations() {
        delete[] data;
    }
    void sort() {
        for (int i = 1; i < size; i++) {
            T key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }

    double findMedian() {
        T med = -1;
        if (size%2 == 0) {
            med = (data[size/2]+data[(size/2)-1])/2;
        }
        else {
            med = data[(size-1)/2];
        }
        return med;
    }
    T findMin() {
        return data[0];
    }
    T findMax() {
        return data[size-1];
    }
    double findMean() {
        return static_cast<double>(this->findSummation()) / size;
    }
    T findSummation() {
        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        return sum;
    }

    void inputData() {
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i + 1 << " : ";
            cin >> data[i];
        }
    }
    void displayArray() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void statisticsMenu() {
        this->inputData();
        this->sort();
        int menu = -1;
        cout<<endl;

        while (!(menu == 1||menu ==2||menu ==3||menu ==4||menu ==5||menu ==6)) {
            cout<<"Select a statistical calculation: \n1. Find Median\n2. Find Minimum\n3. Find Maximum\n4. Find Mean\n5. Find Summation \n6. Operate all\nEnter your choice (1-5): ";
            cin >> menu;
        }
        switch (menu) {
            case 1: {
                auto med = this->findMedian();
                cout << "Median: " << med << endl;
                break;
            }
            case 2: {
                auto min = this->findMin();
                cout << "Minimum: " << min << endl;
                break;
            }
            case 3: {
                auto max = this->findMax();
                cout << "Maximum: " << max << endl;
                break;
            }
            case 4: {
                auto mean = this->findMean();
                cout << "Mean: " << mean << endl;
                break;
            }
            case 5: {
                auto sum = this->findSummation();
                cout << "Summation: " << sum << endl;
                break;
            }
            case 6: {
                displayArray();
                auto med = this->findMedian();
                cout << "Median: " << med << endl;
                auto min = this->findMin();
                cout << "Minimum: " << min << endl;
                auto max = this->findMax();
                cout << "Maximum: " << max << endl;
                auto mean = this->findMean();
                cout << "Mean: " << mean << endl;
                auto sum = this->findSummation();
                cout << "Summation: " << sum << endl;
                break;
            }
            default:
                cout << "Enter a valid option" << endl;
        }

    }
};

int main() {
    int Msize;
    cout<<"Enter the number of elements: ";
    cin >> Msize;
    StatisticalCalculations<int> statistics(Msize);
    statistics.statisticsMenu();

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.