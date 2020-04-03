#include "SymbolTable.h"

template<typename T>
bool SymbolTable<T>::insert(std::string key, T value) {
    if (hash.count(key)) {
        int tmp = hash[key];
        if (tmp >= mark)
            return false;
        else {
            stack.push_back(std::make_pair(-1, tmp));
            hash[key] = ord++;
            vec[ord] = value;
            ref[ord] = key;
            stack.push_back(std::make_pair(1, ord));
        }
    }
    else {
        hash[key] = ord++;
        vec[ord] = value;
        ref[ord] = key;
        stack.push_back(std::make_pair(1, ord));
        return true;
    }
}

template <typename T>
bool SymbolTable<T>::count(std::string key) {
    return hash.count(key);
}

template <typename T>
T SymbolTable<T>::find(std::string key) {
    return vec[hash[key]];
}

template<typename T>
void SymbolTable<T>::beginScope() {
    stack.push_back(std::make_pair(0 ,ord));
    mark = ord;
}

template<typename T>
void SymbolTable<T>::endScope() {
    std::pair<int, int> info;
    do {
        info = stack.back();
        stack.pop_back();
        if (info.first == -1) {
            hash[ref[info.second]] = info.second;
        } else if (info.first == 1) {
            hash.erase(ref[info.second]);
            vec.pop_back();
            ref.pop_back();
        }
    } while (info.first == 0);
    mark = info.second;
}
