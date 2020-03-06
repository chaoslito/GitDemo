//
//  main.cpp
//  Dijkstra
//
//  Created by fanqy on 2020/3/3.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
using namespace std;
#define INF 10000
#define MAX 100
int G[MAX][MAX];                //邻接矩阵
char vertex[MAX];               //节点信息
int dis[MAX],vis[MAX];          //距离，访问标记
int n;
void Dijkstra(int n,int G[][MAX],int start,int end,int dis[],int path[]){
    int min,v=0;                //min用来存储最短距离，v用来临时存放当前最短路径经过的单个点
    for(int i=0;i<n;i++){       //初始化
        dis[i]=G[start][i];     //每个点距离起点的距离
        vis[i]=0;               //当前未访问
        if(G[start][i]<INF)     //如果当前点与起点连通，则标记为路径
            path[i]=start;
        else
            path[i]=-1;
    }
    vis[start]=1;               //起点标记为已经访问过
    path[start]=-1;             //起点不算做路径，主要用于输出判断
    for(int i=0;i<n-1;i++){     //处理其余顶点
        min=INF;                //最短路径初始化
        for(int j=0;j<n;j++){
            if(vis[j]==0&&dis[j]<min){//如果j未访问过并且起点到j的路径小于当前最短路径
                v=j;            //标记j
                min=dis[j];     //更新最短路径
            }
        }
        vis[v]=1;               //剩下点中有最短路径的点标记为已访问
        for(int j=0;j<n;j++){   //更新距离和经过的点
            if(vis[j]==0&&dis[v]+G[v][j]<dis[j]){
                dis[j]=dis[v]+G[v][j];
                path[j]=v;
            }
        }
        if(v==end)              //到终点后结束
            return;
    }
}
int main() {
    int start,end,i;
    int path[MAX],dis[MAX];
    char temp[MAX+5];
    scanf("%d",&n);             //输入节点数量
    scanf("%s",temp);           //输入节点信息（abcdefgh）
    for(int i=0;i<n;i++)
        vertex[i]=temp[i];      //节点和下标对号入座
    for(int k=0;k<n;k++){       //根据权值输入邻接矩阵
        for(int j=0;j<n;j++){
           scanf("%d",&G[k][j]);
        }
    }
    scanf("%d%d",&start,&end);  //输入起止点下标
    Dijkstra(n,G,start,end,dis,path);
    printf("从%d到%d的最短路径为:",start,end);
    for(i=end;path[i]!=-1;i=path[i]){  //输出
        printf("%c <- ",vertex[i]);
    }
    printf("%c\n",vertex[start]);
    return 0;
}
