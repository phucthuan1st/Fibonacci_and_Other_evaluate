#include "utilities.h"

vector<int> uniqueValueList(int a[], int n, int &count_compare, int &count_assign)
{
    count_compare = 0;
    count_assign = 0;

    vector<int> result;

    for (int i = 0; ++count_compare && i < n; ++count_assign, i++)
    {
        bool isDup = false;
        count_assign++;

        // Kiểm tra xem trong danh sách unique value đã chứa a[i] hay chưa
        for (int j = 0; ++count_compare && j < result.size(); ++count_assign, j++)
        {
            if (++count_compare && a[i] == result[j])
            {
                isDup = true;
                ++count_assign;
                break;
            }
        }

        // Nếu a[i] chưa nằm trong danh sách thì thêm nó vào danh sách
        if (++count_compare && !isDup)
        {
            result.push_back(a[i]);
        }
    }

    return result;
}

int main()
{
    int N_size[] = {10, 100, 1000, 10000, 100000};

    srand(time(0));

    fstream fout("Unique_Value.csv", ios::out);
    fout << "n, Comparision, Assign" << endl;
    for (int i = 0; i < 5; i++)
    {
        int count_compare = 0;
        int count_assign = 0;
        cout << "With n = " << N_size[i] << ", unique values are: " << endl;
        int *a = generateA(N_size[i]);

        vector<int> unique_value_list = uniqueValueList(a, N_size[i], count_compare, count_assign);

        for (auto value : unique_value_list)
        {
            cout << value << " ";
        }

        cout << endl;
        cout << "Number of assign: " << count_assign << endl;
        cout << "Number of compare: " << count_compare << endl;
        cout << "--------------------" << endl;

        fout << N_size[i] << "," << count_compare << "," << count_assign << endl;
        delete[] a;
    }
    fout.close();
    return 0;
}