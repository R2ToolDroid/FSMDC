#define USE_DEBUG 
#include "ReelTwo.h"
#include "ServoDispatchDirect.h"
#include "ServoSequencer.h"
#include "core/Marcduino.h"

#define COMMAND_SERIAL Serial

#define PIE_PANEL          0x0008
#define TOP_PIE_PANEL      0x0010

const ServoSettings servoSettings[] PROGMEM = {
    { 2,  PIE_PANEL,     1250, 1900 },  /* 0: pie panel 1 */
    { 3,  PIE_PANEL,     1075, 1700 },  /* 1: pie panel 2 */
    { 4,  PIE_PANEL,     1200, 2000 },  /* 2: pie panel 3 */
    { 5,  PIE_PANEL,      750, 1450 },  /* 3: pie panel 4 */
    { 6,  TOP_PIE_PANEL, 1250, 1850 },  /* 4: dome top panel */
};

ServoDispatchDirect<SizeOfArray(servoSettings)> servoDispatch(servoSettings);
ServoSequencer servoSequencer(servoDispatch);
AnimationPlayer player(servoSequencer);
MarcduinoSerial<> marcduinoSerial(COMMAND_SERIAL, player);


int ledState = LOW;   

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    REELTWO_READY();
    COMMAND_SERIAL.begin(9600);
    SetupEvent::ready();
    //COMMAND_SERIAL.print("ready..");
    DEBUG_PRINTLN("ready.."); 
}


void test(){
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(LED_BUILTIN, ledState);  
}

MARCDUINO_ACTION(test, :CL00, ({
    //Marcduino::processCommand(player, "@4S3");
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllClose, ALL_DOME_PANELS_MASK);

   // COMMAND_SERIAL.print("found CL00");
   DEBUG_PRINTLN("found CL00"); 
}))

// Marcduino command starting with '*RT' followed by Reeltwo command
MARCDUINO_ACTION(DirectCommand, *RT, ({
    // Direct ReelTwo command
    CommandEvent::process(Marcduino::getCommand());
}))

 
void loop()
{
    AnimatedEvent::process();
}
