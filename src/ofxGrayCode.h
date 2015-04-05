//
//  ofxGrayCode.h
//
//  Created by ISHII 2bit on 2015/04/05.
//

#pragma once

#define BEGIN_NAMESPACE(name) namespace name {
#define END_NAMESPACE(name) };

BEGIN_NAMESPACE(ofxGrayCode)

inline unsigned long encode(unsigned long value) {
    return value ^ (value >> 1);
}

inline unsigned long decode(unsigned long code) {
    unsigned long value = code;
    while(code) value ^= (code >>= 1);
    return value;
}

END_NAMESPACE(ofxGrayCode)