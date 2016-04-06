/*
 * Battery Housing (3 AA)
 * Quick Connect for Battery (2 pin)
 * Quick Connect for Temp Sensor (3 pin)
 * Apoxy for temp sensor sealing 
 * 3 inch gasket
 * Power managment?
 * nylon tape
 * Solder another board
 * 
 * 
 */

#include <RTClib.h>
#include <SPI.h>
#include <SD.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 9 //temp sensor - data wire pin 9

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);



// declaring clock object
RTC_DS1307 rtc;
// declare file object
File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
   ; // wait for serial port to connect. Needed for native USB port only
  }
  if (!SD.begin(10)) {
    //Serial.println("initialization failed!");
    return;
  }
  //Serial.println("initialization done.");
  // Initialize the rtc object
  rtc.begin();
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement

}

void loop()
{

sensors.requestTemperatures(); // Send the command to get temperatures

  DateTime now = rtc.now();

  String outString = now.month() + String("/") + now.day() + String("/") + now.year() + String(" ") + now.hour() + String(":") + now.minute() + String(":") + now.second() + ", " + sensors.getTempCByIndex(0);
  Serial.println(outString);
 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("tempdata.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    myFile.println(outString); //took out ",24.77" ?
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening tempdata.txt");
  }
  
  // Wait before repeating :)
  delay (5000);
}
