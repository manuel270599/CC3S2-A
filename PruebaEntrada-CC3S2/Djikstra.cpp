#include <iostream>
#include <climits> 
using namespace std;
// Función para encontrar el vértice con la distancia mínima que no ha sido visitado
int minDistancia(int dist[], bool visitado[], int numVertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < numVertices; v++) {
        if (!visitado[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
//implementacion para calcular el camino minimo desde el origen
void dijkstra(int grafo[][100], int origen, int numVertices) {
    int dist[100]; 
    bool visitado[100]; 

    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        visitado[i] = false;
    }
    dist[origen] = 0; 

  // Encuentrael camino más corto para todos los vértices
    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistancia(dist, visitado, numVertices); 
        visitado[u] = true; 
    // Actualiza la distancia de los vértices adyacentes al vértice seleccionado
        for (int v = 0; v < numVertices; v++) {
            if (!visitado[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }

    cout << "Vertice \t Distancia desde el origen" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}
//vista
int main() {
    int numVertices;
    cout << "Ingrese el numero de vertices: ";
    cin >> numVertices;

    int grafo[100][100] = {0};

    int numArcos;
    cout << "Ingrese el numero de arcos: ";
    cin >> numArcos;

    cout << "Ingrese la informacion para cada arco" << endl;
    for (int i = 0; i < numArcos; i++) {
        int inicio, fin, peso;
        cout << "Arco " << i + 1 << " Vertice de salida:";
        cin >> inicio;
        cout << "Arco " << i + 1 << " Vertice de llegada:";
        cin >> fin;
        cout << "Arco " << i + 1 << " Peso: ";
        cin >> peso;
        grafo[inicio][fin] = peso; 
    }

    int origen;
    cout << "Ingrese el vertice origen: ";
    cin >> origen;

    dijkstra(grafo, origen, numVertices);

    return 0;
}
