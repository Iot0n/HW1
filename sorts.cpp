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
    std::cout << std::endl;
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

void inputSort(int *mass, int size){
    int boofer;
    //bool input = false;
    for (int j = 1; j < size; j++){
        boofer = mass[j];
        for (int i = j;; i--){
            if (boofer >= mass[i-1] || i == 0){
                mass[i] = boofer;
                break;
            }
            if (boofer < mass[i-1])
                mass[i] = mass[i-1];
        }
    }
}

void test_inputSort(){
    const int size = 10;
    int mass[size] = {10, 20, 43, 68, 2, 0, 1, 23, 43, 65};
    int etalonmass[size] = {0,1 ,2, 10, 20, 23, 43, 43, 65, 68};
    inputSort(mass, size);
    for (int i = 0; i < size; i++) {
        if (mass[i] != etalonmass[i]) {
            std::cout << "bad inputSort";
            break;
        }
    }
    for (int i = 0; i < size; i++)
        std::cout << mass[i] << " ";
}

int get_max(int *mass, int size){
    int diapason = 0;
    for (int i = 0; i < size; i++){
        if (diapason < mass[i])
            diapason = mass[i];
    }
    return diapason;
}


void countSort(int *mass, int size) {
    int diapason = get_max(mass, size);
    int *boofmass = new int[diapason];
    for (int i = 0; i < diapason; i++)
        boofmass[i] = 0;
    for (int i = 0; i < size; i++) {
        boofmass[mass[i]]++;
    }
    int numb = 0;
    for (int i = 0; i <= diapason; i++) {
        if (boofmass[i] != 0) {
            for (int j = 0; j < boofmass[i]; j++) {
                mass[numb] = i;
                numb++;
            }
        }
    }
        delete[] boofmass;
}

void test_countSort(){
    const int size = 10;
    int mass[size] = {10, 20, 43, 68, 2, 7, 0, 23, 43, 65};
    int etalonmass[size] = {0,2 ,7, 10, 20, 23, 43, 43, 65, 68};
    countSort(mass, size);
    for (int i = 0; i < size; i++) {
        if (mass[i] != etalonmass[i]) {
            std::cout << "bad countSort";
            break;
        }
    }
    for (int i = 0; i < size; i++)
        std::cout << mass[i] << " ";
}

int main() {
    test_countSort();
    return 0;
}
