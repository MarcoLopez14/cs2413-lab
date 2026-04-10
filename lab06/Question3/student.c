int has_triangle(Graph* g) {
    for (int i = 0; i < g->numNodes; i++) {
        for (int j = i + 1; j < g->numNodes; j++) {
            if (g->adj[i][j] == 1) {
                for (int k = j + 1; k < g->numNodes; k++) {
                    if (g->adj[i][k] == 1 && g->adj[j][k] == 1) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}
