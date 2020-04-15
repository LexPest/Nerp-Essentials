// Copyright (c) 2019-2020 Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by a GNU LGPLv3 license
// that can be found in the LICENSE file.

#include "Version.h"

Version::Version(unsigned int major, unsigned int minor) : Major(major), Minor(minor) {}

bool Version::operator==(const Version &rhs) const {
    return Major == rhs.Major &&
           Minor == rhs.Minor;
}

bool Version::operator!=(const Version &rhs) const {
    return !(rhs == *this);
}

bool Version::operator<(const Version &rhs) const {
    if (Major < rhs.Major)
        return true;
    if (rhs.Major < Major)
        return false;
    return Minor < rhs.Minor;
}

bool Version::operator>(const Version &rhs) const {
    return rhs < *this;
}

bool Version::operator<=(const Version &rhs) const {
    return !(rhs < *this);
}

bool Version::operator>=(const Version &rhs) const {
    return !(*this < rhs);
}

Version::Version(const std::string & parStr) {
    size_t dotPos = parStr.find_first_of('.');
    std::string majorVer = parStr.substr(0, dotPos);
    std::string minorVer = parStr.substr(dotPos + 1, parStr.size() - 1 - dotPos);
    Major = std::stoi(majorVer);
    Minor = std::stoi(minorVer);
}

