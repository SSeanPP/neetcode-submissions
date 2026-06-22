class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::stack<int> carIndex{};
        int noFleets{static_cast<int>(position.size())};
        
        std::vector<std::pair<int,int>> cars;
        cars.reserve(position.size());
        for(size_t i{}; i < position.size(); i++) cars.emplace_back(position[i], speed[i]);
        
        std::sort(cars.begin(), cars.end(), std::greater<>());

        for(size_t i{}; const auto& [position, speed] : cars) {
            if(carIndex.empty()) {
                carIndex.push(i);
            } else {
                
                if(((double)(target - position) / speed) <= ((double)(target - cars[carIndex.top()].first) / cars[carIndex.top()].second)) {
                    noFleets--;
                } else {
                    carIndex.push(i);
                }
            }

            i++;
        }

        return noFleets;
    }
};
