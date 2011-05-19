/* ----------------------------------------------------------------------- *//**
 *
 * @file Reference.hpp
 *
 *//* ----------------------------------------------------------------------- */

#ifndef MADLIB_REFERENCE_HPP
#define MADLIB_REFERENCE_HPP

namespace madlib {

namespace utils {

template <typename T, typename U = T>
class Reference {
public:
    Reference(T *inPtr) {
        mPtr = inPtr;
    }
    
    Reference &rebind(T *inPtr) {
        mPtr = inPtr;
        return *this;
    }

    operator U() const {
        return static_cast<U>(*mPtr);
    }
    
    /**
     * @internal
     * It is important to define this operator because C++ will otherwise
     * perform an assignment as a bit-by-bit copy. Note that this default 
     * operator= would be used even though there is a conversion path
     * through dest.operator=(orig.operator U())
     */
    Reference &operator=(const Reference &inReference) {
        *mPtr = *inReference.mPtr;
        return *this;
    }
    
    Reference &operator=(const U &inValue) {
        *mPtr = inValue;
        return *this;
    }
    
    Reference &operator+=(const U &inValue) {
        *mPtr += inValue;
        return *this;
    }

    Reference &operator-=(const U &inValue) {
        *mPtr -= inValue;
        return *this;
    }
    
    U operator++(int) {
        U returnValue = static_cast<U>(*mPtr);
        *mPtr += 1;
        return returnValue;
    }
    
    Reference &operator++() {
        *mPtr += 1;
        return *this;
    }
        
protected:
    T *mPtr;
};


} // namespace modules

} // namespace regress

#endif
