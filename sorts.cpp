#include <iostream>

void swap(int& a, int& b) {
    a += b;
    b = a - b;
    a = a - b;
}

void bubblesort(int *mass, int size) {
    bool sorted = false;
    while (!sorted) {
        for (int i = 1; i < size; i++) {
            if (mass[i] < mass[i - 1])
                swap(mass[i], mass[i - 1]);
            else {
                sorted = true;
                break;
            }
        }
    }
}

void test (){
    const int size = 10;
    int mass[size] = {10, 20, 43, 68, 2, 0, 1, 23, 43, 65};
    int etalonmass[size] = {0,1 ,2, 10, 20, 23, 43, 43, 65, 68};
    bubblesort(mass, size);
    for (int i = 0; i < size; i++) {
        if (mass[i] != etalonmass[i])
            std::cout << "bad sort";
    }
}

int main() {
    test;
    return 0;
}
