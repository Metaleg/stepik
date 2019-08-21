Задача на программирование: наибольший общий делитель

По данным двум числам 1≤a,b≤2⋅10^9 найдите их наибольший общий делитель.

#include <iostream>

template<class T>
inline T gcd(T a, T b) {
    return abs(b ? gcd(b, a % b) : a);
}

int main() {
    auto a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << gcd(a, b);
    return 0;
}
