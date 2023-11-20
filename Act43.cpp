// =================================================================
//
// File: main.cpp
// Author: Arles Guevara Molina -A01710380
// Date: 10/11/2023
//
// =================================================================
//COMPLEJIDAD DE  O(V + E) 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

// Declaración de la función dfs
void dfs(char point, unordered_map<char, unordered_set<char>>& edges, unordered_set<char>& visited, unordered_set<char>& tree);

// Definición de la función find_trees
vector<unordered_set<char>> find_trees(unordered_map<char, unordered_set<char>>& edges, unordered_set<char>& points);

// Definición de la función dfs
void dfs(char point, unordered_map<char, unordered_set<char>>& edges, unordered_set<char>& visited, unordered_set<char>& tree) {
    visited.insert(point);
    tree.insert(point);

    if (edges.find(point) != edges.end()) {
        for (char neighbor : edges[point]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, edges, visited, tree);
            }
        }
    }
}

// Definición de la función find_trees
vector<unordered_set<char>> find_trees(unordered_map<char, unordered_set<char>>& edges, unordered_set<char>& points) {
    vector<unordered_set<char>> trees;
    unordered_set<char> visited;

    for (char point : points) {
        if (visited.find(point) == visited.end()) {
            unordered_set<char> tree;
            dfs(point, edges, visited, tree);
            trees.push_back(tree);
        }
    }

    return trees;
}

int main() {
    // Entrada de aristas
    cout << "Enter the list of tree edges (one per line, given as an unordered pair of uppercase letters delimited by a row of 4 asterisks):\n";
    unordered_map<char, unordered_set<char>> edges; // Utilizamos un mapa para representar los bordes
    string input;
    while (getline(cin, input) && input != "****") {
        char start, end;
        // Modificamos la entrada para manejar (A,B) y (B,A) como lo mismo
        sscanf(input.c_str(), "(%c,%c)", &start, &end);
        edges[start].insert(end);
        edges[end].insert(start);  // Se agrega la arista inversa también
    }

    // Entrada de puntos
    cout << "Enter the list of points in the tree (up to 26 corresponding to uppercase letters, A..Z):\n";
    unordered_set<char> points;
    string pointsInput;
    getline(cin, pointsInput);
    istringstream iss(pointsInput);
    char point;
    while (iss >> point) {
        if (point != ',') {  // Evitar contar comas como bellotas
            points.insert(point);
        }
    }

    vector<unordered_set<char>> trees = find_trees(edges, points);
    unordered_set<char> treeVertices;

    int num_trees = 0;
    int num_acorns = 0;

    for (auto& tree : trees) {
        if (tree.size() > 1) {
            cout << "Arbol" << num_trees + 1 << ": ";
            for (char vertex : tree) {
                cout << vertex;
                treeVertices.insert(vertex);
            }
            cout << endl;
            num_trees++;
        }
    }

    cout << "Bellotas: ";
    for (char vertex : points) {
        if (vertex != ',' && treeVertices.find(vertex) == treeVertices.end()) {
            cout << vertex;
            num_acorns++;
        }
    }
    cout << endl;

    cout << "There are " << num_trees << " tree(s) and " << num_acorns << " acorn(s)." << endl;

    return 0;
}
