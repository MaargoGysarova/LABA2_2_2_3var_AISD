#include <iostream>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
using namespace std;

//���஢�� ����쪮� std::vector<int> &vec
void bubble_sort(std::vector<int> &vec){
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec.size()-1;j++){
            if(vec[j]>vec[j+1]){
                int tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
        }
    }
}

//�㭪�� ��������� ᠬ�� ����� �᫮ � ����� std::vector<int> &vec
int left_v(std::vector<int> &vec){
    return vec[0];
}

//�㭪�� ��������� ᠬ�� �ࠢ�� �᫮ � ����� std::vector<int>
int right_v(std::vector<int> &vec){
    return vec[vec.size()-1];
}

// ������ ���஢�� std::vector<int>
void quick_sort(std::vector<int> &vec, int left, int right){
    int i = left;
    int j = right;
    int pivot = vec[(left+right)/2];
    while(i<=j){
        while(vec[i]<pivot){
            i++;
        }
        while(vec[j]>pivot){
            j--;
        }
        if(i<=j){
            int tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
            i++;
            j--;
        }
    }
    if(left<j){
        quick_sort(vec,left,j);
    }
    if(i<right){
        quick_sort(vec,i,right);
    }
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
