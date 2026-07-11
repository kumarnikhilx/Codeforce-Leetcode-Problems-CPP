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

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {

        auto [dis, node] = pq.top();
        pq.pop();

        if (dis > dist[node])
            continue;

        for (auto &it : adj[node]) {

            int next = it.first;
            int wt = it.second;

            if (dis + wt < dist[next]) {

                dist[next] = dis + wt;
                parent[next] = node;

                pq.push({dist[next], next});
            }
        }
    }

    if (dist[n] == LLONG_MAX) {
        cout << -1;
        return 0;
    }

    vector<int> path;

    int node = n;

    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(1);

    reverse(path.begin(), path.end());

    for (int x : path)
        cout << x << " ";
}