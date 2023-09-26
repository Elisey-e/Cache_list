#ifndef CACHE_PAGE
#define CACHE_PAGE

namespace page_functions{
    struct page_t{
        int id = 0;
    };

    int slow_get_page(int key){
            return key;
    }

    int hash_f(int id){
        return id % 1000;
    }
}

#endif