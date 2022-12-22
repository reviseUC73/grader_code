#include <iostream>

using namespace std;

int minimum_stops(int N, int Z, int D, int E, int gas_station_locations[])
{
    int current_location = 0;
    int num_stops = 0;
    for (int i = 0; i < N; i++)
    {
        int distance_to_gas_station = gas_station_locations[i] - current_location;
        if (distance_to_gas_station > D)
        {
            num_stops++;
            current_location = gas_station_locations[i];
        }
        else
        {
            int distance_to_final_destination = Z - gas_station_locations[i];
            if (distance_to_final_destination <= E)
            {
                current_location = Z;
            }
            else
            {
                num_stops++;
                current_location = gas_station_locations[i];
            }
        }
    }
    if (current_location == Z)
    {
        return num_stops;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int N, Z, D, E;
    cin >> N >> Z >> D >> E;
    int gas_station_locations[N];
    for (int i = 0; i < N; i++)
    {
        cin >> gas_station_locations[i];
    }
    cout << minimum_stops(N, Z, D, E, gas_station_locations) << endl;
    return 0;
}
