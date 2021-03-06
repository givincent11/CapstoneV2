//TMP36 Pin Variables
int sensorPin = 18; //the analog pin the TMP36's Vout (sense) pin is connected to: A0 (aka 18)
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
 
/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
}
 
void loop()                     // run over and over again
{
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3 (Feathers work on 3.3v logic)
 float voltage = reading * 3.25; //tested the actual voltage w/ multimeter hence the 3.25
 voltage /= 1024.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.print(" volts;  ");
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print(temperatureC); Serial.print(" degrees C;  ");
 
 // now convert to Fahrenheit
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.print(" degrees F  ");
 Serial.println();
 
 delay(1000);                                     //waiting a second
}
