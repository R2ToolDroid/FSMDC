#define USE_DEBUG 
#include "ReelTwo.h"
#include "core/Animation.h"
#include "core/DelayCall.h"
#include "ServoDispatchPCA9685.h"
#include "ServoSequencer.h"
#include "core/Marcduino.h"

#define COMMAND_SERIAL Serial

#define GROUP_DOORS      0x000F

#define DOOR_LEFT       0
#define DOOR_DATAPANEL  1
#define DOOR_CHARGEBAY  2
#define DOOR_MINI       3
#define DOOR_RIGHT      4
#define UPPER_ARM       5
#define LOWER_ARM       6
#define GRIPP_LIFT      7
#define GRIPP_CLAW      8
#define CPUARM_EXTEND   9
#define CPUARM_LIFT     10

#define DRAWER_1     11
#define DRAWER_2     12
#define DRAWER_3     13
#define DRAWER_4     14


#define PANEL_GROUP_1      (1L<<14)
#define PANEL_GROUP_2      (1L<<15)
#define PANEL_GROUP_3      (1L<<16)
#define PANEL_GROUP_4      (1L<<17)
#define PANEL_GROUP_5      (1L<<18)

#define BIG_DOOR_GROUP     (1L<<19)
#define DRAWER_GROUP       (1L<<20)
#define DRAWER_GROUP_1     (1L<<21)
#define DRAWER_GROUP_2     (1L<<22)
#define DRAWER_GROUP_3     (1L<<23)
#define DRAWER_GROUP_4     (1L<<24)

#define PANELS_MASK        (DRAWER_GROUP|GROUP_DOORS)

const ServoSettings servoSettings[] PROGMEM = {
    //* PIN, closed, Open, GRoupe//
    
    { 1,  1000,  2090, GROUP_DOORS|PANEL_GROUP_1|BIG_DOOR_GROUP },  /* 0: DOOR_LEFT */
    { 2,  1000,  2050, GROUP_DOORS|PANEL_GROUP_2},  /* 1: DOOR_DATAPANEL */
    { 3,  2050, 1000, GROUP_DOORS|PANEL_GROUP_3},  /* 2: DOOR_CHARGEBAY  */
    { 4,  1000, 2050, GROUP_DOORS|PANEL_GROUP_4},   /* 3: DOOR_MINI */
    { 5,  2150, 1100, GROUP_DOORS|PANEL_GROUP_5|BIG_DOOR_GROUP },    /* 4: DOOR_RIGHT */
    { 6,  600, 2500, 0 },             /* 5: UPPER_ARM */
    { 7,  600, 2500, 0 },             /* 6: LOWER_ARM */
    { 8,  1000, 2050, 0 },            /* 7: GRIPP_LIFT */
    { 9,  1000, 2050, 0 },            /* 8: GRIPP_CLAW */
    { 10, 1000, 2050, 0 },            /* 9: CPUARM_EXTEND */
    { 11, 1000, 2050, 0 },            /* 10:CPUARM_LIFT */
    { 12, 1000, 2050, DRAWER_GROUP|DRAWER_GROUP_1 }, /* 11:DRAWER_1 */
    { 13, 1000, 2050, DRAWER_GROUP|DRAWER_GROUP_2 }, /* 12:DRAWER_2 */ 
    { 14, 1000, 2050, DRAWER_GROUP|DRAWER_GROUP_3 }, /*|13:DRAWER_3 */ 
    { 15, 1000, 2050, DRAWER_GROUP|DRAWER_GROUP_4 }, /* 13:DRAWER_4 */ 
    
};


static const ServoSequence SeqPanelAllOpenLong PROGMEM =
{
    { 1000,   B11111111, B11111111, B11111111, B11111111 },
};

static const ServoSequence SeqPanelAllCloseLong PROGMEM =
{
    { 1000,   B00000000, B00000000, B00000000, B00000000 },
};



ServoDispatchPCA9685<SizeOfArray(servoSettings)> servoDispatch(servoSettings);
ServoSequencer servoSequencer(servoDispatch);
AnimationPlayer player(servoSequencer);
MarcduinoSerial<> marcduinoSerial(COMMAND_SERIAL, player);

int ledState = LOW;   

#include "functions.h"

////////////////
#include "MarcduinoPanel.h"

////////////////

#include "MarcduinoSequence.h"


MARCDUINO_ACTION(FlutterPanelTest, test, ({
    SEQUENCE_PLAY_ONCE_VARSPEED(servoSequencer, SeqPanelAllFlutter, PANELS_MASK , 10, 50);
    //OpenUpperArm();
    //OpenLowerArm();
}))



// Marcduino command starting with '*RT' followed by Reeltwo command
MARCDUINO_ACTION(DirectCommand, *RT, ({
    // Direct ReelTwo command
    CommandEvent::process(Marcduino::getCommand());
}))


void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    REELTWO_READY();
    Wire.begin();
    COMMAND_SERIAL.begin(9600);
    SetupEvent::ready();
    //COMMAND_SERIAL.print("ready..");
    resetSequence();
    
    DEBUG_PRINTLN("ready.."); 

    //SEQUENCE_PLAY_ONCE(servoSequencer, sMySeqPanelAllOpen, GROUP_DOORS);
    //servoDispatch.moveServosTo(GROUP_DOORS, 150, 100, 1.0); // completely open
    //SEQUENCE_PLAY_ONCE_VARSPEED_EASING(servoSequencer, SeqPanelMarchingAnts, GROUP_DOORS, 500, 1000, Easing::CircularEaseIn, Easing::BounceEaseOut);
}


 
void loop()
{
    AnimatedEvent::process();
}
