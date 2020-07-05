//
// Created by Alexey Mihailov on 24/05/2020.
//

#ifndef NERP_BUILDER_WX_PROPERTY_H
#define NERP_BUILDER_WX_PROPERTY_H

#include <list>
#include <functional>
#include <map>
#include <boost/any.hpp>
#include <memory>

namespace nerp {
    struct InvokeFunctionHandlerMeta_NoArg{};
    struct InvokeFunctionHandlerMeta_ArgT{};
    struct InvokeFunctionHandlerMeta_ArgAny{};


    template<typename T>
    class Property {
    public:
        explicit Property() : PropValue() { PropValue = std::make_shared<T>(); };
        explicit Property(T propValue) : PropValue(propValue) {}
        explicit Property(T& propValue) : PropValue(propValue) {}
        explicit Property(Property<T>& propValue) = delete;
        Property<T> operator=(Property<T>& propValue) = delete;

        std::shared_ptr<InvokeFunctionHandlerMeta_NoArg> addOnChangePropertyInvokeFunction_NoArg(std::function<void(void)> f){
            std::shared_ptr<InvokeFunctionHandlerMeta_NoArg> handler = std::make_shared<InvokeFunctionHandlerMeta_NoArg>();
            OnChangePropertyInvokeFuncs_NoArg.insert(std::make_pair(handler, f));
            return handler;
        }

        std::shared_ptr<InvokeFunctionHandlerMeta_ArgT> addOnChangePropertyInvokeFunction_ArgT(std::function<void(const T&)> f){
            std::shared_ptr<InvokeFunctionHandlerMeta_ArgT> handler = std::make_shared<InvokeFunctionHandlerMeta_ArgT>();
            OnChangePropertyInvokeFuncs_ArgT.insert(std::make_pair(handler, f));
            return handler;
        }

        std::shared_ptr<InvokeFunctionHandlerMeta_ArgAny> addOnChangePropertyInvokeFunction_ArgAny(std::function<void(const boost::any&)> f){
            std::shared_ptr<InvokeFunctionHandlerMeta_ArgAny> handler = std::make_shared<InvokeFunctionHandlerMeta_ArgAny>();
            OnChangePropertyInvokeFuncs_ArgAny.insert(std::make_pair(handler, f));
            return handler;
        }

        void removeOnChangePropertyInvokeFunction_NoArg(std::shared_ptr<InvokeFunctionHandlerMeta_NoArg> parHandler){
            OnChangePropertyInvokeFuncs_NoArg.erase(parHandler);
        }

        void removeOnChangePropertyInvokeFunction_ArgT(std::shared_ptr<InvokeFunctionHandlerMeta_ArgT> parHandler){
            OnChangePropertyInvokeFuncs_ArgT.erase(parHandler);
        }

        void removeOnChangePropertyInvokeFunction_ArgAny(std::shared_ptr<InvokeFunctionHandlerMeta_ArgAny> parHandler){
            OnChangePropertyInvokeFuncs_ArgAny.erase(parHandler);
        }

        inline T& get(){
            return *PropValue;
        }

        inline void set(const T& parNewValue){
            *PropValue = parNewValue;
            for (auto const& invokeFunc : OnChangePropertyInvokeFuncs_NoArg){
                invokeFunc.second();
            }
            for (auto const& invokeFunc : OnChangePropertyInvokeFuncs_ArgT){
                invokeFunc.second(*PropValue);
            }
            for (auto const& invokeFunc : OnChangePropertyInvokeFuncs_ArgAny){
                invokeFunc.second(*PropValue);
            }
        }

    private:
        std::map<std::shared_ptr<InvokeFunctionHandlerMeta_NoArg>, std::function<void(void)>> OnChangePropertyInvokeFuncs_NoArg;
        std::map<std::shared_ptr<InvokeFunctionHandlerMeta_ArgT>, std::function<void(const T&)>> OnChangePropertyInvokeFuncs_ArgT;
        std::map<std::shared_ptr<InvokeFunctionHandlerMeta_ArgAny>, std::function<void(const boost::any&)>> OnChangePropertyInvokeFuncs_ArgAny;

        std::shared_ptr<T> PropValue;
    };
}

#endif //NERP_BUILDER_WX_PROPERTY_H
