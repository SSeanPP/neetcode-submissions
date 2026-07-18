class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left{}, right{static_cast<int>(nums.size())-1};
        int mid{right / 2};

        while(left < right) {
            mid = ((right-left) / 2) + left;

            if (nums[mid] < nums [right]) {
                if(target>= nums[mid] && target <= nums[right]) {
                    return binarySearch(std::span<const int>(nums).subspan(mid), target, mid);
                } else {
                    right = mid;
                }
                
            } else {
                left = mid+1;
            }
        }
        
        return -1;
    }

    int binarySearch(std::span<const int> nums, int target, int rightPos) {
        std::cout<<"Nums:";
        for(const auto& i : nums) {
            std::cout << i;
        } 
        std::cout<<"\n";
        int left{}, right{static_cast<int>(nums.size())-1};
        int mid{right / 2};

        while (left <= right) {
            mid = ((right-left) / 2) + left;
            if(nums[mid] == target) {
                std::cout<<"reached\n";
                return mid+rightPos;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return -1;
    }
};
