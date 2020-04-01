//
//  main.cpp
//  select_kth_smallest
//
//  Created by fanqy on 2020/4/1.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
using namespace std;
int a[2];
//交换
void swap(int root[],int a,int b){
    int t=root[a];
    root[a]=root[b];
    root[b]=t;
}
//从root数组的begin位置到end位置上找出第k小的元素
int select_kth_smallest(int root[], int begin ,int end,int k);
//求由每5个数所分成的小组的小组内的中位数
int choose_mid(int root[], int left, int right){
    sort(root+left, root+right+1);
    int sum=left+right;
    int mid=(sum/2)+(sum%2);
    return root[mid];
}
//将root数组start位置到end位置分成每5个数一个小组，并求出每个小组内的中位数
int findMidOfMid(int root[],int start,int end){
    int num=end-start+1;//数组长度
    int offset=num%5==0?0:1;//如果剩余的数不足5个，也将其分成一个小组
    int range=num/5+offset;
    int mid[range];//存每组的中位数
    for (int i=0; i<range; i++) {
        int left=start+i*5; //第i组数对应root数组上的位置
        int right=left+4;
        mid[i]=choose_mid(root, left, min(right,end));
    }
    return select_kth_smallest(mid, 0, range-1, range/2);
}
//求范围,快速排序
void partation(int root[],int start,int end,int n){
    int low=start-1;
    int high=end+1;
    int m=start;
    while (m<high) {
        if (root[m]<n) {
            low++;
            swap(root,m,low);
            m++;
        }
        else if (root[m]==n){
            m++;
        }
        else{
            high--;
            swap(root,m,high);
        }
    }
    a[0]=low+1;
    a[1]=high-1;
}
//求第k小元素
int select_kth_smallest(int root[], int begin ,int end,int k){
    if(begin==end){//数组中只有一个数
        return root[begin];
    }
    int div=findMidOfMid(root, begin, end);
    partation(root, begin, end, div);
    if(k>=a[0]&&k<=a[1]){//如果需要求的数正好在等于区域，直接返回root[k]
        return root[k];
    }
    else if(k<a[0]){//要找的数比divide小，递归求前半部分
        return select_kth_smallest(root, begin, a[0]-1, k);
    }
    else{//要找的数比divide大，递归求后半部分
        return select_kth_smallest(root, a[1]+1, end, k);
    }
}
int main(int argc, const char * argv[]) {
    int n,k;
    int root[10000];
    while (scanf("%d",&n)) {
        scanf("%d",&k);
        for (int i=0;i<n; i++) {
            scanf("%d",&root[i]);
        }
        printf("%d\n",select_kth_smallest(root, 0, n-1, k-1));
        memset(root, 0, sizeof(root));
        memset(a, 0, sizeof(a));
    }
    return 0;
}
