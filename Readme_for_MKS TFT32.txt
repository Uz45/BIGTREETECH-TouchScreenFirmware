����������� ������������� ���� �������� � MKS TFT32L

V4.0
����� � ��������� ���������� MKS, ����������� ������� � ������ SD.

V3.0
����� � ��������� ���������� MKS, ����������� ������� � ������ SD.
�� ��������� ������� ���� ������ ����������� ���������� ����������� ������, � ����� variants.h ����� � ���������������� ������ #define MKSTFTV3 . ������ ��������� ��� //#define MKSTFTV3 .

V2.0
����� � ��������� ���������� MKSV2, ����������� ������� � ������ SD.
������ ������������ logo.bmp �������� ������� �� �� ������ ������ ���� ������ - 4MB.

V1.0
����� � ��������� ���������� MKSV1, ����������� ������� � ������ SD.
������ ������������ logo.bmp �������� �������, ����� word_unicode.fon �� ������ ��������� 208KB, �� �� ������ ������ ���� ������ - 2MB. �� ���� ������� ����� ������ � ���� ������������ �����������.

������������� ������ �������� 12864.
��� ������������� ������ �������� ���������� �������� ���� ������ � 89 ����� STM32, ��� PB3 pin ��� SPI3.

� ����� variants.h ���������� ���� ��������:

  #define LCD_ENCA_PIN  PA13 ���������� �� ������� JTAG ������ DIO
  #define LCD_ENCB_PIN  PA14  ���������� �� ������� JTAG ������ CLK
  #define LCD_BTN_PIN   PB0 

����������� � ����������� �����:

�� ������� MKS Gen L V1.0

	MKS TFT32				MKS Gen L V1.0 (Marlin pins)

 LCD_ENCA_PIN  PA13 	JTAG DIO		=>	exp2 D31-pin (BTN_EN1)
 LCD_ENCB_PIN  PA14 	JTAG CLK		=>	exp2 D33-pin (BTN_EN2)
 LCD_BTN_PIN    PB0 	PB0		=>	exp1 D35-pin (BTN_ENC)
 SPISIM_CS_PIN    PB1 	PB1		=>	exp1 D16-pin (LCD_PINS_RS)
 SPI3_SCK_PIN  PB3 	PB3 		=>	exp1 D23-pin (LCD_PINS_D4)
 SPI3_MOSI_PIN  PB5 	PB5		=>	exp1 D17-pin (LCD_PINS_ENABLE)




Features of using this firmware with MKS TFT32L

V4.0

The resource folder is called MKS copy the entire folder to the SD root.

V3.0

The resource folder is called MKS copy the entire folder to the SD root.
 Some screens in this version have a mirror image of the screen, in the file variants.h find and comment the #define MKSTFTV3 string . It should look like this // #define MKSTFTV3 .

V2.0

The resource folder is called MKSV2, copy the entire folder to the SD root.
You can't use logo.bmp of large size due to the small amount of flash memory - 4MB.

V1.0

The resource folder is called MKSV1, copy the entire folder to the SD root.
 You can't use logo.bmp has a big size, the font word_unicode.fon must not exceed 208KB, due to 

a small amount of flash memory - 2MB. For this reason, some of the languages in the menu are displayed incorrectly.

The use of emulation mode 12864.
 To use the emulation mode, you need to solder one wire to the stm32 89 leg, this is the PB3 pin for SPI3.

In the file variants.h determine the encoder pins:

#define LCD_ENCA_PIN PA13 is located on the JTAG signal DIO
#define LCD_ENCB_PIN PA14 is located on the JTAG signal CLK
#define LCD_BTN_PIN PB0

Connecting to the printer Board:
for example, MKS Gen L V1. 0

	MKS TFT32				MKS Gen L V1.0 (Marlin pins)

 LCD_ENCA_PIN  PA13 	JTAG DIO		=>	exp2 D31-pin (BTN_EN1)
 LCD_ENCB_PIN  PA14 	JTAG CLK		=>	exp2 D33-pin (BTN_EN2)
 LCD_BTN_PIN    PB0 	PB0		=>	exp1 D35-pin (BTN_ENC)
 SPISIM_CS_PIN    PB1 	PB1		=>	exp1 D16-pin (LCD_PINS_RS)
 SPI3_SCK_PIN  PB3 	PB3 		=>	exp1 D23-pin (LCD_PINS_D4)
 SPI3_MOSI_PIN  PB5 	PB5		=>	exp1 D17-pin (LCD_PINS_ENABLE)
