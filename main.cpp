#include <iostream>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <iterator>
using namespace std;

struct stats{
    int count;
    int copy;
    double time;
    stats(){
        count=0;
        copy=0;
        time=0;
    }
};

//функция высчитывающая количество элементв между двумя итераторами
int count_between_iter(vector<int>::iterator left, vector<int>::iterator right){
    int count=0;
    for(auto i=left;i<right;i++){
        count++;
    }
    return count;
}
//сортировка пузырьком std::vector<int> &vec c использованием итераторов
stats bubble_sort_count(vector<int> &vec, vector<int>::iterator left, vector<int>::iterator right) {
    stats stat;
    int count = 0;
    int copy = 0;
    //начало отсчета времени
    clock_t start = clock();
    for (int i = 0; i < count_between_iter(left, right)+1; i++) {
        for (int j = 0; j < count_between_iter(left, right); j++) {
            if (vec[j] > vec[j + 1]) {
                int tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
                copy++;
            }
            count++;
        }
    }
    //конец отсчета времени
    clock_t end = clock();
    stat.count = count;
    stat.copy = copy;
    stat.time = (double) (end - start) / CLOCKS_PER_SEC;
    return stat;
}
//функция возвращающая итератор на самое левое число в векторе std::vector<int>
std::vector<int>::iterator left_v(vector<int> &vec){
    return vec.begin();
}

//функция возвращающий итератор на самое правое число в векторе std::vector<int>
std::vector<int>::iterator right_v(vector<int> &vec){
    return vec.end()-1;
}

//функция возвращающая самое левое число в векторе std::vector<int>
int left_v_int(vector<int> &vec){
    return *vec.begin();
}

//функция возвращающая самое правое число в векторе std::vector<int>
int right_v_int(vector<int> &vec){
    //указатель на последний элемент вектора
    auto it = vec.end()-1;
    return *it;
}

