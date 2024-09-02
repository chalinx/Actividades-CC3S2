#include<bits/stdc++.h>
#define ll long long int

#define all(a) a.begin(),a.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vll vector<ll>
#define vct vector
#define pb push_back
#define er erase
#define fi(i,a,n,w) for(int i =a;i<n;i+=w)
#define fl(i,a,n,w) for(ll i=a;i<n;i+=w)
#define fr first
#define se second
#define sz(a) a.size()
#define mstr(r) for(auto i:r)cout<<i<<" ";
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ingr(r) fi(i,0,sz(r),1)cin>>r[i]; 

using namespace std;

class Graph {

    // numero de vertices
	int V; 
    // listad e adyacencia
	list<pair<int,int>>*l;
public:
    // definimos el numero e nodos en la lista de adyacnecia
    Graph(int v) {
        this->V = v;
        l = new list<pair<int, int>>[V];
    }

    // enlazamos los nodos, si undir es true es un digrafo caso contrario es una grafo unidirecional
    void addEdge(int u, int v, int wt, bool undir = true) {
        l[u].push_back({wt, v});

        if (undir)
            l[v].push_back({wt, u});
    }


    int dijkstra(int src, int dest) {
        // creamos un vector para las distancia y una cola de prioridad para
        // dar prioridad a los de menor distancia
        vector<int> dist(V, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-Heap


        dist[src] = 0;
        pq.push({0, src});


        while (!pq.empty()) {
            // obtenemos el menor valor del la cola de prioridad
            int distTillNow = pq.top().first;
            //obtenemos el nodo 
            int node = pq.top().second; 
            pq.pop();// eliminamos

            // visitamos los vecimnos del nodo actual
            for (auto nbrPair : l[node]) {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;
                // si la suma actual es de los pesos es menor entonces actualizamos la
                // distancia hasta el nodo actual
                if (distTillNow + currentEdge < dist[nbr]) {
                    dist[nbr] = distTillNow + currentEdge;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        for (int i = 0; i < V; i++)
            cout << "Node " << i << " Dist " << dist[i] << endl;

        return dist[dest];
    }

};


void solve() {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    cout << g.dijkstra(0, 4) << endl;
}

int main(){

#ifndef ONLINE_JUDGE
freopen("D:/Problem Set Competitiva/input.txt","r",stdin);
freopen("D:/Problem Set Competitiva/output.txt","w",stdout);
#endif
fast
	int t=1;
	while(t--){
		solve();
	}

	return 0;
}