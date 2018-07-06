#ifndef BIT_H_
#define BIT_H_

#define LITTLE_ENDIAN

#ifdef LITTLE_ENDIAN
#define BIT_GET_SIGN(x) \
        (((signed char *)&x)[sizeof(x) - 1] >> 7 | 1)
#endif

#ifdef BIG_ENDIAN
#define BIT_GET_SIGN(x) \
        (((signed char *)&x)[0] >> 7 | 1)
#endif

#endif /* BIT_H_ */
