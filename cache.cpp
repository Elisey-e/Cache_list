#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>

int hash_f(int x);

using std::cin, std::cout, std::endl, std::unordered_map, std::vector, std::list, std::set;

#define ONE_USED  1
#define ZERO_USED 0

int hash_f(int x){
    return x;
}

int main(){

    unordered_map<int, list<int>> memc = {};
    unordered_map<int, set<int>> hash_table = {};
    unordered_map<int, int> map_of_el_index = {};

    int size_of_cache, el_count;
    cin >> size_of_cache >> el_count;

    int el, cached_el_count = 0, hit = 0;
    for (int i = 0; i < el_count; i++){
        cin >> el;

        if (hash_table.find(hash_f(el)) == hash_table.end()){   // If table doesn't have element
            if (cached_el_count == size_of_cache){
                if (not memc[ONE_USED].empty()){                // else cache is finally filled
                    hash_table[hash_f(el)].insert(el);
                    ++cached_el_count;
                    map_of_el_index[memc[ONE_USED].front()] = ZERO_USED;
                    map_of_el_index[el] = ONE_USED;
                    memc[ONE_USED].pop_back();
                    memc[ONE_USED].push_front(el);
                }
            }
            else{
                hash_table[hash_f(el)].insert(el);
                ++cached_el_count;
                memc[ONE_USED].push_front(el);
                map_of_el_index[el] = ONE_USED;
            }
        }
        else{
            memc[map_of_el_index[el]].erase(std::find(memc[map_of_el_index[el]].begin(), memc[map_of_el_index[el]].end(), el));
            ++map_of_el_index[el];
            memc[map_of_el_index[el]].push_front(el);
            ++hit;

        }
    }
    cout << hit << endl;

}