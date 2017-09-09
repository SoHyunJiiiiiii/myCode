//
//  main.cpp
//  11403_경로찾기
//
//  Created by 지소현 on 2017. 9. 9..
//  Copyright © 2017년 지소현. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n;//정점의 갯수
int matrix[101][101];
int visited[101][101];
int v[101];
vector<int> st;
void check() {
    
    if(st.begin()==st.end()) {
        for(int i=0; i<st.size()-1; i++) {
            for(int j=0; j<st.size()-1; j++) {
                visited[st[i]][st[j]]=1;
            }
        }
    } else {
        for(int i=0; i<st.size(); i++) {
            for(int j=i+1; j<st.size(); j++) {
                visited[st[i]][st[j]]=1;
            }
        }
    }

    st.pop_back();

    
}
void DFS(int start) {

    
    if(v[start]) {
        st.push_back(start);
        check();
        st.pop_back();
        return;
    }

    st.push_back(start);
    v[start]=1;


    int cnt=0;
    for(int j=1; j<=n; j++) {
        if(matrix[start][j]) {
            cnt++;
            //printf("push %d \n",j);
            DFS(j);
        }
    }
    if(cnt==0){
        check();
        return;
    }
    
    
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(!v[i]) {
            DFS(i);
            st.clear();
            memset(v, 0, sizeof(v));
            v[i]=1;
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d ",visited[i][j]);
        }printf("\n");
    }
    
    return 0;
}
