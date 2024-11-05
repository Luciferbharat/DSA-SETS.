///palindrome_array///

#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    cout << "Enter 5 integers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    bool isPalindrome = true;
    for (int i = 0; i < 2; i++) {
        if (numbers[i] != numbers[4 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "The array is in palindrome order." << endl;
    } else {
        cout << "The array is not in palindrome order." << endl;
    }
    
    return 0;
}

///negative//

#include <iostream>
using namespace std;

int main() {
    int size;

    // Get the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];

    // Input elements into the array
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Count negative numbers
    int negativeCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            negativeCount++;
        }
    }

    // Output the result
    cout << "Total number of negative numbers: " << negativeCount << endl;

    return 0;
}

///merge_sorted_array//

#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    
    cout << "Enter size of second array: ";
    cin >> n2;
    int arr2[n2];
    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    
    int merged[n1 + n2];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        merged[k++] = arr1[i++];
    }
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
    
    cout << "Merged array:\n";
    for (int i = 0; i < n1 + n2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    return 0;
}

///maximum_stock_price///

#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}

///max_sum_k_consticative////

#include <iostream>
#include <vector>
using namespace std;

int maxSumKConsecutive(vector<int>& arr, int k) {
    if (arr.size() < k) return -1;
    int maxSum = 0, currentSum = 0;
    for (int i = 0; i < k; i++) currentSum += arr[i];
    maxSum = currentSum;
    for (int i = k; i < arr.size(); i++) {
        currentSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    cout << maxSumKConsecutive(arr, k) << endl;
    return 0;
}

///max_subarray_sum///

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> maxLenSubarray(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    int sum = 0, maxLength = 0, start = -1, end = -1;
    map[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (map.find(sum - target) != map.end() && i - map[sum - target] > maxLength) {
            start = map[sum - target] + 1;
            end = i;
            maxLength = i - map[sum - target];
        }
        if (map.find(sum) == map.end()) map[sum] = i;
    }
    return {nums.begin() + start, nums.begin() + end + 1};
}

int main() {
    vector<int> nums = {5, 6, -5, 5, 3, 5, 3, -2, 0};
    int target = 8;
    vector<int> result = maxLenSubarray(nums, target);
    for (int num : result) cout << num << " ";
    cout << endl;
    return 0;
}

///max_element_in_subarray///

#include<iostream>
#include<climits>
using namespace std;

void maxElSubArray(int arr[],int len,int k){
    for(int i=0; i<=len-k; i++){
        int max = INT_MIN;
        for(int j=i; j<i+k; j++){
            if(max<arr[j]) max = arr[j];
        }
        cout<<max<<" ";
    }
}   
int main(){
    int arr[] = {8,5,10,7,9,4,15,12,90,13};
    int k,len;
    len = sizeof(arr)/sizeof(int);
    cout<<"Enter the value of k : ";
    cin>>k;

    if (k > len || k <= 0) {
        cout << "Invalid value of k." << endl;
        return 1;
    }
    // cout<<*max_element(arr,arr+len);
    maxElSubArray(arr,len,k);    
    return 0;
}

////kth_largest_element///

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}

///half_diamond_pattern///

#include <iostream>
using namespace std;

void printHalfDiamond(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int columns;
    cin >> columns;
    printHalfDiamond(columns);
    return 0;
}

///frequency_of_element///

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

    cout << "Frequency of each number:\n";
    for (const auto& pair : frequencyMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}