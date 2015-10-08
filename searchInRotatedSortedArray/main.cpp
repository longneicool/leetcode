#include <iostream>
#include <vector>

using namespace std;

int searchVal(unsigned int first, unsigned int end, int target, vector<int> &nums)
{
    unsigned int mid = (first + end)/2;

    if(nums.at(mid) == target)
        return mid;

    if(first == end && nums.at(mid)!=target)
        return -1;

    if(nums.at(first) <= nums.at(mid))
    {
        if(nums.at(first) <= target && target <= nums.at(mid))
        {
            return searchVal(first, mid, target, nums);
        }

        return searchVal(mid+1, end, target, nums);
    }else
    {
        if(nums.at(mid+1) <= target && target <= nums.at(end))
        {
            return searchVal(mid+1, end, target, nums);
        }
        return searchVal(first, mid, target, nums);
    }
}

int main()
{
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout<<searchVal(0, vec.size()-1, 5, vec)<<std::endl;

    return 0;
}

