#include <iostream>
#include <list>
#include <limits>

#define MAX std::numeric_limits<int>::max()

using namespace std;

void showQuadMatrix(int** vet, int size);

class Grafo{
    
    private:
        int V;
        list< pair<int, int> > *E;

        void build_grafo(int** vet, int size){
            for(int i = 0; i < size-1; i++){
                for(int j = 0; j < size - (i+1); j++){
                    addAresta(i, j, vet[i][j]);
                }
            }
        }

    public:
        Grafo(int V){
            this->V = V;
            E = new list < <int, int> >[V];
        }

        /**Adiciona Aresta entre os vertices 1 e 2**/
        void addAresta(int v1, int v2, int custo){
            E[v1].push_back(make_pair(v2, custo));
        }

        int dijkstra(int origem, int destino){
            int dist[V];
            bool visitado[V];

            for(int i = 0; i < V; i++){
                dist[i] = MAX;
                visitado[i] = false;
            }

            dist[origem] = 0;
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

    for(int i = 0; i < tam-1; i++){
        for(int j = 0; j < tam - (i+1); j++){
            cin >> matAdj[i][j];
        }
    }

    showQuadMatrix(matAdj, tam);

}

//void relaxamento

/**Exibe matriz quadraticas**/
void showQuadMatrix(int** vet, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << vet[j][i] << " ";
        }
        cout << endl;
    }
}