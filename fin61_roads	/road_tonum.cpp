#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Pair < Connected Vertex, Min Speed Limit >
vector<pair<int, int>> graph[200000];
bool seen[200000];

int n, m, s, q;

bool is_possible = false;
void is_possible_dfs(int city_a, int city_b)
{
    seen[city_a] = true;
    if (is_possible)
    {
        return;
    }
    for (int i = 0; i < graph[city_a].size(); i++)
    {
        pair<int, int> focused_road = graph[city_a][i];

        // cout<<focused_road.first<<" "<<focused_road.second<<endl;


        if (!seen[focused_road.first] && focused_road.second <= s)
        {
            if (focused_road.first == city_b)
            {
                is_possible = true;
                return;
            }
            // cout << "in_city: " << focused_road.first+1 << " stop: " << city_b+ 1 << endl;

            is_possible_dfs(focused_road.first, city_b);
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    cin >> n >> m >> s >> q;
    for (int i = 0; i < m; i++)
    {
        int city_a, city_b, min_speed;
        cin >> city_a >> city_b >> min_speed;
        city_a--;
        city_b--;
        graph[city_a].push_back(make_pair(city_b, min_speed));
        graph[city_b].push_back(make_pair(city_a, min_speed));
    }

    for (int i = 0; i < q; i++)
    {
        int city_a, city_b;
        cin >> city_a >> city_b;
        city_a--;
        city_b--;

        for (int i = 0; i < m; i++)
        {
            seen[i] = false;
        }
        is_possible = false;
        is_possible_dfs(city_a, city_b);
        if (is_possible)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}