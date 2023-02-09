## Maximum Bipartite Matching
`` www.github.com/navgtcode
``

This problem can be solved using the concept of graph theory and maximum matching. A matching in a graph is a set of edges such that no two edges share a common vertex. 
A maximum matching is a matching with the largest number of edges.

One way to solve this problem is to construct a bipartite graph with the job applicants as one set of 
vertices and the jobs as the other set of vertices. Then, connect an applicant to a job if and only if the applicant is interested in that job. Finally, find the maximum 
matching in this bipartite graph. 

In this problem, the number of edges in the maximum matching is the maximum number of applicants who can get a job. This can be done 
using the Hungarian algorithm, which is an algorithm to solve the assignment problem and find the maximum matching in a bipartite graph. The time complexity of the 
Hungarian algorithm is O(N^3), where N is the number of vertices in the bipartite graph.

###  Brute-force Approach
````
int dfs(vector<vector<int>>&G, int u, bool used[], int match[]) {
    int n = G[0].size();
    for (int v = 0; v < n; v++) {
        if (G[u][v] && !used[v]) {
            used[v] = true;
            if (match[v] == -1 || dfs(G, match[v], used, match)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maximumMatch(vector<vector<int>>&G) {
    int n = G.size();
    int m = G[0].size();
    int match[m];
    memset(match, -1, sizeof match);
    int res = 0;
    for (int i = 0; i < n; i++) {
        bool used[m];
        memset(used, false, sizeof used);
        if (dfs(G, i, used, match)) {
            res++;
        }
    }
    return res;
}

````

_The code uses a brute-force approach to find the maximum matching, which is a backtracking method, which tries all possible assignments of jobs to applicants and selects the best one that gives the maximum number of matches. The time complexity of the code is O(N3), where N is the number of jobs. The space complexity of the code is O(N)._


###  Optimized Approach
````
int maximumMatch(vector<vector<int>>& G) {
    n = G.size();
    m = G[0].size();
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(slack, 0x3f, sizeof slack);
    for (int i = 0; i < n; i++) {
        memset(vx, 0, sizeof vx);
        memset(vy, 0, sizeof vy);
        if (dfs(G, i)) {
            ++cnt;
        }
    }
    return cnt;
}

bool dfs(vector<vector<int>>& G, int u) {
    vx[u] = true;
    for (int v = 0; v < m; v++) {
        if (!vy[v]) {
            int t = lx[u] + ly[v] - G[u][v];
            if (!t) {
                vy[v] = true;
                if (!y[v] || dfs(G, y[v])) {
                    x[u] = v;
                    y[v] = u;
                    return true;
                }
            } else {
                slack[v] = min(slack[v], t);
            }
        }
    }
    return false;
}

````

_The concept used in the code above is the Maximum Bipartite Matching algorithm, which is a famous problem in graph theory. The algorithm is based on finding the maximum matching in a bipartite graph. The time complexity of this code is O(n * m) and the space complexity of this code is O(m). Where n is the number of job applicants and m is the number of jobs_



