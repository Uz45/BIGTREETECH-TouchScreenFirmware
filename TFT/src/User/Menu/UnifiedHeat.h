#ifndef _UNIFIEDHEAT_H_
#define _UNIFIEDHEAT_H_

typedef enum
{
  BOTH = 0,
  BED_PREHEAT = 1,
  NOZZLE0_PREHEAT = 2,
}TOOLPREHEAT;

void menuUnifiedHeat(void);

#endif
