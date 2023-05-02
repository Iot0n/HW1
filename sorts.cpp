#include <iostream>
#include "sorts.h"

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



void quickSort(int *mass, int low, int high) {
    int i = low;
    int j = high;
    int pivot = mass[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (mass[i] < pivot)
            i++;
        while (mass[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = mass[i];
            mass[i] = mass[j];
            mass[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(mass, low, j);
    if (i < high)
        quickSort(mass, i, high);

}

void mergeSort(int *mass, int size){
	if (size == 1)
	return;

  mergeSort(mass, size/2);
  mergeSort(&mass[size/2], size - size/2);

  int liter = 0; // left half iteraor
  int riter = 0; // right half iteraor
  int tmp[size];

  for(int i = 0; i < size; i++){
    if(mass[liter] < mass[size/2 + riter])
      tmp[i] = mass[liter++];
    else
      tmp[i] = mass[size/2 + riter++];

    if (liter == size / 2){ /* ran out of left half */
      while(riter < size - size / 2)
        tmp[++i] = mass[size/2 + riter++];
      break;
    } else if (riter == size - size / 2){ /* ran out of right half */
      while(liter < size / 2)
        tmp[++i] = mass[liter++];
      break;
    }
  }

  for(int i = 0; i < size; i++)
    mass[i] = tmp[i];
}

void test(){
    const int size = 10;
    int mass[size] = {10, 20, 43, 68, 2, 7, 0, 23, 43, 65};
    int etalonmass[size] = {0,2 ,7, 10, 20, 23, 43, 43, 65, 68};
    mergeSort(mass, size);
    for (int i = 0; i < size; i++) {
        if (mass[i] != etalonmass[i]) {
            std::cout << "bad Sort" << "  ";
            break;
        }
    }
    for (int i = 0; i < size; i++)
        std::cout << mass[i] << " ";
}

int main() {
    //test();
    //return 0;
}
