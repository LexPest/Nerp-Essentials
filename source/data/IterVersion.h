// Copyright (c) 2019-2020 Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by a GNU LGPLv3 license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_ITERVERSION_H
#define NERP_BUILDER_ITERVERSION_H

#include <string>

struct IterVersion {
    unsigned long long Value;

    bool operator<(const IterVersion &rhs) const;

    bool operator>(const IterVersion &rhs) const;

    bool operator<=(const IterVersion &rhs) const;

    bool operator>=(const IterVersion &rhs) const;

    IterVersion(unsigned long long int value);

    IterVersion(const std::string &parStr);

    bool operator==(const IterVersion &rhs) const;

    bool operator!=(const IterVersion &rhs) const;
};

#endif //NERP_BUILDER_ITERVERSION_H
