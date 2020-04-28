//
//  main.cpp
//  Greedy
//
//  Created by fanqy on 2020/4/28.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct{
    int s;      //开始时间
    int f;      //结束时间
    int i;      //活动序号
}S;
//根据活动结束时间进行非降序排序
void fsort(S a[],int n){
    int i,j;
    S temp;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            if(a[j].f>a[j+1].f){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
//根据活动开始时间进行非降序排序
void ssort(S a[],int n){
    int i,j;
    S temp;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            if(a[j].s>a[j+1].s){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
//根据活动进行时间进行非降序排序
void asort(S a[],int n){
    int i,j;
    S temp;
    int t[n];
    for (int i=1; i<=n; i++) {
        t[i]=a[i].f-a[i].s;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            if(t[j]>t[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void Greedy(int n){
    S a[n+1];
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&a[i].s,&a[i].f);
        a[i].i=i;
    }
    fsort(a, n);
    //ssort(a, n);
    //asort(a, n);
    bool flag[n+1];
    flag[1]=true;              //第一个活动必定安排
    int pre=a[1].f;
    int num=1;
    for (int i=2;i<=n;i++) {
        if (a[i].s>=pre) {
            flag[i]=true;
            num++;//活动数+1
            pre=a[i].f;
        }
        else
            flag[i]=false;
    }
    printf("%d\n",num);        //输出最大相容活动数
    for (int i=1; i<=n; i++) {
        if (flag[i]) {
            printf("%d\t",a[i].i);//输出活动序号
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);          //活动数
    Greedy(n);
    return 0;
}
