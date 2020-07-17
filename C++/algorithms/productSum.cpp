#include <any>
#include <iostream>
#include <vector>

// A special array is a non-empty array that contains either ints or special arrays.
// The product sum is the sum of its elements multiplied by their depth
// [x, y] = x + y [x,[y,z]] = x + 2 *(y + zi)

int productSum(std::vector<std::any> array, int level = 1)
{
    int sum = 0;
    for (int i = 0; i < array.size(); i++)
    {
        // el.type() == typeid(vector<any>) check whether an item is list or an integer.
        if (array[i].type() == typeid(std::vector<std::any>))
        {
            sum += productSum(std::any_cast<std::vector<std::any>>(array[i]), level + 1);
        }
        else
        {
            sum += std::any_cast<int>(array[i]);
        }
    }
    return sum * level;
}

int main()
{
    std::vector<std::any> test = {5, 2, std::vector<std::any>{7, -1}, 3, std::vector<std::any>{6, std::vector<std::any>{-13, 8}, 4}};
    std::cout << productSum(test) << std::endl;
    return 0;
}
