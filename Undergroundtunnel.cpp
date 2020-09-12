class UndergroundSystem {
public:
    string combine(string s1,string s2)
    {
        return s1+"->"+s2;
    }
    unordered_map<int, pair<string,int>>checkindict;
    unordered_map<string,pair<double,double>>journey;
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        checkindict[id] = make_pair(stationName,t);
    }

    void checkOut(int id, string stationName, int t) {
        pair<string,int>fron = checkindict[id];
        pair<double,double>fron2;
        checkindict.erase(id);
        string start = fron.first;
        int start_time = fron.second;

        string finish = stationName;
        string res_journey = combine(start,finish);
        if(journey.find(res_journey) != journey.end())
            fron2 = journey[res_journey];
        else
            fron2 = make_pair(0.0,0.0);
        fron2.first = fron2.first + 1;
        fron2.second=fron2.second + t - start_time;
        journey[res_journey]=fron2;
    }

    double getAverageTime(string startStation, string endStation) {
        string res_journey = combine(startStation,endStation);
        if(journey.find(res_journey) == journey.end())
            return 0.0;
        return journey[res_journey].second/journey[res_journey].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
