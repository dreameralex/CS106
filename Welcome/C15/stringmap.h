#ifndef STRINGMAP_H
#define STRINGMAP_H
#include <string>
#include "vector.h"

class stringMap
{
public:

    stringMap();

    ~stringMap();

    /*
     * Method: get
     * Usage: string value = map.get(key);
     * Returns the value for key or the empty string, if key is unbound.
     */
    std::string get(const std::string & key) const;

    /*
     * Method: put
     * Usage: map.put(key, value);
     * Associatees key with value in this map
     */
    void put(const std::string & key, const std:: string & value);

private:
    struct Cell{
        std::string key;
        std::string value;
        Cell *link;
    };

    static const int INITIAL_BUCKET_COUNT = 13;

    /* Instace variables */
    Cell **buckets; // Dynamic array o pointers to cells
    int nBuckets; // The number of buckets in the array

    /* Private methods */
    Cell *findCell(int bucket, const std::string & key) const;

    /* Make copying illegal */
    stringMap (const stringMap & src) {}
    stringMap & operator=(const stringMap & src){ return *this;}


};

#endif // STRINGMAP_H
