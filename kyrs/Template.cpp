#include "Functions.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

  freopen("C:\\Temp\\input.txt", "rt", stdin);
  freopen("C:\\Temp\\output.txt", "wt", stdout);

  int n, m;
  scanf("%d%d", &n, &m);
 
  for (int i = 0; i < m; i++)
  {
      scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);

      e[i].x--;
      e[i].y--;
  }

  sort(e.begin(), e.end(), comparator);

  leader.resize(n);
  e.resize(m);

  for (int i = 0; i < n; i++) {
    leader[i] = i;
  }

  vector <edge> ans;

  for (int i = 0; i < m; i++)
  {
      int x = e[i].x, y = e[i].y;

      if (unite(x, y))
          ans.push_back(e[i]);
  }

  int sum = 0;
    for (int i = 0; i < ans.size(); i++)
        sum+=ans[i].w;
    printf("%d\n", sum);
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].x + 1, ans[i].y + 1);
    
    return 0;
}