//
// Created by Alexey Mihailov on 24/05/2020.
//

#ifndef NERP_BUILDER_WX_PROPERTY_H
#define NERP_BUILDER_WX_PROPERTY_H

#include <list>
#include <functional>
#include <map>

namespace nerp {
    struct InvokeFunctionHandlerMeta{};

    template<typename T>
    class Property {
    public:
        explicit Property() : PropValue() {};
        explicit Property(T propValue) : PropValue(propValue) {}
        explicit Property(T& propValue) : PropValue(propValue) {}
        explicit Property(Property<T>& propValue) = delete;
        Property<T> operator=(Property<T>& propValue) = delete;

        std::shared_ptr<InvokeFunctionHandlerMeta> addOnChangePropertyInvokeFunction(std::function<void(T)> f){
            std::shared_ptr<InvokeFunctionHandlerMeta> handler = std::make_shared<InvokeFunctionHandlerMeta>();
            OnChangePropertyInvokeFuncs.insert(std::make_pair(handler, f));
            return handler;
        }

        void removeOnChangePropertyInvokeFunction(std::shared_ptr<InvokeFunctionHandlerMeta> parHandler){
            OnChangePropertyInvokeFuncs.erase(parHandler);
        }

        inline T get(){
            return std::move(PropValue);
        }

        inline void set(const T& parNewValue){
            PropValue = parNewValue;
            for (auto const& invokeFunc : OnChangePropertyInvokeFuncs){
                invokeFunc.second(PropValue);
            }
        }

    private:
        std::map<std::shared_ptr<InvokeFunctionHandlerMeta>, std::function<void(T)>> OnChangePropertyInvokeFuncs;

        T PropValue;
    };
}

#endif //NERP_BUILDER_WX_PROPERTY_H
