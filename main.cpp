/**
 ******************************************************************************
 *
 *   Copyright (C) 2023, Kulikova Alyona, IU8-11M
 *
 ******************************************************************************
 *
 * @name RK 1
 *
 * @file main.cpp
 *
 * <b>Modification History</b>
 *
 *   Date        Name        Description
 *
 ******************************************************************************
 * encoding:   UTF-8 BOM
 * tab size:   4
 */

#include "func.h"

#ifdef RANDOM
/**
* @brief random_search_method_table1
* Number of iterations and Output values
*
* @param begin, end, P, q
*
* @return null
*/
void random_search_method_table1(double begin, double end, double P, double q);

/**
* @brief random_search_method_table2
* Number of iterations and Output 'N' values
*
* @param begin, end, P, q
*
* @return null
*/
void random_search_method_table2(double begin, double end, double P, double q);

/**
* @brief random_search_method_table3
* Number of iterations and Output 'N' values
*
* @param begin, end, P, q
*
* @return null
*/
void random_search_method_table3(double begin, double end, double P, double q);
#endif

#ifdef PASSIVE_SEARCH
/**
* @brief optimal_passive_search
* optimal passive search
*
* @return null
*/
void optimal_passive_search();
#endif

#ifdef DICHOTOMY
/**
* @brief dihotomiya_metod
* dihotomiya metod
*
* @return null
*/
void dihotomiya_metod();
#endif

#ifdef GOLDEN_RATIO
/**
* @brief optimal_passive_search
* optimal passive search
*
* @return null
*/
void golden_ratio_metod();
#endif

#ifdef FIBONACCI
/**
* @brief fibonacci_metod
*
* @return null
*/
void fibonacci_metod(double begin, double end, double epsilon);
#endif

int main()
{
#ifdef RANDOM
    /* We set the variables beginning and end of the segment, permissible error, vector of values
     * probabilities of missing each test 'q' and probabilities of finding
     * extremum for N iterations 'P' */

    std::vector<double> P, q;

    /* Let us polarize the vector of probabilities of getting into the vicinity of
     * the extremum in general */
    std::cout << "\n\nrandom_search_method_table1\n\n";
    std::string menu = "  q \\P    ";
    double tmp = 0.90;
    while(tmp < 1) {
        P.push_back(tmp);
        menu += std::to_string(tmp).substr(0, 4) + "\t";
        tmp += 0.01;
    }

    std::cout << menu << std::endl;

    /* Filling in the probability vector
     * getting into the vicinity
     * exteremum by a random point */
    tmp = 0.005;
    while(tmp < 0.101) {
        q.push_back(tmp);
        tmp += 0.005;
    }

    /* We calculate the results N for
     * P and q data */
    for(size_t i = 0; i < q.size(); ++i) {
        std::cout << std::fixed << std::setprecision(3) << std::right;
        std::cout << q[i];
        for(size_t j = 0; j < P.size(); ++j) {
            random_search_method_table1(CONST_A, CONST_B, P[j], q[i]);
        }
        std::cout << std::endl;
    }

    std::cout << "\n\nrandom_search_method_table2\n\n";
    std::cout << std::endl << menu << std::endl;

    /* We calculate the results of Ymin for
     * P and q data */

    for(size_t i = 0; i < q.size(); ++i) {
        std::cout << std::fixed << std::setprecision(3) << std::right;
        std::cout << q[i];
        for(size_t j = 0; j < P.size(); ++j) {
            random_search_method_table2(CONST_A, CONST_B, P[j], q[i]);
        }
        std::cout << std::endl;
    }

    std::cout << "\n\nrandom_search_method_table3\n\n";
    std::cout << std::endl << menu << std::endl;

    /* We calculate the results of Ymin for
     * P and q data in a multimodal function */

    for(size_t i = 0; i < q.size(); ++i) {
        std::cout << std::fixed << std::setprecision(3) << std::right;
        std::cout << q[i];
        for(size_t j = 0; j < P.size(); ++j) {
            random_search_method_table3(CONST_A, CONST_B, P[j], q[i]);
        }
        std::cout << std::endl;
    }
#endif

#ifdef PASSIVE_SEARCH
    optimal_passive_search();
#endif

#ifdef DICHOTOMY
    dihotomiya_metod();
#endif

#ifdef GOLDEN_RATIO
    golden_ratio_metod();
#endif

#ifdef FIBONACCI
    fibonacci_metod(CONST_A, CONST_B, E);
#endif

    cout << "\n";
    return 0;
}
