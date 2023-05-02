#include <iostream>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <iterator>
using namespace std;

//функция высчитывающая количество элементв между двумя итераторами
int count_between_iter(vector<int>::iterator left, vector<int>::iterator right){
    int count=0;
    for(auto i=left;i<right;i++){
        count++;
    }
    return count;
}
//сортировка пузырьком std::vector<int> &vec c использованием итераторов
void bubble_sort_count(std::vector<int> &vec, vector<int>::iterator left, vector<int>::iterator right) {
    int count = 0;
    int copy = 0;
    for (int i = *left; i < count_between_iter(left, right); i++) {
        for (int j = 0; j < count_between_iter(left, right) - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                int tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
                copy++;
            }
            count++;
        }
    }
    cout << "Количество сравнений: " << count << endl;
    cout << "Количество копирований: " << copy << endl;
}
//функция возвращающая итератор на самое левое число в векторе std::vector<int>
std::vector<int>::iterator left_v(std::vector<int> &vec){
    return vec.begin();
}

//функция возвращающий итератор на самое правое число в векторе std::vector<int>
std::vector<int>::iterator right_v(std::vector<int> &vec){
    return vec.end();
}


// быстрая сортировка std::vector<int>
void quick_sort_count(std::vector<int> &vec, int left, int right, int &count, int &copy){
    int i = left;
    int j = right;
    int pivot = vec[(left+right)/2];
    while(i<=j){
        while(vec[i]<pivot){
            i++;
            count++;
        }
        while(vec[j]>pivot){
            j--;
            count++;
        }
        if(i<=j){
            int tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
            i++;
            j--;
            copy++;
        }
    }
    if(left<j){
        quick_sort_count(vec,left,j,count,copy);
    }
    if(i<right){
        quick_sort_count(vec,i,right,count,copy);
    }
}
// наибольший элемент в векторе std::vector<int>
int max_v(std::vector<int> &vec){
    int max = vec[0];
    for(int i=1;i<vec.size();i++){
        if(vec[i]>max){
            max = vec[i];
        }
    }
    return max;
}

//функция для пирамидальной сортировки std::vector<int>
void heapify(std::vector<int> &vec, int n, int i){
    int largest = i; // Инициализируем наибольший элемент как корень
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && vec[l]>vec[largest]){  // Если левый дочерний элемент больше корня
        largest = l;
    }
    if(r<n && vec[r]>vec[largest]){  // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
        largest = r;
    }
    if(largest!=i){ // Если самый большой элемент не корень
        int tmp = vec[i];
        vec[i] = vec[largest];
        vec[largest] = tmp;
        heapify(vec,n,largest); // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
    }
}
//пирамидальная сортировка std::vector<int>
void heap_sort(std::vector<int> &vec){
    int n = vec.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(vec,n,i);
    }
    for(int i=n-1;i>=0;i--){
        int tmp = vec[0];
        vec[0] = vec[i];
        vec[i] = tmp;
        heapify(vec,i,0);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}