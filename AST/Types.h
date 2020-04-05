#pragma once

#include <string>

class type_t {
public:

    enum type_et {ty_void, ty_null, ty_bool, ty_int, ty_string, ty_class, ty_func};
    type_et kind;
    std::string name;
    int dim;

    type_t() = default;
    type_t(type_et _kind, std::string _name, int _dim);

    bool isClass();

    bool operator == (const type_t &rhs) const;
    bool operator != (const type_t &rhs) const;
};

static type_t typeVoid = type_t(type_t::ty_void, "", 0);
static type_t typeNull = type_t(type_t::ty_null, "", 0);
static type_t typeBool = type_t(type_t::ty_bool, "", 0);
static type_t typeInt = type_t(type_t::ty_int, "", 0);
static type_t typeString = type_t(type_t::ty_class, "string", 0);

class value_t {
public:
    enum value_et {lvalue, rvalue};
    value_et kind;

    value_t() = default;
    value_t(value_et _kind);

    bool operator == (const value_t &rhs) const;
    bool operator != (const value_t &rhs) const;
};

static value_t lvalue = value_t(value_t::lvalue);
static value_t rvalue = value_t(value_t::rvalue);