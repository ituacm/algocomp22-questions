#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int SZ = 2000;

bool table[SZ][SZ+1];
int counts[SZ+1][SZ+1];

int main() {
  int X, Y, N, D;
  scanf("%d%d%d%d", &X, &Y, &N, &D);

  for(int i = 0; i < N; i++) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
    for(int x = x1; x < x2; x++)
      for(int y = y1; y < y2; y++)
        table[x][y] = true;
  }

  for(int x = 0; x < X; x++) table[x][Y] = true;

  vector<int> hist(Y+1, 0);
  for(int x = 0; x < X; x++) {
    vector<pair<int, int>> stk(1, make_pair(0, -1));
    for(int y = 0; y <= Y; y++) {
      hist[y] = table[x][y] ? 0 : hist[y]+1;
      int y0 = y;
      while(stk.back().first > hist[y]) {
        y0 = stk.back().second;
        counts[stk.back().first][y - y0]++;
        stk.pop_back();
        counts[max(stk.back().first, hist[y])][y - y0]--;
      }
      stk.push_back(make_pair(hist[y], y0));
    }
  }

  for(int x = X; x >= 1; x--) {
    for(int y = Y-1; y >= 1; y--)
      counts[x][y] += counts[x][y+1];
    for(int y = Y-1; y >= 1; y--)
      counts[x][y] += counts[x][y+1];
  }
  for(int x = X-1; x >= 1; x--)
    for(int y = Y; y >= 1; y--)
      counts[x][y] += counts[x+1][y];

  for(int i = 0; i < D; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", counts[x][y]);
  }

  return 0;
}