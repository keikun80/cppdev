#include <cstdio> 
#include <queue> 

struct Node 
{
    int data;
    Node* link;
};

Node* AllocNode(int data)
{
    Node* p = new Node;
    p->data = data;
    p->link = NULL;
    return p;
}
void AddNode(Node*& head, int data)
{
    if (head == NULL)
        head = AllocNode(data);  
    else 
    { 
        Node *tail;
        for (tail = head; tail->link != NULL; tail=tail->link)
            ; 
        tail->link = AllocNode(data);
    }
} 
void destroyNode(Node* head)
{
    for (Node* p = head; p != NULL; )
    { 
        Node* np = p->link;
        delete p;
        p = np;
    }
}
void PrintNode(Node* head)
{
    for (Node* p=head; p != NULL; p = p->link)
        printf("%d\n", p->data);
}  
struct Graph
{
    Node** head; 
    int versize;
}; 

void AddEdge(Graph* pg, int sv, int ev)
{
    AddNode(pg->head[sv], ev);
}
void PrintGraph(Graph* pg)
{ 
    printf("V :");
    for (int i = 0; i < pg->versize ; i++)  
        printf("%d", i); 
    printf("\n");

    for (int i = 0; i < pg->versize; i++) 
    { 
        printf("Edge : ");
        for (Node* p = pg->head[i]; p != NULL; p=p->link)
        {
            printf("(%d, %d)", i , p->data);
        }
        printf("\n");
    }
}
void InitGraph(Graph* pg, int versize)
{
    pg->versize = versize;
    pg->head = new Node*[versize]; 
    for (int i = 0; i < versize; i++)
    {
        pg->head[i] = NULL;
    }
} 
void UninitGraph(Graph* pg)
{ 
    for (int i =0; i < pg->versize; i++)
        destroyNode(pg->head[i]);
    delete[] pg->head;
} 
void _DFS(Graph* pg, int ver, int* visited)
{
    visited[ver] = 1;
    printf("%d ", ver);

    for (Node* p = pg->head[ver]; p != NULL; p = p->link) 
    {
        if (!visited[p->data])
            _DFS(pg, p->data, visited);
    }
}
void DFS(Graph* pg, int ver)
{
    int* visited = new int[pg->versize]; 
    for (int i = 0; i <pg->versize; i++)
        visited[i] = 0;

    _DFS(pg, ver, visited);  
    printf("\n");
    delete [] visited;
} 
void BFS(Graph* pg, int ver)
{
    int* visited = new int[pg->versize];
    for (int i = 0; i < pg->versize; i++)
        visited[i] = 0; 

    std::queue<int> q; 
    q.push(ver); 
    visited[ver] = 1;
    while(!q.empty())
    { 
        int cur = q.front();
        q.pop(); 
        printf("%d ", cur); 
        for (Node *p = pg->head[cur] ; p != NULL; p = p->link) 
        {
            if(!visited[p->data]) 
            {
                q.push(p->data); 
                visited[p->data] = 1;
            }
        } 
    }
    delete [] visited;
}
int main()
{ 
    Graph g;
    InitGraph(&g, 5);
    AddEdge(&g, 0, 1);
    AddEdge(&g, 0, 3); 

    AddEdge(&g, 1, 0);
    AddEdge(&g, 1, 2);
    AddEdge(&g, 1, 3); 

    AddEdge(&g, 2, 1);
    AddEdge(&g, 2, 3);
    
    AddEdge(&g, 3, 0);
    AddEdge(&g, 3, 1);
    AddEdge(&g, 3, 2);
    AddEdge(&g, 3, 4);
   
    AddEdge(&g, 4, 3);

    PrintGraph(&g); 

    //DFS(&g, 0); 

    BFS(&g, 0);
    UninitGraph(&g);
    return 0;
} 

