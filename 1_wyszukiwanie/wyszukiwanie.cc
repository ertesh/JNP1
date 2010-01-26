// Maciej Andrejczuk
// Task 1 - Wyszukiwanie

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
#include <cctype>

using namespace std;

typedef vector<double> VD;
typedef vector<string> VS;

// Representation of line contains a set of numbers,
// (actually sorted vector without duplicates)
// a set of non-numbers and number of line.
typedef pair<pair<VD, VS>, int> Line;

// Reads input line by line into given `vector<string>`.
// Ignores blank lines.
void read_input(vector<string> &lines)
{
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        lines.push_back(line);
    }
}

// Returns a representation of a given number.
// By now it is a binary logarithm rounded to
// 8 most significant digits after a decimal point.
double representation(double w)
{
    double ret = log(w);
    int accuracy = 1e8;
    ret = round(ret * accuracy) / accuracy;
    return ret;
}

// Checks if `word` is a valid `double`.
// Additionally result of conversion is saved in `value`.
bool is_number(string &word, double &value)
{
    istringstream iss(word);
    iss >> value;
    return (!iss.fail());
}

template <class T> void sort_and_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

// Prepares each line by computing its representation as a `Line`.
void prepare(const vector<string> &lines, vector<Line> &data)
{
    int n = lines.size();
    data.reserve(lines.size());
    for (int i = 0; i < n; i++) {
        vector<double> numbers;
        vector<string> non_numbers;
        istringstream ss(lines[i]);
        string word;
        while (ss >> word) {
            double number;
            if (is_number(word, number)) {
                number = representation(number);
                numbers.push_back(number);
            }
            else {
                int n = word.size();
                for (int i = 0; i < n; i++) {
                    word[i] = toupper(word[i]);
                }
                non_numbers.push_back(word);
            }
        }
        sort_and_unique(numbers);
        sort_and_unique(non_numbers);
        data.push_back(make_pair(make_pair(numbers, non_numbers), i));
    }
    sort(data.begin(), data.end());
}

// Writes out all equivalence classes separeted by empty line
// Two lines are from the same equivalence class
// if and only if they have the same representations.
void write_output(const vector<string> &lines, const vector<Line> &v)
{
    int n = v.size();
    int k = 0;
    bool first = false;
    while (k < n) {
        // A group will contain elements [k,l)
        int l = k + 1;
        while (l < n && v[l].first == v[k].first) {
           l++;
        }
        if (l > k + 1) {  // If group has more than 1 element
            if (!first) first = true;
            else cout << endl;
            for (int i = k; i < l; i++)
              cout << lines[v[i].second] << endl;
        }
        k = l;
    }
}

int main()
{
    vector<string> lines;  // raw input divided into lines
    vector<Line> data;  // full representation of each line

    read_input(lines);
    prepare(lines, data);
    write_output(lines, data);
}

