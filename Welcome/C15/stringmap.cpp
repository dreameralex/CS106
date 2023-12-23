#include "stringmap.h"
#include <string>
using namespace std;

stringMap::stringMap() {
    nBuckets = INITIAL_BUCKET_COUNT;
    buckets = new Cell*[nBuckets];
    for (int i = 0; i < nBuckets; i++){
        buckets[i] = NULL;
    }
}

stringMap::~stringMap() {
    for (int i = 0; i < nBuckets; i++){
        Cell *cp = buckets[i];
        while(cp != NULL){
            Cell *oldCell = cp;
            cp = cp->link;
            delete oldCell;
        }
    }
}

/*
 * Implementation notes: put, get
 * These methods use finKey to search for the specified key.
 */

string stringMap::get(const string &key) const{
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket,key);
    return (cp == NULL) ? "":cp->value;
}

void stringMap::put(const string & key, const string & value){
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if( cp == NULL){
        cp = new Cell;
        cp->key = key;
        cp->link = buckets[bucket];
        buckets[bucket] = cp;
    }
    cp->value = value;
}

/*
 * Private method: findKey
 * Returns the index at which the key appears, or -1 key is not found
 */
stringMap::Cell *stringMap::findCell(int bucket, const string & key) const{
    Cell *cp = buckets[bucket];
    while(cp != NULL && key != cp->key){
        cp = cp->link;
    }
    return cp;
}
