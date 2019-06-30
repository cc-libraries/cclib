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
#ifndef CCLIB_STR_STRING_H
#define CCLIB_STR_STRING_H
#include <string.h> //DEPRECATED:
#include "./../../cclib-common/inc/base/common_define.h"
namespace cclib {
    namespace str {
        class String {
            public:
                String(const char* str = CC_NULL) {
                    if(NULL == str) {
                        m_data = new char[1]();
                        m_data = '\0';
                    } else {
                        m_data = new char[strlen(str) + 1]();
                        strcpy(m_data, str);
                    }
                }

                String(const String& other) {
                    m_data = new char[strlen(other.m_data) + 1]();
                    strcpy(m_data, other.m_data);
                }

                String& operator =(const String& other) {
                    if(this == &other) {
                        return *this;
                    }

                    delete m_data;
                    m_data = NULL;

                    m_data = new char[strlen(other.m_data) + 1]();
                    strcpy(m_data, other.m_data);

                    return *this;
                }

            private:
                char* m_data;
        };
    }   //namespace str
}   //namespace cclib

#endif //CCLIB_STR_STRING_H
