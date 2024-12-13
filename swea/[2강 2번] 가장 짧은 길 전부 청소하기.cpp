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

        vector<vector<pair<ll, ll>>> graph(N + 1);  // �׷���: (���, ����ġ)
        vector<ll> cost(N + 1, LLONG_MAX);  // �ִ� ��� ���
        vector<ll> final_cost(N + 1, 0);  // ������ ������ ���

        // �׷��� ���� �Է�
        for (ll i = 0; i < M; i++) {
            ll u, v;
            ll c;
            cin >> u >> v >> c;
            graph[u].emplace_back(v, c);
            graph[v].emplace_back(u, c);
        }

        // ���ͽ�Ʈ�� �˰����� ���� �ּ� ��
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        cost[1] = 0;
        pq.push({ 0, 1 });  // (���, ���)

        while (!pq.empty()) {
            ll cur_cost = pq.top().first;
            ll cur_node = pq.top().second;
            pq.pop();

            // �̹� ó���� ��뺸�� �� ū ������� ó���� �ʿ䰡 �����Ƿ� �ǳʶٱ�
            if (cur_cost > cost[cur_node]) continue;

            // ���� ��忡�� ���� ���� ���� ��� Ž��
            for (const auto& edge : graph[cur_node]) {
                ll next_node = edge.first;
                ll next_cost = edge.second;

                // �� ���� ������� ������ �� ������ ����
                if (cost[next_node] > cur_cost + next_cost) {
                    cost[next_node] = cur_cost + next_cost;
                    final_cost[next_node] = next_cost;
                    pq.push({ cost[next_node], next_node });
                }
                // ���� ����� �� �� ���� ���� ����
                else if (cost[next_node] == cur_cost + next_cost) {
                    final_cost[next_node] = min(final_cost[next_node], next_cost);
                }
            }
        }

        // ��� ��忡 ���� final_cost �� �ջ�
        for (ll i = 1; i <= N; i++) {
            ans += final_cost[i];
        }

        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}