//
//  main.cpp
//  EfficientClosestPair
//
//  Created by fanqy on 2020/3/24.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct point{           //点结构
    double x,y;
};
point s[9999];
bool cmpX(point a,point b){  //按x坐标升序排序
    return a.x>b.x;
}
bool cmpY(point a,point b){  //按y坐标升序排序
    return a.y>b.y;
}
double EfficientClosestPair(point *p,point *q,int start,int n){  //最近对
    if(n<=3){    //如果n小于3则用蛮力算法求出最短距离
        double result;
        result=(p[start].x - p[start+1].x)*(p[start].x - p[start+1].x) + (p[start].y - p[start+1].y) * (p[start].y - p[start+1].y);
        if(n==3){
            double t;
            t=(p[start].x - p[start+2].x)*(p[start].x - p[start+2].x) + (p[start].y - p[start+2].y) * (p[start].y - p[start+2].y);
            if(t<result)
                result=t;
            t=(p[start+1].x - p[start+2].x)*(p[start+1].x - p[start+2].x) + (p[start+1].y - p[start+2].y) * (p[start+1].y - p[start+2].y);
            if(t<result)
                result=t;
        }
        return sqrt(result);
    }
    else{
        int mid=n/2;       //找到中间点
        double d1 = EfficientClosestPair(p,q,start,mid); //递归计算d1、d2距离
        double d2 = EfficientClosestPair(p,q,start+mid,n-mid);
        double d=d1<d2?d1:d2;
        double m=p[start+mid-1].x;
        double t;
        int count=0,i;
        for(i=start;i<start+n;i++){
            t=q[i].x-m;
            if(t<0)
                t=-t;
            if(t<d)
                count++;
        }
        double result=d;
        int j,k=0;
        if(count>1){
            for(i=start;i<start+n;i++){
                t=q[i].x-m;
                if(t<0)
                    t=-t;
                if(t<d){
                    s[j].x=q[i].x;
                    s[j].y=q[i].y;
                    j++;
                }
            }
            for(i=0;i<count-1;i++){
                k=i+1;
                while (k < count && (s[k].y - s[i].y)*(s[k].y - s[i].y) < result) {
                    result=min((s[k].x-s[i].x)*(s[k].x - s[i].x) + (s[k].y - s[i].y)*(s[k].y - s[i].y),result);
                    k++;
                }
            }
        }
        return sqrt(result);  //避免在最内存循环中计算平方根
    }
}
int main() {
    int n;
    point *p,*q;
    p=new point[9999];
    q= new point[9999];
    while(scanf("%d", &n) != EOF){
        if(n == 0)
            break;
       for(int i = 0; i < n; i++){
           scanf("%lf %lf", &p[i].x,&p[i].y);
           q[i].x = p[i].x;
           q[i].y = p[i].y;
       }
       if(n <= 3){
           printf("%.3lf\n",EfficientClosestPair(p,q,0,n)/2);
       }
       else{
           sort(p, p+n, cmpX);     //先进行排序
           sort(q, q+n, cmpY);
           printf("%.3lf\n",EfficientClosestPair(p,q,0,n)/2);
       }
    }
    return 0;
}
