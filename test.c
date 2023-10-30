#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int parent[MAX];
int pos[MAX];

int findParent(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

bool isUnion(int x, int y){
    int rx,ry;
    rx = findParent(x);
    ry = findParent(y);

    if(rx == ry){
        return false; 
    }

    if (pos[rx] < pos[ry]){
        parent[rx] = ry;
    } 
    else if(pos[rx] > pos[ry]){
        parent[ry] = rx;
    } 
    else{
        parent[ry] = rx;
        pos[rx]++;
    }

    return true;
}

bool isTree(int n, int e, int edges[][2]) {
    if (e != (n-1)) {
        return false;
    }

    for (int i=0; i<n; i++) {
        parent[i] = i;
        pos[i] = 0;
    }

    for (int i=0; i<e; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];

        if (!isUnion(src, dest)) {
            return false; 
        }
    }
    return true;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    int edges[MAX][2];
    for (int i=0; i<e; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    if (isTree(n, e, edges)) {
        printf("true\n");
    } 
    else{
        printf("false\n");
    }

    return 0;
}
