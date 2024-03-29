////////////////

MARCDUINO_ACTION(StopSequence, :SE00, ({
  resetSequence();
}))

MARCDUINO_ACTION(StopSequence2, :SE10, ({
  resetSequence();
}))

////////////////

MARCDUINO_ACTION(ScreamSequence, :SE01, ({
    //CommandEvent::process("LE10003");
   // Marcduino::send(F("$S"));
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpenClose, GROUP_DOORS);
}))

////////////////

MARCDUINO_ACTION(WaveSequence, :SE02, ({
   // Marcduino::send(F("$213"));
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelWave, GROUP_DOORS);
}))

////////////////

MARCDUINO_ACTION(SmirkWaveSequence, :SE03, ({
   // Marcduino::send(F("$34"));
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelWaveFast, GROUP_DOORS);
}))

////////////////

MARCDUINO_ACTION(OpenCloseWaveSequence, :SE04, ({
    //Marcduino::send(F("$36"));
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelOpenCloseWave, GROUP_DOORS);
}))

////////////////

MARCDUINO_ANIMATION(BeepCantinaSequence, :SE05)
{
    DO_START()
    DO_MARCDUINO(F("$c"))
    // Wait 1 second
    DO_COMMAND(F(
        // Fire logics
        "LE84115\n"
        // Holo Short Circuit
        "HPA002|15\n"))
    DO_SEQUENCE(SeqPanelMarchingAnts, GROUP_DOORS)
    // Wait 15 seconds
    DO_WAIT_SEC(15)
    DO_RESET({
        resetSequence();
    })
    DO_END()
}

////////////////

MARCDUINO_ANIMATION(ShortSequence, :SE06)
{
    DO_START()
    // Logic engine alarm
    DO_COMMAND(F("LE105000"))
    // Play scream-3 and wait 500ms
    DO_MARCDUINO_AND_WAIT(F("$623"), 500);
    // Logic engine failure
    DO_COMMAND(F(
        // Logic engine failure
        "LE20000\n"
        // Holo Short Circuit
        "HPA007|7\n"
        // Fire strip spark for 1000ms
        "FS11000\n"
        // Charge Bay Indicator flicker for 6s
        "CB20006\n"
        // Data Panel flicker for 6s
        "DP20006\n"
        // Smoke on
        "BMON\n"))
    // Wait 3 seconds
    DO_WAIT_SEC(3)
    DO_COMMAND(F(
        // Smoke off
        "BMOFF\n"
        // Fire strip off
        "FSOFF\n"))
    // Wait 3 seconds
    DO_WAIT_SEC(3)   
    DO_COMMAND(F(
        // Charge Bay Indicator disabled for 8s
        "CB10008\n"
        // Data Panel disabled for 8s
        "DP10008\n"
        // Holo off
        "HPA000|0\n"))
    DO_SEQUENCE_VARSPEED(SeqPanelAllOpenCloseLong, GROUP_DOORS, 700, 900);
    // Fake being dead for 8 seconds
    DO_WAIT_SEC(8)
    // Ok We are back!
    DO_RESET({
        resetSequence();
    })
    DO_END()
}

////////////////

MARCDUINO_ANIMATION(CantinaSequence, :SE07)
{
    DO_START()
    // Play Orchestral Cantina
    DO_MARCDUINO(F("$C"))
    // Wait 1 second
    DO_WAIT_SEC(1)
    DO_COMMAND(F(
        // Disco Logics
        "LE104146\n"
        // Holo Short Circuit
        "HPA006|46\n"))
    DO_SEQUENCE(SeqPanelDance, GROUP_DOORS)
    // Wait 46 seconds
    DO_WAIT_SEC(46)
    DO_RESET({
        resetSequence();
    })
    DO_END()
}



MARCDUINO_ANIMATION(DiscoSequence, :SE09)
{
    DO_START()
    DO_MARCDUINO(F("$D"))
    DO_SEQUENCE(SeqPanelLongDisco, GROUP_DOORS)
    DO_ONCE({
        //FLD.selectSequence(LogicEngineRenderer::RAINBOW);
        //RLD.selectScrollTextLeft("STAR WARS R2-D2 ASTROMECH", LogicEngineRenderer::ColorVal(random(10)));
    })
    DO_COMMAND_AND_WAIT(F(
        "HPS1|45\n"
        "CB10000\n"
        "DP10000\n"), 45000)
    DO_RESET({
        resetSequence();
    })
    DO_END()
}



MARCDUINO_ACTION(ScreamPanelSequence, :SE51, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelAllOpenClose, GROUP_DOORS);
}))

////////////////

MARCDUINO_ACTION(WavePanelSequence, :SE52, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelWave, GROUP_DOORS);
}))

////////////////

MARCDUINO_ACTION(SmirkWavePanelSequence, :SE53, ({
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelWaveFast, GROUP_DOORS);
}))

////////////////

MARCDUINO_ACTION(OpenWaveSequence, :SE54, ({
    Marcduino::send(F("$36"));
    SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelOpenCloseWave, GROUP_DOORS);
}))

////////////////

