class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> network;
    int price = 0;
    int res = 10000000;
    unordered_map<int,vector<pair<int,int>>> stop_price;
    inline bool continueroute(int city, int stop, int price){
        if (stop_price.find(city) == stop_price.end()){
            //the first route for the city found, add it to hash map and return true
            pair<int,int> p = {stop, price};
            vector<pair<int,int>> v;
            v.emplace_back(p);
            stop_price.emplace(city,v);
            return true;
        } else{
            auto it = find_if(stop_price[city].begin(), stop_price[city].end(),
            [&stop](const pair<int,int>& p){ return p.first == stop; });
            if (it == stop_price[city].end()){
                //if there exist a route that has smaller stops and lower / same price with this route, return false
                for (int i=0; i< stop_price[city].size();i++){
                    if (stop_price[city][i].first < stop && stop_price[city][i].second <= price ){
                        return false;
                    }
                }
                pair<int,int> p = {stop, price};
                stop_price[city].emplace_back(p);
                return true;
            } else{//route with same stops already exist, if the price is lower than existing route, update the price and return true
                if (price < it-> second){
                    it->second = price;
                    return true;
                } else{ //price higher, return false and not continue with this route
                    return false;
                }
            }
        }

    }
    void dfs(int city, int dest, int k,int stop){
        //cout << "depart " << city << endl;
        if (city == dest){
            //cout << "reached " << price << endl;
            res = min(res,price);
            return;
        }
        for (int i=0; i< network[city].size();i++){
            int next = network[city][i].first;
            //cout << "next " << next << endl;
            if (stop<=k && price < res-network[city][i].second){//visit next city
                price += network[city][i].second;
                //
                if ( continueroute(next, stop+1, price) ){
                    dfs(next, dest,k,stop+1);
                }
                price -= network[city][i].second;
            }
        }
        //cout << city << "," << price << endl;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for (int i=0; i< flights.size();i++){
            if (network.find(flights[i][0]) == network.end()){
                vector<pair<int,int>> v;
                pair<int,int> p= {flights[i][1],flights[i][2]}; //destination & price
                v.emplace_back(p);
                network.emplace(flights[i][0],v);
            } else{
                pair<int,int> p= {flights[i][1],flights[i][2]}; //destination & price
                network[flights[i][0]].emplace_back(p);
            }

        }

        dfs(src, dst,k,0);
        if (res == 10000000){
            return -1;
        }
        return res;
    }
};