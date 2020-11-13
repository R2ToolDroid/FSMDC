
void OpenUpperArm(){
  servoDispatch.moveTo(UPPER_ARM, 150, 1000, 1.0);  
}
void CloseUpperArm(){
  servoDispatch.moveTo(UPPER_ARM, 50, 500, 0.0);  
}
void OpenLowerArm(){
  servoDispatch.moveTo(LOWER_ARM, 150, 1000, 1.0);  
}
void CloseLowerArm(){
  servoDispatch.moveTo(LOWER_ARM, 50, 500, 0.0);  
}


void CloseClaw(){
  servoDispatch.moveTo(GRIPP_CLAW, 50, 500, 0.0); 
}

void OpenClaw(){
  servoDispatch.moveTo(GRIPP_CLAW, 50, 500, 1.0); 
}


void GrippLift(){
  servoDispatch.moveTo(GRIPP_LIFT, 50, 500, 1.0);
}

void GrippDown(){
  servoDispatch.moveTo(GRIPP_LIFT, 50, 500, 0.0);
}


void CPUArmLift(){

  servoDispatch.moveTo(CPUARM_LIFT, 50, 500, 1.0);
  DEBUG_PRINTLN("CPU ARM LIFT"); 
}

void CPUArmDown(){
  servoDispatch.moveTo(CPUARM_LIFT, 50, 500, 0.0);
  DEBUG_PRINTLN("CPU ARM DOWN"); 
}

void CPUArmON(){
  servoDispatch.moveTo(CPUARM_EXTEND, 50, 500, 1.0);
  
}
void CPUArmOFF(){
  servoDispatch.moveTo(CPUARM_EXTEND, 50, 500, 0.0);
}

void FireOut(){
  servoDispatch.moveTo(FIRE, 50, 50, 1.0);
}

void FireIn() {
  servoDispatch.moveTo(FIRE, 50, 50, 0.0);
}

void FireStop(){
  servoDispatch.moveToPulse(FIRE, 150, 100, 1500); // Einzenelner Servo
}




void resetSequence()
{
    //servoSequencer.play(SeqPanelAllCloseLong, SizeOfArray(SeqPanelAllCloseLong), (GROUP_DOORS));
        
    DelayCall::schedule([] {
   SEQUENCE_PLAY_ONCE_VARSPEED_EASING(servoSequencer, SeqPanelAllClose, PANELS_MASK, 500, 1000, Easing::CircularEaseIn, Easing::CircularEaseOut);
   //servoSequencer.play(SeqPanelAllCloseLong, SizeOfArray(SeqPanelAllCloseLong), (PANELS_MASK));
    }, 2000);
    
    CloseUpperArm();
    CloseLowerArm();
    CloseClaw();
    GrippDown();
    CPUArmDown();
   //FireStop();
   
   DEBUG_PRINTLN("reset.OK"); 
}
