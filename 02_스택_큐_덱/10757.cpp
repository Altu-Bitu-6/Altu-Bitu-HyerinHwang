#include <iostream>
#include <algorithm> // reverse
using namespace std;

string addStrings(const string& a, const string& b) {
    string result = "";
    int carry = 0;

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result += to_string(sum % 10);
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << addStrings(a, b) << endl;

    return 0;
}
