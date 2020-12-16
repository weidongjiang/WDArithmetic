//
//  WDArithmeticManager.c
//  WDArithmetic
//
//  Created by 伟东 on 2020/12/16.
//

#include "WDArithmeticManager.h"











































//-----------------------------------------------------------------------
//直接插入排序算法
void insert_sort (int *array,int n) {
    int j;
    for (int i = 1;i < n; i++) {//直接插入排序算法
        int temp = array[i];//直接插入排序算法
        j = i-1;//直接插入排序算法
        
        while (temp < array[j] && j >= 0) {
            array[j+1] = array[j];
            j--;
        }
        
        array[j+1] = temp;
    }
}


void insertSort (void) {
    int i;
    int n = 10;
    int a[10] = {2,3,9,5,4,1,6,8,23,34};
    insert_sort(a,n);
    
    for (i = 1; i <= n; i++) {
        printf("%d-",a[i]);
    }
}


//-----------------------------------------------------------------------
// 选择排序
void select_sort (int *array, int n) {
    int temp;
    int i,small,j;
    
    for (i = 0 ;i < n-1;i++) {
        small = i;
        for (j = i+1; j<n; j++) {
            if (array[j] < array[small]) {
                small = j;
            }
        }
        
        if (small != i) {
            temp = array[i];
            array[i] = array[small];
            array[small] = temp;
        }
    }
}

void selectSort (void) {
    int i;
    int n = 10;
    int a[] = {2,3,9,5,4,7,6,8,23,34};
    select_sort(a,n);
    
    for (i = 1; i <= n; i++) {
        printf("%d-",a[i]);
    }
}





//-----------------------------------------------------------------------
// 冒泡排序
void bubbling_sort (int *array, int n) {
    for (int i = 1; i <= n-1; i++) {
        for (int j = 1; j <= n-i; j++) {
            if (array[j] < array[j+1]) {
                int t = array[j];
                array[j] = array[j+1];
                array[j+1] = t;
            }
        }
    }
}

void bubblingSort (void) {
    int i;
    int n = 9;
    int a[10] = {2,3,9,5,4,1,6,8,23,34};
    bubbling_sort(a,n);
    
    for (i = 1; i <= n; i++) {
        printf("%d-",a[i]);
    }
}



//-----------------------------------------------------------------------
// 开始排序
void quick_sort (int left, int right ,int *arr) {
    
    if (left > right) {
        return;
    }
    
    int temp = arr[left];
    int i = left;
    int j = right;
    
    while (i < j) {
        while (i < j && arr[j] >= temp) {
            j--;
        }
        if (i < j) {
            arr[i++] = arr[j];
        }
        
        while (i < j && arr[i] < temp) {
            i++;
        }
        if (i < j) {
            arr[j--] = arr[i];
        }
    }
    
    arr[i] = temp;
    
    quick_sort(left, i-1,arr);
    quick_sort(i+1, right,arr);
    
    return;
}

void quickSort (void) {
    int i;
    int n = 9;
    int a[10] = {2,3,9,5,4,1,6,8,23,34};
    quick_sort(1, n,a);
    
    for (i = 1; i <= n; i++) {
        printf("%d-",a[i]);
    }
}
