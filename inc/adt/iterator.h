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
#ifndef CCLIB_ADT_ITERATOR_H
#define CCLIB_ADT_ITERATOR_H

namespace cclib {
    namespace adt {
        template<typename T>
        class iterator {
            public:
                typedef iterator<T>     itr;
            public:
                virtual T operator*() = 0;
                virtual T operator++() = 0;
                virtual T operator++(int) = 0;
                //TODO: for operator--
                // virtual T operator--() = 0;
                // virtual T operator--(int) = 0;

                virtual T begin() = 0;
                virtual T end() = 0;
                virtual T next() = 0;
                //TODO: for prev
                // virtual T prev() = 0;
        };
    }
}

#endif  //CCLIB_ADT_ITERATOR_H