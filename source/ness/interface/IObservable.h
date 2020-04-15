// Copyright (c) 2019-2020 Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by a GNU LGPLv3 license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_IOBSERVABLE_H
#define NERP_BUILDER_IOBSERVABLE_H

#include <vector>
#include <functional>

namespace nerp {
    template<typename TObserver>
    class IObservable {
    public:

        typedef size_t size_type;

        typedef std::vector<std::shared_ptr<TObserver>> ObserverList;

        //*****************************************************************
        /// Add an observer to the list.
        //*****************************************************************
        void AddObserver(std::shared_ptr<TObserver> observer) {

            observer_list.push_back(observer);
        }

        //*****************************************************************
        /// Remove a particular observer from the list.
        //*****************************************************************
        void RemoveObserver(std::shared_ptr<TObserver> observer) {
            for (size_t i = 0; i < observer_list.size(); i++) {
                if (observer_list[i] == observer) {
                    observer_list.erase(i);
                }
            }
        }

        //*****************************************************************
        /// Clear all observers from the list.
        //*****************************************************************
        void ClearObservers() {
            observer_list.clear();
        }

        //*****************************************************************
        /// Returns the number of observers.
        //*****************************************************************
        size_type NumberOfObservers() const {
            return observer_list.size();
        }


    protected:
        //*****************************************************************
        /// Notify all observers.
        //*****************************************************************
        void NotifyAll(std::function<void(TObserver &)> notifyFunc) {
            for (auto observer : observer_list) {
                notifyFunc(*observer);
            }
        }

        /// The list of observers.
        ObserverList observer_list;
    };
}

#endif //NERP_BUILDER_IOBSERVABLE_H
