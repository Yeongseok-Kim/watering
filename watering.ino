#include <U8glib.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

int pump = 4;

int moisture;

void setup() {
  pinMode(pump, OUTPUT);
  
  u8g.setFont(u8g_font_unifont);
  u8g.setColorIndex(1);
  
}

void loop() {
  moisture = analogRead(A0);
  
  u8g.firstPage();
  do {
    draw_oled();
  } while(u8g.nextPage());
  
  water();
  
  delay(50);
}

void draw_oled(){
  u8g.setPrintPos(2, 20);
  u8g.print(moisture);
}

void water(){
  if (moisture > 500){
    digitalWrite(pump, HIGH);
  } else {
    digitalWrite(pump, LOW);      
  }
}
