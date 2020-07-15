#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array)
{
    // Write your code here.
    vector<int> result = {INT_MIN, INT_MIN, INT_MIN};
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] > result[0])
        {
            int index = 0;
            result[index] = array[i];
            while (result[index] > result[index + 1] && index < 2)
            {
                int temp = result[index];
                result[index] = result[index + 1];
                result[index + 1] = temp;
                index++;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> my_array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    for (int num : findThreeLargestNumbers(my_array))
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}