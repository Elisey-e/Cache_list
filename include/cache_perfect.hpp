#ifndef CACHE_PERFECT
#define CACHE_PERFECT

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
class cache_perfect{

    private:
        vector <int> data = {};
        size_t size_of_cache = 0;
        int el_count = 0;
        int curr_elem = 0;

        unordered_map<int, list<int>> elements_places = {};
        set <int> buff = {};

        bool buff_replace_elem(auto elem, int base){
            auto ind1 = buff.find(elem);
            buff.erase(ind1);
            buff.insert(buff.end(), base);
            return true;
        }

    public:
        cache_perfect(size_t sz, vector <int>& data_i, int e_c) : size_of_cache(sz), el_count(e_c) {
            data.reserve((size_t) e_c);
            for (int i = 0; i < el_count; ++i){              
                data[i] = data_i[i];
                elements_places[data[i]].push_back(i);
            }
        }
    
        bool lookup_update(int i){    // namespace page_functions contain slow get page
            elements_places[i].pop_front();
            if(buff.find(i) != buff.end()){
                return true;
            }
            else if (buff.size() < size_of_cache){
                buff.insert(buff.end(), i);
            }
            else{
                page_functions::slow_get_page(i);
                   
                int maximum_pos = 0;
                int el_with_max_pos = 0;
                if (elements_places[i].size() == 0){
                    return false;
                }
                for (auto j : buff){
                    if (elements_places[j].size() != 0){
                        if (elements_places[j].front() > maximum_pos){
                            el_with_max_pos = j;
                            maximum_pos = elements_places[j].front();
                        }
                    }
                    else{
                        buff_replace_elem(j, i);
                        return false;
                    }
                }
                if (elements_places[i].front() < maximum_pos){
                    buff_replace_elem(el_with_max_pos, i);
                }
            }
            return false;
        }
};


#endif