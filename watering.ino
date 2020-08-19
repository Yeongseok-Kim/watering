#include <U8glib.h>
#define DRY 500

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

int pump = 4;
int moisture[4];
int relay[4] = {6, 8, 9, 10};

void setup() {
  pinMode(pump, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(relay[i], OUTPUT);
  }
  u8g.setFont(u8g_font_unifont);
  u8g.setColorIndex(1);
}

void loop() {
  Check();
  Draw();
  Water();
  delay(50);
}

void Draw(){
  u8g.firstPage();
  do {
    u8g.setPrintPos(0, 20);
    u8g.print(moisture[0]); u8g.print(" "); u8g.print(moisture[1]); u8g.print(" ");
    u8g.print(moisture[2]); u8g.print(" "); u8g.print(moisture[3]);
  } while(u8g.nextPage());
}

void Check(){
  moisture[0] = analogRead(A0);
  moisture[1] = analogRead(A1);
  moisture[2] = analogRead(A2);
  moisture[3] = analogRead(A3);
}

void Valve(){
  for (int i = 0; i < 4; i++) {
    if (moisture[i] > DRY) {
      digitalWrite(relay[i], HIGH);
    } else {
      digitalWrite(relay[i], LOW);
    }
  }
}

void Pump(){
  if (moisture[0] > DRY || moisture[1] > DRY ||
      moisture[2] > DRY || moisture[3] > DRY){
    digitalWrite(pump, HIGH);
  } else {
    digitalWrite(pump, LOW);      
  }
}

void Water(){
  Pump();
  Valve();
}
