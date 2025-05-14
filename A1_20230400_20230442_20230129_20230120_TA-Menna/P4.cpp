#include <iostream>
#include <chrono>
#define BUCKETS 10
#define SIZE 100
using namespace std;

template <class T>

class SortingSystem{
    private: 
    T* data;
    int size;

    public:
    SortingSystem(int n);
    ~SortingSystem();

    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void mergeSort(int left, int right);
    void quickSort(int left, int right);
    void countSort();
    void radixSort();
    void bucketSort();

    void merge(int left, int mid, int right); //merge sort helper
    int partition(int low, int high); //quick sort helper

    void displayData();

    void measureSortTime(void(SortingSystem::*sortFunc)());
    void measureSortTime(void(SortingSystem::*sortFunc)(int, int), int param1, int param2);

    void showMenu(); 

};

//Constructor
template <class T>
SortingSystem<T>::SortingSystem(int n) {
    size = n;
    data = new T[size]; 
}

//Destructor
template <class T>
SortingSystem<T>::~SortingSystem() {
    delete[] data; 
}

//print the current state of the array
template <class T>
void SortingSystem<T>::displayData() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}



template <class T>
void SortingSystem<T>::measureSortTime(void (SortingSystem<T>::*sortFunc)()) {
    auto start = chrono::high_resolution_clock::now();
    (this->*sortFunc)(); 
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Execution time: " << elapsed.count() << " seconds\n";
}

template <class T>
void SortingSystem<T>::measureSortTime(void (SortingSystem<T>::*sortFunc)(int, int), int param1, int param2) {
    auto start = chrono::high_resolution_clock::now();
    (this->*sortFunc)(param1, param2);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Execution time: " << elapsed.count() << " seconds\n";
}



