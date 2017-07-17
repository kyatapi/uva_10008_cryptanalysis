#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cctype>

using namespace std;

int main(int argc, char **argv) {
    size_t line_count;
    cin >> line_count;
    cin.ignore(1, '\n');

    vector< tuple<char, size_t> > appear_times(26);
    for (char i = 0; i < 26; ++i) {
        get<0>(appear_times[i]) = i + 'A';
        get<1>(appear_times[i]) = 0;
    }

    for (size_t l = 0; l < line_count; ++l) {
        char token = '\0';
        while (cin.get(token) && token != '\n') {
            if (!isalpha(token)) continue;

            if (islower(token))  token = toupper(token);
            get<1>(appear_times[token - 'A'])++;
        }
    }

    sort(appear_times.begin(), appear_times.end(), [](tuple<char, size_t> a, tuple<char, size_t> b) {
        return (get<1>(a) == get<1>(b)) ? (get<0>(a) < get<0>(b)) : (get<1>(a) > get<1>(b));
    });

    for (size_t i = 0; i < 26 && get<1>(appear_times[i]) > 0; ++i) {
        cout << get<0>(appear_times[i]) << " " << get<1>(appear_times[i]) << endl;
    }

    return 0;
}