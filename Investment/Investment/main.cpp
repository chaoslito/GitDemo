//
//  main.cpp
//  Investment
//
//  Created by fanqy on 2020/4/7.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAXN 101    //最大投资的项目数
#define MAXM 101    //最大投资金额
int m,n;            //投资金额m，投资项目n个
int f[MAXN][MAXM];  //第k项投资x万元的收益
int F[MAXN][MAXM];  //x万元投资前k个项目的最大效益
int x[MAXN][MAXM];  //新增加第i项时，总共分配x元时，第i项分配了k元

//动态规划实现最大投资收益
void invest(){
    int i,j,k,t;
    for(k=2;k<=n;k++){
        memset(F[k],-1,sizeof(int)*(m+1));  //初始化最大收益值的值是-1
    }
    for(k=0;k<=m;k++){
        F[1][k]=f[1][k]; //投资第一个项目
    }
    for(k=2; k<=n;k++){ //投资前k个项目
        F[k][0]=0;      //投资前k个项目初始最大收益是0
        x[k][0]=0;
        for(j=1; j<=m;j++){     //投资金额不超过j
            for(i=0; i<=j;i++){ //投资当前项目的金额
                t=f[k][i]+F[k-1][j-i];
                if(t>F[k][j]){  //如果t>之前的，那么更新最大收益
                    F[k][j]=t;
                    x[k][j]=i;
                }
            }
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            printf("(%d,%d)\t", F[i][j], x[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",F[n][m]);
}

int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i =1; i<=n;i++){ //输入效益函数
        f[i][0]=0;         //投资0元的收益是0
        for(j=1;j<=m;j++)
            scanf("%d",&f[i][j]);
    }
    invest();
    return 0;
}
