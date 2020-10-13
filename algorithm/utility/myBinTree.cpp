#include "myBinTree.h"
#include <stdio.h>

namespace XL
{
    namespace Algorithm
    {
        BinTreeNode *CreateBinTreeNode(int value)
        {
            BinTreeNode *pNode = new BinTreeNode();
            pNode->m_nValue = value;
            pNode->m_pLeft = nullptr;
            pNode->m_pRight = nullptr;
            return pNode;
        }

        void ConnectTreeNodes(BinTreeNode *pParent, BinTreeNode *pLeft, BinTreeNode *pRight)
        {
            if (pParent != nullptr)
            {
                pParent->m_pLeft = pLeft;
                pParent->m_pRight = pRight;
            }
        }

        void PrintTreeNode(const BinTreeNode *pNode)
        {
            if (pNode != nullptr)
            {
                printf("%d\n", pNode->m_nValue);
                if (pNode->m_pLeft != nullptr)
                {
                    printf("%d\n", pNode->m_pLeft->m_nValue);
                }
                else
                    printf("left child is nullptr.\n");

                if (pNode->m_pRight != nullptr)
                {
                    printf("%d\n", pNode->m_pRight->m_nValue);
                }
                else
                    printf("right child is nullptr.\n");
            }
            else
            {
                printf("this node is nullptr.\n");
            }
            printf("\n");
        }

        void PrintTree(const BinTreeNode *pRoot)
        {
            PrintTreeNode(pRoot);

            if (pRoot != nullptr)
            {
                if (pRoot->m_pLeft != nullptr)
                    PrintTree(pRoot->m_pLeft);

                if (pRoot->m_pRight != nullptr)
                    PrintTree(pRoot->m_pRight);
            }
        }

        void DestroyTree(BinTreeNode *pRoot)
        {
            if (pRoot != nullptr)
            {
                BinTreeNode *pLeft = pRoot->m_pLeft;
                BinTreeNode *pRight = pRoot->m_pRight;

                delete pRoot;
                pRoot = nullptr;

                DestroyTree(pLeft);
                DestroyTree(pRight);
            }
        }

    } // namespace Algorithm

} // namespace XL
