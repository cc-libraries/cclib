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
                return this->_value < instance._value;
            }

            bool operator>(const Pair& instance) const {
                return this->_value > instance._value;
            }

            static std::string to_string(Pair& instance) {
                return "key:" + std::to_string(instance._key) + "-" + "value:" + std::to_string(instance._value);
            }
        };
    } // namespace adt
} // namespace cclib

#endif //CCLIB_ADT_PAIR_H