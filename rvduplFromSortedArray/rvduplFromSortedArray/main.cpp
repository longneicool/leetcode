#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(nums.size() == 0)
        return -1;

    int index = 0;
    int counter = 1;
    for(int i=1; i<nums.size(); i++)
    {
        if(nums.at(i) == nums.at(index))
        {
            if(counter < 2)
            {
              index++;
              nums.at(index) = nums.at(i);
            }
            counter ++;
        }else
        {
            index++;
            nums.at(index) = nums.at(i);
            counter = 1;
        }
    }

    return index+1;
}

int main()
{
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(1);
//    vec1.push_back(1);
//    vec1.push_back(1);
//    vec1.push_back(1);
//    vec1.push_back(3);
//    vec1.push_back(3);
//    vec1.push_back(3);
//    vec1.push_back(4);

    cout<<removeDuplicates(vec1)<<endl;
    for(int i=0; i<vec1.size(); i++)
    {
        cout<<vec1.at(i)<<endl;
    }
    cout << "Hello World!" << endl;
    return 0;
}

