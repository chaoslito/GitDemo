//
//  main.cpp
//  center
//
//  Created by fanqy on 2020/5/29.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
#include<math.h>
#include<algorithm>
#define N 4
using namespace std;
double minlen=10000,x[N],r[N];//分别为最小圆排列长度，每个圆心横坐标，每个圆半径
double bestsort[N];//最小圆排列的半径顺序
 
double center(int m){//求每个圆的圆心坐标
    double a=0;
    for(int j=1;j<m;++j){//判断目标圆是否与排在它之前的任一圆相切
        double b=x[j]+2.0*sqrt(r[m]*r[j]);//计算圆在当前圆排列中的横坐标
        if(b>a)
            a=b;
    }
    return a;
}
void compute(){//计算当前圆排列的长度
    double low=0,high=0;
    for(int i=1;i<N;++i){//通过比较找出最小的左部坐标和最大的右部坐标，相减就是圆排列的长度。
        if(x[i]-r[i]<low)
            low=x[i]-r[i];
        if(x[i]+r[i]>high)
            high=x[i]+r[i];
    }
    if(high-low<minlen){//把每次不同的排列长度进行比较，找到更小的minlen
        minlen=high-low;
        for(int i=1;i<N;++i)
            bestsort[i]=r[i];
    }
}
void backtrack(int m){
    if(m==N)
        compute();
    else{
        for(int j=m;j<N;++j){
            swap(r[m],r[j]);
            double center_x=center(m);
            if(center_x+r[m]+r[1]<minlen){//先判断当前层是否在范围内，是则继续搜索下一层，否则直接回溯。
                x[m]=center_x;
                backtrack(m+1);
            }
            swap(r[m],r[j]);
        }
    }
}
int main()
{
    r[1]=1,r[2]=1,r[3]=2;
    printf("每个圆的半径分别为:");
    for(int i=1;i<N;++i)
        printf("%f",r[i]);
    printf("\n");
    backtrack(1);
    printf("最小圆排列长度为：%f\n",minlen);
    printf("最优圆排列的顺序对应的半径分别为：");
    for(int i=1;i<N;++i)
        printf("%f",bestsort[i]);
    printf("\n");
    return 0;
}
