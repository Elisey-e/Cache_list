#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>

int hash_f(int x);

int perfect_cache(int size_of_cache, int el_count);

using std::cin, std::cout, std::endl, std::unordered_map, std::vector, std::list, std::set;

#define ONE_USED  1
#define ZERO_USED 0

int hash_f(int x){
    return x % 1000;
}

int perfect_cache(int size_of_cache, int el_count){
    unordered_map<int, list<int>> elements_places = {};
    vector <int> data = {1, 2, 5, 5, 5, 1};

    for (int i = 0; i < el_count; ++i){                    
        elements_places[data[i]].push_back(i);
    }

    vector <int> buff = {};
    int hit = 0;
    for (auto i : data){
        elements_places[i].pop_front();
        if ((int) buff.size() < size_of_cache){
            if (std::find(buff.begin(), buff.end(), i) != buff.end()){
                ++hit;
            }
            else{
                buff.push_back(i);
            }
        }
        else{
            if (std::find(buff.begin(), buff.end(), i) != buff.end()){
                ++hit;
            }
            else{
                //int minimum_pos = (int) buff.size() + 1;           
                int maximum_pos = 0;
                auto el_with_max_pos = buff[0];
                for (auto j : buff){
                    if (elements_places[j].size() != 0){
                        //minimum_pos = std::min(elements_places[j].front(), minimum_pos);
                        if (elements_places[j].front() > maximum_pos){
                            el_with_max_pos = j;
                            maximum_pos = elements_places[j].front();
                        }
                    }
                    else{
                        maximum_pos = (int) buff.size();
                        el_with_max_pos = j;
                        buff.insert(std::find(buff.begin(), buff.end(), el_with_max_pos), i);
                        break;
                    }
                }
                if (elements_places[i].front() < maximum_pos){
                    buff.insert(std::find(buff.begin(), buff.end(), el_with_max_pos), i);
                    buff.erase(std::find(buff.begin(), buff.end(), el_with_max_pos));
                }
            }
        }
    }
    cout << hit << endl;
    return 0;
    
}

int main(){
    perfect_cache(2, 6);
    return 0;

    unordered_map<int, list<int>> memc = {};
    unordered_map<int, set<int>> hash_table = {};
    unordered_map<int, int> map_of_el_index = {};

    int size_of_cache, el_count;
    cin >> size_of_cache >> el_count;

    int el, cached_el_count = 0, hit = 0;
    for (int i = 0; i < el_count; i++){
        cin >> el;
        auto hash_el = hash_f(el);
        if (hash_table.find(hash_el) == hash_table.end() || hash_table[hash_el].find(el) == hash_table[hash_el].end()){   // If table doesn't have element
            if (cached_el_count == size_of_cache){
                if (not memc[ONE_USED].empty()){                // else cache is finally filled
                    hash_table[hash_f(el)].insert(el);
                    //map_of_el_index[memc[ONE_USED].front()] = ZERO_USED;
                    auto del_el = memc[ONE_USED].front();
                    map_of_el_index.erase(memc[ONE_USED].front());
                    hash_table[hash_f(del_el)].erase(del_el);
                    map_of_el_index[el] = ONE_USED;
                    memc[ONE_USED].pop_front();
                    memc[ONE_USED].push_back(el);
                }
                else{
                    continue;
                }
            }
            else{
                hash_table[hash_f(el)].insert(el);
                ++cached_el_count;
                memc[ONE_USED].push_back(el);
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