// быстрая сортировка std::vector<int> c  использованием итераторов с подсчетом количества операций и копирований
stats quick_sort_count(vector<int> &vec, vector<int>::iterator left, vector<int>::iterator right, int &count, int &copy){
    stats stat;
    //начало отсчета времени
    clock_t start = clock();
    //указатель на первый элемент вектора
    auto it_left = left;
    //указатель на последний элемент вектора
    auto it_right = right;
    //указатель на середину вектора
    auto it_middle = left + (right - left) / 2+1;
    //выбор опорного элемента
    int pivot = *it_middle;
    //разделение вектора на две части
    while (it_left <= it_right) {
        while (*it_left < pivot) {
            it_left++;
            count++;
        }
        while (*it_right > pivot) {
            it_right--;
            count++;
        }
        if (it_left <= it_right) {
            int tmp = *it_left;
            *it_left = *it_right;
            *it_right = tmp;
            it_left++;
            it_right--;
            copy++;
        }
    }
    //рекурсивные вызовы, если есть, что сортировать
    if (left < it_right) {
        quick_sort_count(vec, left, it_right,  count, copy);
    }
    if (it_left < right) {
        quick_sort_count(vec, it_left, right,  count, copy);
    }
    //конец отсчета времени

        clock_t end = clock();
        stat.count = count;
        stat.copy = copy;
        stat.time = (double) (end - start) / CLOCKS_PER_SEC;
        return stat;

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

//функция для пирамидальной сортировки std::vector<int> (1 этап)
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
stats heap_sort(std::vector<int> &vec){
    int n = vec.size();
    //начало отсчета времени
    clock_t start = clock();
    for(int i=n/2-1;i>=0;i--){
        heapify(vec,n,i);
    }
    for(int i=n-1;i>=0;i--){
        int tmp = vec[0]; // переносим последний элемент в конец
        vec[0] = vec[i];
        vec[i] = tmp;
        heapify(vec,i,0); // заново первый этап
    }
    //конец отсчета времени
    clock_t end = clock();
    stats stat;
    stat.count = 0;
    stat.copy = 0;
    stat.time = (double) (end - start) / CLOCKS_PER_SEC;
    return stat;
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

//вывод вектора std::vector<int>
void printVector(vector<int> &vec,char *str){
    cout << str << endl;
    for(int i : vec){
        cout << i << " ";
    }
    cout << endl;
}
//функция для сортировки в обратном порядке vector<int>
vector<int> reverse(vector<int> &vec){
    vector<int> vec_reverse;
    for(int i=vec.size()-1;i>=0;i--){
        vec_reverse.push_back(vec[i]);
    }
    return vec_reverse;
}

void exp(int size){
    vector<int> vec;
    int count = 0;
    int copy = 0;
    int flag = 0;
    for(int i=0;i<size;i++){
        vec.push_back(rand()%100);
    }
    for(int m : vec){
        cout << m << " ";
    }
    cout << endl;
    vector<int> vec_bubl = vec;
    vector<int> vec_quick = vec;
    vector<int> vec_heap = vec;

    stats stat1 = bubble_sort_count(vec_bubl,left_v(vec_bubl),right_v(vec_bubl));
    printVector(vec_bubl,"bubble_sort");
    stats stat2 = quick_sort_count(vec_quick,left_v(vec_quick),right_v(vec_quick) , count, copy);
    printVector(vec_quick,"quick_sort");
    stats stat3 = heap_sort(vec_heap);
    printVector(vec_heap,"heap_sort");
    vector<int> vec_bubl_back = reverse(vec_bubl);
    printVector(vec_bubl_back,"bubble_sort_back_before_sort");
    stats stat4 = bubble_sort_count(vec_bubl_back,left_v(vec_bubl_back),right_v(vec_bubl_back));
    printVector(vec_bubl_back,"bubble_sort_back_after_sort");

    //запись в файл данных о сортировке stats
    FILE *file;
    file = fopen("stats.txt","a");
    fprintf(file,"%d\n",size);
    fprintf(file,"bubble_sort: count: %d copy: %d time: %f\n",stat1.count,stat1.copy,stat1.time);
    fprintf(file,"quick_sort: count: %d copy: %d time: %f\n",stat2.count,stat2.copy,stat2.time);
    fprintf(file,"heap_sort: count: %d copy: %d time: %f\n",stat3.count,stat3.copy,stat3.time);
    fprintf(file,"bubble_sort_back: count: %d copy: %d time: %f\n",stat4.count,stat4.copy,stat4.time);
}


int main() {
    srand(time(NULL));
    int loop;
    cout << "Enter 1 to sort massive" << endl;
    cout << "Enter 2 to make file with data-stats" << endl;
    cin >> loop;
    if(loop==2) {
        exp(100);
        //exp(2000);
        //exp(3000);
        //exp(4000);
        //exp(5000);
        //exp(6000);
        //exp(7000);
        // exp(8000);
        // exp(9000);
        // exp(10000);
        //exp(25000);
        // exp(50000);
        // exp(100000);
    }
    if(loop==1){
        int loop_sort;
        int size=100;
        vector<int> vec;
        cout << "Enter 1 - bouble sort" << endl;
        cout << "Enter 2 - quick sort" << endl;
        cout << "Enter 3 - heap sort" << endl;
        cin >> loop_sort;
        if(loop_sort==1){
            if(vec.empty()){
            vec.clear();}
            for(int i=0;i<size;i++){
                vec.push_back(rand()%100);
            }
            cout<<"Исходный массив";
            for(int m : vec){
                cout << m << " ";
            }
            cout<< endl;
            stats stat1 = bubble_sort_count(vec,left_v(vec),right_v(vec));
            printVector(vec,"bubble_sort");
            cout<<" Count: "<< stat1.count;
            cout<< " Copy: "<<stat1.copy;
            cout<<" time: "<< stat1.time;
        }
        if(loop_sort==2){
            int count=0;
            int copy=0;
            if(vec.empty()){
                vec.clear();}
            for(int i=0;i<size;i++){
                vec.push_back(rand()%100);
            }
            cout<<"Исходный массив\n";
            for(int m : vec){
                cout << m << " ";
            }
            cout<< endl;
            stats stat2 = quick_sort_count(vec,left_v(vec),right_v(vec) , count, copy);
            printVector(vec,"quick_sort");
            cout<<" Count: "<< stat2.count;
            cout<< "Copy: "<<stat2.copy;
            cout<<" time: "<< stat2.time;
        }
        if(loop_sort==3){
            if(vec.empty()){
                vec.clear();}
            for(int i=0;i<size;i++){
                vec.push_back(rand()%100);
            }
            cout<<"Исходный массив\n";
            for(int m : vec){
                cout << m << " ";
            }
            cout<< endl;
            stats stat3 = heap_sort(vec);
            printVector(vec,"heap_sort");
            cout<<" Count: "<< stat3.count;
            cout<< " Copy: "<< stat3.copy;
            cout<<" time: "<< stat3.time;
        }
    }
    return 0;
}