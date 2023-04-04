#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <Adafruit_GFX.h>    // Core graphics library

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3    // Chip Select goes to Analog 3
#define LCD_CD A2    // Command/Data goes to Analog 2
#define LCD_WR A1    // LCD Write goes to Analog 1
#define LCD_RD A0    // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Color definitions
#define COLOR_BLACK 0x0000       ///<   0,   0,   0
#define COLOR_WHITE 0xFFFF     ///< 255, 255, 255

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

const int SCREEN_WIDTH  = tft.width();
const int SCREEN_HEIGHT = tft.height();

void setup(void) {
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);

  drawHermannGrid();
}

void loop(void) {

}

void drawHermannGrid() {
  int gridSize = 10;
  int squareSize = 10;
  int lineWidth = 2;

  clearScreen();

  // Draw vertical lines
  for (int i = 0; i <= gridSize; i++) {
    tft.fillRect(i * (squareSize + lineWidth), 0, lineWidth, SCREEN_HEIGHT, COLOR_WHITE);
  }

  // Draw horizontal lines
  for (int i = 0; i <= gridSize; i++) {
    tft.fillRect(0, i * (squareSize + lineWidth), SCREEN_WIDTH, lineWidth, COLOR_WHITE);
  }
}

void clearScreen(void)
{
  tft.fillScreen(COLOR_BLACK);
}