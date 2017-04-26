
#include <hid.h>
#include <hiduniversal.h>
#include <usbhub.h>

#include "hidjoystickrptparser.h"

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);


int rightJoy, leftJoy, hat,Button, leftXX, rightXX;


void setup()
{
  rightJoy=0; 
  leftJoy=0; 
  hat=20;
  Button=0;
  leftXX=0;
  rightXX=0;
  Serial.begin(9600);


  if (Usb.Init() == -1)  digitalWrite(13,HIGH);
  delay(200);
  if (!Hid.SetReportParser(0, &Joy))  ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);  

}

void loop()
{

  // read joystick

  Usb.Task();
  leftJoy=(JoyEvents.get_left())-127;
  rightJoy=(JoyEvents.get_right())-127;
  leftXX=(JoyEvents.get_left_X())-128;
  rightXX=(JoyEvents.get_right_X())-128;
  Button=JoyEvents.get_button();
  hat=JoyEvents.get_hat();
  /////////////////////////////  set wheels

  Serial.print(leftJoy);
  Serial.print("  ");
  Serial.print(rightJoy);
  Serial.print("  ");
  Serial.print(leftXX);
  Serial.print("  ");
  Serial.print(rightXX);
  Serial.print("     ");
  Serial.print(Button);
  Serial.print("  ");
  Serial.println(hat);
   
}

