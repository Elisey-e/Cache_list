#include "cache_lfu.hpp"
#include "cache_perfect.hpp"
#include "page_t.hpp"

#include <cassert>
#include <ctime>
#include <fstream>

using namespace page_functions;

int main(){

    // проверка работы идеального кэша

    time_t start = time(NULL);

    size_t m;
    int n;

    int hits = 0;

    std::cin >> m >> n;
    vector <standart_key_type> test_vec_id = {};
    for (int i = 0; i < n; ++i) {
        #if 0
        if (i % 10000 == 0){
            cout << i;
        }
        #endif
        page_t p;
        std::cin >> p.id;
        assert(std::cin.good());
        test_vec_id.push_back(p.id);
    }

    cache_perfect<page_t> cp(m, test_vec_id, n); // инициализировали кеш

    hits = 0;
    for (auto p : test_vec_id) {
        #if 0
        if (hits % 10000 == 0){
            cout << hits << endl;
        }
        #endif
        if (cp.lookup_update(p)) hits += 1;
    }

    std::cout << hits << "\n";

    cout << "Approximate time: " << time(NULL) - start << endl;

    return 0;
}
