int count_edges(Graph* g) {
    int count = 0;

    for (int i = 0; i < g->numNodes; i++) {
        for (int j = 0; j < g->numNodes; j++) {
            if (g->adj[i][j] == 1) {
                count++;
            }
        }
    }

    return count / 2;
}
