#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstdio>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        ll ans = 0;

        ll N, M;
        cin >> N >> M;

        vector<vector<pair<ll, ll>>> graph(N + 1);  // 그래프: (노드, 가중치)
        vector<ll> cost(N + 1, LLONG_MAX);  // 최단 경로 비용
        vector<ll> final_cost(N + 1, 0);  // 선택한 간선의 비용

        // 그래프 정보 입력
        for (ll i = 0; i < M; i++) {
            ll u, v;
            ll c;
            cin >> u >> v >> c;
            graph[u].emplace_back(v, c);
            graph[v].emplace_back(u, c);
        }

        // 다익스트라 알고리즘을 위한 최소 힙
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        cost[1] = 0;
        pq.push({ 0, 1 });  // (비용, 노드)

        while (!pq.empty()) {
            ll cur_cost = pq.top().first;
            ll cur_node = pq.top().second;
            pq.pop();

            // 이미 처리된 비용보다 더 큰 비용으로 처리할 필요가 없으므로 건너뛰기
            if (cur_cost > cost[cur_node]) continue;

            // 현재 노드에서 인접 노드로 가는 경로 탐색
            for (const auto& edge : graph[cur_node]) {
                ll next_node = edge.first;
                ll next_cost = edge.second;

                // 더 작은 비용으로 도달할 수 있으면 갱신
                if (cost[next_node] > cur_cost + next_cost) {
                    cost[next_node] = cur_cost + next_cost;
                    final_cost[next_node] = next_cost;
                    pq.push({ cost[next_node], next_node });
                }
                // 같은 비용일 때 더 작은 간선 선택
                else if (cost[next_node] == cur_cost + next_cost) {
                    final_cost[next_node] = min(final_cost[next_node], next_cost);
                }
            }
        }

        // 모든 노드에 대해 final_cost 값 합산
        for (ll i = 1; i <= N; i++) {
            ans += final_cost[i];
        }

        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}