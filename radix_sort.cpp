///////////////////////////////////////////////////////////////////////////////
// Author: Mika Chang
// Email: mikacchang@gmail.com
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

/**
 * Sort a vector of integers using a base 10 counting sort algorithm
 * 
 * @param nums vector of ints to be sorted
 * @param digit indicates which digit to sort by with 0 (the default)
 * indicating the least significant digit 10 ^ 0, 1 indicating 10 ^ 1
 * and so on 
 * 
 * @return sorted_nums the numbers sorted in ascending order
 */
std::vector<int> counting_sort(std::vector<int>& nums, int digit = 0) {
	std::vector<int> digit_counts(10);
	int divisor = 1;
	for (int i = 0; i < digit; i++) {
		divisor *= 10;
	}
	// Count the number each value [0-9] for the given decimal place
	for (unsigned int i = 0; i < nums.size(); i++) {
		digit_counts[(nums[i] / divisor) % 10]++;
	}

	// Create a vector with the last position of each digit in the sorted
	// list 
	std::vector<int> endpoints(10);
	int curr_endpoint = 0;
	for (unsigned int i = 0; i < digit_counts.size(); i++) {
		curr_endpoint += digit_counts[i];
		endpoints[i] = curr_endpoint;
	}

	// Put each value in the list in its correct position
	std::vector<int> sorted_nums(nums.size());
	for (int i = nums.size() - 1; i >= 0; i--) {
		sorted_nums[endpoints[(nums[i] / divisor) % 10]-- - 1] = nums[i];
	}	
	return sorted_nums;
}

std::vector<int> radix_sort(std::vector<int>& nums) {
	// Do a linear scan to determine the maximum magnitude in the list
	int max_magnitude = 0;
	for (int num : nums) {
		int magnitude = 0;
		while (num >= 10) {
			num = num / 10;
			magnitude++;
		}
		max_magnitude = max_magnitude > magnitude ? max_magnitude : magnitude;
	}
	for (int i = 0; i <= max_magnitude; i++) {
		nums = counting_sort(nums, i);
	}
	return nums;
}	

int main() {
	std::vector<int> nums = {2, 41, 1, 90, 30, 3, 1, 7};
//	std::vector<int> nums = {8, 8, 9 , 0 , 1 , 3, 9, 0, 3, 5, 3};
	std::vector<int> counts = radix_sort(nums);
	for (int count : counts) {
		std::cout<<count<<" ";
	}
	std::cout<<"\n";
}

