#include <iostream>
#include <string.h>

#include "poly_diff.hpp"

using namespace std;

int main(void) {
    string data;
    PolyDiff poly_;
    int x;
    
    while(true) {
        cin >> data;
        if (data == "quit") {
            break;
        } else {
            poly_.SetVariables(data);
            cin >> x;
            poly_.GetDiff(x);
        }
    }
    return 0;
}
