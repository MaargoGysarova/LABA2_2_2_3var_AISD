#include <iostream>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>

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

//�㭪�� ��������� ᠬ�� �ࠢ�� �᫮ � ����� std::vector<int> &vec
int right_v(std::vector<int> &vec){
    return vec[vec.size()-1];
}

// ������ ���஢�� std::vector<int> &vec
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

