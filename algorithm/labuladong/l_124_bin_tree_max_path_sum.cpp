#include "../utility/myBinTree.h"
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace XL::Algorithm;
class Solution
{
public:
    int findmaxsum(BinTreeNode *root, int &maxsum)
    {
        if (!root)
            return 0;
        int leftmax = std::max(findmaxsum(root->m_pLeft, maxsum), 0);
        int rightmax = std::max(findmaxsum(root->m_pRight, maxsum), 0);
        // 比较的时候左右子树和加上根
        maxsum = std::max(maxsum, leftmax + rightmax + root->m_nValue);
        // 返回到上层的只是左右的较大者和根
        return std::max(leftmax, rightmax) + root->m_nValue;
    }

    int maxPathSum(BinTreeNode *root)
    {
        int maxsum = INT_MIN;
        findmaxsum(root, maxsum);
        return maxsum;
    }
};
/*
[1,2,3]
[-10,9,20,null,null,15,7]
*/
int main()
{
    Solution tmp;
    BinTreeNode *root = CreateBinTreeNode(-10);
    BinTreeNode *root1 = CreateBinTreeNode(9);
    BinTreeNode *root2 = CreateBinTreeNode(20);
    BinTreeNode *root3 = CreateBinTreeNode(15);
    BinTreeNode *root4 = CreateBinTreeNode(7);
    ConnectTreeNodes(root, root1, root2);
    ConnectTreeNodes(root2, root3, root4);
    PrintTree(root);

    std::cout << tmp.maxPathSum(root) << std::endl;
    return 0;
}