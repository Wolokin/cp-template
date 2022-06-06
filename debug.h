#ifndef CP_DEBUG_H
#define CP_DEBUG_H

#include <bits/stdc++.h>
#include <execinfo.h>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

using namespace std;

// Various ostream overloads
// All iterables with begin method
template <typename C,
          typename T = std::decay_t<decltype(*begin(std::declval<C>()))>>
ostream &operator<<(ostream &os, C const &v) {
  os << "[";
  for (auto &u : v)
    os << u << (&u != &v.back() ? ", " : "");
  os << "]";
  return os;
}

// queue
template<typename T>
ostream &operator<<(ostream &os, const queue<T> &q) {
    queue<T> q2(q);
    os << "[";
    while(!q2.empty()) {
        os << q2.front() << (&q2.front() != &q2.back() ? ", " : "");
        q2.pop();
    }
    os << "]";
    return os;
}


// Debug printing
void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
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

#endif //CP_DEBUG_H
