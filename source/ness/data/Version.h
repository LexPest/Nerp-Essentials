// Copyright (c) 2019-2020 Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by a GNU LGPLv3 license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_VERSION_H
#define NERP_BUILDER_VERSION_H

#include <string>

namespace nerp {
    struct Version {
        unsigned int Major;
        unsigned int Minor;

        Version(unsigned int major, unsigned int minor);

        Version(const std::string &parStr);

        bool operator==(const Version &rhs) const;

        bool operator!=(const Version &rhs) const;

        bool operator<(const Version &rhs) const;

        bool operator>(const Version &rhs) const;

        bool operator<=(const Version &rhs) const;

        bool operator>=(const Version &rhs) const;


    };
}


#endif //NERP_BUILDER_VERSION_H
