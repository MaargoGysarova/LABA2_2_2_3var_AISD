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

//�㭪�� �����뢠��� ������⢮ ������� ����� ���� ����ࠬ�
int count_between_iter(vector<int>::iterator left, vector<int>::iterator right){
    int count=0;
    for(auto i=left;i<right;i++){
        count++;
    }
    return count;
}
//���஢�� ����쪮� std::vector<int> &vec c �ᯮ�짮������ ����஢
stats bubble_sort_count(vector<int> &vec, vector<int>::iterator left, vector<int>::iterator right) {
    stats stat;
    int count = 0;
    int copy = 0;
    //��砫� ����� �६���
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
    //����� ����� �६���
    clock_t end = clock();
    stat.count = count;
    stat.copy = copy;
    stat.time = (double) (end - start) / CLOCKS_PER_SEC;
    return stat;
}
//�㭪�� ��������� ����� �� ᠬ�� ����� �᫮ � ����� std::vector<int>
std::vector<int>::iterator left_v(vector<int> &vec){
    return vec.begin();
}

//�㭪�� �������騩 ����� �� ᠬ�� �ࠢ�� �᫮ � ����� std::vector<int>
std::vector<int>::iterator right_v(vector<int> &vec){
    return vec.end()-1;
}

//�㭪�� ��������� ᠬ�� ����� �᫮ � ����� std::vector<int>
int left_v_int(vector<int> &vec){
    return *vec.begin();
}

//�㭪�� ��������� ᠬ�� �ࠢ�� �᫮ � ����� std::vector<int>
int right_v_int(vector<int> &vec){
    //㪠��⥫� �� ��᫥���� ������� �����
    auto it = vec.end()-1;
    return *it;
}

// ������ ���஢�� std::vector<int> c  �ᯮ�짮������ ����஢ � �����⮬ ������⢠ ����権 � ����஢����
stats quick_sort_count(vector<int> &vec, vector<int>::iterator left, vector<int>::iterator right, int &flag, int &count, int &copy){
    stats stat;
    count = 0;
    copy = 0;
    flag += 1;
    //��砫� ����� �६���
    clock_t start = clock();
    //㪠��⥫� �� ���� ������� �����
    auto it_left = left;
    //㪠��⥫� �� ��᫥���� ������� �����
    auto it_right = right;
    //㪠��⥫� �� �।��� �����
    auto it_middle = left + (right - left) / 2+1;
    //�롮� ���୮�� �������
    int pivot = *it_middle;
    //ࠧ������� ����� �� ��� ���
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
    //४��ᨢ�� �맮��, �᫨ ����, �� ���஢���
    if (left < it_right) {
        quick_sort_count(vec, left, it_right, flag, count, copy);
    }
    if (it_left < right) {
        quick_sort_count(vec, it_left, right, flag, count, copy);
    }
    //����� ����� �६���

        clock_t end = clock();
        stat.count = count;
        stat.copy = copy;
        stat.time = (double) (end - start) / CLOCKS_PER_SEC;
        return stat;

}


// �������訩 ������� � ����� std::vector<int>
int max_v(std::vector<int> &vec){
    int max = vec[0];
    for(int i=1;i<vec.size();i++){
        if(vec[i]>max){
            max = vec[i];
        }
    }
    return max;
}

//�㭪�� ��� ��ࠬ����쭮� ���஢�� std::vector<int>
void heapify(std::vector<int> &vec, int n, int i){
    int largest = i; // ���樠�����㥬 �������訩 ������� ��� ��७�
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && vec[l]>vec[largest]){  // �᫨ ���� ���୨� ������� ����� ����
        largest = l;
    }
    if(r<n && vec[r]>vec[largest]){  // �᫨ �ࠢ� ���୨� ������� �����, 祬 ᠬ� ����让 ������� �� ����� ������
        largest = r;
    }
    if(largest!=i){ // �᫨ ᠬ� ����让 ������� �� ��७�
        int tmp = vec[i];
        vec[i] = vec[largest];
        vec[largest] = tmp;
        heapify(vec,n,largest); // �����ᨢ�� �८�ࠧ㥬 � ������� ���� ���஭�⮥ �����ॢ�
    }
}
//��ࠬ����쭠� ���஢�� std::vector<int>
stats heap_sort(std::vector<int> &vec){
    int n = vec.size();
    //��砫� ����� �६���
    clock_t start = clock();
    for(int i=n/2-1;i>=0;i--){
        heapify(vec,n,i);
    }
    for(int i=n-1;i>=0;i--){
        int tmp = vec[0];
        vec[0] = vec[i];
        vec[i] = tmp;
        heapify(vec,i,0);
    }
    //����� ����� �६���
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

//�뢮� ����� std::vector<int>
void printVector(vector<int> &vec,char *str){
    cout << str << endl;
    for(int i : vec){
        cout << i << " ";
    }
    cout << endl;
}
//�㭪�� ��� ���஢�� � ���⭮� ���浪� vector<int>
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
    stats stat2 = quick_sort_count(vec_quick,left_v(vec_quick),right_v(vec_quick) ,flag, count, copy);
    printVector(vec_quick,"quick_sort");
    stats stat3 = heap_sort(vec_heap);
    printVector(vec_heap,"heap_sort");
    vector<int> vec_bubl_back = reverse(vec_bubl);
    printVector(vec_bubl_back,"bubble_sort_back_before_sort");
    stats stat4 = bubble_sort_count(vec_bubl_back,left_v(vec_bubl_back),right_v(vec_bubl_back));
    printVector(vec_bubl_back,"bubble_sort_back_after_sort");

    //������ � 䠩� ������ � ���஢�� stats
    FILE *file;
    char file_name[20];
    sprintf(file_name,"stats %d.txt",size);
    file = fopen(file_name,"a");
    fprintf(file,"bubble_sort: count: %d copy: %d time: %f\n",stat1.count,stat1.copy,stat1.time);
    fprintf(file,"quick_sort: count: %d copy: %d time: %f\n",stat2.count,stat2.copy,stat2.time);
    fprintf(file,"heap_sort: count: %d copy: %d time: %f\n",stat3.count,stat3.copy,stat3.time);
    fprintf(file,"bubble_sort_back: count: %d copy: %d time: %f\n",stat4.count,stat4.copy,stat4.time);
}


int main() {
    srand(time(NULL));
    int size = 10;
    exp(size);
    return 0;
}