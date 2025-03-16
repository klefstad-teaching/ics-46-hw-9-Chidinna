#include "dijkstras.h"

vector<int> dijkstra_shortest_path(Graph& G, int source, vector<int>& previous){
    //adjacencyList
    n = G.numVertices;


    //distance.resize(n, INT_MAX);

    //previous.resize(n, -1);

    //visited.resize(n, false);

    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    previous.assign(n, -1);

    priorityQueue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, source});

    distance[source] = 0;

    ///pq.push({0, source});
    while !pq.empty(){

        int u = pq.top().second;

        pq.pop();

        if (visited[u]) continue;


        visited[u] = true;

        for(Edge& neighbor : G[u]){

            int v = neighbor.dst;

            weight = neighbor.weight;


            if(!visited[v] && distance[u] + weight <  distance[v]){

                distance[v] = distance[u] + weight;

                previous[v] = u;

                pq.push({v, distance[v]});
            }
        }   

    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> returnVec;
    if(previous[destination] == -1 || distances[destination] == 0){
        std::cout << "No path to " << destination;
        return returnVec;
    }
    for (int i = destination; i != -1; i = previous[i]) returnVec.push_back(i);
    return returnVec;
}