#include "dijkstras.h"
int main(){
    // Graph tester;
    // argv[1] >> tester;
    // vector<int> distances = dijkstra_shortest_path(tester, 0, );
    // print_path(extract_shortest_path());

    Graph G;
    
    string filename = "src/small.txt"; // Change to actual file path

    try {
        file_to_graph(filename, G);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    //G.numVertices = 4;
    int source = 0, destination = 2; // Change based on your graph
    vector<int> previous;
    
    // Run Dijkstra's algorithm
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    // Extract the shortest path from `previous` array
    vector<int> path = extract_shortest_path(distances, previous, destination);

    // Print the path
    //print_path(path, distances[destination]);

}