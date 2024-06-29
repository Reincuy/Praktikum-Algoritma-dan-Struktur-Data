#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void insertionSort(std::vector<char>& arr) {
    auto n = arr.size();
    for (std::vector<char>::size_type i = 1; i < n; ++i) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(std::vector<char>& arr, std::vector<char>::size_type l, std::vector<char>::size_type m, std::vector<char>::size_type r) {
    auto n1 = m - l + 1;
    auto n2 = r - m;

    std::vector<char> L(n1), R(n2);

    for (std::vector<char>::size_type i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (std::vector<char>::size_type i = 0; i < n2; ++i)
        R[i] = arr[m + 1 + i];

    std::vector<char>::size_type i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<char>& arr, std::vector<char>::size_type l, std::vector<char>::size_type r) {
    if (l < r) {
        auto m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void shellSort(std::vector<char>& arr) {
    auto n = arr.size();
    for (std::vector<char>::size_type gap = n / 2; gap > 0; gap /= 2) {
        for (std::vector<char>::size_type i = gap; i < n; ++i) {
            char temp = arr[i];
            std::vector<char>::size_type j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int partition(std::vector<char>& arr, int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<char>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(std::vector<char>& arr) {
    auto n = arr.size();
    for (std::vector<char>::size_type i = 0; i < n - 1; ++i) {
        for (std::vector<char>::size_type j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<char>& arr) {
    auto n = arr.size();
    for (std::vector<char>::size_type i = 0; i < n - 1; ++i) {
        std::vector<char>::size_type minIdx = i;
        for (std::vector<char>::size_type j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(arr[minIdx], arr[i]);
    }
}

void printVector(const std::vector<char>& arr) {
    for (char c : arr) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main() {
    std::string name = "M. Samil Rendy Nor Saleh";
    std::string nim = "2310817310004";
    std::vector<char> nameVec(name.begin(), name.end());
    std::vector<char> nimVec(nim.begin(), nim.end());

    while (true) {
        std::cout << "\nSORTING\n";
        std::cout << "1. Insertion Sort (Name)\n";
        std::cout << "2. Merge Sort (Name)\n";
        std::cout << "3. Shell Sort (Name)\n";
        std::cout << "4. Quick Sort (NIM)\n";
        std::cout << "5. Bubble Sort (NIM)\n";
        std::cout << "6. Selection Sort (NIM)\n";
        std::cout << "7. Exit\n";
        std::cout << "Masukkan Pilihan: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                insertionSort(nameVec);
                std::cout << "Sorted Name: ";
                printVector(nameVec);
                break;
            case 2:
                mergeSort(nameVec, 0, nameVec.size() - 1);
                std::cout << "Sorted Name: ";
                printVector(nameVec);
                break;
            case 3:
                shellSort(nameVec);
                std::cout << "Sorted Name: ";
                printVector(nameVec);
                break;
            case 4:
                quickSort(nimVec, 0, nimVec.size() - 1);
                std::cout << "Sorted NIM: ";
                printVector(nimVec);
                break;
            case 5:
                bubbleSort(nimVec);
                std::cout << "Sorted NIM: ";
                printVector(nimVec);
                break;
            case 6:
                selectionSort(nimVec);
                std::cout << "Sorted NIM: ";
                printVector(nimVec);
                break;
            case 7:
                return 0;
            default:
                std::cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    }
    return 0;
}
