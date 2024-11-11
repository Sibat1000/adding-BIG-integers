
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string a, string b) {
    if (a.length() < b.length()) 
        swap(a, b);
    
    int carry = 0;
    int n1 = a.length(), n2 = b.length();
    string result = "";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n2; i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n2; i < n1; i++) {
        int sum = (a[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    cout << "Sum: " << add(a, b) << endl;

    return 0;
}
