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
  u8g.firstPage();
  moisture = analogRead(A0);
  do {
    u8g.setPrintPos(0, 20);
    u8g.print(moisture);
    if (moisture > 500){
      digitalWrite(pump, HIGH);
    } else {
      digitalWrite(pump, LOW);      
    }
  } while(u8g.nextPage());
  delay(50);
}
