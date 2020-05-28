Для использования этой прошивки нужно поместить на SD карту файл bin, папку с ресурсами соответствующие
вашей версии экрана и файл "config.ini" содержащий настройки экрана и вашей машины.

 			Особенности использования этой прошивки с MKS TFT32L различных версий

V4.0
Папка с ресурсами - "MKS", скопировать целиком в корень SD.
Файл bin - "MKS_32_V1_4.xx.x.bin"

V3.0
Папка с ресурсами - "MKS", скопировать целиком в корень SD.
Файл bin - "MKS_32_V1_3.xx.x.bin"
На экранах этой версии встречается зеркальное отображение интерфейса, для устранения этого
в файле "config.ini" найти параметр "rotate_ui:0" и изменить его значение на "1".

V2.0
Папка с ресурсами - "MKSV2", скопировать целиком в корень SD.
Файл bin - "MKS_32_V1_2.xx.x.bin"
Нельзя использовать logo.bmp большого размера из за малого объема флэш памяти - 4MB.

V1.0
Папка с ресурсами - "MKSV1", скопировать целиком в корень SD.
Файл bin - "MKS_32_V1_1.xx.x.bin"
Нельзя использовать logo.bmp большого размера, шрифт word_unicode.fon не должен превышать 208KB, 
из за малого объема флэш памяти - 2MB. По этой причине часть языков в меню отображается некорректно.

Использование режима эмуляции 12864.
Для использования режима эмуляции необходимо припаять один провод к 89 ножке STM32, это PB3 pin для SPI3.

В файле для вашей версии экрана pin_MKS_TFT32_V1_X.h определить пины энкодера:

  #define LCD_ENCA_PIN  PA13 расположен на колодке JTAG сигнал DIO
  #define LCD_ENCB_PIN  PA14  расположен на колодке JTAG сигнал CLK
  #define LCD_BTN_PIN   PB0 

Подключение к управляющей плате на примере MKS Gen L V1.0:

	MKS TFT32								MKS Gen L V1.0 (Marlin pins)

 LCD_ENCA_PIN  PA13 		JTAG DIO	=>			exp2 D31-pin (BTN_EN1)
 LCD_ENCB_PIN  PA14 		JTAG CLK	=>			exp2 D33-pin (BTN_EN2)
 LCD_BTN_PIN   PB0 		PB0		=>			exp1 D35-pin (BTN_ENC)
 SPISIM_CS_PIN PB1 		PB1		=>			exp1 D16-pin (LCD_PINS_RS)
 SPI3_SCK_PIN  PB3 		PB3 		=>			exp1 D23-pin (LCD_PINS_D4)
 SPI3_MOSI_PIN PB5 		PB5		=>			exp1 D17-pin (LCD_PINS_ENABLE)

Настройки Marlin.

Тип контроллера LCD выбираем
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

  Из особых настроек мне понадобилась только одна
#define ENCODER_PULSES_PER_STEP 3

Подключение к управляющей плате на примере SKR V1.3
                _____                                              _____
            NC | 1 2 | GND                                     5V | 1 2 | GND
         RESET | 3 4 | 1.31 (SD_DETECT)             (LCD_D7) 1.23 | 3 4 | 1.22 (LCD_D6)
   (MOSI) 0.18 | 5 6   3.25 (BTN_EN2)               (LCD_D5) 1.21 | 5 6   1.20 (LCD_D4)
  (SD_SS) 0.16 | 7 8 | 3.26 (BTN_EN1)               (LCD_RS) 1.19 | 7 8 | 1.18 (LCD_EN)
    (SCK) 0.15 | 9 10| 0.17 (MISO)                 (BTN_ENC) 0.28 | 9 10| 1.30 (BEEPER)
                -----                                              -----
                 EXP2                                               EXP1


	MKS TFT32								SKR V1.3 (Marlin pins)

 LCD_ENCA_PIN  PA13 		JTAG DIO	=>			EXPA2_08_PIN (BTN_EN1)
 LCD_ENCB_PIN  PA14 		JTAG CLK	=>			EXPA2_06_PIN (BTN_EN2)
 LCD_BTN_PIN   PB0 		PB0		=>			EXPA2_07_PIN (BTN_ENC)
 SPISIM_CS_PIN PB1 		PB1		=>			EXPA2_04_PIN (LCD_PINS_RS)
 SPI3_SCK_PIN  PB3 		PB3 		=>			EXPA2_09_PIN (LCD_PINS_D4)
 SPI3_MOSI_PIN PB5 		PB5		=>			EXPA2_05_PIN (LCD_PINS_ENABLE)
 
Настройки Marlin.

	Тип контроллера LCD - #define CR10_STOCKDISPLAY

	В файле pins_BTT_SKR_V1_3.h определяем пины для подключения экрана
	
  #elif ENABLED(CR10_STOCKDISPLAY)

    #define LCD_PINS_RS             EXPA2_04_PIN  //CS
    #define BTN_EN1                 EXPA2_08_PIN
    #define BTN_EN2                 EXPA2_06_PIN
    #define BTN_ENC                 EXPA2_07_PIN  // (58) open-drain  EXPA1_09_PIN
    #define LCD_PINS_ENABLE         EXPA2_05_PIN // EXPA1_03_PIN  //MOSI
    #define LCD_PINS_D4             EXPA2_09_PIN // EXPA1_05_PIN  //CLK

Для стабильной работы энкодера мне понадобилась дополнительная настройка	
#define ENCODER_PULSES_PER_STEP 3

	Вход в режим эмуляции 12864 осуществляется долгим нажатием на экран.
