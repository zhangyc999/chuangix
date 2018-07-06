#ifndef BIT_H_
#define BIT_H_

#define LITTLE_ENDIAN

#ifdef LITTLE_ENDIAN
#define GET_SIGN_BIT(x) \
        (((signed char *)&x)[sizeof(x) - 1] >> 7 | 1)
#endif

#ifdef BIG_ENDIAN
#define GET_SIGN_BIT(x) \
        (((signed char *)&x)[0] >> 7 | 1)
#endif

#endif /* BIT_H_ */
