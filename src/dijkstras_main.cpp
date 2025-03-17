#include "dijkstras.h"
int main(){
    // Graph tester;
    // argv[1] >> tester;
    // vector<int> distances = dijkstra_shortest_path(tester, 0, );
    // print_path(extract_shortest_path());

    Graph G;
    
    string filename = "src/small.txt"; // Change to actual file path

    file_to_graph(filename, G);
    
    int source = 0, destination = 2; 
    vector<int> previous;
    
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    vector<int> path = extract_shortest_path(distances, previous, destination);

}