#ifndef CACHE_PAGE
#define CACHE_PAGE

struct page_t{
    int id = 0;

    page_t(int x) : id(x) {}
    page_t() {}
    
    int slow_get_page(int key){
        return key;
    }

    int hash_f(){
        return id % 1000;
    }
};

#endif