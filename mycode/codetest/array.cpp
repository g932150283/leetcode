#include <bits/stdc++.h>

using namespace std;

// int main(void)
// {
//     vector<int> array;
//     array.push_back(100);
//     array.push_back(300);
//     array.push_back(300);
//     array.push_back(500);
//     vector<int>::iterator iter;
//     for (iter = array.begin(); iter != array.end(); iter++)
//     {
//         if (*iter == 300)
//         {
//             iter = array.erase(iter);
//         }
//     }
//     for (iter = array.begin(); iter != array.end(); iter++)
//     {
//         cout << *iter << " ";
//     }
//     return 0;
// }

// int f(int &a, int &b) {
// a = 9;
// b = 5; return a + b;
// }
// int main() {
// int a = 2;
// int b = 7;
// int c = f(a, a);
// std::cout << a << b << c;
// }

size_t get_size_1(int *arr)
{
    return sizeof(arr);
}
size_t get_size_2(int arr[])
{
    return sizeof(arr);
}
size_t get_size_3(int (&arr)[10])
{
    return sizeof(arr);
}
int main()
{
    int array[10] = {0,0,0,0,0,0,0,0,0,0};
    cout << (sizeof(array) == get_size_1(array) ? 1 : 0);
    cout << (sizeof(array) == get_size_2(array) ? 1 : 0);
    cout << (sizeof(array) == get_size_3(array) ? 1 : 0);
}