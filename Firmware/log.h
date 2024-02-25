#ifndef _LOG_H  // somehow LOG_H is already defined!?
#define _LOG_H

#include "nrf_log.h"

#define ERROR_CHECK(FUNCTION, CODE)                          \
  do {                                                       \
    if (CODE != NRF_SUCCESS) {                               \
      const char* strerror = nrf_strerror_find(CODE);        \
      if (strerror == NULL) {                                \
        NRF_LOG_ERROR("%s returned 0x%x", FUNCTION, CODE);   \
      } else {                                               \
        NRF_LOG_ERROR("%s returned %s", FUNCTION, strerror); \
      }                                                      \
    }                                                        \
  } while (0)

void log_init(void);

#endif  // _LOG_H
