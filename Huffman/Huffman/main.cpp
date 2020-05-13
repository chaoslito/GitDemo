//
//  main.cpp
//  Huffman
//
//  Created by fanqy on 2020/5/12.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAXNUM 100      //最大字符编码数组长度
#define MAXHUFF 100     //最大哈夫曼节点结构体数组个数
#define MAXCODE 100     //最大哈夫曼编码结构体数组的个数
#define MAXWEIGHT 10000 //最大权值

typedef struct Huffman{
    int weight;      //权值
    char ch;         //字符
    int parent;      //父节点
    int leftchild;   //左孩子
    int rightchild;  //右孩子
}HuffmanNode;
typedef struct Code{
    int code[MAXNUM];    //字符的哈夫曼编码的存储
    int start;           //开始位置
}HuffmanCode;

HuffmanNode huffman[MAXHUFF];
HuffmanCode code[MAXCODE];

void buildHuffmanTree(int n){
    for (int i=0; i<n*2-1; ++i) {//初始化
        huffman[i].weight=0;
        huffman[i].parent=-1;
        huffman[i].leftchild=-1;
        huffman[i].rightchild=-1;
    }
    for (int i=0; i<n; i++) {
        printf("请分别输入第%d个哈夫曼字符和权重",i);
        std::cin >> huffman[i].ch;
        scanf("%d",&huffman[i].weight);
    }
    int x1,x2,w1,w2;
    for (int i=0; i<n-1; i++) {
        x1=x2=-1;
        w1=w2=MAXWEIGHT;
        for (int j=0; j<n+i; j++) {
            if (huffman[j].parent==-1&&huffman[j].weight<w1) {
                w2=w1;//如果每次最小的更新了，那么需要把上次最小的给第二小的
                x2=x1;
                x1=j;
                w1=huffman[j].weight;
            }
            else if (huffman[j].parent==-1&&huffman[j].weight<w2){
                x2=j;
                w2=huffman[j].weight;
            }
        }
        //找到最小的两个节点后要记得合并成一个新的节点
        huffman[n+i].leftchild=x1;
        huffman[n+i].rightchild=x2;
        huffman[n+i].weight=w1+w2;
        huffman[x1].parent=n+i;
        huffman[x2].parent=n+i;
    }
}
void Print(int n){
    HuffmanCode hcode;   //保存当前叶子节点的字符编码
    int curParent;       //当前父节点
    int c;               //下标和叶子节点的编号
    for (int i = 0; i < n; ++i){
        hcode.start = n - 1;
        c = i;
        curParent = huffman[i].parent;
        while (curParent != -1){//我们先拿到父节点，然后判断左节点是否为当前值，如果是取节点0,否则取节点1
            if (huffman[curParent].leftchild == c){
                hcode.code[hcode.start] = 0;
                //std::cout << "hcode.code[" << hcode.start << "] = 0" << std::endl;
            }
            else{
                hcode.code[hcode.start] = 1;
                //std::cout << "hcode.code[" << hcode.start << "] = 1" << std::endl;
            }
            hcode.start--;
            c = curParent;
            curParent = huffman[c].parent;
        }
        //把当前的叶子节点信息保存到编码结构体里面
        for (int j = hcode.start + 1; j < n; j++){
            code[i].code[j] = hcode.code[j];
        }
        code[i].start = hcode.start;
    }
}
int main() {
    printf("请输入有多少个哈夫曼字符");
    int n=0;
    scanf("%d",&n);
    if (n==0) {
        exit(0);
    }
    buildHuffmanTree(n);
    Print(n);
    for (int i = 0; i < n; ++i){
        printf("%c 's Huffman Code is:",huffman[i].ch);
        for (int j = code[i].start + 1; j < n; ++j){
            printf("%d",code[i].code[j]);
        }
        printf("\n");
    }
    return 0;
}