//Display menu for user interaction
template <class T>
void SortingSystem<T>::showMenu() {

    int choice;
    while (true) {
        cout << "\nSorting System Menu:\n";
        cout << "1. Insertion Sort \n";
        cout << "2. Selection Sort \n";
        cout << "3. Bubble Sort \n";
        cout << "4. Shell Sort \n";
        cout << "5. Merge Sort \n";
        cout << "6. Quick Sort \n";
        cout << "7. Count Sort (Only for integers) \n";
        cout << "8. Radix Sort (Only for integers) \n";
        cout << "9. Bucket Sort \n";

        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
                //insertionSort();
                measureSortTime(SortingSystem<T>::insertionSort);
                cout << "Sorted Data: ";
                displayData();
                delete[] data;
                
                break;

            case 2:
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
                //selectionSort();
                measureSortTime(SortingSystem<T>::selectionSort);
                cout << "Sorted Data: ";
                displayData();
                delete[] data;
                break;

            case 3:
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
                //bubbleSort();
                measureSortTime(SortingSystem<T>::bubbleSort);
                cout << "Sorted Data: ";
                displayData();
                delete[] data;
                break;

            case 4:
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
                //shellSort();
                measureSortTime(SortingSystem<T>::shellSort);
                cout << "Sorted Data: ";
                displayData();
                delete[] data;
                break;
            case 5:
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
                //mergeSort(0 , size - 1);
                measureSortTime(&SortingSystem<T>::mergeSort, 0, size - 1);
                cout << "Sorted Data: ";
                displayData();
                delete[] data;
                break;
            case 6:
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
                //quickSort(0 , size - 1);
                measureSortTime(&SortingSystem<T>::quickSort, 0, size - 1);
                cout << "Sorted Data: ";
                displayData();
                delete[] data;
                break;
            case 7:
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
                //countSort();
                measureSortTime(SortingSystem<T>::countSort);
                delete[] data;
                break;
            case 8:
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
                //radixSort();
                measureSortTime(SortingSystem<T>::radixSort);
                delete[] data;
                break;
            case 9:
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
                //bucketSort();
                measureSortTime(SortingSystem<T>::bucketSort);
                delete[] data;
                break;
            case 10:
                cout << "Exiting program...\n";
                return;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

//1-Insertion Sort
template <class T>
void SortingSystem<T>::insertionSort(){
    T key ;
    int j;

    for(int i = 1 ; i < size ; i++){
        key = data[i];
        j = i - 1; 

        while(j >= 0 && data[j] > key){
            data[j + 1] = data[j];
            j = j - 1; 
        }
        data[j + 1] = key;
        displayData();
    }
}

//2-Selection Sort
template <class T>
void SortingSystem<T>::selectionSort() {     

    for(int i = 0 ; i < size-1 ; i++){
        int minIdx = i;

        for(int j = i + 1 ; j < size ; j++){
        if(data[j] < data[minIdx]){
            minIdx = j;
        }
        }
        swap(data[minIdx],data[i]);
        displayData();
    }

}

//3-Bubble Sort
template <class T>
void SortingSystem<T>::bubbleSort(){
    bool flag = true;

    for(int i = 0 ; i < size - 1 ; i++ ){

    for(int j = 0 ; j < size - i - 1 ; j++){
        if(data[j] > data[j + 1]){
            swap(data[j] , data[j + 1]);
            flag = false;
        }
    }
    displayData();
    if(flag == true) break;
}
}


//4-Shell Sort
template<class T>
void SortingSystem<T>::shellSort()
{
    for (int gap = size/2 ; gap > 0 ; gap /= 2)
    {
        cout << "\nGap: " << gap << endl;
        for (int i = gap ; i < size ; i++)
        {
            T temp = data[i];
            int j = i;
            for (; j >= gap && data[j-gap] > temp ; j-= gap)
                data[j] = data[j-gap];
            data[j] = temp;
        }
        cout << "Array after gap " << gap << ": ";
        displayData();
        //cout << endl;
    }
}


//merge sort helper
template <class T>
void SortingSystem<T>::merge(int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left +1;
    int n2 = right - mid;

    T *L = new T[n1];
    T *R = new T[n2]; 
    
    for (i = 0 ; i < n1 ; i++){
        L[i] = data[left + i];
    }
    for (j = 0 ; j < n2 ; j++){
        R[j] = data[mid + 1 + j];
    }

    i = j = 0;
    k = left;

    while (i < n1 && j < n2){
        if (L[i] < R[j]){
            data[k] = L[i];
            i++;
        }
        else {
            data[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        data[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        data[k] = R[j];
        j++;
        k++;
    }
}

//5-Merge Sort
template <class T>
void SortingSystem<T>::mergeSort(int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort( left, mid);
        mergeSort( mid + 1 , right);

        merge( left, mid, right);
        displayData();
    }

}


//quick sort helper
template <class T>
int SortingSystem<T>::partition(int low, int high){
    T pivot = data[low];
    int i = low ;

    for (int j = low + 1; j <= high; j++) {
        if (data[j] <= pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i], data[low]);

    return (i);
}

//6-Quick Sort
template <class T>
void SortingSystem<T>::quickSort(int low, int high){
    if (low < high) {

        int pi = partition(low, high);
        displayData();
    
        quickSort(low, pi - 1);
    
        quickSort(pi + 1, high);
        
        }
}


//7-Count Sort
//8-Radix Sort
template <class T>
void SortingSystem<T>::countSort()
{
    cout << "This Sorting algorithm is designed to work only with Integer values." <<endl;

}
template <>
void SortingSystem<int>::countSort()
{

        int sortedArr[size];
        int max = data[0];

        for (int i = 1; i < size; i++) {
            if (data[i] > max)
                max = data[i];
        }
        int count[max + 1];

        for (int i = 0; i <= max; ++i) {
            count[i] = 0;
        }

        for (int i = 0; i < size; i++) {
            count[data[i]]++;
        }

        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--) {
            sortedArr[count[data[i]] - 1] = data[i];
            count[data[i]]--;
        }

        for (int i = 0; i < size; i++) {
            data[i] = sortedArr[i];
        }
    cout << "Sorted Data: ";
    displayData();

}

//Get the maximum element in the array
int getMax(const int arr[], int n)
{
    int maximum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maximum)
            maximum = arr[i];
    }
    return maximum;
}

//Counting algorithm for the Radix sort
void Counting(int A[] , int n , int place)
{
    int B[n];
    int C[10] = {0};
    for (int i = 0 ; i < n ; i++)//count the occurences of each digit at place
    {
        int digit = (A[i]/place) %10;
        C[digit]++;
    }
    for (int i = 1 ; i < 10 ; i++)//compute the cumulative count
        C[i] += C[i-1];
    for (int i = n-1 ; i >= 0 ; i--)//Build the output array->sort by current digit
    {
        int digit = (A[i]/place) %10;
        B[C[digit]-1] = A[i];
        C[digit]--;
    }
    for (int i = 0 ; i < n ; i++)
        A[i] = B[i];
    cout << "After sorting by place " << place << ": ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

}

//8-Radix Sort
template <class T>
void SortingSystem<T>::radixSort()
{
    cout << "This Sorting algorithm is designed to work only with Integer values." <<endl;

}
// Radix for Integers
template <>
void SortingSystem<int>::radixSort()
{
    int maxval = getMax(data , size);
    for (int place = 1 ; maxval/place > 0 ; place *= 10)
        Counting(data,size,place);
    cout << "Sorted Data: ";
    displayData();
}

//Insertion sort for Buckets
template <class T>
void insertSorted(T bucket[], int &size, T value)
{
    int i = size - 1;
    while (i >= 0 && bucket[i] > value)
    {
        bucket[i + 1] = bucket[i]; // Shift elements to the right
        i--;
    }
    bucket[i + 1] = value;
    size++;
}
//1-Integer
void bucketSortInteger(int arr[], int n)
{
    int buckets[BUCKETS][n] = {0};
    int bucketSize[BUCKETS] = {0};

    int maxVal = getMax(arr,n);

    for (int i = 0; i < n; i++)
    {
        int index = (BUCKETS * arr[i]) / (maxVal + 1);
        insertSorted(buckets[index], bucketSize[index], arr[i]);
    }

    int idx = 0;
    for (int i = 0; i < BUCKETS; i++)
        for (int j = 0; j < bucketSize[i]; j++)
            arr[idx++] = buckets[i][j];
}

//2-Float
void bucketSortFloat(float arr[], int n) {
    float buckets[BUCKETS][SIZE];
    int bucketSize[BUCKETS] = {0};

    for (int i = 0; i < n; i++) {
        int index = static_cast<int>(arr[i] * BUCKETS);
        if (index >= BUCKETS)
            index = BUCKETS - 1;
        insertSorted(buckets[index], bucketSize[index], arr[i]);
    }

    int idx = 0;
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}


// Generic bucketSort (Invalid for non-int/float types)
template <class T>
void SortingSystem<T>::bucketSort() {
    cout << "Bucket sort is only available for integers and floats.\n";
}

// Specialization for integers
template <>
void SortingSystem<int>::bucketSort() {
    cout << "Sorting integers using bucketSortInteger\n";
    bucketSortInteger(data, size);
    cout << "Sorted Data: ";
    displayData();
}

// Specialization for floats
template <>
void SortingSystem<float>::bucketSort() {
    cout << "Sorting floats using bucketSortFloat\n";
    bucketSortFloat(data, size);
    cout << "Sorted Data: ";
    displayData();
}



//Main
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

        cout << "\n please enter the data type of the array:\n";
        cout << "1. Integer\n";
        cout << "2. Float\n";
        cout << "3. Double\n";
        cout << "4. Char\n";
        cout << "5. String\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            SortingSystem<int> sort(n);
            sort.showMenu();
        }
        else if (choice == 2)
        {
            SortingSystem<float> sort(n);
            sort.showMenu();
        }
        else if (choice == 3)
        {
            SortingSystem<double> sort(n);
            sort.showMenu();
        }
        else if (choice == 4)
        {
            SortingSystem<char> sort(n);
            sort.showMenu();
        }
        else if (choice == 5)
        {
            SortingSystem<string> sort(n);
            sort.showMenu();
        }
        else
        {
            cout << "Invalid choice\n";
        }
    
    return 0;
} 
