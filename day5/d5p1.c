#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct {
  int64_t low;
  int64_t high;
} Range;

// This is hardcoded but works for AOC
#define MAXRANGES 200
#define MAXVALUES 1001

int main(void){
  FILE *fp = fopen("input.txt", "r");

  Range ranges[MAXRANGES];
  int64_t values[MAXVALUES];
  
  char line[256];
  int isRange = 1;

  int rangeLength = 0;
  int valueLength = 0;

  while(fgets(line, sizeof(line), fp)) {
    if (line[0] == '\n') { // Blank line
      isRange = 0;
      continue;
    }

    if (isRange){
      // Was not used to taking inputs through files in C, versus through command line args.
      // Could have used command line for this but seemed interesting to learn about file input in C
      // https://en.wikipedia.org/wiki/Scanf so learend about macros like SCNd64 and portability
      sscanf(line, "%" SCNd64 "-%" SCNd64, &ranges[rangeLength].low, &ranges[rangeLength].high);
      ++rangeLength;
    } else {
      sscanf(line, "%" SCNd64, &values[valueLength]);
      ++valueLength;
    }
  }

  fclose(fp);

  int numberOfFresh = 0;

  for (int i = 0; i < valueLength; ++i){
    for (int j = 0; j < rangeLength; ++j){
      if (values[i] <= ranges[j].high && values[i] >= ranges[j].low){
        ++numberOfFresh;
        break;
      }
    }
  }

  printf("%d\n", numberOfFresh);

  return 0;
}