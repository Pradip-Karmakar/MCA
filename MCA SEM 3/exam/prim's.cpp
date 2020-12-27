#include<iostream>
using namespace std;
#define V 4

struct adjlist {
    int vertices;
    int distance;
    adjlist *next;
};

int findMin(int tree[][V],int limit,int edgeVisted[][V]){
    int index,value = INT_MAX;
    for(int i = 0; i <= limit; i++){
        for(int j = 0; j < V; j++){
            if(tree[i][j] != 0 && tree[i][j] < value) {
                value = tree[i][j];
                index = j;
            }
        }
    }
    return index;
}

void MST(int tree[][V],int start){
    int table[V][V],min,edgeVisted[V][V] = {0};

    for(int i = 0; i < V; i++) {
        table[i][0] = i+1;
        table[i][1] = 0;
        table[i][2] = INT_MAX;
        table[i][3] = 0;
    }

    for(int i = 0; i < V; i++) {
        min = findMin(tree,i,edgeVisted);

    }

}



// WeightedGraph getMinimumSpanningTree() {
//     WeightedGraph tree
// }

int main(){

    int tree[][V] = {
            {0,2,3,0},
            {2,0,1,3},
            {3,1,0,5},
            {0,3,5,0}
    };

    int starting = 0;

    MST(tree,starting);

    return 0;
}

