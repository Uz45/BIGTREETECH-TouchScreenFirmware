#include "ui_draw.h"
#include "includes.h"

#ifdef STM32_HAS_FSMC

void lcd_frame_display(u16 sx,u16 sy,u16 w,u16 h, u32 addr);

#else

void lcd_frame_display(u16 sx,u16 sy,u16 w,u16 h, u32 addr)
{
  u16 x,y;
  u16 color = 0;
  u32 address = addr;

  LCD_SetWindow(sx,sy,sx+w-1,sy+h-1);
#if defined MKS_32_V1_3 || defined MKS_32_V1_1
  LCD_WR_REG(0x22); 
#else
  LCD_WR_REG(0x2C);
#endif

  W25Qxx_SPI_CS_Set(0);
  W25Qxx_SPI_Read_Write_Byte(CMD_READ_DATA);
  W25Qxx_SPI_Read_Write_Byte((address & 0xFF0000) >> 16);
  W25Qxx_SPI_Read_Write_Byte((address& 0xFF00) >> 8);
  W25Qxx_SPI_Read_Write_Byte(address & 0xFF);

  for(y=sy; y<sy+h; y++)
  {	
    for(x=sx; x<sx+w; x++)
    {
      color  = (W25Qxx_SPI_Read_Write_Byte(W25QXX_DUMMY_BYTE)<<8);
      color |= W25Qxx_SPI_Read_Write_Byte(W25QXX_DUMMY_BYTE);
      LCD_WR_16BITS_DATA(color);
    }
  }		
  W25Qxx_SPI_CS_Set(1);		
}
#endif

void LOGO_ReadDisplay(void)
{
     lcd_frame_display((LCD_WIDTH/2-(ICON_WIDTH/2)), (LCD_HEIGHT/2-(ICON_HEIGHT/2)), ICON_WIDTH, ICON_HEIGHT, LOGO_ADDR);
}

void ICON_ReadDisplay(u16 sx,u16 sy, u8 icon)
{
  lcd_frame_display(sx, sy, ICON_WIDTH, ICON_HEIGHT, ICON_ADDR(icon));
}

//draw icon with different length and width (sx & sy cordinates for top left of icon, w width, h height, addr flash byte address)
void ICON_CustomReadDisplay(u16 sx,u16 sy,u16 w, u16 h, u32 addr)
{
  lcd_frame_display(sx, sy, w, h, addr);
}

void SMALLICON_ReadDisplay(u16 sx,u16 sy, u8 icon)
{
  lcd_frame_display(sx, sy, SMALLICON_WIDTH, SMALLICON_HEIGHT, SMALL_ICON_ADDR(icon));
}

void ICON_PressedDisplay(u16 sx,u16 sy, u8 icon)
{
  u16 mode=0x0FF0;
  u16 x,y;
  u16 color = 0;
  u32 address = ICON_ADDR(icon);

  LCD_SetWindow(sx, sy, sx+ICON_WIDTH-1, sy+ICON_HEIGHT-1);
#if defined MKS_32_V1_3 || defined MKS_32_V1_1
  LCD_WR_REG(0x22); 
#else
  LCD_WR_REG(0x2C);
#endif

  W25Qxx_SPI_CS_Set(0);
  W25Qxx_SPI_Read_Write_Byte(CMD_READ_DATA);
  W25Qxx_SPI_Read_Write_Byte((address & 0xFF0000) >> 16);
  W25Qxx_SPI_Read_Write_Byte((address& 0xFF00) >> 8);
  W25Qxx_SPI_Read_Write_Byte(address & 0xFF);

  for(y=sy; y<sy+ICON_HEIGHT; y++)
  {	
    for(x=sx; x<sx+ICON_WIDTH; x++)
    {
      color  = (W25Qxx_SPI_Read_Write_Byte(W25QXX_DUMMY_BYTE)<<8);
      color |= W25Qxx_SPI_Read_Write_Byte(W25QXX_DUMMY_BYTE);
      LCD_WR_16BITS_DATA(color & mode);
    }
  }		
  W25Qxx_SPI_CS_Set(1);		
}
