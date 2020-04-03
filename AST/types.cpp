#include "types.h"

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



