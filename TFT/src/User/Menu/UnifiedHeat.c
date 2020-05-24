#include "UnifiedHeat.h"
#include "includes.h"

STRINGS_STORE * preheatnames;

const ITEM itemToolPreheatU[] = {
// icon                       label
  {ICON_PREHEAT_BOTH,         LABEL_PREHEAT_BOTH},
  {ICON_BED,                  LABEL_BED},
  {ICON_NOZZLE,               LABEL_NOZZLE},
  {ICON_NOZZLE,               LABEL_NOZZLE},
  {ICON_NOZZLE,               LABEL_NOZZLE},
  {ICON_NOZZLE,               LABEL_NOZZLE},
  {ICON_NOZZLE,               LABEL_NOZZLE},
  {ICON_NOZZLE,               LABEL_NOZZLE},
};

void drawPreheatNamesU(void)
{
    for (int i = 0;i < PREHEAT_COUNT;i++)
  {
    const GUI_RECT *rect;
    rect = rect_of_key + ITEM_PER_PAGE + i;
    GUI_ClearPrect(rect);

    GUI_DispStringInPrect(rect, (u8*)preheatnames->preheat_name[i]);
  }
}

void menuUnifiedHeat(void)
{
  MENUITEMS UnifiedHeatItems = {
// title
LABEL_UNIFIEDHEAT,
// icon                       label
 {
  {ICON_PREHEAT_PLA,          LABEL_BACKGROUND},
  {ICON_PREHEAT_PETG,         LABEL_BACKGROUND},
  {ICON_PREHEAT_ABS,          LABEL_BACKGROUND},
  {ICON_PREHEAT_BOTH,         LABEL_PREHEAT_BOTH},
  {ICON_HEAT,                 LABEL_HEAT},
  {ICON_COOLDOWN,             LABEL_COOLDOWN},
  {ICON_FAN,                  LABEL_FAN},
  {ICON_BACK,                 LABEL_BACK},
 }
};

  Buzzer_TurnOn(1,1); //Sound off

  preheatnames = (STRINGS_STORE*)malloc(sizeof(STRINGS_STORE));
  uint8_t *data_p = (uint8_t *)preheatnames;
  W25Qxx_ReadBuffer(data_p,STRINGS_STORE_ADDR,sizeof(STRINGS_STORE));

  static TOOLPREHEAT nowHeater = BOTH;

  KEY_VALUES key_num = KEY_IDLE;
  menuDrawPage(&UnifiedHeatItems);
  drawPreheatNamesU();
  while(infoMenu.menu[infoMenu.cur] == menuUnifiedHeat)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
      case KEY_ICON_0:
      case KEY_ICON_1:
      case KEY_ICON_2:
        switch(nowHeater)
        {
          case BOTH:
            heatSetTargetTemp(BED, infoSettings.preheat_bed[(key_num)]);
            heatSetTargetTemp(heatGetCurrentToolNozzle(), infoSettings.preheat_temp[key_num]);
            break;
          case BED_PREHEAT:
            heatSetTargetTemp(BED, infoSettings.preheat_bed[(key_num)]);
            break;
          case NOZZLE0_PREHEAT:
            heatSetTargetTemp(heatGetCurrentToolNozzle(), infoSettings.preheat_temp[(key_num)]);
            break;
        }
         drawPreheatNamesU();
        break;

      case KEY_ICON_3: 
        nowHeater = (TOOLPREHEAT)((nowHeater+1) % 3);
        UnifiedHeatItems.items[key_num] = itemToolPreheatU[nowHeater];
        menuDrawItem(&UnifiedHeatItems.items[key_num], key_num);
        break;

      case KEY_ICON_4: infoMenu.menu[++infoMenu.cur] = menuHeat;    break;
      case KEY_ICON_5:
        for(TOOL i = BED; i < HEATER_COUNT; i++)
        {
          heatSetTargetTemp(i, 0);
        }
        break;

      case KEY_ICON_6: infoMenu.menu[++infoMenu.cur] = menuFan;    break;

      case KEY_ICON_7: infoMenu.cur--;      break;
      default:break;
    }
    loopProcess();
  }
}
