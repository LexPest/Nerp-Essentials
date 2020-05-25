//
// Created by Alexey Mihailov on 25/05/2020.
//

#ifndef NERP_BUILDER_WX_IHASMEMBER_DEF_H
#define NERP_BUILDER_WX_IHASMEMBER_DEF_H

#include <ness/data/Property.h>

namespace nerp {
    #define __NERP_DEF_PREFIX_I_HAS_MEMBER IHasMember_

    #define __NERP_DEF_GENERATE_I_HAS_MEMBER(memberType, memberName) \
    class __NERP_DEF_PREFIX_I_HAS_MEMBER ##memberName { \
    public: \
        virtual memberType get_##memberName() = 0; \
        virtual void set_##memberName(const memberType& parValue) = 0; \
    };

    #define __NERP_DEF_GENERATE_IMPLEMENT_I_HAS_MEMBER(memberType, memberName, memberVarName) \
    virtual memberType get_##memberName() override { return memberVarName;} \
    virtual void set_##memberName(const memberType& parValue) override { memberVarName = parValue;}

    #define __NERP_DEF_INHERIT_I_HAS_MEMBER(memberName)  public __NERP_DEF_PREFIX_I_HAS_MEMBER ##memberName

    #define __NERP_DEF_STATIC_CAST_I_HAS_MEMBER(memberName, castTarget) std::static_cast<__NERP_DEF_PREFIX_I_HAS_MEMBER ##memberName>(castTarget)





    #define __NERP_DEF_PREFIX_I_HAS_PROPERTY_MEMBER IHasPropertyMember_

    #define __NERP_DEF_GENERATE_I_HAS_PROPERTY_MEMBER(memberInsideType, memberName) \
    class __NERP_DEF_PREFIX_I_HAS_PROPERTY_MEMBER ##memberName { \
    public: \
        virtual memberInsideType get_##memberName() = 0; \
        virtual void set_##memberName(const memberInsideType& parValue) = 0; \
    };

    #define __NERP_DEF_GENERATE_IMPLEMENT_I_HAS_PROPERTY_MEMBER(memberInsideType, memberName, memberVarName) \
    virtual memberInsideType get_##memberName() override {return memberVarName.get();} \
    virtual void set_##memberName(const memberInsideType& parValue) override {memberVarName.set(parValue);}

    #define __NERP_DEF_INHERIT_I_HAS_PROPERTY_MEMBER(memberName) public __NERP_DEF_PREFIX_I_HAS_PROPERTY_MEMBER ##memberName

    #define __NERP_DEF_STATIC_CAST_I_HAS_PROPERTY_MEMBER(memberName, castTarget) std::static_cast<__NERP_DEF_PREFIX_I_HAS_PROPERTY_MEMBER ##memberName>(castTarget)

}

#endif //NERP_BUILDER_WX_IHASMEMBER_DEF_H
