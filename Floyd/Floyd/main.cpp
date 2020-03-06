//
//  main.cpp
//  Floyd
//
//  Created by fanqy on 2020/3/3.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAX 100
#define INF 999999
struct MGraph{
    int e;                                          //边数
    int n;                                          //顶点数
    int weight[MAX][MAX];                           //权值
}G;
int path[MAX][MAX];                                 //当前两顶点间最短路径上要经过的中间点
int dis[MAX][MAX];
void InitGraoh(){
    memset(G.weight, INF, sizeof(G.weight));        //初始化为无穷大（不连通）
    for(int i=1;i<=MAX;i++){                        //顶点本身到本身的距离为0
        G.weight[i][i]=0;
    }
}
void Insert(int u,int v,int w){
    G.weight[u][v]=w;                               //根据相连的边输入权值
}
void Floyd(MGraph G){
    int i,j,k;
    for(i=1;i<=G.n;i++){
        for(j=1;j<=G.n;j++){
            dis[i][j]=G.weight[i][j];
        }
    }
    for(k=1;k<=G.n;k++){                             //1，2...G.n为经过的中间点
        for(i=1;i<=G.n;i++){                          //矩阵的行
            for(j=1;j<=G.n;j++){                      //矩阵的列
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];   //如果以k为中间点检测到更短的路径则更新最短路径
                }
            }
        }
    }
}
void Print(int n){
    int i,j;
    for(i=1;i<=n;i++){                                //矩阵的行
        for(j=1;j<=n;j++){                            //矩阵的列
            printf("%10d",dis[i][j]);
        }
        printf("\n");
    }
}
int main() {
    InitGraoh();
    int n,m,x,y,w;
    scanf("%d%d",&n,&m);
    G.n=n;
    G.e=m;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d",&x,&y,&w);
        Insert(x, y, w);
    }
    Floyd(G);
    Print(n);
    return 0;
}
