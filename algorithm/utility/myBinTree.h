#ifndef _MY_BIN_TREE_H_
#define _MY_BIN_TREE_H_

namespace XL
{
    namespace Algorithm
    {
        // Definition for a binary tree node.
        struct BinTreeNode
        {
            int m_nValue;
            BinTreeNode *m_pLeft;
            BinTreeNode *m_pRight;

            BinTreeNode(int nValue) : m_nValue(nValue), m_pLeft(nullptr), m_pRight(nullptr) {}
            BinTreeNode() : m_nValue(0), m_pLeft(nullptr), m_pRight(nullptr) {}
        };

        BinTreeNode *CreateBinTreeNode(int value);
        void ConnectTreeNodes(BinTreeNode *pParent, BinTreeNode *pLeft, BinTreeNode *pRight);
        void PrintTreeNode(const BinTreeNode *pNode);
        void PrintTree(const BinTreeNode *pRoot);
        void DestroyTree(BinTreeNode *pRoot);

    } // namespace Algorithm
} // namespace XL

#endif