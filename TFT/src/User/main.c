#include "includes.h"

HOST  infoHost;  // Information interaction with Marlin
MENU  infoMenu;  // Menu structure

void Hardware_GenericInit(void)
{
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  Delay_init(F_CPUM);
  OS_TimerInit(9999, F_CPUM-1);  // System clock timer, cycle 10ms

  #ifdef DISABLE_DEBUG
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE); //disable JTAG & SWD
  #endif

  #ifdef DISABLE_JTAG
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
  #endif

  #if defined MKS_32_V1_4 || defined(MKS_32_V1_3) || defined(MKS_32_V1_1) 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_USART2, ENABLE);
  #endif

  XPT2046_Init();
  W25Qxx_Init();
  LCD_Init();
  readStoredPara();
  LCD_RefreshDirection();  //refresh display direction after reading settings
  scanUpdates();
#if defined (MKS_32_V1_4) || defined(MKS_32_V1_3) || defined(MKS_32_V1_1) 
#else
  //causes hang if we deinit spi1    
  SD_DeInit();
#endif
  #if LCD_ENCODER_SUPPORT
    LCD_EncoderInit();
  #endif

  #ifdef PS_ON_PIN
    PS_ON_Init();
  #endif

  #ifdef FIL_RUNOUT_PIN
    FIL_Runout_Init();
  #endif

  #ifdef LED_color_PIN
    knob_LED_Init();
  #else
    #define STARTUP_KNOB_LED_COLOR 1
  #endif

  if(readStoredPara() == false) // Read settings parameter
  {
    TSC_Calibration();
    storePara();
  }
  GUI_RestoreColorDefault();
  infoMenuSelect();
}

int main(void)
{
  SCB->VTOR = VECT_TAB_FLASH;

  Hardware_GenericInit();

  for(;;)
  {
    (*infoMenu.menu[infoMenu.cur])();
  }
}
