#ifndef CACHE_LFU
#define CACHE_LFU

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>

#include "page_t.hpp"

using std::cin, std::cout, std::endl, std::unordered_map, std::vector, std::list, std::set;
using namespace page_functions;

#define ONE_USED  1
#define ZERO_USED 0

template <typename PAGES, typename KeyT = int>
class cache_lfu{

    private:
        size_t size_of_cache = 0;
        int el_count = 0;

        unordered_map<int, set<int>> memc = {};
        unordered_map<int, set<int>> hash_table = {};
        unordered_map<int, int> map_of_el_index = {};

        size_t cached_el_count = 0;

        bool is_elem_exist(int el, auto hash_el){
            return not (hash_table.find(hash_el) == hash_table.end() || hash_table[hash_el].find(el) == hash_table[hash_el].end());
        }

        bool delete_elem_from_once_used(){
            auto del_el = *(memc[ONE_USED].begin());
            map_of_el_index.erase(del_el);
            hash_table[hash_f(del_el)].erase(del_el);
            return true;
        }

        bool append_elem_to_once_used(int el){
            map_of_el_index[el] = ONE_USED;
            memc[ONE_USED].erase(memc[ONE_USED].begin());
            memc[ONE_USED].insert(memc[ONE_USED].end(), el);
            return true;
        }

        bool use_elem_once_more_time(int el){
            memc[map_of_el_index[el]].erase(el);
            ++map_of_el_index[el];
            memc[map_of_el_index[el]].insert(memc[map_of_el_index[el]].begin(), el);
            return true;
        }

        bool use_elem_first_time(int el, auto hash_el){
            hash_table[hash_el].insert(el);
            ++cached_el_count;
            memc[ONE_USED].insert(memc[ONE_USED].end(), el);
            map_of_el_index[el] = ONE_USED;
            return true;
        }

    public:
        cache_lfu(size_t sz) : size_of_cache(sz) {}

        bool lookup_update(PAGES elem){
            int el = elem.id;
            auto hash_el = hash_f(elem.id);
            
            if (not is_elem_exist(el, hash_el)){   // If table doesn't have element
                if (cached_el_count == size_of_cache){
                    if (not memc[ONE_USED].empty()){                // else cache is finally filled
                        hash_table[hash_el].insert(el);

                        delete_elem_from_once_used();
                        append_elem_to_once_used(el);

                        return false;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    use_elem_first_time(el, hash_el);
                    return false;
                }
            }
            else{
                use_elem_once_more_time(el);
                return true;
            }
            return false;
        }
};

#endif