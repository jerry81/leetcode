/*

As we know, it is easy and effective to insert a new value and check if a value is in a hash set or not.

Therefore, typically, a hash set is used to check if a value has ever appeared or not.



An Example
Let's look at an example:

Given an array of integers, find if the array contains any duplicates.

This is a typical problem which can be solved by a hash set.

You can simply iterate each value and insert the value into the set. If a value has already been in the hash set, there is a duplicate.



Template
Here we provide a template for you to solve this kind of problems:

*/

/*
 * Template for using hash set to find duplicates.
 */

#include <unordered_set>
#include <vector>
using namespace std;

bool findDuplicates(vector<Type>& keys) {
    // Replace Type with actual type of your key
    unordered_set<Type> hashset;
    for (Type key : keys) {
        if (hashset.count(key) > 0) {
            return true;
        }
        hashset.insert(key);
    }
    return false;
}