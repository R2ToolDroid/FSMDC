# FSMDC
 Front Skin Marcduino Controller
 
BODY Action with Prefix #
 
DO ALL SE Marcduino Commands with : Prefix 

Panels:
#CL00
#CL01 - 05
#OP00
#OP01 - 05
Panels Flutter:
#OF00
#OF01 - 05

ARMS :
#OPUA   //Upper Arm
#OPLA   //Lower Arm
#CLUA   //Upper Arm
#CLLA   //Lower Arm
#LGA   //Lift Gripper Arm
#DGA   //Down Gripper Arm
#CC    //lose Claw
#OC    //open Claw
#CPUL  //CPU Arm Lift
#CPUD  //CPU Arm Down
#CPU1  //CPU Arm On
#CPU0  //CPU Arm Off
DRAWER:
#OPD0  //ALL Drawer open
#OPD1 - #OPD4
#CLD0  //All Drawer close
#CLD1  - #CLD4

GADGETS:
---Fire---
#F0    //Fire Stop  TEST
#FOUT  //Move Out   TEST
#FIN   //Move In    TEST
---Spray---
#SP1   //Spray On
#SP0   //Spray Off

----ANIMATION----
#GAON   //Open Door lift Arm and move Gripp
:SE00   //reset that move
#FION   // Open Door Move Fire out
#FIOFF  // Move Fire In and close Door
//Check position Input for Status//
#SPRAY  // Move Spary ON and Off
#SAON   // Open Door Move Arm and play On/off with Motor
