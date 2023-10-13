#include "func.h"

/**
* @brief optimal_passive_search
* optimal passive search
*
* @return null
*/
void optimal_passive_search() {
    double a = CONST_A, b = CONST_B;
    double x1 = a, x2 = b;
    cout <<"*** Optimal passive search: ***\n\n";
    a = 1.5;
    b = 4;
    int N = 1;
    cout << "Number of\t\tValue of x" <<endl;
    cout << "points(N)\t\tin the min" <<endl;
    cout <<setfill('-') <<setw(50) <<"-" <<endl;

    while ((b - a) / N > E){
        cout << N ;
        double a1 = a, b1 = b;
        double d = (b1 - a1) / (N + 1);
        while (b1 - a1 > 2 * d){
            x1 = a1 + d;
            x2 = b1 - d;
            if ((double)UNIMODAL_FUNCTION(x1) <= (double)UNIMODAL_FUNCTION(x2)) {
                b1 = x2;
            } else a1 = x1;
        } cout << "\t\t"
              << (b1 + a1)/2
              << " +- "
              << d  << endl;
        N++;
    }
}

const double _GOLDEN_RATIO = (1 + sqrt(5)) / 2;

/**
* @brief optimal_passive_search
* optimal passive search
*
* @return null
*/
void golden_ratio_metod() {
    double a = CONST_A, b = CONST_B;
    double x1 = a, x2 = b;
    cout <<"*** The golden ratio method ***\n\n";
    cout <<"Start of the\tEnd of the\tLength of" <<endl;
    cout <<"interval\t\tinterval\t\tthe interval\t\tf(ak)\t\tf(bk)" <<endl;
    cout <<"(ak)\t\t(bk)\t\t(l)                                 " <<endl;
    cout <<setfill('-') <<setw(120) <<"-" <<endl;
    while (fabs(b - a) > E) {
        cout
            << a << "\t\t"
            << b  << "\t\t"
            << abs(b-a)  << "\t\t"
            << (double)UNIMODAL_FUNCTION(a)  << "\t\t"
            << (double)UNIMODAL_FUNCTION(b)  << endl;

        x1 = b - (b - a) / _GOLDEN_RATIO;
        x2 = a + (b - a) / _GOLDEN_RATIO;

        if ((double)UNIMODAL_FUNCTION(x1) <= (double)UNIMODAL_FUNCTION(x2) )
            b = x2;
        else a = x1;
    }

    cout
        << a  << "\t\t"
        << b  << "\t\t"
        << abs(b-a);

    if (b-a < E)
        cout <<"\t\tl < epsilon" <<endl;

    cout <<"\nMinimum x = "  <<fixed <<setprecision(3) << (a + b) / 2 <<" +- " <<(b-a)/2 <<endl;
    cout <<endl <<endl;
}

// ////////////////////////// fibonacci ........ ///////////////////
int fibonacci_num(int n) {
    return (n == 1 || n == 2) ? 1 : fibonacci_num(n - 1) + fibonacci_num(n -2);
}

void print_point_fibonacci_metod(int N, double result_x, double interval) {
    std::cout << "Number of points: " << N
              << "\t\tx = " << std::fixed << std::setprecision(6) << result_x
              << "\t\tIndefinite interval: " << std::fixed << std::setprecision(6) << interval
              << "\t\tF(x):= " << std::fixed << std::setprecision(6) << (double)UNIMODAL_FUNCTION(result_x) << '\n';
}

//void PrintPointForReport(double a, double b, double l) {
//    std::cout<< a << " | " << b << " | " << l << " | " << (double)UNIMODAL_FUNCTION(a) << " | " << (double)UNIMODAL_FUNCTION(b) << '\n';
//}
void print_result_fibonacci_metod(int N, double result_x, double interval){
    std::cout << "Result:\nx = " << std::fixed << std::setprecision(6) << result_x
              << "\t\tIndefinite interval: " << std::fixed << std::setprecision(6) << interval
              << "\t\tF(x) = " << std::fixed << std::setprecision(6) << (double)UNIMODAL_FUNCTION(result_x)
              << "\nNumber of points: " << N;
}

