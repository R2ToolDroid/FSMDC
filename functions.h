
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


void resetSequence()
{
    //servoSequencer.play(SeqPanelAllCloseLong, SizeOfArray(SeqPanelAllCloseLong), (GROUP_DOORS));
   SEQUENCE_PLAY_ONCE_VARSPEED_EASING(servoSequencer, SeqPanelAllClose, PANELS_MASK, 500, 1000, Easing::CircularEaseIn, Easing::CircularEaseOut);
    CloseUpperArm();
    CloseLowerArm();
    
   
   DEBUG_PRINTLN("reset.OK"); 
}
