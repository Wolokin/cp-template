#ifndef CP_DEBUG_H
#define CP_DEBUG_H

// Various ostream overloads
// Vector
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (auto &u : v) os << u << (&u != &v.back() ? ", " : "");
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

#endif //CP_DEBUG_H
