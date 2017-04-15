#include <iostream>
#include <list>
#include <limits>
#include <queue>

#define MAX std::numeric_limits<int>::max()

using namespace std;

void showQuadMatrix(int** vet, int size);

class Grafo{
    
    private:
        int V;
        list< pair<int, int> > *E;

        void build_grafo(int** vet, int size){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(vet[i][j] != 0)
                        addAresta(i, j, vet[i][j]);
                }
            }
        }

    public:
        Grafo(int** vet, int V){
            this->V = V;
            E = new list < pair<int, int> >[V];
            build_grafo(vet, V);
        }

        Grafo(int V){
            this->V = V;
            E = new list < pair<int, int> >[V];
        }

        /**Adiciona Aresta entre os vertices v1 e v2**/
        void addAresta(int v1, int v2, int custo){
            E[v1].push_back(make_pair(v2, custo));
        }

        void showGrafo(){
            for(int i = 0; i < V; i++){

            }
        }

        int dijkstra(int origem, int destino){
            
            /**Vetor de distancias**/
            int dist[V];
            
            /**Vetor de visitados, para evitar que se expanda o mesmo vertice mais de uma vez**/
            bool visitado[V];

            priority_queue< pair <int, int>, vector <pair <int, int> >, greater<pair <int, int> > > pq; 

            /**INITIALIZE-SINGLE-SOURCE**/
            for(int i = 0; i < V; i++){
                dist[i] = MAX;
                visitado[i] = false;
            }

            /**Distancia da origem**/
            dist[origem] = 0;
            pq.push(make_pair(dist[origem], origem));

            while(!pq.empty()){
                /**EXTRACT-MIN**/
                pair <int, int> p = pq.top();
                int u = p.second;/**Obtem o vertice do pair**/
                cout << "Expandindo o vertice [" << u << "]" << endl;
                pq.pop();

                if(!visitado[u]){
                    visitado[u] = true;

                    list<pair<int, int> > :: iterator it;

                    // Expande o vertice u
                    for(it = E[u].begin(); it != E[u].end(); it++){
                        int v = it->first;
                        int custo = it->second;

                        //Relaxamento de u e v
                        if(dist[v] > (dist[u] + custo)){
                            //Atualiza a distancia de v e insere na fila de prioridades
                            dist[v] = dist[u] + custo;
                            cout << "Relaxamento de " << u << " e " << v << ": " << dist[v] << endl;
                            pq.push(make_pair(dist[v], v));
                        }
                    }
                }
            }

            return dist[destino];
        }

};

int main(){

    int tam;
    cin >> tam;
 
    int **matAdj;
    matAdj = new int *[tam];

    for(int i = 0; i < tam; i++){
        matAdj[i] = new int[tam];
    }

    //Grafo g(matAdj, tam);

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(j <= i){
                matAdj[i][j] = 0;
            }else{
                cin >> matAdj[i][j];
                //g.addAresta(i, j, matAdj[i][j]);
            }
        }
    }

    showQuadMatrix(matAdj, tam);

    Grafo g(matAdj, tam);
    cout << g.dijkstra(0, tam-1) << endl;
}

/**Exibe matriz quadraticas**/
void showQuadMatrix(int** vet, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(vet[i][j] != 0)
                cout << vet[i][j] << " ";
        }
        cout << endl;
    }
}
