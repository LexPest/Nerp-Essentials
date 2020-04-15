// Copyright (c) 2019-2020 Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by a GNU LGPLv3 license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_ILINKEDOBSERVER_H
#define NERP_BUILDER_ILINKEDOBSERVER_H

#include <memory>
#include "IObservable.h"

template <typename TObserver>
class IObservable;


template <typename TObservable, typename TObserverType>
class ILinkedObserver {
public:
    ILinkedObserver(std::shared_ptr<TObservable> linkedObservable) : LinkedObservable(linkedObservable) {
        // Compile-time check
        static_assert(std::is_base_of<IObservable<TObserverType>, TObservable>::value, "type parameter of this class must derive from IObservable");
    }

    void InitObserver(std::shared_ptr<ILinkedObserver<TObservable, TObserverType>> parSelf){
        LinkedObservable->AddObserver(std::dynamic_pointer_cast<TObserverType>(parSelf));
    }

    virtual ~ILinkedObserver() = default;
protected:
    std::shared_ptr<TObservable> LinkedObservable;
};


#endif //NERP_BUILDER_ILINKEDOBSERVER_H
