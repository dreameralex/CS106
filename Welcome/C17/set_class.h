#ifndef SET_CLASS_H
#define SET_CLASS_H
#include "map.h"
#include "vector.h"


template <typename ValueType>
class set_class
{
public:
    set_class();

    /*
     * Usage: Set<ValueType> set;
     * Frees any heap storage associated with set.
     */
    ~set_class();

    /*
     * Method: size
     * Usage: int count = set_class.size();
     * Returns the number of elements in this set.
     */
    int size() const;

    /*
     * Method: isEmpty
     * Usage: if (set_class.isEmpty())...
     * Returns true if this set contains no elements.
     */
    bool isEmpty() const;

    /*
     * Method: add
     * Usage: int count = set_class.add(value);
     * Adds an elemnet to this set if it is not already there.
     */
    void add(const ValueType & value);

    /*
     * Method: remove
     * Usage: int count = set_class.remove(value);
     * Remove an elemnet from the set. If the value .
     */
    void remove(const ValueType & value);

    void print() const;

    /*
     * Method: contains
     * Usage: if (set_class.contains(value)...
     * Returns true if this set contains object value.
     */
    bool contains(const ValueType & value) const;

    /*
     * Method: clear
     * Usage:  set_class.clear(value);
     * Removes all elements from this set.
     */
    void clear();

    /*
     * Method: isSubsetOf
     * Usage:  if(set_class.isSubsetOf(set2))...
     * Implements the subset relation on sets. It returns true if every element of this set is contained in set2.
     */
    bool isSubsetOf(const set_class & set2) const;

    /*
     * Operator: ==
     * Usage:  set1 == set2;
     * Returns true if set1 and set2 contain the same elements.
     */
    bool operator==(const set_class & set2) const;

    /*
     * Operator: !=
     * Usage:  set1 != set2;
     * Returns true if set1 and set2 are different.
     */
    bool operator!=(const set_class & set2) const;

    /*
     * Operator: +
     * Usage:  set1 + set2;
     *         set1 + value
     * Returns the union of sets set1 and set2, which is the set of elements
     * that appear in at least one of the two sets. The second form return
     * the set formed by adding a single element.
     */
    set_class operator+(const set_class & set2) const;
    set_class operator+(const ValueType & value) const;

    /*
     * Operator: *
     * Usage:  set1 * set2;
     * Returns the intersection of stes set1 and set2, which is the set of
     * all elements that apper in both.
     */
    set_class operator*(const set_class & set2) const;

    /*
     * Operator: -
     * Usage:  set1 - set2;
     *         set1 - value
     * Returns the difference of sets set1 and set2, which is all of the
     * elements that appear in set1 but not set2. The second form returns
     * the set formed by adding a single element.
     */
    set_class operator-(const set_class & set2) const;
    set_class operator-(const ValueType & value) const;

    /*
     * Operator: +=
     * Usage:  set1 += set2;
     *         set1 += value
     * Adds all elemnets form sest2.
     */
    set_class & operator+=(const set_class & set2);
    set_class & operator+=(const ValueType & value);

    /*
     * Operator: *=
     * Usage:  set1 *= set2;
     * any elemnets from set1 that are not present in set2.
     */
    set_class & operator*=(const set_class & set2);

    /*
     * Operator: -=
     * Usage:  set1 -= set2;
     *         set1 -= value
     * Removes all elements from set2(for a single value) from set1.
     */
    set_class & operator-=(const set_class & set2);
    set_class & operator-=(const ValueType & value);


private:
    /* Instance variables */
    Map<ValueType,bool> map; // Map used to store the elements

























};

#endif // SET_CLASS_H
