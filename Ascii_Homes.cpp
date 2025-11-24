#include <bits/stdc++.h>
using namespace std;

using ll = long long;
map<int, map<int, char>> G;
int mn = 1e9, mx = -1e9, C = 0;

void P(int x, int y, char c) {
    G[y][x] = c;
    mn = min(mn, y);
    mx = max(mx, y);
}

int main() {
    string s;
    while (cin >> s) {
        int xP = s.find('x');
        int l = stoi(s.substr(0, xP));
        // Parse height from substring between 'x' and the last char (direction)
        int h = stoi(s.substr(xP + 1, s.size() - xP - 2));
        char d = s.back();
        int rh = l / 2; // Roof height

        if (d == 'H' || d == 'D') {
            // Upright: Base at 0, grows Up (-y)
            for (int i = 0; i < rh; i++) {
                P(C + l / 2 - 1 - i, -(h + i + 1), '/');
                P(C + l / 2 + i, -(h + i + 1), '\\');
            }
            for (int i = 0; i < h; i++) {
                P(C, -(i + 1), '@');
                P(C + l - 1, -(i + 1), '&');
            }
            for (int i = 0; i < l; i++) P(C + i, 0, '#');
            C += l;
        } 
        else if (d == 'U') {
            // Inverted: Base at 0, grows Down (+y)
            for (int i = 0; i < l; i++) P(C + i, 0, '#');
            for (int i = 0; i < h; i++) {
                P(C, i + 1, '@');
                P(C + l - 1, i + 1, '&');
            }
            for (int i = 0; i < rh; i++) {
                P(C + i, h + i + 1, '\\');
                P(C + l - 1 - i, h + i + 1, '/');
            }
            C += l;
        } 
        else if (d == 'L') {
            // Tilted Left: Rotated 90 CCW. Base on Right.
            // Total width = Roof(rh) + Wall(h) + Base(1)
            int w = rh + h + 1, ys = -(l / 2);
            for (int i = 0; i < l; i++) P(C + w - 1, ys + i, '#');
            for (int i = 0; i < h; i++) {
                P(C + rh + i, ys, '&');       // Top Wall
                P(C + rh + i, ys + l - 1, '@'); // Bottom Wall
            }
            for (int i = 0; i < rh; i++) {
                P(C + rh - 1 - i, ys + i, '/');      // Top slope
                P(C + rh - 1 - i, ys + l - 1 - i, '\\'); // Bottom slope
            }
            C += w;
        } 
        else if (d == 'R') {
            // Tilted Right: Rotated 90 CW. Base on Left.
            int w = rh + h + 1, ys = -(l / 2);
            for (int i = 0; i < l; i++) P(C, ys + i, '#');
            for (int i = 0; i < h; i++) {
                P(C + 1 + i, ys, '@');       // Top Wall
                P(C + 1 + i, ys + l - 1, '&'); // Bottom Wall
            }
            for (int i = 0; i < rh; i++) {
                P(C + h + i, ys + i, '\\');          // Top slope
                P(C + h + i, ys + l - 1 - i, '/'); // Bottom slope
            }
            C += w;
        }
    }

    // Render Grid
    for (int y = mn; y <= mx; y++) {
        if (G.find(y) == G.end()) { cout << '\n'; continue; }
        int mX = G[y].rbegin()->first;
        for (int x = 0; x <= mX; x++) {
            cout << (G[y].count(x) ? G[y][x] : ' ');
        }
        cout << '\n';
    }
}