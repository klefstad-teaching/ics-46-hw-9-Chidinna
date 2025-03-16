int main(int argc, char* argv[]){
    Graph tester;
    argv[1] >> tester;
    vector<int> distances = dijkstra_shortest_path(tester, 0, );
    print_path(extract_shortest_path());

}