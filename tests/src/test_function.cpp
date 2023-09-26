#include "cache_lfu.hpp"
#include "cache_perfect.hpp"
#include "page_t.hpp"

#include <cassert>

using namespace page_functions;

int main(){
    // cache_t <int, int> test;
    // while (test.init_data()){
    //     cout << "Perfect cache result: ";
    //     test.lfu_cache();
    //     cout << "LFU cache result: ";
    //     test.perfect_cache();
    // }
    
    size_t m;
    int n;
    std::cin >> m >> n;
    cache_lfu<page_t> c(m); // создали кеш

    int hits = 0;
    for (int i = 0; i < n; ++i) {
        page_t p;
        std::cin >> p.id;
        assert(std::cin.good());
        if (c.lookup_update(p)) hits += 1;
    }
    std::cout << hits << "\n";





    std::cin >> m >> n;
    vector <int> test_vec_id = {};
    for (int i = 0; i < n; ++i) {
        page_t p;
        std::cin >> p.id;
        assert(std::cin.good());
        test_vec_id.push_back(p.id);
    }

    cache_perfect<page_t> cp(m, test_vec_id, n); // инициализировали кеш

    hits = 0;
    for (auto p : test_vec_id) {
        if (cp.lookup_update(p)) hits += 1;
    }
    std::cout << hits << "\n";

    return 0;
}
