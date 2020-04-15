// Copyright (c) 2019-2020 Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by a GNU LGPLv3 license
// that can be found in the LICENSE file.

#include "IterVersion.h"

using namespace nerp;

IterVersion::IterVersion(unsigned long long int value) : Value(value) {}

bool IterVersion::operator==(const IterVersion &rhs) const {
    return Value == rhs.Value;
}

bool IterVersion::operator!=(const IterVersion &rhs) const {
    return !(rhs == *this);
}

bool IterVersion::operator<(const IterVersion &rhs) const {
    return Value < rhs.Value;
}

bool IterVersion::operator>(const IterVersion &rhs) const {
    return rhs < *this;
}

bool IterVersion::operator<=(const IterVersion &rhs) const {
    return !(rhs < *this);
}

bool IterVersion::operator>=(const IterVersion &rhs) const {
    return !(*this < rhs);
}

IterVersion::IterVersion(const std::string &parStr) {
    Value = std::stoull(parStr);
}
