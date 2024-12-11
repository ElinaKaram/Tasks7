#include <iostream>
#include <vector>
using namespace std;

// 1 задача
int sumOfDigits(const vector<int>& arr)
{
    int totalSum = 0;
    for (int num : arr)
    {
        int absNum = abs(num);
        while (absNum > 0) 
        {
            totalSum += absNum % 10;
            absNum /= 10;
        }
    }
    return totalSum;
}

// 2 задача
double averageOfPositive(const vector<int>& arr)
{
    int sum = 0, count = 0;
    for (int num : arr)
    {
        if (num > 0)
        {
            sum += num;
            count++;
        }
    }
    return count > 0 ? static_cast<double>(sum) / count : 0.0;
}

// 3 задача
pair<int, int> maxNegative(const vector<int>& arr)
{
    int maxNeg = INT_MIN, index = -1;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] < 0 && arr[i] > maxNeg)
        {
            maxNeg = arr[i];
            index = i;
        }
    }
    return { maxNeg, index };
}

// 4 задача
int mostFrequent(const vector<int>& arr) 
{
    vector<int> freq(arr.size(), 0);
    int maxCount = 0, result = arr[0];
    for (int i = 0; i < arr.size(); ++i)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); ++j)
        {
            if (arr[i] == arr[j]) count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            result = arr[i];
        }
    }
    return result;
}

// 5 задача
int maxOddIndexDivisibleByThree(const vector<int>& arr)
{
    int maxVal = INT_MIN;
    for (int i = 1; i < arr.size(); i += 2)
    {
        if (arr[i] % 3 == 0 && arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal == INT_MIN ? -1 : maxVal;
}

// 6 задача
void swapMaxEvenAndMinOdd(vector<int>& arr)
{
    int maxEven = INT_MIN, minOdd = INT_MAX, maxEvenIndex = -1, minOddIndex = -1;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] % 2 == 0 && arr[i] > maxEven)
        {
            maxEven = arr[i];
            maxEvenIndex = i;
        }
        if (arr[i] % 2 != 0 && arr[i] < minOdd)
        {
            minOdd = arr[i];
            minOddIndex = i;
        }
    }

    if (maxEvenIndex != -1 && minOddIndex != -1)
    {
        swap(arr[maxEvenIndex], arr[minOddIndex]);
    }

    else
    {
        for (int& num : arr)
        {
            num = 0;
        }
    }
}

// 7 задача a б
vector<int> commonElements(const vector<int>& arr1, const vector<int>& arr2)
{
    vector<int> result;
    for (int num1 : arr1)
    {
        for (int num2 : arr2) 
        {
            if (num1 == num2) 
            {
                result.push_back(num1);
                break;
            }
        }
    }
    return result;
}

vector<int> uniqueElements(const vector<int>& arr1, const vector<int>& arr2) 
{
    vector<int> result;
    for (int num1 : arr1)
    {
        bool isUnique = true;
        for (int num2 : arr2) 
        {
            if (num1 == num2)
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique) result.push_back(num1);
    }

    for (int num2 : arr2)
    {
        bool isUnique = true;
        for (int num1 : arr1)
        {
            if (num2 == num1)
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique) result.push_back(num2);
    }
    return result;
}

/*
int main() {
    vector<int> arr = { 12, -104, 81, 0, -15 };
    vector<int> arr2 = { 81, -15, 50, 100 };

    cout << "1. Сумма цифр массива: " << sumOfDigits(arr) << endl;
    cout << "2. Среднее положительных: " << averageOfPositive(arr) << endl;

    auto [maxNeg, index] = maxNegative(arr);
    cout << "3. Максимальный отрицательный: " << maxNeg << " на позиции " << index << endl;

    cout << "4. Число, чаще всего встречающееся: " << mostFrequent(arr) << endl;

    cout << "5. Наибольший элемент с нечетным индексом, делится на 3: "
        << maxOddIndexDivisibleByThree(arr) << endl;
    swapMaxEvenAndMinOdd(arr);
    cout << "6. Массив после замены: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    vector<int> common = commonElements(arr, arr2);
    cout << "7a. Общие элементы: ";
    for (int num : common) cout << num << " ";
    cout << endl;

    vector<int> unique = uniqueElements(arr, arr2);
    cout << "7b. Уникальные элементы: ";
    for (int num : unique) cout << num << " ";
    cout << endl;

    return 0;
}
*/