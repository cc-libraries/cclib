/*********************************************************************
 * cclib
 *
 * Copyright (c) 2019 cclib contributors:
 *   - hello_chenchen <https://github.com/hello-chenchen>
 *
 * MIT License <https://github.com/cc-libraries/cclib/blob/master/LICENSE>
 * See https://github.com/cc-libraries/cclib for the latest update to this file
 *
 * author: hello_chenchen <https://github.com/hello-chenchen>
 **********************************************************************************/
#ifndef CCLIB_ADT_MAP_H
#define CCLIB_ADT_MAP_H

namespace cclib
{
    namespace adt
    {
        template<typename T>
        class MapIterator {
            public:
                typedef MapIterator<T> _Self;

            public:
                MapIterator() {}

                ~MapIterator() {}

                T operator*() {
                }

                _Self operator++() {
                }

                _Self operator++(int) {
                }

                _Self operator--() {
                }

                _Self operator--(int) {
                }

                bool operator== (const _Self& instance) const {
                }

                bool operator!= (const _Self& instance) const {
                }
        };

        template<typename T>
        class Map {
            public:
                typedef MapIterator<T> iterator;
            public:
                explicit Map() {}
                ~Map() {}

            public:
                const Map& operator=(const Map& instance) {}
                iterator begin() {}
                iterator end() {}
                size_t size() const {}
                bool empty() const {}
                bool clear() {}
                bool push_front(const T& data) {}
                bool push_back(const T& data) {}
                bool pop_front() {}
                bool pop_back() {}
                iterator insert(iterator itr, const T& data) {}
                iterator erase(iterator itr) {}

            private:
                size_t _size;
        };
    } // namespace adt
} // namespace cclib


#endif  //CCLIB_ADT_MAP_H