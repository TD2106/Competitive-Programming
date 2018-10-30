/* 
 * File:   SODU.cpp
 * Author: LongPham
 *
 * Created on November 6, 2012, 11:40 PM
 */

#include <iostream>
#include <fstream>
#include <cmath>
#define E 1000000
using namespace std;
//------------------------------------------------------------------------------
long long bigMod(long long, long long, long long);
long long muliply10(long long, long long, long long);
//------------------------------------------------------------------------------

int main(int argc, char** argv) {
    ifstream in("SODU.INP");
    ofstream out("SODU.OUT");

    long long B, P, M, R;

    in >> B >> P >> M;
    R = bigMod(B, P, M);

    out << R << endl;
    in.close();
    out.close();
    return 0;
}

//------------------------------------------------------------------------------

long long bigMod(long long B, long long P, long long M) {
    if (P == 0) {
        return 1;
    } else if (P % 2 == 0) {
        long long a, b, t1;
        t1 = bigMod(B, P / 2, M);

        a = t1 / E;
        b = t1 % E;
        return (muliply10(a * a, 12, M) + 2 * muliply10(a * b, 6, M) + ((b * b) % M)) % M;
    } else {
        long long c, d, e, f, t2;
        t2 = (bigMod(B, P - 1, M) % M);

        c = (B % M) / E;
        d = (B % M) % E;
        e = t2 / E;
        f = t2 % E;
        return (muliply10(c * e, 12, M) + muliply10((c * f) + (d * e), 6, M) + ((d * f) % M)) % M;
    }
}

//------------------------------------------------------------------------------

long long muliply10(long long b, long long n, long long m) {
    for (int i = 0; i < n; i++) {
        b = (b * 10) % m;
    }
    return b;
}