#pragma once

#include <string>
#include <vector>
#include <map>

template<typename T>
class SymbolTable {
private:
    int ord = 0;
    int mark = 0;
    std::map<std::string, int> hash;
    std::vector<T> vec;
    std::vector<std::string> ref;
    std::vector<std::pair<int, int>> stack;
public:
    class iterator {
    public:
        std::map<std::string, int>::iterator it;
        std::vector<T> *vec;
        iterator(std::map<std::string, int>::iterator _it, std::vector<T> *_vec) : it(_it), vec(_vec) {}
        iterator operator++ (int) {
            iterator ret(it, vec);
            it++;
            return ret;
        }
        iterator &operator++ () {
            it++;
            return *this;
        }
        iterator operator-- (int) {
            iterator ret(it, vec);
            it--;
            return ret;
        }
        iterator &operator-- () {
            it--;
            return *this;
        }
        std::string first() {
            return it->first;
        }
        T& second() {
            return (*vec)[it->second];
        }
        std::pair<std::string, T> operator*() const
        {
            return std::make_pair(it->first, (*vec)[it->second]);
        }
        bool operator==(const iterator &rhs) const
        {
            return it == rhs.it && vec == rhs.vec;
        }
        bool operator!=(const iterator &rhs) const
        {
            return !(*this == rhs);
        }
    };
    iterator begin() {
        return iterator(hash.begin(), &vec);
    }
    iterator end() {
        return iterator(hash.end(), &vec);
    }
    bool insert(std::string key, T value);
    bool insert(std::pair<std::string, T> p);
    bool count(std::string s);
    T & find(std::string s);
    int getOrder(std::string s);
    void beginScope();
    void endScope();
};

template<typename T>
bool SymbolTable<T>::insert(std::string key, T value) {
    if (hash.count(key)) {
        int tmp = hash[key];
        if (tmp >= mark)
            return false;
        else {
            stack.push_back(std::make_pair(-1, tmp));
            hash[key] = ord;
            vec.push_back(value);
            ref.push_back(key);
            stack.push_back(std::make_pair(1, ord++));
            return true;
        }
    }
    else {
        hash[key] = ord;
        vec.push_back(value);
        ref.push_back(key);
        stack.push_back(std::make_pair(1, ord++));
        return true;
    }
}

template<typename T>
bool SymbolTable<T>::insert(std::pair<std::string, T> p) {
    return insert(p.first, p.second);
}


template <typename T>
bool SymbolTable<T>::count(std::string key) {
    return hash.count(key);
}

template <typename T>
T & SymbolTable<T>::find(std::string key) {
    return vec[hash[key]];
}

template<typename T>
void SymbolTable<T>::beginScope() {
    stack.push_back(std::make_pair(0, mark));
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
        }
    } while (info.first != 0);
    mark = info.second;
}

template<typename T>
int SymbolTable<T>::getOrder(std::string s) {
    if (count(s))
        return hash[s];
    else
        return -1;
}
