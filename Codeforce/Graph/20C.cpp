#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {

        pair<long long, int> curr = pq.top();
        pq.pop();

        long long currDist = curr.first;
        int node = curr.second;

        if (currDist > dist[node])
            continue;

        for (auto &it : adj[node]) {

            int nextNode = it.first;
            int weight = it.second;

            if (currDist + weight < dist[nextNode]) {

                dist[nextNode] = currDist + weight;
                parent[nextNode] = node;

                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    if (dist[n] == LLONG_MAX) {
        cout << -1;
        return 0;
    }

    vector<int> path;

    int currNode = n;

    while (parent[currNode] != currNode) {
        path.push_back(currNode);
        currNode = parent[currNode];
    }

    path.push_back(1);

    reverse(path.begin(), path.end());

    for (int x : path) {
        cout << x << " ";
    }

    return 0;
}