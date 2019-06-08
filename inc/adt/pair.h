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
#ifndef CCLIB_ADT_PAIR_H
#define CCLIB_ADT_PAIR_H

#include "./../../cclib-common/inc/base/common_define.h"
#include <string>

namespace cclib
{
    namespace adt
    {
        template<typename _Key, typename _Value>
        struct Pair {
            _Key _key;
            _Value _value;

            Pair() {}
            Pair(const _Key& key, const _Value& value): _key(key), _value(value) {}
            Pair(const _Key& key): _key(key), _value(CC_NULL) {}
            ~Pair() {}

            Pair& operator=(const Pair& instance) {
                this->_key = instance._key;
                this->_value = instance._value;
            }

            bool operator==(const Pair& instance) const {
                return this->_key == instance._key;
            }

            bool operator!=(const Pair& instance) const {
                return this->_key != instance._key;
            }

            bool operator<(const Pair& instance) const {
                return this->_key < instance._key;
            }

            bool operator>(const Pair& instance) const {
                return this->_key > instance._key;
            }

            // std::string operator<<() {}  //TODO:
            // std::string operator>>() {}  //TODO:

            //TODO: remove std::string
            static std::string to_string(const Pair& instance) {
                return "key:" + std::to_string(instance._key) + "-" + "value:" + std::to_string(instance._value);
            }
        };
    } // namespace adt
} // namespace cclib

#endif //CCLIB_ADT_PAIR_H