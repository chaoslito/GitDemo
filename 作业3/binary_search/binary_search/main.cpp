//
//  main.cpp
//  binary_search
//
//  Created by fanqy on 2020/3/10.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
#define MAX 1000
int i,j,n,x;
int T[MAX];
void search(int x){
    int low,mid,high,j=0;
    low=1;
    high=n;
    while (low<high) {
        mid=(low+high)/2;
        if(T[mid]<x)
            low=mid+1;
        else if(T[mid]>x)
            high=mid-1;
        else if(T[mid]==x){
            j=mid;
            break;
        }
    }
    printf("%d\n",j);
}
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&T[i]);
    }
    scanf("%d",&x);
    search(x);
    return 0;
}
