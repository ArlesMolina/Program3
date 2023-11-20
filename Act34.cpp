// =========================================================
// File: Act34.cpp
// Author: Jonathan Arles Guevara Molina -A01710380
// Date: 25/10/2023
// =========================================================

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // Lista de adyacencia para representar el árbol
vector<int> leafCount;   // Contador de hojas por nodo

bool isAbeto(int node) {
    // si es una hoja, no hay nada más que verificar
    if (adj[node].empty()) {
        leafCount[node] = 1;
        return true;
    }

    // Contador de hojas en el subárbol de este nodo
    int totalLeaves = 0;

    for (int child : adj[node]) {
        if (!isAbeto(child)) return false; // Verificar si el subárbol es un abeto
        totalLeaves += leafCount[child];  // Acumular hojas del subárbol
    }

    leafCount[node] = totalLeaves;

    // Verificar si este nodo cumple con la condición de ser abeto
    if (node != 0 && leafCount[node] < 3) return false;

    return true;
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    leafCount.resize(n, 0);

    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        adj[parent - 1].push_back(i); // Convertir 1-index a 0-index
    }

    if (isAbeto(0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}