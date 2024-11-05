/// uniqe_element_array///

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> countMap;
    for (int num : arr) {
        countMap[num]++;
    }

    cout << "Unique numbers are:\n";
    for (const auto& pair : countMap) {
        if (pair.second == 1) {
            cout << pair.first << " ";
        }
    }
    cout << endl;

    return 0;
}

///triangle_star_pattern//

#include <iostream>
using namespace std;

void printRightTriangle(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    printRightTriangle(rows);

    return 0;
}


///sub_array_largest_sum///

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], currentSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    return 0;
}

///string_pallindrome///

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++; right--;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s) << endl;
    return 0;
}

///squre_free_number///

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool checkSqrt(int n) {
    int sqrt_n = sqrt(n);
    return (sqrt_n * sqrt_n == n);
}

int squareFreeNum(const vector<int>& factor) {
    int count = 0;
    for (int i = 0; i < factor.size(); i++) {
        if (checkSqrt(factor[i])) continue;  // Skip the factor if it's a perfect square

        bool hasSquareDivisor = false;
        for (int j = 2; j <= sqrt(factor[i]); j++) {
            if (factor[i] % (j * j) == 0) {
                hasSquareDivisor = true;
                break;
            }
        }

        if (!hasSquareDivisor) count++;
    }
    return count;
}

vector<int> factors(int n) {
    vector<int> fact;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            fact.push_back(i);
        }
    }
    return fact;
}

int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n;
    vector<int> factor = factors(n);

    int ans = squareFreeNum(factor);
    cout << "ans : " << ans << endl;

    for (int i : factor) {
        cout << i << " ";
    }
    return 0;
}

///reversed array///

#include <iostream>
using namespace std;

int main() {
    int numbers[7];
    cout << "Enter 7 integers:\n";
    for (int i = 0; i < 7; i++) {
        cin >> numbers[i];
    }

    for (int i = 6; i >= 0; i--) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    return 0;
}

///patter_num3///

 #include <iostream>
using namespace std;

void printPattern(int rows) {
    for (int i = 1; i <= rows; ++i) {
        for (int j = i; j <= rows; ++j) {
            cout << j;
        }
        for (int j = rows - i + 1; j < rows; ++j) {
            cout << rows;
        }
        cout << endl;
    }
}

int main() {
    int rows;
    cin >> rows;
    printPattern(rows);
    return 0;
}

///pattern_num1///

#include <iostream>
using namespace std;

void printPattern(int rows, int columns) {
    for (int i = 1; i <= rows; ++i) {
        if (i % 2 != 0) {
            for (int j = 1; j <= columns; ++j) {
                cout << j;
            }
        } else {
            for (int j = columns; j >= 1; --j) {
                cout << j;
            }
        }
        cout << endl;
    }
}

int main() {
    int rows, columns;
    cin >> rows >> columns;
    printPattern(rows, columns);
    return 0;
}

///pattern_num2///

#include <iostream>
using namespace std;

void printPattern(int rows, int columns) {
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= columns; ++j) {
            if (i == 1 || i == rows || j == 1 || j == columns) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }
}

int main() {
    int rows, columns;
    cin >> rows >> columns;
    printPattern(rows, columns);
    return 0;
}

///palindrom_star_pattern///

#include <iostream>
using namespace std;

void printParallelogram(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < cols; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    printParallelogram(rows, cols);

    return 0;
}