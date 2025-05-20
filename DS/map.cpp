#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

// Generic print_map function for map, multimap, and unordered_map
template <typename MapType>
void print_map(const MapType& m) {
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    // Declare a map with int keys and string values
    map<int, string> m;

    // Insert key-value pairs into the map
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";
    m[6] = "six";
    m[7] = "seven";

    cout << "Map elements (sorted by key):" << endl;
    print_map(m); // Map is always sorted by key

    // Insert a new key-value pair using insert()
    m.insert({8, "eight"});

    // Update the value for an existing key
    m[5] = "five updated";
    cout << endl << "Map after update:" << endl;
    print_map(m);

    // Accessing values by key
    cout << endl << "Value for key 7: " << m[7] << endl;
    cout << "Value for key 10 (non-existing, default-initialized): " << m[10] << endl;
    // Note: Accessing a non-existing key inserts it with a default value (empty string for string type)

    m.erase(5);
    cout << endl << "Map after erasing key 5:" << endl;
    print_map(m);

    // Check if a key exists
    //find command returns an iterator to the element if found, otherwise it returns the end iterator

    if(m.find(3) != m.end()) {
        cout << "Key 3 exists in the map." << endl;
    } else {
        cout << "Key 3 does not exist in the map." << endl;
    }

    //MULTI MAP
    multimap<int, string> mm;
    mm.insert({1, "one"});
    mm.insert({1, "uno"});
    mm.insert({2, "two"});
    mm.insert({3, "three"});
    mm.insert({3, "tres"});
    mm.insert({4, "four"});
    mm.insert({5, "five"});
    mm.insert({6, "six"});
    mm.insert({7, "seven"});
    mm.insert({8, "eight"});
    mm.insert({8, "octo"});

    cout << endl << "Multimap elements (sorted by key):" << endl;
    print_map(mm);

    // To modify a specific value among multiple entries with the same key in a multimap, you must find its iterator and update it directly.
    // Example: Change "uno" to "uno updated" for key 1
    auto range = mm.equal_range(1); //function provides the range of elements with the same key
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == "uno") {
            it->second = "uno updated";
            break; // Only update the first matching value
        }
    }
    
    mm.erase(3); //erase all key instances 
    cout << endl << "Multimap after updates:    " << endl;
    print_map(mm);

    // UNORDERED MAP
    unordered_map<int, string> um;
    um[1] = "one";
    um[2] = "two";
    um[3] = "three";
    um[4] = "four"; 
    um[5] = "five";
    um[6] = "six";
    um[7] = "seven";
    um[8] = "eight";
    um[9] = "nine";

    cout << endl << "Unordered map elements (not sorted):" << endl; 
    print_map(um);
    // Unordered maps do not maintain any order, so the output may vary
    return 0;
}