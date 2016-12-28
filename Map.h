uint8_t levels[NUM_LEDS] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4 };

uint8_t zCoords[NUM_LEDS] = { 0, 0, 0, 0, 0, 64, 64, 64, 64, 64, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 192, 192, 192, 192, 192, 255, 255, 255, 255, 255 };

uint8_t angles[NUM_LEDS] = { 0, 51, 102, 154, 205, 26, 77, 128, 179, 230, 13, 38, 64, 90, 115, 141, 166, 192, 218, 243, 0, 51, 102, 154, 205, 26, 77, 128, 179, 230 };

void fallingRainbow() {
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(zCoords[i] / 6 - beat8(speed), 255, 255);
  }
}

void risingRainbow() {
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(zCoords[i] / 6 + beat8(speed), 255, 255);
  }
}

void rotatingRainbow()
{
  for (uint8_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(angles[i] + beat8(speed), 255, 255);
  }
}


void fallingPalette() {
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(gCurrentPalette, zCoords[i] / 8 - beat8(speed));
  }
}

void risingPalette() {
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(gCurrentPalette, zCoords[i] / 8 + beat8(speed));
  }
}

void rotatingPalette()
{
  for (uint8_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = ColorFromPalette(gCurrentPalette, angles[i] + beat8(speed));
  }
}
