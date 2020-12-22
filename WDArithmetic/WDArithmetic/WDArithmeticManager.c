//
//  WDArithmeticManager.c
//  WDArithmetic
//
//  Created by 伟东 on 2020/12/16.
//

#include "WDArithmeticManager.h"




































//-----------------------------------------------------------------------
// 给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
// [0,2,1,-6,6,-7,9,1,2,0,1]  --> 0+2+1=-6+6-7+9+1=2+0+1   ture
// [0,2,1,-6,6,7,9,-1,2,0,1]    false
// [3,3,6,5,-2,2,5,1,-9,4]  ----> 3+3=6=5-2+2+5+1-9+4   ture
int isCanThreePartsEqualSum(int a[],int aSize) {
    
    if (aSize <=0 ) {
        return 0;
    }
    int sum = 0;
    
    for (int i = 0; i < aSize; i++) {// 求和
        sum += a[i];
    }
    
    if (sum %3 == 0) {// 可以三等分
        int s1 = 0,s2 = 0;
        for (int j=0; j<aSize; j++) {
            s1 += a[j];
            
            if (s1 == sum/3) {//第一部分
                for (int k = j+1; k < aSize - 1; k++) {
                    s2 += a[k];
                    if (s2 == sum/3) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}



void canThreePartsEqualSum (void){
//    int a[] = {0,2,1,-6,6,-7,9,1,2,0,1};
//    int a[] = {0,2,1,-6,6,7,9,-1,2,0,1};
    int a[] = {3,3,6,5,-2,2,5,1,-9,4};

    int aSize = sizeof(a)/sizeof(a[0]);
    
    int isCan = isCanThreePartsEqualSum(a, aSize);
    printf("isCanThreePartsEqualSum---%d",isCan);
}




//-----------------------------------------------------------------------
// [1,2,3,4,5,6,7,8,9]  [7,8,9,1,2,3,4,5,6]

/// 逆序数组
/// @param array 需要操作的数组
/// @param array_length 数组的长度
/// @param index 进行求逆序的其实位置
/// @param length 进行求逆序的元素个数（包括其实位置的那个）
void reversetargetArray(int array[],int array_length,int index,int length) {
    
    if (index < 0 || length > array_length || index + length > array_length) {
        return;
    }
    
    int first = index;
    int end = length + first - 1;
    while (first < end) {
        int temp = 0;
        temp = array[first];
        array[first] = array[end];
        array[end] = temp;
        first++;
        end--;
    }
}


void updateArray (void) {
    
    int k = 6;
    int a[] = {1,2,3,4,5,6,7,8,9};
    int array_length = sizeof(a)/sizeof(a[0]);
    printf("原始数据：\n");
    for (int i = 0; i < array_length; i++) {
        printf("%d-",a[i]);
    }
    reversetargetArray(a, array_length,0, k);// 数组前k 逆序
    reversetargetArray(a, array_length,k, array_length-k); //数组从第k位开始 逆序array_length-k 个数
    reversetargetArray(a, array_length,0, array_length);// 整个数组逆序
    printf("\n转化后的：\n");
    for (int i = 0; i < array_length; i++) {
        printf("%d-",a[i]);
    }
    
}






//-----------------------------------------------------------------------
//最大堆排序
void swap(int *a,int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void max_heapify(int arr[],int start, int end) {
    // 创建父节点 子节点
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 如果子节点在指标范围内才做比较
        if (son + 1 <= end && arr[son] < arr[son+1]) {
            // 先比较两个子节点的大小 选择最大的
            son++;
        }
        if (arr[dad] > arr[son]) { //如果父节点大于子节点，代表调整完成 直接跳出函数
            return;
        }else { // 交换父子节点的 继续子节点和孙节点的比较
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad*2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) {
    int i;
    for (i = len/2-1; i>=0; i--) {
        max_heapify(arr, i, len-1);
    }
    for (i= len-1; i>0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i-1);
    }
}


void maxHeapifySort(void) {
    int arr[] = {3,5,3,0,8,6,1,10,5,8,6,2,4,22,9,4,7,0,1,21,55,8,9,7,3,1,33,2,5,9,7,4,0,2};
    int len = (int)sizeof(arr)/sizeof(*arr);
    heap_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d-",arr[i]);
    }
}


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
