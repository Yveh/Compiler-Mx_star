#pragma once

#include <string>
#include <unordered_map>

class type_t {
public:

    enum type_et {ty_void, ty_null, ty_bool, ty_int, ty_string, ty_class, ty_func};
    type_et kind;
    std::string name;
    int dim;

    type_t() = default;
    type_t(type_et _kind, std::string _name, int _dim);

    bool operator == (const type_t &rhs) const;
    bool operator != (const type_t &rhs) const;
};

static type_t typeVoid = type_t(type_t::ty_void, "", 0);
static type_t typeNull = type_t(type_t::ty_null, "", 0);
static type_t typeBool = type_t(type_t::ty_bool, "", 0);
static type_t typeInt = type_t(type_t::ty_int, "", 0);
static type_t typeString = type_t(type_t::ty_string, "", 0);
static type_t typeFunc = type_t(type_t::ty_func, "", 0);
