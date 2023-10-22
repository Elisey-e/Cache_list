#ifndef CACHE_PAGE
#define CACHE_PAGE

namespace page_functions{

    using standart_key_type = int;

    struct page_t{
        standart_key_type id = 0;
    };

    standart_key_type slow_get_page(standart_key_type key){
            return key;
    }

    int hash_f(standart_key_type id){
        return id % 1000;
    }
}

#endif