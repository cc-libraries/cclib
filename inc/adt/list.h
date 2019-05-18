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
#ifndef CCLIB_ADT_LIST_H
#define CCLIB_ADT_LIST_H

namespace cclib {
    namespace adt {
        template<typename T>
        class ListIterator {
            public:
                typedef vectorIterator<T> _Self;

            public:
                T operator*() {}
                _Self operator++() {}
                _Self operator++(int) {}

                _Self begin() {}
                _Self next() {}
        };

        template <typename T>
        class List {
            private:
                struct Node {}

            public:
                typedef ListIterator<T> iterator;

            public:
                List() {}
                List( const List& instance) {}
                ~List() {}

                const List& operator=(const List& instance) {}

                iterator begin() {}
                iterator end() {}

        };
    }
}

#endif  //CCLIB_ADT_LIST_H