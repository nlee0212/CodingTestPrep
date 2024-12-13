#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;
typedef long long ll;

struct Point {
    ll x;
    ll y;

    bool operator < (const Point& b) const {
        if (x == b.x)
            return y < b.y;
        else
            return x < b.x;
    }
};

ll Distance(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool CompareY(Point a, Point b) {
    return a.y < b.y;
}




ll SearchAll(vector<Point>& v, ll s, ll e) {
    ll minDist = -1;

    for (ll i = s; i <= e - 1; i++) {
        for (ll j = i + 1; j <= e; j++) {
            ll dist = Distance(v[i], v[j]);

            if (minDist == -1 || minDist > dist)
                minDist = dist;
        }
    }

    return minDist;
}



ll SearchPoint(vector<Point>& v, ll start, ll end) {
    ll count = end - start + 1;

    if (count <= 3)
        return SearchAll(v, start, end);

    ll mid = (start + end) / 2;
    ll left = SearchPoint(v, start, mid);
    ll right = SearchPoint(v, mid + 1, end);

    ll answer;
    if (left > right)
        answer = right;
    else
        answer = left;

    // 중앙 근처 값을 계산할 예정
    vector<Point> final;

    for (ll i = start; i <= end; i++) {
        ll xDistance = v[i].x - v[mid].x;

        if (xDistance * xDistance < answer)
            final.push_back(v[i]);
    }

    // y 기준 정렬
    ll maxIndex = final.size();
    sort(final.begin(), final.end(), CompareY);

    for (ll i = 0; i < maxIndex - 1; i++) {
        for (ll j = i + 1; j < maxIndex; j++) {

            ll y = final[j].y - final[i].y;

            if (y * y < answer) {
                ll dist = Distance(final[j], final[i]);
                if (dist < answer)
                    answer = dist;
            }
            else
                break;
        }
    }
    return answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t=1;t<T+1;t++)
    {
		cout << "#" << t << " ";
        ll n;
        cin >> n;
        vector<Point> points(n);

        for (ll i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;

        sort(points.begin(), points.end());


        ll answer = SearchPoint(points, 0, n - 1);

        cout << answer << '\n';
	}
	return 0;
}
