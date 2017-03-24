//http://blog.csdn.net/alps1992/article/details/44795113

/*
然后我们假设有一个图如下：

节点1->3->NULL 
节点2->NULL 
节点3->2->4->NULL 
节点4->1->2->NULL
这样我们已经知道这是一个什么图了。

假设我们从节点1开始遍历。 
1.首先把节点1变成灰色，然后加入到队列(queue)中，然后把所有与节点1的点变成灰色同时加入到队列中。
2.输出并弹出队首元素节点1并把节点1的颜色变为黑色。
3.然后再把队首元素的相邻节点加入到队列中。然后继续输出并弹出队首元素依次类推。到队列空为止。
*/

#include <iostream>
#include <queue>

#ifndef Vertex
#define Vertex int
#endif

#ifndef NumVertex
#define NumVertex 4
#endif

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

struct node{
    int val;
    int weight;
    node* next;
    node(int v, int w): val(v), weight(w), next(NULL){}
};

typedef node* VList;//每个TableEntery后面跟

struct TableEntery{
    VList next;
    Vertex color;
};

typedef TableEntery Table[NumVertex+1];//点从1开始 保存numVertex个点

void InitTableEntry(Vertex start, Table T){ //init the Graph
    Vertex OutDegree = 0;
    VList temp = NULL;

    for (int i = 1; i <= NumVertex; i++) {
        scanf("%d",&OutDegree); // input the out degree of vertex
        T[i].next = NULL;
        T[i].color = WHITE;
        for (int j = 0; j < OutDegree; j++) {
            temp = (VList)malloc(sizeof(struct node));
            scanf("%d %d",&temp->val, &temp->weight);
            temp->next = T[i].next;
            T[i].next = temp;
        }
    }

    T[start].color = GRAY; //init the start vertex color to gray
}

void BFS(Vertex start, Table T){
    queue<Vertex> Q;
    Q.push(start);
    VList temp = NULL;
    while (!Q.empty()) { //if queue is not empty, then the bfs is not over
        temp = T[Q.front()].next; //find the front of the queue
        while (temp) { //if the front vertex has next vertex
            if (T[temp->val].color == WHITE) {
                Q.push(temp->val); //push the white vertex to queue
                T[temp->val].color = GRAY; //change the color to gray
            }
            temp = temp->next;
        }
        printf("%d ",Q.front()); //output the vertex
        T[Q.front()].color = BLACK; //then change color
        Q.pop();
    }
}

int main(int argc, const char * argv[]) {
    Table T;
    InitTableEntry(1, T);
    BFS(1, T);
    return 0;
}