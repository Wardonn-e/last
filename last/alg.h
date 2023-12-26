//
//  alg.h
//  AISD_3LAB
//
//  Created by Роман Казаев on 26.12.2023.
//

#ifndef alg_h
#define alg_h

#pragma once
#include<vector>
#include<random>
using namespace std;

namespace algorithm {

    int generate_random_number(int min, int max, int seed) {
        mt19937 mt(seed);
        uniform_int_distribution<int> distribution(min, max);
        return distribution(mt);
    }
    struct stats {
        size_t comparison_count = 0;
        size_t copy_count = 0;
    };

    template<typename T>
    stats bubble_sort(vector<T>& mass) {
        int temp;
        stats cur_stat;
        for (int i = 0; i < mass.size() - 1; i++) {
            for (int j = 0; j < mass.size() - i - 1; j++) {
                cur_stat.comparison_count++;
                if (mass[j] > mass[j + 1]) {
                    cur_stat.copy_count++;
                    temp = mass[j];
                    mass[j] = mass[j + 1];
                    mass[j + 1] = temp;
                }
            }
        }
        return cur_stat;
    }
    template<typename T>
    stats comb_sort(vector<T>& mass) {
        stats cur_stat;
        double factor = 1.2473309;
        int step = mass.size() - 1;
        while (step >= 1)
        {
            for (int i = 0; i + step < mass.size(); i++)
            {
                cur_stat.comparison_count++;
                if (mass[i] > mass[i + step])
                {
                    cur_stat.copy_count++;
                    std::swap(mass[i], mass[i + step]);
                }
            }
            step /= factor;
        }
        return cur_stat;
    }
}

#endif /* alg_h */
