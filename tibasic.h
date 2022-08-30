//
//  macros.h
//  triangle
//
//  Created by Dave DeLong on 8/30/22.
//

#ifndef macros_h
#define macros_h

#import <stdio.h>
#import <math.h>
#import <assert.h>
#import "metamacros.h"

#define Pause { \
    char c = 0; \
    while (1) { c = fgetc(stdin); if (c == EOF || c == '\n') { break; } } \
}

double _readDouble(void) {
    double d = 0;
    fscanf(stdin, "%lf", &d);
    Pause // clear out stdin
    return d;
}

int _readInt(void) {
    int d = 0;
    fscanf(stdin, "%d", &d);
    Pause // clear out stdin
    return d;
}

int8_t _degrees = 1;
#define Degree _degrees = 1;
#define Radian _degrees = 0;
#define π M_PI

double A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, θ = 0;

#define ClrHome printf("\n\n\n\n\n\n\n\n");

#define Stop exit(0);


void print_int(int x) { printf("%d\n", x); }
void print_float(float x) { printf("%.5f\n", x); }
void print_char(char x) { printf("%c\n", x); }
void print_string(char *x) { printf("%s\n", x); }

#define _Disp(_i, X) \
    _Generic((X),\
        int: print_int, \
        float: print_float, \
        double: print_float, \
        char: print_char, \
        char *: print_string)(X);

#define Disp(...) metamacro_foreach(_Disp,,__VA_ARGS__)


#define Input(_v) printf(# _v ": "); _v = _readDouble();

void _CHECKVAL(double _v, double _min, double _max) {
    if (_v < _min || _v > _max) {
        printf("Bad value: %f. Should be %f ... %f\n", _v, _min, _max);
        exit(-1);
    }
}

#define _CHECKDEG(_v) _CHECKVAL(_v, 0, 360)
#define _CHECKRAD(_v) _CHECKVAL(_v, -2*π, 2*π)
#define _CHECK(_v) (_degrees ? _CHECKDEG(_v) : _CHECKRAD(_v))

double _DTOR(double d) {
    _CHECK(d);
    return d / 180.0 * M_PI;
}

double _RTOD(double r) {
    _CHECK(r);
    return r / M_PI * 180.0;
}

double COS(double _v) {
    _CHECK(_v);
    if (_degrees) { _v = _DTOR(_v); }
    return cos(_v);
}

double SIN(double _v) {
    _CHECK(_v);
    if (_degrees) { _v = _DTOR(_v); }
    return sin(_v);
}

double ACOS(double _v) {
    _CHECKVAL(_v, -1, 1);
    double d = acos(_v);
    if (_degrees) { d = _RTOD(d); }
    _CHECK(d);
    return d;
}

double ASIN(double _v) {
    _CHECKVAL(_v, -1, 1);
    double d = asin(_v);
    if (_degrees) { d = _RTOD(d); }
    _CHECK(d);
    return d;
}


#define Menu(_prompt, ...) \
    while (1) { \
        printf(_prompt "\n"); \
        metamacro_concat(_PrintMenu, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__) \
        int choice = _readInt(); \
        switch (choice) { \
            metamacro_concat(_CaseMenu, metamacro_argcount(__VA_ARGS__))(__VA_ARGS__) \
            default: printf("Unknown choice: %d\n\n", choice); break; \
        } \
    }

#define _PrintMenu2(...) printf("1: %s\n", metamacro_at(0, __VA_ARGS__));
#define _PrintMenu4(...) _PrintMenu2(__VA_ARGS__) \
    printf("2: %s\n", metamacro_at(2, __VA_ARGS__));
#define _PrintMenu6(...) _PrintMenu4(__VA_ARGS__) \
    printf("3: %s\n", metamacro_at(4, __VA_ARGS__));
#define _PrintMenu8(...) _PrintMenu6(__VA_ARGS__) \
    printf("4: %s\n", metamacro_at(6, __VA_ARGS__));
#define _PrintMenu10(...) _PrintMenu8(__VA_ARGS__) \
    printf("5: %s\n", metamacro_at(8, __VA_ARGS__));
#define _PrintMenu12(...) _PrintMenu10(__VA_ARGS__) \
    printf("6: %s\n", metamacro_at(10, __VA_ARGS__));
#define _PrintMenu14(...) _PrintMenu12(__VA_ARGS__) \
    printf("7: %s\n", metamacro_at(12, __VA_ARGS__));
#define _PrintMenu16(...) _PrintMenu14(__VA_ARGS__) \
    printf("8: %s\n", metamacro_at(14, __VA_ARGS__));
#define _PrintMenu18(...) _PrintMenu16(__VA_ARGS__) \
    printf("9: %s\n", metamacro_at(16, __VA_ARGS__));
#define _PrintMenu20(...) _PrintMenu18(__VA_ARGS__) \
    printf("10: %s\n", metamacro_at(18, __VA_ARGS__));

#define _CaseMenu2(...) case 1: goto metamacro_at(1, __VA_ARGS__);
#define _CaseMenu4(...) _CaseMenu2(__VA_ARGS__) \
    case 2: goto metamacro_at(3, __VA_ARGS__);
#define _CaseMenu6(...) _CaseMenu4(__VA_ARGS__) \
    case 3: goto metamacro_at(5, __VA_ARGS__);
#define _CaseMenu8(...) _CaseMenu6(__VA_ARGS__) \
    case 4: goto metamacro_at(7, __VA_ARGS__);
#define _CaseMenu10(...) _CaseMenu8(__VA_ARGS__) \
    case 5: goto metamacro_at(9, __VA_ARGS__);
#define _CaseMenu12(...) _CaseMenu10(__VA_ARGS__) \
    case 6: goto metamacro_at(11, __VA_ARGS__);
#define _CaseMenu14(...) _CaseMenu12(__VA_ARGS__) \
    case 7: goto metamacro_at(13, __VA_ARGS__);
#define _CaseMenu16(...) _CaseMenu14(__VA_ARGS__) \
    case 8: goto metamacro_at(15, __VA_ARGS__);
#define _CaseMenu18(...) _CaseMenu16(__VA_ARGS__) \
    case 9: goto metamacro_at(17, __VA_ARGS__);
#define _CaseMenu20(...) _CaseMenu18(__VA_ARGS__) \
    case 10: goto metamacro_at(19, __VA_ARGS__);


#endif /* macros_h */
