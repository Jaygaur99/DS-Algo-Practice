#include<bits/stdc++.h>
using namespace std;

// // Recursion
// int num_codes(int n[], int size) {
// 	if (size == 1 or size == 0) {
// 		return 1;
// 	}

// 	int output = num_codes(n, size - 1);
// 	if (output[size - 2] * 10 + output[size - 1] <= 26)
// 		output += num_codes(n, size - 2);
// 	return output;
// }


// // TopDown
// int num_codes_2(int n[], int size, int arr[]) {
// 	if (size == 1 or size == 0) {
// 		return 1;
// 	}
// 	if (arr[size] > 0) {
// 		return arr[size];
// 	}
// 	int output = num_codes(n, size - 1);
// 	if (output[size - 2] * 10 + output[size - 1] <= 26)
// 		output += num_codes(n, size - 2);
// 	arr[size] = output;
// 	return output;
// }

int num_codes_i(int *input, int size) {
	int *output = new int[size + 1];
	output[0] = 1;
	output[1] = 1;

	for (int i = 2; i <= size; i++) {
		output[i] = output[i - 1];
		if (input[i - 2] * 10 + input[i - 1] <= 26) {
			output[i] += output[i - 2];
		}
	}
	int ans = output[size];
	delete [] output;
	return ans;
}

int main() {
	int arr[] = {1, 2};
	cout <<	num_codes_i(arr, 2);
}
