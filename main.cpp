#include <iostream>
#include <utility>

#define _ACNT(_1, _2, _3, ...) AUTO_##_3
#define AUTO_CNT(...) _ACNT(__VA_ARGS__, 2, 1, 0)

#define EMPTY
#define AUTO_0(...) EMPTY
#define AUTO_1(_1, ...) auto _1
#define AUTO_2(_1, _2, ...) auto _1, auto _2

#define var auto
#define function(...) [](AUTO_CNT(__VA_ARGS__) (__VA_ARGS__))

struct {
    template <typename Arg, typename... Args>
    void log(Arg&& arg, Args&&... args) {
        std::cout<< std::forward<Arg>(arg);
        using expander = int[];
        (void)expander{0, (void(std::cout<< std::forward<Args>(args)), 0)...};
    }
} console;

using namespace std;

int main()
{
    var x = 5;
    var y = 7;

    var sum = function(a,b) {
        return a + b;
    };
    console.log(sum(x,y));
}
