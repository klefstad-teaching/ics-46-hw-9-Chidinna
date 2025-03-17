#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    //adjacencyList
    int n = G.numVertices;
    


    //distance.resize(n, INT_MAX);

    //previous.resize(n, -1);

    //visited.resize(n, false);

    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    previous.assign(n, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0, source});

    distance[source] = 0;

    ///pq.push({0, source});
    while (!pq.empty()){

        int u = pq.top().second;
        if (u < 0 || u >= n) continue;

        pq.pop();

        if (visited[u]) continue;


        visited[u] = true;

        for(const Edge& neighbor : G[u]){

            int v = neighbor.dst;

            int weight = neighbor.weight;


            if(!visited[v] && distance[u] + weight <  distance[v]){

                distance[v] = distance[u] + weight;

                previous[v] = u;

                pq.push({distance[v], v});
            }
        }   

    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> returnVec;
    if(previous[destination] == -1 /* || distances[destination] == 0*/){
        std::cout << "No path to " << destination;
        return returnVec;
    }
    vector<int> reverse;
    for (int i = destination; i != -1; i = previous[i]) returnVec.push_back(i);
    //for(int i = returnVec.size()-1; i > 0; --i) reverse.push_back(returnVec[i]);
    std::reverse(returnVec.begin(), returnVec.end());
    //for(int i = 0; i < returnVec.size(); ++i){
       //print_path(returnVec, i);
    //}
    return returnVec;
}

void print_path(const vector<int>& v, int total){
    
    for (int i = 0; i < v.size(); ++i){
        std::cout<< v[i] << " ";
    }
    std::cout<< std::endl<< "Total cost is " << total << std::endl;
    //std::cout << std::endl;
}