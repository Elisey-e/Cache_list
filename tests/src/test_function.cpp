#include "cache_.hpp"

int main(){
    Cache test;
    while (test.init_data()){
        cout << "Perfect cache result: ";
        test.lfu_cache();
        cout << "LFU cache result: ";
        test.perfect_cache();
    }

    return 0;
}
