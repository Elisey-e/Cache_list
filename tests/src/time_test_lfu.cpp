#include "cache_lfu.hpp"
#include "cache_perfect.hpp"
#include "page_t.hpp"

#include <cassert>

using namespace page_functions;

int main(){
    
    // проверка работы lfu кэша

    time_t start = time(NULL);

    size_t m;
    int n;
    std::cin >> m >> n;
    cache_lfu<page_t> c(m); // создали кеш

    int hits = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 1000 == 0){
            cout << i << endl;
        }
        page_t p;
        std::cin >> p.id;
        assert(std::cin.good());
        if (c.lookup_update(p)) hits += 1;
    }
    std::cout << hits << "\n";

    cout << "Approximate time: " << time(NULL) - start << endl;

    return 0;
}
