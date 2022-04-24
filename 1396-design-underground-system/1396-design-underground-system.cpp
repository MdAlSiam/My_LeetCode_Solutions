class UndergroundSystem {
    unordered_map<int, pair<string, int>> checkInLog;
    unordered_map<string, pair<int, int>> path;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInLog[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> checkInHere = checkInLog[id];
        checkInLog.erase(id);

        string pathHere = checkInHere.first+"_"+stationName;
        path[pathHere].first += t-checkInHere.second;
        path[pathHere].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string pathHere = startStation+"_"+endStation;
        return (double) path[pathHere].first/path[pathHere].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */