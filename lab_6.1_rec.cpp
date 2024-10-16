#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) 
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(const int* a, const int size, int i) 
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

void ProcessArray(int* a, const int size, int& count, int& sum, int i) 
{
    if (a[i] % 2 != 0 && a[i] % 3 == 0) {
        sum += a[i];
        count++;
        a[i] = 0;
    }
    if (i < size - 1)
        ProcessArray(a, size, count, sum, i + 1);
}

int main() {
    srand((unsigned)time(0));

    const int n = 21;
    int b[n];

    int Low = 10, High = 90;

    Create(b, n, Low, High, 0);
    cout << "Initial array: " << endl;
    Print(b, n, 0);

    int count = 0, sum = 0;
    ProcessArray(b, n, count, sum, 0);

    cout << "Number of elements that meet the criteria: " << count << endl;
    cout << "Sum of those elements: " << sum << endl;
    cout << "Modified array: " << endl;
    Print(b, n, 0);

    return 0;
}
