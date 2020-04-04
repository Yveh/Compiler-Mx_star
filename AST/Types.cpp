#include "Types.h"

bool type_t::operator==(const type_t &rhs) const {
    if (kind != rhs.kind)
        return false;
    else
        return name == rhs.name && dim == rhs.dim;
}

type_t::type_t(type_t::type_et _kind, std::string _name, int _dim) {
    kind = _kind;
    name = _name;
    dim = _dim;
}

bool type_t::operator!=(const type_t &rhs) const {
    return !(*this == rhs);
}

bool type_t::isClass() {
    return kind == ty_class;
}


value_t::value_t(value_t::value_et _kind) {
    kind = _kind;
}

bool value_t::operator==(const value_t &rhs) const {
    return kind == rhs.kind;
}

bool value_t::operator!=(const value_t &rhs) const {
    return !(*this == rhs);
}
