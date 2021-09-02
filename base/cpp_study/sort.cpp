#include "std.hpp"
// [函数对象参数] (操作符重载函数参数) mutable 或 exception 声明 -> 返回值类型 {函数体}
int main()
{
    std::vector<int> v = {42, 9, 4, 5, 7, 34, 1, 0};
    int len = v.size();

    for (auto &x : v)
    {
        std::cout << x << ",";
    }
    std::cout << std::endl;

    // auto f = [捕获参数列表](函数参数列表) mutable throw(类型)->返回值类型 {函数语句};
    auto bubble_sort = [=]() mutable
    {
        for (size_t i = 0; i < len - 1; i++)
        {
            for (size_t j = 0; j < len - i - 1; j++)
            {
                if (v[j] > v[j + 1])
                {
                    std::swap(v[j], v[j + 1]);
                }
            }
        }

        for (auto &x : v)
        {
            std::cout << x << ",";
        }
        std::cout << std::endl;
    };

    bubble_sort();

    auto select_sort = [=]() mutable
    {
        for (size_t i = 0; i < len - 1; i++)
        {
            int min = i;
            for (size_t j = i + 1; j < len; j++)
            {
                if (v[min] > v[j])
                {
                    min = j;
                }
            }
            std::swap(v[i], v[min]);
        }

        for (auto &x : v)
        {
            std::cout << x << ",";
        }
        std::cout << std::endl;
    };
    select_sort();

    auto insert_sort = [=]() mutable
    {
        for (size_t i = 1; i < len; i++)
        {
            for (size_t j = i; j > 0; j--)
            {
                if (v[j] < v[j - 1])
                {
                    std::swap(v[j], v[j - 1]);
                }
                else
                {
                    break;
                }

                /* code */
            }
        }

        for (auto &x : v)
        {
            std::cout << x << ",";
        }
        std::cout << std::endl;
    };
    insert_sort();
}