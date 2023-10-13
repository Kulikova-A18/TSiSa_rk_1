#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <locale>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#define E 0.1

#define CONST_A -2
#define CONST_B 4

#define UNIMODAL_FUNCTION(x)\
    ((double)-cos(0.5 * x) - 1)
    
#define MULTIMODAL_FUNCTION(x)\
    ((double)UNIMODAL_FUNCTION(x) * (sin(5 * x)))
