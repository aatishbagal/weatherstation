/**************************************************************************
  Progarm to control weather station 
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
int sensorValue;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

 // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
 //display.display();
 // delay(2000); // Pause for 2 seconds
  
  
 
  
}

void testdrawchar(int temp , int airQuality) {
  display.clearDisplay();
      // Normal 1:1 pixel scale
  
  int i = 17;
  display.setCursor(0, 0);     // Start at top-left corner
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  display.setTextSize(1);  
  display.println(F("   Weather Station   "));     
  display.setTextSize(1);  
  display.setCursor(5, i+0);     // Start at top-left corner
  display.setTextColor(SSD1306_WHITE); // Draw white text
  String tempDisplay = "Temperature - " + String(temp) + " C";
  display.println(tempDisplay);      
  display.setCursor(5, i+12);     // Start at top-left corner
  display.println(F("Humidity - 60 %"));      
  display.setCursor(5, i+24);     // Start at top-left corner
  String airQualityDispaly = "AirQuality - " + String(airQuality);
  display.println(airQualityDispaly);        
  display.setCursor(5, i+36);     // Start at top-left corner
  display.println(F("Raining - No"));        

  display.display();
  delay(1000);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(0); 
  Serial.print("AirQua=");
  Serial.print(sensorValue, DEC);               
  testdrawchar(10, sensorValue); 
  
}
