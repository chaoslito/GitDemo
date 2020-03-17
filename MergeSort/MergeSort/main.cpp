//
//  main.cpp
//  MergeSort
//
//  Created by fanqy on 2020/3/17.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
#include<stdio.h>
using namespace std;
#define MAX 100000
int a[MAX],temp[MAX];            //定义数组
void Merge_Sort(int *a, int *temp,int start,int mid,int end){  //归并排序
    int left_start=start;                                //数组前一半的起点
    int left_end=mid;                                    //数组前一半的终点
    int right_start=mid+1;                               //数组后一半的起点
    int right_end=end;                                   //数组后一半的终点
    int i=start;                                         //指向数组起点
    while(left_start<=left_end&&right_start<=right_end){ //当数组左右两端都还没遍历完则进行以下操作
        if(a[left_start]>a[right_start])//数组前一半的起点与后一半的起点做比较，把值小的记录在新数组中
            temp[i++]=a[right_start++];
        else
            temp[i++]=a[left_start++];
    }
    while(left_start<=left_end)                          //左剩
        temp[i++]=a[left_start++];
    while(right_start<=right_end)                        //右剩
        temp[i++]=a[right_start++];
    for(i=start;i<=end;i++)
        a[i]=temp[i];                                    //把排好序的数组赋给a数组
}
void Sort(int *a, int *temp,int start,int end){          //把数组对半分开通过递归来排序
    if(start<end){
        int mid=(start+end)/2;                           //找到中点
        Sort(a,temp,start,mid);                          //前一半排序
        Sort(a,temp,mid+1,end);                          //后一半排序
        Merge_Sort(a,temp,start,mid,end);                //归并排序
    }
}

int main(void){
    int i,n;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    Sort(a,temp,0,n-1) ;
    printf("\n排后序列:") ;
    for(i=0;i<n;++i)
        printf("%d ",a[i]) ;
    printf("\n") ;
    return 0 ;
}
