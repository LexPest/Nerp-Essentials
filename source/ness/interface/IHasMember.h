//
// Created by Alexey Mihailov on 25/05/2020.
//

#ifndef NERP_BUILDER_WX_IHASMEMBER_H
#define NERP_BUILDER_WX_IHASMEMBER_H

namespace nerp {
    template<typename T>
    class IHasMember {
    public:
        virtual T getValue() = 0;
        virtual void setValue(const T& parValue) = 0;
    };
}

#endif //NERP_BUILDER_WX_IHASMEMBER_H
