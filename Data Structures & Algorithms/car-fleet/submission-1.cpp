class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::stack<double> carTimes{};
        int noFleets{static_cast<int>(position.size())};
        
        std::vector<std::pair<int,int>> cars;
        cars.reserve(position.size());
        for(size_t i{}; i < position.size(); i++) cars.emplace_back(position[i], speed[i]);
        
        std::sort(cars.begin(), cars.end(), std::greater<>());

        for(size_t i{}; i < cars.size(); i++) {
            double carETA{((double)(target - cars[i].first) / cars[i].second)};
            if(carTimes.empty()) {
                carTimes.push(carETA);
            } else {
                if(carETA <= carTimes.top()) {
                    noFleets--;
                } else {
                    carTimes.push(carETA);
                }
            }

        }

        return noFleets;
    }
};
