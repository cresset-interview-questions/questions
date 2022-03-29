#include <vector>
#include <iostream>

using namespace std;

vector<int> foo(vector<int> *values)
{
    vector<int> results;
    auto it = values->begin();
    while (it != values->end())
    {
        results.reserve(results.size() + 1);

        int sum = 0;

        for (int i = 0; i <= std::distance(values->begin(), it); i++)
        {
            sum = sum + values->at(i);
        }

        results.push_back(sum);
        it++;
    }
    return std::move(results);
}


int main(int argc, char* argv[])
{
    vector<int> values = {1, 6, 4, 9, -3, 13};
    vector<int> results = foo(&values);

    for (const auto& i: results)
        cout << i << " ";
    cout << endl;
    std::exit(0);
}
