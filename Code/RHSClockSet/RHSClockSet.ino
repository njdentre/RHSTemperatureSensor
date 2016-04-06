#include <RTClib.h>

// declaring clock object
RTC_DS1307 rtc;


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
   ; // wait for serial port to connect. Needed for native USB port only
  }
  
  // Initialize the rtc object
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

}

void loop()
{
/*

sensors.requestTemperatures(); // Send the command to get temperatures

  DateTime now = rtc.now();

  String outString = now.month() + String("/") + now.day() + String("/") + now.year() + String(" ") + now.hour() + String(":") + now.minute() + String(":") + now.second() + ", " + sensors.getTempCByIndex(0);
  Serial.println(outString);
 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("tempdata.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  
  
  // Wait before repeating :)
  delay (5000);
  */
}
