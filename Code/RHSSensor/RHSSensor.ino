#include <RTClib.h>
#include <SPI.h>
#include <SD.h>
//#include <DS3231.h>
// Init the DS3231 using the hardware interface
//DS3231 rtc(SDA, SCL);
RTC_DS1307 rtc;
// declare file object
File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  // Initialize the rtc object
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop()
{

  DateTime now = rtc.now();
    
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print("/");
    Serial.print(now.year(), DEC);
    Serial.print("  ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    delay(1000);
  // build date time string
 // String outString = rtc.getDOWStr() + String(" ") + rtc.getDateStr() + String(" -- ") + rtc.getTimeStr();
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("tempdata.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
//myFile.println(outString + ",24.77");
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening tempdata.txt");
  }
  
  // Wait one second before repeating :)
  delay (10000);
}
