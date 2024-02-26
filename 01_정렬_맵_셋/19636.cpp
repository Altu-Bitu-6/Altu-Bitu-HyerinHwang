#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int w, basic, t, day, d_input, d_output;

    cin >> w >> basic >> t;
    cin >> day >> d_input >> d_output;

    int w1 = w;
    int w2 = w;
    int basic2 = basic;

    for (int i=0; i<day; i++){
        w1 += d_input - (basic + d_output);
        w2 += d_input - (basic2 + d_output);
        if (abs(d_input - (basic2 + d_output)) > t)
            basic2 += floor((d_input - (basic2+d_output))/2.0);
    }

    if (w1 <= 0)
        cout << "Danger Diet\n";
    else
        cout << w1 << " " << basic << "\n";

    if (w2 <= 0 || basic2 <= 0)
        cout << "Danger Diet\n";
    else{
        cout << w2 << " " << basic2 << " ";
        if (basic - basic2 > 0)
            cout << "YOYO";
        else
            cout << "NO";
    }
}