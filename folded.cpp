#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;
const ld EPS = 1e-9;

struct P {
    ld x, y;
    bool operator<(const P& o) const {
        if (abs(x - o.x) > EPS) return x < o.x;
        return y < o.y - EPS;
    }
    bool operator==(const P& o) const {
        return abs(x - o.x) < EPS && abs(y - o.y) < EPS;
    }
};

P operator+(P a, P b) { return {a.x + b.x, a.y + b.y}; }
P operator-(P a, P b) { return {a.x - b.x, a.y - b.y}; }
P operator*(P a, ld s) { return {a.x * s, a.y * s}; }
ld cross(P a, P b) { return a.x * b.y - a.y * b.x; }
ld dot(P a, P b) { return a.x * b.x + a.y * b.y; }
ld distSq(P a) { return dot(a, a); }

ld fix(ld n) {
    if (abs(n) < 0.005) return 0.0;
    return n;
}

bool onSegment(P p, P a, P b) {
    return abs(cross(b - a, p - a)) < EPS && dot(p - a, p - b) <= EPS;
}

P intersect(P a, P b, P c, P d) {
    ld cp1 = cross(b - a, c - a), cp2 = cross(b - a, d - a);
    if (abs(cp1 - cp2) < EPS) return {NAN, NAN};
    return (c * cp2 - d * cp1) * (1.0 / (cp2 - cp1));
}

int pointInPoly(P p, const vector<P>& poly) {
    int w = 0, n = poly.size();
    for (int i = 0; i < n; i++) {
        P a = poly[i], b = poly[(i + 1) % n];
        if (onSegment(p, a, b)) return 1;
        if (a.y <= p.y) {
            if (b.y > p.y && cross(b - a, p - a) > EPS) w++;
        } else {
            if (b.y <= p.y && cross(b - a, p - a) < -EPS) w--;
        }
    }
    return w ? 2 : 0;
}

vector<P> cutPoly(const vector<P>& poly, P a, P b) {
    vector<P> res;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        P c = poly[i], d = poly[(i + 1) % n];
        ld cp1 = cross(b - a, c - a), cp2 = cross(b - a, d - a);
        if (cp1 > -EPS) res.push_back(c);
        if (cp1 * cp2 < -EPS) res.push_back(intersect(a, b, c, d));
    }
    return res;
}

struct Seg { P u, v; };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ld area;
    if (!(cin >> area)) return 0;
    ld s = sqrt(area);
    P f1, f2;
    cin >> f1.x >> f1.y >> f2.x >> f2.y;

    vector<P> sq = {{0, 0}, {0, s}, {s, s}, {s, 0}};
    vector<P> left = cutPoly(sq, f1, f2);
    vector<P> right = cutPoly(sq, f2, f1);
    
    vector<P> ref;
    P line = f2 - f1;
    for (P p : left) {
        ld t = dot(p - f1, line) / distSq(line);
        P proj = f1 + line * t;
        ref.push_back(proj * 2.0 - p);
    }

    vector<Seg> raw;
    auto pushSegs = [&](const vector<P>& poly) {
        for (int i = 0; i < (int)poly.size(); i++) 
            raw.push_back({poly[i], poly[(i + 1) % poly.size()]});
    };
    pushSegs(right);
    pushSegs(ref);

    vector<Seg> atomic;
    for (auto& s : raw) {
        vector<P> cuts = {s.u, s.v};
        for (auto& o : raw) {
            if (abs(cross(s.v - s.u, o.v - o.u)) > EPS) {
                P ip = intersect(s.u, s.v, o.u, o.v);
                if (!isnan(ip.x) && onSegment(ip, s.u, s.v) && onSegment(ip, o.u, o.v))
                    cuts.push_back(ip);
            }
        }
        sort(cuts.begin(), cuts.end());
        cuts.erase(unique(cuts.begin(), cuts.end()), cuts.end());
        for (size_t i = 0; i < cuts.size() - 1; i++) atomic.push_back({cuts[i], cuts[i+1]});
    }

    vector<Seg> bound;
    for (auto& s : atomic) {
        P mid = (s.u + s.v) * 0.5;
        if (pointInPoly(mid, right) == 2 || pointInPoly(mid, ref) == 2) continue;
        bound.push_back(s);
    }

    vector<P> pts;
    for (auto& s : bound) { pts.push_back(s.u); pts.push_back(s.v); }
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    auto getIdx = [&](P p) { return lower_bound(pts.begin(), pts.end(), p) - pts.begin(); };
    vector<vector<int>> adj(pts.size());
    
    for (auto& s : bound) {
        int u = getIdx(s.u), v = getIdx(s.v);
        bool dup = 0;
        for(int n : adj[u]) if(n == v) dup = 1;
        if(!dup) { adj[u].push_back(v); adj[v].push_back(u); }
    }

    vector<string> ans;
    cout << fixed << setprecision(2);
    for (int i = 0; i < (int)pts.size(); i++) {
        bool keep = true;
        if (adj[i].size() == 2) {
            P p = pts[i], a = pts[adj[i][0]], b = pts[adj[i][1]];
            if (abs(cross(a - p, b - p)) < 1e-4) keep = false;
        } else if (adj[i].size() == 0) keep = false;
        
        if (keep) {
            stringstream ss;
            ss << fixed << setprecision(2) << fix(pts[i].x) << " " << fix(pts[i].y);
            ans.push_back(ss.str());
        }
    }

    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        if(i != (int)ans.size() - 1) cout << "\n";
    }

    return 0;
}