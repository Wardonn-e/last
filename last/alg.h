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
#include<iostream>
#include<random>
#include<fstream>
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

    ostream& operator<<(ostream& stream, stats val) {
        stream << val.comparison_count << " " << val.copy_count << endl;
        return stream;
    }
    template<typename T>
    fstream& operator<<(fstream& stream, vector<T> val) {
        for (int i = 0; i < val.size(); i++) {
            stream << val[i];
        }
        return stream;
    }
    template<typename T>
    ostream& operator<<(ostream& stream, vector<T> val) {
        for (int i = 0; i < val.size(); i++) {
            stream << setw(3) << val[i] << " ";
        }
        return stream;
    }
    template<typename T>
    stats sort(vector<T>& mass, stats func(vector<T>&)) {
        return func(mass);
    }
    stats average(vector<stats> mass) {
        stats stat;
        for (int i = 0; i < mass.size(); i++) {
            stat.comparison_count += mass[i].comparison_count;
            stat.copy_count += mass[i].copy_count;
        }
        stat.comparison_count /= mass.size();
        stat.copy_count /= mass.size();
        return stat;
    }
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
    template<typename T>
    stats shaker_sort(vector<T>& mass) {
        stats cur_stat;
        int control = static_cast<int>(mass.size() - 1);
        int left = 0, right = control;
        do {
            for (int i = left; i < right; i++) {
                cur_stat.comparison_count++;
                if (mass[i] > mass[i + 1]) {
                    cur_stat.copy_count++;
                    std::swap(mass[i], mass[i + 1]);
                    control = i;
                }
            }
            right = control;
            for (int i = right; i > left; i--) {
                cur_stat.comparison_count++;
                if (mass[i] < mass[i - 1]) {
                    cur_stat.copy_count++;
                    std::swap(mass[i], mass[i - 1]);
                    control = i;
                }
            }
            left = control;
        } while (left < right);
        return cur_stat;
    }
}

#endif /* alg_h */
