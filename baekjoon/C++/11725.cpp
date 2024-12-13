#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, x, y, parent[100001];
bool visit[100001];
vector<int> edge[100001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visit[start] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto i : edge[cur]) {
            if (!visit[i]) {
                q.push(i);
                visit[i] = true;
                parent[i] = cur;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    bfs(1);
    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
}