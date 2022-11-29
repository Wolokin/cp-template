#ifndef CP_DEBUG_H
#define CP_DEBUG_H

#include <bits/stdc++.h>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <execinfo.h>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

using namespace std;

// pair
template <typename T, typename L>
ostream &operator<<(ostream &os, const pair<T, L> &p) {
    cout << "<" << p.first << ", " << p.second << ">";
    return os;
}

string replace_all(string str, string pattern, string replacement) {
    std::size_t pos;
    while ((pos = str.find(pattern)) != std::string::npos)
        str.replace(pos, pattern.size(), replacement);
    return str;
}

string format_array_str(string str) {
    str = replace_all(str, "], [ ", "]\n\t[ ");
    str = replace_all(str, "[ [ ", "[\n\t[");
    str = replace_all(str, "] ]", "]\n]");
    str = replace_all(str, " ]", "]");
    size_t max_dist = 0;
    for (size_t pos = 0; pos < str.size(); pos++) {
        if (str[pos] == '\t' || (str[pos] == ',' && str[pos - 1] != ']')) {
            size_t closest =
                min(str.find(",", pos + 1), str.find("]", pos + 1)) - pos;
            max_dist = max(max_dist, closest);
        }
    }
    vector<int> offsets;
    for (size_t pos = 0; pos < str.size(); pos++) {
        if (str[pos] == '\t' || (str[pos] == ',' && str[pos - 1] != ']')) {
            size_t closest =
                min(str.find(",", pos + 1), str.find("]", pos + 1)) - pos;
            offsets.push_back(max_dist - closest);
        }
    }
    string offset_str;
    for (size_t index = 0, pos = 0; pos < str.size(); pos++) {
        offset_str += str[pos];
        if (str[pos] == '\t' || (str[pos] == ',' && str[pos - 1] != ']')) {
            offset_str += string(offsets[index++], ' ');
        }
    }
    offset_str = replace_all(offset_str, " [", "[ ");
    return offset_str;
}

// Various ostream overloads
// All iterables with begin method, except string
template <typename C,
          typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
          typename std::enable_if<!std::is_same<C, std::string>::value>::type
              * = nullptr>
ostream &operator<<(ostream &os, C const &v) {
    stringstream ss;
    ss << "[ ";
    for (auto &u : v)
        ss << u << (&u != &v.back() ? ", " : "");
    ss << " ]";
    string str = ss.str();
    if (str.find("[ [") != string::npos) {
        str = format_array_str(str);
    }
    os << str;
    return os;
}

// queue
template <typename T> ostream &operator<<(ostream &os, const queue<T> &q) {
    queue<T> q2(q);
    os << "[";
    while (!q2.empty()) {
        os << q2.front() << (&q2.front() != &q2.back() ? ", " : "");
        q2.pop();
    }
    os << "]";
    return os;
}

// Debug printing
void dbg_out() { cerr << endl; }

template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

// Stacktrace
void handler(int sig) {
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}

void init_debug() {
    signal(SIGSEGV, handler);
    signal(SIGABRT, handler);
}

#endif // CP_DEBUG_H
