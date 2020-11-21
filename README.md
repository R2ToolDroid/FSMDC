# FSMDC
 Front Skin Marcduino Controller
 
BODY Action with Prefix #
 
DO ALL SE Marcduino Commands with : Prefix 

## Panels:
* #CL00
* #CL01 - 05
* #OP00
* #OP01 - 05
  
## Panels Flutter:
* #OF00
* #OF01 - 05

## ARMS :
* #OPUA   //Upper Arm
* #OPLA   //Lower Arm
* #CLUA   //Upper Arm
* #CLLA   //Lower Arm
* #LGA   //Lift Gripper Arm
* #DGA   //Down Gripper Arm
* #CC    //lose Claw
* #OC    //open Claw
* #CPUL  //CPU Arm Lift
* #CPUD  //CPU Arm Down
* #CPU1  //CPU Arm On
* #CPU0  //CPU Arm Off

## DRAWER:
* #OPD0  //ALL Drawer open
* #OPD1 - #OPD4
* #CLD0  //All Drawer close
* #CLD1  - #CLD4

## GADGETS:
### ---Fire---
* #F0    //Fire Stop  TEST
* #FOUT  //Move Out   TEST
* #FIN   //Move In    TEST

### ---Spray---
* #SP1   //Spray On
* #SP0   //Spray Off

### ----ANIMATION----
* #GAON   //Open Door lift Arm and move Gripp
* :SE00   //reset that move
* #FION   // Open Door Move Fire out
* #FIOFF  // Move Fire In and close Door
//Check position Input for Status//

* #SPRAY  // Move Spary ON and Off
* #SAON   // Open Door Move Arm and play On/off with Motor

# Marcduino Commands
* :SE00     Close all panels (full speed), servo off - use as init only. Use CL00 for all soft close.
* :SE01     Scream, with all panels open
* :SE02     Wave, one panel at a time
* :SE03     Fast (Smirk) back and forth wave
* :SE04     Wave 2 (open progressively all panels, then close one by one)
* :SE05     Beep Cantina (with marching ants panel action)
* :SE06     Faint/Short Circuit
* :SE07     Cantina dance (orchestral, rhythmic panel dance)
* :SE08     Leia
* :SE09     Disco
* :SE10     Quite Mode reset (panel close, stop holos, stop sounds)
* :SE11     Full Awake Mode reset (panel close, random sound, holo movement, no holo lights)
* :SE12     Top Panels to RC
* :SE13     Mid Awake Mode reset (panel close, random sound, stop holos)
* :SE14     Awake+ Mode reset ((panel close, random sound, holo movement, lights on)
* :SE15     Screams no panels

###  Panel Moves and light display only, no sound

* :SE51     Scream, with all panels open
* :SE52     Wave, one panel at a time
* :SE53     Fast (Smirk) back and forth wave
* :SE54     Wave 2 (open progressively all panels, then close one by one)
* :SE55     Marching ants 
* :SE56     Faint/Short Circuit
* :SE57     Rhythmic cantina panel dance

...maybe more to come
