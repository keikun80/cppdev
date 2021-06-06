#include <cstdio> 
#include <queue> 

#define INFINY 1000000

using namespace std; 

struct Edge
{
	int ver;
	int cost;
	Edge(int v, int c):ver(v),cost(c) {} 
	bool operator<(const Edge& arg) const
	{
		return cost < arg.cost;
	}
};
struct Node 
{
    int ver; 
    int cost;
    Node* link;
};

Node* AllocNode(int ver, int cost)
{
    Node* p = new Node;
    p->ver = ver; 
    p->cost = cost; 
    p->link = NULL;
    return p;
}
void AddNode(Node*& head, int ver, int cost)
{
    if (head == NULL)
        head = AllocNode(ver, cost);  
    else 
    { 
        Node *tail;
        for (tail = head; tail->link != NULL; tail=tail->link)
            ; 
        tail->link = AllocNode(ver, cost);
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
        printf("%d , %d\n", p->ver, p->cost);
}  
struct Graph
{
    Node** head; 
    int versize;
}; 

void AddEdge(Graph* pg, int sv, int ev, int cost)
{
    AddNode(pg->head[sv], ev, cost);
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
            printf("(%d, %d, %d)", i , p->ver, p->cost);
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
        if (!visited[p->ver])
            _DFS(pg, p->ver, visited);
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
            if(!visited[p->ver]) 
            {
                q.push(p->ver); 
                visited[p->ver] = 1;
            }
        } 
    }
    delete [] visited;
} 
void Dijkstra (Graph* p, int sv)
{
	int* distance = new int[p->versize];
	for (int i =0 ; i < p->versize; ++i)
		distance[i] = INFINY; 

	std::priority_queue<Edge> pq;
	distance[sv] = 0; 
	
	for(Node* n= p->head[sv]; n != NULL; n = n->link)
	{
		pq.push(Edge(n->ver , n->cost));
	} 
	while(!pq.empty())
	{
		Edge min = pq.top(); 
		pq.pop();
		for (Node* n = p->head[min.ver]; n != NULL; n = n->link)
		{
			if(distance[min.ver] + n->cost < distance[n->ver]) 
			{
				distance[n->ver] = distance[min.ver]+ n->cost;
			}
		}
	}
	delete[] distance;
}
int main()
{  
//	priority_queue<Edge> pq;
//	pq.push(Edge(1,20));
//	pq.push(Edge(2,15));
//	pq.push(Edge(3,8));
//
//	printf("%d\n", pq.top().cost); 
//	pq.pop();
//	printf("%d\n", pq.top());
//	pq.pop();
    Graph g;
    InitGraph(&g, 9);
    AddEdge(&g, 0, 1,8);
    AddEdge(&g, 0, 2,15);
    AddEdge(&g, 0, 3,20);
    AddEdge(&g, 1, 4,5);
    AddEdge(&g, 2, 3,3);
    AddEdge(&g, 2, 5,20);
    AddEdge(&g, 2, 6,15);
    AddEdge(&g, 2, 8,37);
    AddEdge(&g, 3, 8,30);
    AddEdge(&g, 4, 5,14);
    AddEdge(&g, 4, 7,10); 
    AddEdge(&g, 5, 8,20); 

// AddEdge(&g, 0, 3); 
//
//    AddEdge(&g, 1, 0);
//    AddEdge(&g, 1, 2);
//    AddEdge(&g, 1, 3); 
//
//    AddEdge(&g, 2, 1);
//    AddEdge(&g, 2, 3);
//    
//    AddEdge(&g, 3, 0);
//    AddEdge(&g, 3, 1);
//    AddEdge(&g, 3, 2);
//    AddEdge(&g, 3, 4);
//   
//    AddEdge(&g, 4, 3);

    PrintGraph(&g); 
	Dijkstra(&g, 0);
    //DFS(&g, 0); 

    //BFS(&g, 0);
    //UninitGraph(&g);
    return 0;
} 

