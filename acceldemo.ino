
// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// I2C: Name the object
Adafruit_LIS3DH lis = Adafruit_LIS3DH();


// the setup function runs once when you press reset or power on the board
void setup(void) {
  Serial.begin(115200);
  while (!Serial) delay(10);     // will pause board until serial console opens

  Serial.println("LIS3DH test!");

  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1) yield();
  }
  Serial.println("LIS3DH found!");

  // lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!

  Serial.print("Range = "); Serial.print(2 << lis.getRange());
  Serial.println("G");

  // lis.setDataRate(LIS3DH_DATARATE_50_HZ);
  Serial.print("Data rate set to: ");
  switch (lis.getDataRate()) {
    case LIS3DH_DATARATE_1_HZ: Serial.println("1 Hz"); break;
    case LIS3DH_DATARATE_10_HZ: Serial.println("10 Hz"); break;
    case LIS3DH_DATARATE_25_HZ: Serial.println("25 Hz"); break;
    case LIS3DH_DATARATE_50_HZ: Serial.println("50 Hz"); break;
    case LIS3DH_DATARATE_100_HZ: Serial.println("100 Hz"); break;
    case LIS3DH_DATARATE_200_HZ: Serial.println("200 Hz"); break;
    case LIS3DH_DATARATE_400_HZ: Serial.println("400 Hz"); break;

    case LIS3DH_DATARATE_POWERDOWN: Serial.println("Powered Down"); break;
    case LIS3DH_DATARATE_LOWPOWER_5KHZ: Serial.println("5 Khz Low Power"); break;
    case LIS3DH_DATARATE_LOWPOWER_1K6HZ: Serial.println("16 Khz Low Power"); break;
  }
  // initialize digital pin 13 as output for blinking
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  lis.read();      // get X Y and Z data at once
  // Then print X,Y,Z positions
  //Serial.print("X:  "); Serial.print(lis.x);
  //Serial.print("  \tY:  "); Serial.print(lis.y);
  //Serial.print("  \tZ:  "); Serial.print(lis.z);

  /* Or....get a new sensor event, normalized */
  sensors_event_t event;
  lis.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("\t\tX: "); Serial.print(event.acceleration.x);
  Serial.print(" \tY: "); Serial.print(event.acceleration.y);
  Serial.print(" \tZ: "); Serial.print(event.acceleration.z);
  Serial.println(" m/s^2 ");

  Serial.println();
  // statement to make blink if z acceleration goes below 1
  // note need to hold flat
  if (abs(event.acceleration.z) + abs(event.acceleration.y) + abs(event.acceleration.x) < 1) {
    int blinkcount = 0;
    while (blinkcount < 5) {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);              // delay(ms)
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(100);              // wait for a second
    blinkcount += 1;
  
    }
  }

  
  delay(200);
}