/**
* @brief fibonacci_metod
*
* @return null
*/
void fibonacci_metod(double begin, double end, double epsilon) {
    std::cout<<"\n\n\n\tFibonacci metod:\n\n";
    double begin_new, end_new, x1, x2, function_in_x1, function_in_x2;
    int N = 3;
    bool done = false;
    while(!done) {
        begin_new = begin;
        end_new = end;
        x1 = begin_new + (double)fibonacci_num(N- 2)/ fibonacci_num(N) *(end_new - begin_new);
        x2 = end_new - (double)fibonacci_num(N- 2)/ fibonacci_num(N) *(end_new - begin_new);

        function_in_x1 = (double)UNIMODAL_FUNCTION(x1);
        function_in_x2 = (double)UNIMODAL_FUNCTION(x2);

        for (int i = 0; i < N - 2 ; i++) {
            if (function_in_x1 > function_in_x2) {
                begin_new = x1;
                x1 = x2;
                function_in_x1 = function_in_x2;
                x2 = end_new - (double)fibonacci_num(N - i - 2) / fibonacci_num(N - i) * (end_new - begin_new) ;
                function_in_x2 = (double)UNIMODAL_FUNCTION(x2);
            }
            else if(function_in_x1 < function_in_x2) {
                end_new = x2;
                x2 = x1;
                function_in_x2 = function_in_x1;
                x1 = begin_new + (double) fibonacci_num(N - i - 2) / fibonacci_num(N - i) * (end_new - begin_new);
                function_in_x1 = (double)UNIMODAL_FUNCTION(x1);
            }
            if (fabs(end_new - begin_new)  <= epsilon) {
                done = true;
                break;
            }
        }
        print_point_fibonacci_metod(N - 2, (begin_new + end_new) / 2,fabs(end_new - begin_new) );
        //PrintPointForReport(begin_new, end_new, fabs(end_new - begin_new));
        N++;
    }
    print_result_fibonacci_metod(N - 3, (begin_new + end_new) / 2,fabs(end_new - begin_new) / 2 );
}

/**
* @brief dihotomiya_metod
* dihotomiya metod
*
* @return null
*/
void dihotomiya_metod() {
    const float eps = E;
    double b = CONST_B;
    double a = CONST_A;
    unsigned int N = 1;
//    double Xi;
    double s;
//    double min;
    std::map<double, double> values;

    const float delta = 0.01;
    double Xleft, Xright;
    std::cout << "\ndihotomiya\n";
    std::cout << "a=" << a << "\t\tb=" << b << "\t\tb-a=" << (b - a) << " "<< (double)UNIMODAL_FUNCTION(a) << " " << (double)UNIMODAL_FUNCTION(b) << "\n";
    double a1, b1;
    do {
        Xleft = 0.5 * (b + a) - delta;
        Xright = 0.5 * (b + a) + delta;
        values.insert(std::make_pair((double)UNIMODAL_FUNCTION(Xleft), Xleft));
        values.insert(std::make_pair((double)UNIMODAL_FUNCTION(Xright), Xright));
        std::map<double, double> ::iterator it = values.begin();
        a1 = it->second;
        ++it;
        b1 = it->second;
        if (a1 > b1)
            a = a1;
        else
            b = b1;
        --it;
        std::cout << "a=" << a << "\t\tb=" << b << "\t\tb-a=" << (b - a)
            << "\nf(Xleft)=" << it->first;
        ++it;
        s = 0.5 * (b - a);
        std::cout << "\t\tf(Xright)=" << it->first << "\nmin:"
            << (a + b) / 2 << " +- " << s << "\n";
        values.clear();
    } while ((b - a) > eps);
}
