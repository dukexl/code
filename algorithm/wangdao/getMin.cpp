/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2021-12-12 23:22:42
 * @LastEditors: xuli
 * @LastEditTime: 2021-12-13 22:42:41
 */
/*
实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作
1 pop、push、getMin操作的时间复杂度都是O(1)
2 设计的栈类型可以使用现成的栈结构

两种方式：第一种是，每push一个值的时候，也push一个最小值
          第二种是，每push一个值的时候，判断是否最小值是否为最小值，
*/

#include <iostream>
#include <stack>

using namespace std;

class CgetMin
{
public:    
    
    void push(int iValue)
    {
        stData.push(iValue);
        if (stMin.empty())
        {
           stMin.push(iValue);
        }
        else
        {
            int tmp = stMin.top();
            if(tmp > iValue)
                stMin.push(iValue);
            else
                stMin.push(tmp);
        }
    }

    void pop() 
    {
        if(!stData.empty() && ! stMin.empty())
        {
            stData.pop();
            stMin.pop();
        }
    }

    int getMin()
    {
        return stMin.top();
    }

private:
    stack<int> stData;
    stack<int> stMin;
};

int main()
{
    return 0;
}