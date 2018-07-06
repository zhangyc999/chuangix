#ifndef BIT_H_
#define BIT_H_

#define LITTLE_ENDIAN

#define BIT_FIND_0(x)

#define BIT_FIND_1(x)

#define BIT_FIND_DIFF(x)

#define BIT_FIND_IDEN(x)

#define BIT_SEARCH_0(x)

#define BIT_SEARCH_1(x)

#define BIT_SEARCH_DIFF(x)

#define BIT_SEARCH_IDEN(x)

#define BIT_SET(x, mask)

#define BIT_CLR(x, mask)

#define BIT_REV(x, mask)

#define BIT_SET_Nth(x, n)

#define BIT_CLR_Nth(x, n)

#define BIT_REV_Nth(x, n)

#define BIT_INV(x)

#define BIT_ENDIAN_SWAP(x)

#ifdef LITTLE_ENDIAN
#define BIT_GET_SIGN(x) \
        (((signed char *)&x)[sizeof(x) - 1] >> 7 | 1)
#endif

#ifdef BIG_ENDIAN
#define BIT_GET_SIGN(x) \
        (((signed char *)&x)[0] >> 7 | 1)
#endif

#endif /* BIT_H_ */
