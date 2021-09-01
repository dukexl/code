#include <vector>
using namespace std;

vector<int> twosums(vector<int> &nums, int target)
{
    int ibegin = 0;
    int iend = nums.size();
    vector<int> result;
    while (ibegin < iend)
    {
        if (nums[ibegin] + nums[iend] < target)
        {
            ibegin++;
        }
        else if (nums[ibegin] + nums[iend] > target)
        {
            iend--;
        }
        else
        {
            result.push_back(ibegin);
            result.push_back(iend);
        }
    }
}