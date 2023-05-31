#include <M5Core2.h>
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor; //VL53L0X　"sensor"として操作することを宣言している。

void setup() {
  M5.begin();
  //M5.Power.begin();
  Wire.begin();// I2C通信を開始する
  sensor.init();
  sensor.startContinuous();  //  連続測定を開始
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.setTextSize(4);
}
void loop() {
  int distance = sensor.readRangeContinuousMillimeters(); //センサデータの取得(mm単位)
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print(distance);
  M5.Lcd.print("  [mm]  ");

}
