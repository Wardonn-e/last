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
    void fill_file(stats func(vector<T>&), string path, int count, int sort_type, int seed) {
        fstream file;
        file.open(path, std::ios::app);
        vector<int> vals = { 1,2,3,4,5,6,7,8,9,10,25,50,100 };
        if (file) {
            for (int i = 0; i < vals.size(); i++) {
                /*cout << vals[i] * 1000 << endl;*/
                vector<stats> res = test_sort(func, vals[i] * 1000, count, sort_type, seed);
                file << vals[i] * 1000 << " ";
                file << average(res);
            }
        }
        else {
            cout << "ERROR";
        }
        file.close();
    }
    
    template<typename T>
    vector<stats> test_sort(stats func(vector<T>&), int limit, int count, int mass_type, int seed) {
        //0 - sort; 1 - unsorted; 2 - random
        vector<stats> results;
        int seed_helper = 0;
        for (int i = 0; i <= count - 1; i++) {
            vector<int> mass;
            switch (mass_type)
            {
            case 0:
                for (int j = 0; j < limit; j++) {
                    mass.push_back(j);
                }
                break;
            case 1:
                for (int j = 0; j < limit; j++) {
                    mass.push_back(limit - j);
                }
                break;
            case 2:
                for (int j = 0; j < limit; j++) {
                    mass.push_back(generate_random_number(1, 100, seed+seed_helper));
                    seed_helper++;
                }
                break;
            }

            cout << mass<< endl;
            results.push_back(func(mass));
        }
        return results;
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
        size_t step = mass.size() - 1;
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
