//
// Created by Alexey Mihailov on 25/05/2020.
//

#ifndef NERP_BUILDER_WX_IHASMEMBER_DEF_H
#define NERP_BUILDER_WX_IHASMEMBER_DEF_H

#include <ness/data/Property.h>
#include <memory>
#include <boost/pointer_cast.hpp>

namespace nerp {
    // #define __NERP_DEF_PREFIX_I_HAS_MEMBER IHasMember_

#define __NERP_DEF_GENERATE_I_HAS_MEMBER(memberType, memberName) \
    class IHasMember_##memberName { \
    public: \
        virtual memberType get_##memberName() = 0; \
        virtual void set_##memberName(const memberType& parValue) = 0; \
    };

#define __NERP_DEF_GENERATE_IMPLEMENT_I_HAS_MEMBER(memberType, memberName, memberVarName) \
    virtual memberType get_##memberName() override { return memberVarName;} \
    virtual void set_##memberName(const memberType& parValue) override { memberVarName = parValue;}

#define __NERP_DEF_INHERIT_I_HAS_MEMBER(memberName)  public  IHasMember_##memberName

#define __NERP_DEF_REINTERPRET_CAST_SHARED_PTR_I_HAS_MEMBER(memberName, castTarget)  boost::reinterpret_pointer_cast<IHasMember_##memberName>(castTarget)





    // #define __NERP_DEF_PREFIX_I_HAS_PROPERTY_MEMBER IHasPropertyMember_

#define __NERP_DEF_GENERATE_I_HAS_PROPERTY_MEMBER(memberInsideType, memberName) \
    class IHasPropertyMember_##memberName { \
    public: \
        virtual memberInsideType get_##memberName() = 0; \
        virtual void set_##memberName(const memberInsideType& parValue) = 0; \
        virtual std::shared_ptr<InvokeFunctionHandlerMeta_NoArg> add_function_to_invoke_on_prop_change_no_arg_##memberName(std::function<void(void)> parFunc) = 0; \
    };

#define __NERP_DEF_GENERATE_IMPLEMENT_I_HAS_PROPERTY_MEMBER(memberInsideType, memberName, memberVarName) \
    virtual memberInsideType get_##memberName() override {return memberVarName.get();} \
    virtual void set_##memberName(const memberInsideType& parValue) override {memberVarName.set(parValue);} \
    virtual std::shared_ptr<InvokeFunctionHandlerMeta_NoArg> add_function_to_invoke_on_prop_change_no_arg_##memberName(std::function<void(void)> parFunc) override \
        {return memberVarName.addOnChangePropertyInvokeFunction_NoArg(parFunc);}

#define __NERP_DEF_INHERIT_I_HAS_PROPERTY_MEMBER(memberName) public IHasPropertyMember_##memberName

#define __NERP_DEF_REINTERPRET_CAST_SHARED_PTR_I_HAS_PROPERTY_MEMBER(memberName, castTarget) boost::reinterpret_pointer_cast<IHasPropertyMember_##memberName>(castTarget)

}

#endif //NERP_BUILDER_WX_IHASMEMBER_DEF_H
