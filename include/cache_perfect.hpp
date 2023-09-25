#ifndef CACHE_PERFECT
#define CACHE_PERFECT

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>

using std::cin, std::cout, std::endl, std::unordered_map, std::vector, std::list, std::set;

#define ONE_USED  1
#define ZERO_USED 0

template <typename PAGES, typename KeyT = int>
class cache_perfect{

    private:
        vector <int> data = {};
        size_t size_of_cache = 0;
        int el_count = 0;

        unordered_map<int, list<int>> elements_places = {};
        vector <int> buff = {};

    public:
        int perfect_cache(){

            for (int i = 0; i < el_count; ++i){                    
                elements_places[data[i]].push_back(i);
            }

            int hit = 0;
            for (auto i : data){
                elements_places[i].pop_front();
                if (buff.size() < size_of_cache){
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
            elements_places.clear();
            buff.clear();
            cout << hit << endl;
            return 0;
        }

        int hash_f(int x){
            return x % 1000;
        }
};


#endif