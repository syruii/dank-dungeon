#include "randint.h"
#include <assert.h>

int randint(int n) { //does this random function even work - it does
   if ((n-1) == RAND_MAX) {
      return rand();
   } else {
      long end = RAND_MAX / n;
      assert (end > 0L);
      end *=n;
      int r;
      while ((r = rand()) >= end);

      return r % n;
   }
}