MARCDUINO_ACTION(MarchingAntsPanelSequence, :SE55, ({
    //SEQUENCE_PLAY_ONCE(servoSequencer, SeqPanelMarchingAnts, GROUP_DOORS);

    SEQUENCE_PLAY_ONCE_VARSPEED_EASING(servoSequencer, SeqPanelMarchingAnts, GROUP_DOORS, 500, 1000, Easing::CircularEaseIn, Easing::BounceEaseOut);
}))

////////////////

MARCDUINO_ACTION(FaintPanelSequence, :SE56, ({
    DO_SEQUENCE_VARSPEED(SeqPanelAllOpenCloseLong, GROUP_DOORS, 700, 900);
}))

////////////////

MARCDUINO_ACTION(RythmicPanelSequence, :SE57, ({
    SEQUENCE_PLAY_ONCE_SPEED(servoSequencer, SeqPanelAllOpenCloseLong, GROUP_DOORS, 900);
}))

////////////////

MARCDUINO_ANIMATION(GripperArmON, #GAON)
{
  DO_START()
  DO_ONCE_AND_WAIT({
        servoDispatch.moveTo(DOOR_LEFT, 50, 500, 1.0); 
    }, 1000)
    DO_ONCE_AND_WAIT({
        servoDispatch.moveTo(GRIPP_LIFT, 50, 500, 1.0);
        servoDispatch.moveTo(GRIPP_CLAW, 50, 500, 1.0); 
    }, 3000)
    DO_ONCE({
        servoDispatch.moveTo(GRIPP_CLAW, 50, 500, 0.0); 
    })
    DO_END()
}

MARCDUINO_ANIMATION(FireON, #FION)
{
  DO_START()
  DO_ONCE_AND_WAIT({
        servoDispatch.moveTo(DOOR_MINI, 50, 500, 1.0); 
    }, 1000)
    
    DO_ONCE({
        FireOut();
    })
    DO_WAIT_MILLIS(500)
    DO_ONCE({
        FireOut();
    })
    DO_WAIT_MILLIS(500)
    
    DO_ONCE({
        FireStop();
    })   
    DO_END()
}

MARCDUINO_ANIMATION(FireOFF, #FIOFF)
{
  DO_START()

  DO_ONCE({
        FireIn();
    })
    DO_WAIT_MILLIS(500)
    DO_ONCE({
        FireIn();
    })
    DO_WAIT_MILLIS(500)
    DO_ONCE({
        FireStop();
    })
    DO_WAIT_MILLIS(1500)
    
     
    DO_ONCE({
        servoDispatch.moveTo(DOOR_MINI, 50, 500, .0); 
    })
    DO_END()
}


MARCDUINO_ANIMATION(Spray,#SPRAY)
{
  DO_START()

  DO_ONCE({
        servoDispatch.moveTo(SPRAY, 50, 50, 1.0);
    })
    DO_WAIT_MILLIS(500)
    
    DO_ONCE({
        servoDispatch.moveTo(SPRAY, 50, 50, 0.0);
    })
    
    DO_END()
}



MARCDUINO_ANIMATION(SrewArmON, #SAON)
{
  DO_START()
  DO_ONCE_AND_WAIT({
        servoDispatch.moveTo(DOOR_RIGHT, 50, 100, 1.0); 
    }, 1000)
    DO_ONCE_AND_WAIT({
        //servoDispatch.moveTo(CPUARM_LIFT, 50, 500, 1.0);
        CPUArmLift();
    }, 3000)
    DO_ONCE({
        //servoDispatch.moveTo(CPUARM_EXTEND, 50, 50, 1.0);
        CPUArmON(); 
    })
    DO_WAIT_MILLIS(1000)
    DO_ONCE({
        CPUArmOFF();
    })
    DO_WAIT_MILLIS(1500)
    DO_ONCE({
       CPUArmON(); 
    })
    DO_WAIT_MILLIS(1500)
    DO_ONCE({
       CPUArmOFF(); 
    })
    
    DO_END()
}

/*
MARCDUINO_ANIMATION(HarlemShakeSequence, ARML)
{
    DO_START()
    // Wait 2 seconds
    DO_WAIT_SEC(2)
    DO_COMMAND(F(
        // Fire logics
        "LE70000\n"
        // Holo Short Circuit
        "HPA006|11\n"))
    // Wait 0.5 second
    DO_WAIT_MILLIS(500)
    // Start panel sequence
    DO_SEQUENCE(SeqPanelLongHarlemShake, GROUP_DOORS)
    // Wait 10 second
    DO_WAIT_SEC(11)
    DO_COMMAND(F(
        // Fire logics
        "LE100000\n"
        // Holo Short Circuit
        "HPA002|12\n"))

    // Beginning of Shake loop
    DO_LABEL(shake)
    // Play random
    DO_SEQUENCE_RANDOM_STEP(SeqPanelLongHarlemShake, GROUP_DOORS)
    // Wait 50 seconds
    DO_WAIT_MILLIS(50)
    // Loop until total play time reaches 26.5 seconds
    DO_DURATION(26500, { animation.gotoStep(shake); })
    // Start panel sequence
    DO_SEQUENCE(SeqPanelAllOpenCloseLong, GROUP_DOORS)
    // Wait 2 seconds
    DO_WAIT_SEC(2)

    DO_RESET({
        resetSequence();
    })
    DO_END()
}
*/
