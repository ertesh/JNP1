// Maciej Andrejczuk
// Task 4: Skojarzenia

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

class Edge {
    public:
        int x, y;
        int weight;
        Edge(int a, int b, int c): x(a), y(b), weight(c) {}
};

typedef vector<Edge> EdgeList;

class Graph {
    public:
        Graph();
        bool readGraph();
        bool isBipartite();
    private:
        int n;  // number of vertices (M from problem statement)
        int m;  // number of edges (N from problem statement)
        vector<EdgeList> edges;
};

Graph::Graph()
: n(0), m(0), edges()
{}

bool Graph::readGraph() {
    cin >> m >> n;
    edges.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges[x].push_back(Edge(x, y, w));
        edges[y].push_back(Edge(y, x, w));
    }
    return true;
}

bool Graph::isBipartite() {
    return true;
}

class Matching {
    public:
        Matching(): weight(-1) {}
        void findMatching(const Graph& g);
        void write();
    private:
        int weight;
        vector<Edge> matched;
};

void Matching::findMatching(const Graph& g) {

}

void Matching::write() {
    cout << weight << endl;
    if (weight != -1) {
        vector<Edge>::iterator ii;
        for (ii = matched.begin(); ii != matched.end(); ii++) {
            cout << ii->x << ii->y << endl;
        }
    }
}

int main()
{
    Graph g;
    if (!g.readGraph()) {
        std::cerr << "Error: Invalid input." << std::endl;
        return 1;
    }
    if (!g.isBipartite()) {
        std::cerr << "Error: Not a bipartite graph." << std::endl;
        return 2;
    }
    Matching solution;
    solution.findMatching(g);
    solution.write();
    return 0;
}

