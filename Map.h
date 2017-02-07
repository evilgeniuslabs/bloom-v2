uint8_t levels[NUM_LEDS] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4 };

uint8_t zCoords[NUM_LEDS] = { 0, 0, 0, 0, 0, 64, 64, 64, 64, 64, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 192, 192, 192, 192, 192, 255, 255, 255, 255, 255 };

uint8_t angles[NUM_LEDS] = { 0, 51, 102, 154, 205, 26, 77, 128, 179, 230, 13, 38, 64, 90, 115, 141, 166, 192, 218, 243, 0, 51, 102, 154, 205, 26, 77, 128, 179, 230 };

const uint8_t starCount = 12;
const uint8_t starLength = 5;

uint8_t stars[starCount][starLength] = {
  { 0, 1, 2, 3, 4 },
  { 0, 5, 6, 11, 12 },
  { 1, 6, 7, 13, 14 },
  { 2, 7, 8, 15, 16 },
  { 3, 8, 9, 17, 18 },
  { 4, 5, 9, 10, 19 },
  { 10, 11, 20, 21, 26 },
  { 12, 13, 21, 22, 27 },
  { 14, 15, 22, 23, 28 },
  { 16, 17, 23, 24, 29 },
  { 18, 19, 20, 24, 25 },
  { 25, 26, 27, 28, 29 }
};

const uint8_t triCount = 20;
const uint8_t triLength = 3;

uint8_t tris[triCount][triLength] = {
  { 0, 1, 6 },
  { 1, 2, 7 },
  { 2, 3, 8 },
  { 3, 4, 9 },
  { 0, 4, 5 },
  { 5, 10, 11 },
  { 6, 12, 13 },
  { 7, 14, 15 },
  { 8, 16, 17 },
  { 9, 18, 19 },
  { 10, 19, 20 },
  { 11, 12, 21 },
  { 13, 14, 22 },
  { 15, 16, 23 },
  { 17, 18, 24 },
  { 20, 25, 26 },
  { 21, 26, 27 },
  { 22, 27, 28 },
  { 23, 28, 29 },
  { 24, 25, 29 }
};

void paletteStars() {
  dimAll(240);

  static uint8_t star = 0;

  EVERY_N_MILLIS_I(speedTimer, 255 - speed) {
    speedTimer.setPeriod(255 - speed);
    star++;
    if (star >= starCount) {
      star = 0;
    }
  }

  for (uint8_t i = 0; i < starLength; i++) {
    leds[stars[star][i]] = ColorFromPalette(gCurrentPalette, gHue);
  }
}

void paletteTris() {
  dimAll(240);

  static uint8_t tri = 0;

  EVERY_N_MILLIS_I(speedTimer, 255 - speed) {
    speedTimer.setPeriod(255 - speed);
    tri++;
    if (tri >= triCount) {
      tri = 0;
    }
  }

  for (uint8_t i = 0; i < triLength; i++) {
    leds[tris[tri][i]] = ColorFromPalette(gCurrentPalette, gHue);
  }
}

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
