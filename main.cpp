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

//�㭪�� �����뢠��� ������⢮ ����� ����� ���� ����ࠬ�
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
    return vec.end();
}

//�㭪�� ��������� ᠬ�� ����� �᫮ � ����� std::vector<int>
int left_v_int(vector<int> &vec){
    return *vec.begin();
}

//�㭪�� ��������� ᠬ�� �ࠢ�� �᫮ � ����� std::vector<int>
int right_v_int(vector<int> &vec){
    return *vec.end();
}

// ������ ���஢�� std::vector<int>
stats quick_sort_count(vector<int> &vec, int left, int right, int &count, int &copy){
    stats stat;
    int i = left;
    int j = right;
    int pivot = vec[(left+right)/2];
    //��砫� ����� �६���
    clock_t start = clock();
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
    //����� ����� �६���
    clock_t end = clock();
    stat.count = count;
    stat.copy = copy;
    stat.time = (double) (end - start) / CLOCKS_PER_SEC;
    return stat;
}
// �������訩 ����� � ����� std::vector<int>
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
    int largest = i; // ���樠�����㥬 �������訩 ����� ��� ��७�
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && vec[l]>vec[largest]){  // �᫨ ���� ���୨� ����� ����� ����
        largest = l;
    }
    if(r<n && vec[r]>vec[largest]){  // �᫨ �ࠢ� ���୨� ����� �����, 祬 ᠬ� ����让 ����� �� ����� ������
        largest = r;
    }
    if(largest!=i){ // �᫨ ᠬ� ����让 ����� �� ��७�
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

void exp(int size){
    vector<int> vec;
    int count = 0;
    int copy = 0;
    for(int i=0;i<size;i++){
        vec.push_back(rand()%100);
    }
    vector<int> vec1 = vec;
    vector<int> vec2 = vec;
    vector<int> vec3 = vec;
    stats stat1 = bubble_sort_count(vec1,left_v(vec1),right_v(vec1));
    stats stat2 = quick_sort_count(vec2,left_v_int(vec2),right_v_int(vec2),count,copy);
    stats stat3 = heap_sort(vec3);
    //������ � 䠩� ������ � ���஢�� stats
    FILE *file;
    char file_name[20];
    sprintf(file_name,"stats %d.txt",size);
    file = fopen(file_name,"a");
    fprintf(file,"bubble_sort_count: %d %d %f\n",stat1.count,stat1.copy,stat1.time);
    fprintf(file,"quick_sort_count: %d %d %f\n",stat2.count,stat2.copy,stat2.time);
    fprintf(file,"heap_sort: %d %d %f\n",stat3.count,stat3.copy,stat3.time);
}

