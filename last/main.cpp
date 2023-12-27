//
//  main.cpp
//  last
//
//  Created by Роман Казаев on 27.12.2023.
//

#include <iostream>
#include "alg.h"
using namespace algorithm;
int main(int argc, const char * argv[]) {
    int seed = 983747;
    const int limit = 100;  // adjust the size of the array as needed
    const int count = 1;   // adjust the number of tests as needed

    // Test with sorted input
    vector<algorithm::stats> bubble_sort_sorted_stats = algorithm::test_sort<int>(algorithm::bubble_sort, limit, count, 0, seed);
    algorithm::stats bubble_sort_sorted_avg_stats = algorithm::average(bubble_sort_sorted_stats);
    cout << "Bubble Sort (Sorted Input) Avg Stats: " << bubble_sort_sorted_avg_stats << endl;

    // Test with reverse-sorted input
    vector<algorithm::stats> comb_sort_reverse_sorted_stats = algorithm::test_sort<int>(algorithm::comb_sort, limit, count, 1, seed);
    algorithm::stats comb_sort_reverse_sorted_avg_stats = algorithm::average(comb_sort_reverse_sorted_stats);
    cout << "Comb Sort (Reverse Sorted Input) Avg Stats: " << comb_sort_reverse_sorted_avg_stats << endl;

    // Test with random input
    vector<algorithm::stats> shaker_sort_random_stats = algorithm::test_sort<int>(algorithm::shaker_sort, limit, count, 2, seed);
    algorithm::stats shaker_sort_random_avg_stats = algorithm::average(shaker_sort_random_stats);
    cout << "Shaker Sort (Random Input) Avg Stats: " << shaker_sort_random_avg_stats << endl;


//    fill_file(shaker_sort<int>, "/Users/wardonne/Documents/last/last/rand_data_shaker_sort.txt", 100, 2, seed);
//    fill_file(comb_sort<int>, "/Users/wardonne/Documents/last/last/rand_data_comb_sort.txt", 100, 2, seed);
//    fill_file(bubble_sort<int>, "/Users/wardonne/Documents/last/last/rand_data_bubble_sort.txt", 100, 2, seed);
//    fill_file(bubble_sort<int>, "/Users/wardonne/Documents/last/last/unsorted_bubble.txt", 1, 1, seed);
//    fill_file(shaker_sort<int>, "/Users/wardonne/Documents/last/last/unsorted_shaker.txt", 1, 1, seed);
//    fill_file(comb_sort<int>, "/Users/wardonne/Documents/last/last/unsorted_comb.txt", 1, 1, seed);
//    fill_file(bubble_sort<int>, "/Users/wardonne/Documents/last/last/sorted_bubble.txt", 1, 0, seed);
//    fill_file(shaker_sort<int>, "/Users/wardonne/Documents/last/last/sorted_shaker.txt", 1, 0, seed);
//    fill_file(comb_sort<int>, "/Users/wardonne/Documents/last/last/sorted_comb.txt", 1, 0, seed);

    return 0;
}