Управление курсором и изменения параметров осуществляется свайпами вверх-вниз по правому краю экрана, кнопка ОК находится в верхнем правом углу экрана.






To use this firmware, you need to put on your SD card your bin file, your folder with resources corresponding to your screen version, and a "config.ini" file containing the settings of the screen and your machine.

Features of using this firmware with MKS TFT32L

V4.0
The resource folder is - "MKS" copy the entire folder to the SD root.
Bin file - " MKS_32_V1_4.xx.x.bin"

V3.0
The resource folder is - "MKS" copy the entire folder to the SD root.
Bin file - " MKS_32_V1_3.xx.x.bin"
 On some screens in this version, the screen is mirrored, in the "config.ini" file, find the "rotate_ui:0" parameter "0" and change its value to "1".

V2.0
The resource folder is - "MKSV2", copy the entire folder to the SD root.
Bin file - " MKS_32_V1_2.xx.x.bin"
You can't use "logo.bmp" of large size due to the small amount of flash memory - 4MB.

V1.0
The resource folder is - "MKSV1", copy the entire folder to the SD root.
Bin file - " MKS_32_V1_1.xx.x.bin"
 You can't use "logo.bmp" has a big size, the font word_unicode.fon must not exceed 208KB, due to 
a small amount of flash memory - 2MB. For this reason, some of the languages in the menu are displayed incorrectly.

The use of emulation mode 12864.
 To use the emulation mode, you need to solder one wire to the STM32 89 pin, this is the PB3 pin for SPI3.

In the file for your screen version pin_MKS_TFT32_V1_X.h define the encoder pins:

#define LCD_ENCA_PIN PA13 is located on the JTAG signal DIO
#define LCD_ENCB_PIN PA14 is located on the JTAG signal CLK
#define LCD_BTN_PIN PB0

Connecting to the printer Board:
for example, MKS Gen L V1. 0

	MKS TFT32								MKS Gen L V1.0 (Marlin pins)

 LCD_ENCA_PIN  PA13 		JTAG DIO	=>			exp2 D31-pin (BTN_EN1)
 LCD_ENCB_PIN  PA14 		JTAG CLK	=>			exp2 D33-pin (BTN_EN2)
 LCD_BTN_PIN   PB0 		PB0		=>			exp1 D35-pin (BTN_ENC)
 SPISIM_CS_PIN PB1 		PB1		=>			exp1 D16-pin (LCD_PINS_RS)
 SPI3_SCK_PIN  PB3 		PB3 		=>			exp1 D23-pin (LCD_PINS_D4)
 SPI3_MOSI_PIN PB5 		PB5		=>			exp1 D17-pin (LCD_PINS_ENABLE)
 
 Marlin settings.

Select the type of LCD controller
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

  Define one of the special settings
#define ENCODER_PULSES_PER_STEP 3

Connecting to the printer Board:
for example, SKR V1.3

                _____                                              _____
            NC | 1 2 | GND                                     5V | 1 2 | GND
         RESET | 3 4 | 1.31 (SD_DETECT)             (LCD_D7) 1.23 | 3 4 | 1.22 (LCD_D6)
   (MOSI) 0.18 | 5 6   3.25 (BTN_EN2)               (LCD_D5) 1.21 | 5 6   1.20 (LCD_D4)
  (SD_SS) 0.16 | 7 8 | 3.26 (BTN_EN1)               (LCD_RS) 1.19 | 7 8 | 1.18 (LCD_EN)
    (SCK) 0.15 | 9 10| 0.17 (MISO)                 (BTN_ENC) 0.28 | 9 10| 1.30 (BEEPER)
                -----                                              -----
                 EXP2                                               EXP1


	MKS TFT32								SKR V1.3 (Marlin pins)

 LCD_ENCA_PIN  PA13 		JTAG DIO	=>			EXPA2_08_PIN (BTN_EN1)
 LCD_ENCB_PIN  PA14 		JTAG CLK	=>			EXPA2_06_PIN (BTN_EN2)
 LCD_BTN_PIN   PB0 		PB0		=>			EXPA2_07_PIN (BTN_ENC)
 SPISIM_CS_PIN PB1 		PB1		=>			EXPA2_04_PIN (LCD_PINS_RS)
 SPI3_SCK_PIN  PB3 		PB3 		=>			EXPA2_09_PIN (LCD_PINS_D4)
 SPI3_MOSI_PIN PB5 		PB5		=>			EXPA2_05_PIN (LCD_PINS_ENABLE)
 
	Select the type of LCD controller 
 #define CR10_STOCKDISPLAY
In the file "pins_BTT_SKR_V1_3.h" define pins:
  #elif ENABLED(CR10_STOCKDISPLAY)

    #define LCD_PINS_RS             EXPA2_04_PIN  //CS
    #define BTN_EN1                 EXPA2_08_PIN
    #define BTN_EN2                 EXPA2_06_PIN
    #define BTN_ENC                 EXPA2_07_PIN  // (58) open-drain  EXPA1_09_PIN
    #define LCD_PINS_ENABLE         EXPA2_05_PIN // EXPA1_03_PIN  //MOSI
    #define LCD_PINS_D4             EXPA2_09_PIN // EXPA1_05_PIN  //CLK
	
  Define one of the special settings
#define ENCODER_PULSES_PER_STEP 3

You can enter 12864 emulation mode by long tapping on the screen.
	Cursor control and parameter changes are performed by swiping up and down on the right edge of the screen. the OK button is located in the upper-right corner of the screen.
