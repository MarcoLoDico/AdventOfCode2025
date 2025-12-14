#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {
  int64_t low;
  int64_t high;
} Range;

// This is hardcoded but works for AOC
#define MAXRANGES 200

static int comparisonFunction(const void *a, const void *b){
  const Range *first = (const Range *)a;
  const Range *second = (const Range *)b;
  if (first->low < second->low) {
    return -1;
  } else if (first->low > second->low){
    return 1;
  } else if (first->high < second->high){
    return -1;
  } else if (first->high > second->high){
    return 1;
  } else {
    return 0;
  }
}

int main(void){
  FILE *fp = fopen("input.txt", "r");

  Range ranges[MAXRANGES];
  
  char line[256];
  int rangeLength = 0;

  while(fgets(line, sizeof(line), fp)) {
    sscanf(line, "%" SCNd64 "-%" SCNd64, &ranges[rangeLength].low, &ranges[rangeLength].high);
    ++rangeLength;
  }

  fclose(fp);

  qsort(ranges, rangeLength, sizeof(Range), comparisonFunction);

  int64_t total = 0;

  int i = 0;
  while(i < rangeLength){
    int64_t currentLow = ranges[i].low;
    int64_t currentHigh = ranges[i].high;
    ++i;

    // This loop continues while there is an overlap
    while(i < rangeLength && currentHigh >= ranges[i].low){
      if (currentHigh < ranges[i].high){
        currentHigh = ranges[i].high;
      }
      ++i;
    }

    total += (currentHigh - currentLow + 1);
  }

  printf("%" PRId64 "\n", total);

  return 0;
}