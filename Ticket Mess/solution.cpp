#include <bits/stdc++.h>

using namespace std;

int main()
{
 ios::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
 int test_cases;
 cin >> test_cases;
 while(test_cases--)
 {
  int n;
  string from_city, to_city;
  cin >> n;
  unordered_set < string > to_cities;
  unordered_map < string , string > routes;
  for(int i = 0 ; i < n ; i++)
  {
    cin >> from_city >> to_city;
    to_cities.insert(to_city);
    routes[from_city] = to_city;
  }
  for(auto [from_city,to_city]:routes)
  {
    if (to_cities.find(from_city) == to_cities.end())
    {
      cout << from_city << " " << to_city;
      while(routes.find(to_city)!=routes.end())
      {
        cout << " " << routes[to_city];
        to_city = routes[to_city];
      }
      cout << endl;
      break;
    }
  }
 }
}