#include <iostream>

void swap(int& a, int& b) {
    a += b;
    b = a - b;
    a = a - b;
}

void bubbleSort(int *mass, int size) {
    bool swapped = false;
    while (1) {
        swapped = false;
        for (int i = 0; i < (size-1) ; i++) {
            if (mass[i] > mass[i + 1]) {
                swap(mass[i], mass[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void test_bubbleSort (){
    const int size = 10;
    int mass[size] = {10, 20, 43, 68, 2, 0, 1, 23, 43, 65};
    int etalonmass[size] = {0,1 ,2, 10, 20, 23, 43, 43, 65, 68};
    bubbleSort(mass, size);
    for (int i = 0; i < size-1; i++) {
        if (mass[i] != etalonmass[i]) {
            std::cout << "bad bubbleSort" << std::endl;
            break;
        }
    }
    for (int i = 0; i < size; i++)
        std::cout << mass[i] << " ";
}

int get_max_ind(int *mass, int size){
    int maxind = 0;
    for (int i = 0; i < size; i++){
        if (mass[maxind] < mass[i])
            maxind = i;
    }
    return maxind;
}

void test_get_max_ind(){
    int mass[] = {10, 20, 43, 68, 2, 0, 1, 23, 43, 65};
    int maxind = get_max_ind(mass, 10);
    if (maxind != 3){
        std::cout << "bad test_get_max";
    }
}

void selectionSort(int *mass, int size){
    int maxind;
    while (size){
        maxind = get_max_ind(mass, size);
        swap(mass[maxind], mass[size]);
        size--;
    }
}

void test_selectionSort (){
    const int size = 10;
    int mass[size] = {10, 20, 43, 68, 2, 0, 1, 23, 43, 65};
    int etalonmass[size] = {0,1 ,2, 10, 20, 23, 43, 43, 65, 68};
    selectionSort(mass, size);
    for (int i = 0; i < size; i++) {
        if (mass[i] != etalonmass[i]) {
            std::cout << "bad selectionSort";
            break;
        }
    }
}

int main() {
    test_bubbleSort();
    test_get_max_ind();
    return 0;
}
