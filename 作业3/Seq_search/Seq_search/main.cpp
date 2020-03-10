//
//  main.cpp
//  Seq_search
//
//  Created by fanqy on 2020/3/10.
//  Copyright © 2020 fanqy. All rights reserved.
//

#include <iostream>
#define MAX 10000
int i,j,n,x;
int T[MAX];
void search(int x){
    int j=0,i;
    for(i=1;i<=n;i++){
        if(T[i]==x){
            j=i;
            break;
        }
    }
    printf("%d\n",j);
}
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&T[i]);
    }
    scanf("%d",&x);
    search(x);
    return 0;
}
