///equilibirium_index///

#include <iostream>
#include <vector>
using namespace std;

int equilibriumIndex(vector<int>& arr) {
    int totalSum = 0, leftSum = 0;
    for (int num : arr) totalSum += num;
    for (int i = 0; i < arr.size(); i++) {
        totalSum -= arr[i];
        if (leftSum == totalSum) return i + 1;
        leftSum += arr[i];
    }
    return -1;
}

int main() {
    vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};
    cout << equilibriumIndex(arr) << endl;
    return 0;
}

///duplicate_element///

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

    unordered_map<int, int> frequencyMap;
    for (int num : arr) {
        frequencyMap[num]++;
    }

    int duplicateCount = 0;
    for (const auto& pair : frequencyMap) {
        if (pair.second > 1) {
            duplicateCount++;
        }
    }

    cout << "Total number of duplicate numbers: " << duplicateCount << endl;

    return 0;
}

///diamond_pattern////

#include <iostream>
using namespace std;

bool printDiamond(int rows) {
    if (rows % 2 == 0) {
        cout << "Error: Number of rows must be odd." << endl;
        return false;
    }

    int n = rows / 2;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return true;
}

int main() {
    int rows;
    cin >> rows;
    printDiamond(rows);
    return 0;
}

///count_inversion_array///

#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int i = 0; i < n2; i++) right[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l, swaps = 0;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            swaps += (n1 - i);
        }
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
    return swaps;
}

int mergeSortAndCount(vector<int>& arr, int l, int r) {
    int count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        count += mergeSortAndCount(arr, l, m);
        count += mergeSortAndCount(arr, m + 1, r);
        count += mergeAndCount(arr, l, m, r);
    }
    return count;
}

int main() {
    vector<int> arr = {7, 2, 6, 3};
    cout << mergeSortAndCount(arr, 0, arr.size() - 1) << endl;
    return 0;
}

///bracket_check///

#include<iostream>
#include<string>
using namespace std;

bool checkBracket(string s){
    int bracket = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') bracket++;
        else if(s[i] == ')') bracket--;

        if(bracket<0) return false;
    }
   return (bracket == 0);
}

int main(){
    string s = "(())";
    bool check = checkBracket(s);
    if(check) cout<<"True";
    else cout<<"False";
    return 0;
}

///all_bracket_check///

#include<iostream>
#include<string>
using namespace std;

bool checkBracket(string s){
    int b1=0, b2=0, b3=0;
    for(int i=0; i<s.size(); i++){
             if(s[i] == '(') b1++;
        else if(s[i] == ')') b1--;
        else if(s[i] == '{') b2++;
        else if(s[i] == '}') b2--;
        else if(s[i] == '[') b3++;
        else if(s[i] == ']') b3--;

        if(b1<0 ||b2<0 ||b3<0) return false;
    }
    return (b1 == 0 && b2 == 0 && b3 == 0);
}

int main(){
    string s = "{}{}";
    bool check = checkBracket(s);
    if(check) cout<<"True";
    else cout<<"False";
    return 0;
}

///two_pointer///

#include <iostream>
#include <vector>
using namespace std;

bool findPairTwoPointer(vector<int>& A, int X) {
    int left = 0, right = A.size() - 1;
    while (left < right) {
        int sum = A[left] + A[right];
        if (sum == X) return true;
        if (sum < X) left++;
        else right--;
    }
    return false;
}

int main() {
    vector<int> A = {1, 2, 4, 5, 7, 11};
    int X = 9;
    cout << (findPairTwoPointer(A, X) ? "Yes" : "No") << endl;
    return 0;
}

///max_number///

#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }
    int maxNum = numbers[0];
    for (int i = 1; i < 5; i++) {
        if (numbers[i] > maxNum) {
            maxNum = numbers[i];
        }
    }
    cout << "Maximum number: " << maxNum << endl;
    return 0;
}


///linear_search////

#include <iostream>
using namespace std;

int main() {
    int size, target, index = -1;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number to search for: ";
    cin >> target;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "First occurrence of " << target << " is at index: " << index << endl;
    } else {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}