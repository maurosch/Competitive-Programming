/*
    UVA 11935 - Through the Desert
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
using namespace std;

enum EventType {
    fuel_consumption,
    mechanic,
    gas_station,
    leak,
    goal
};

struct Event {
    EventType type;
    int start;
    int fuelConsumptionValue;
};

bool doesItFit(double tankVolume, const vector<Event>& events){
    int fuelConsumptionPer100km = 0;
    int currentkm = 0;
    int currentLeaks = 0;
    double currentFuel = tankVolume;
    for(int i = 0; i < events.size(); i++){
        currentFuel -= double(events[i].start - currentkm) * (double(fuelConsumptionPer100km) / 100 + currentLeaks);
        
        if(currentFuel < 0)
            return false;
        
        currentkm = events[i].start;
        if(events[i].type == fuel_consumption){
            fuelConsumptionPer100km = events[i].fuelConsumptionValue;
        }
        if(events[i].type == mechanic){
            currentLeaks = 0;
        } 
        if(events[i].type == gas_station){
            currentFuel = tankVolume;
        }  
        if(events[i].type == leak){
            currentLeaks++;
        } 
    }
    return true;
}

int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    while(true){
        vector<Event> events;
        while(true){
            int start;
            string event;
            cin >> start;
            getline(cin,event);
            event = event.substr(1);
            
            if(start == 0 and event == "Fuel consumption 0")
                return 0;

            if(event.rfind("Fuel consumption", 0) == 0){
                events.push_back({
                    fuel_consumption,
                    start,
                    stoi(event.substr(17))
                });
            }
            if(event.rfind("Leak", 0) == 0){
                events.push_back({
                    leak,
                    start
                });
            }
            if(event.rfind("Goal", 0) == 0){
                events.push_back({
                    goal,
                    start
                });
                break;
            }
            if(event.rfind("Mechanic", 0) == 0){
                events.push_back({
                    mechanic,
                    start
                });
            }
            if(event.rfind("Gas station", 0) == 0){
                events.push_back({
                    gas_station,
                    start
                });
            }
        }
            
        double tankVolume = 0;
        double hi = events[events.size()-1].start * (30 / 100 + events.size() * events.size()), lo = 0;
        while(hi-lo >= 1e-10){
            tankVolume = (hi+lo)/2;
            if(doesItFit(tankVolume, events)){
                hi = tankVolume;
            } else {
                lo = tankVolume;
            }
        }
        cout << fixed << setprecision(3) << hi << endl;
        
   }
    return 0;
}