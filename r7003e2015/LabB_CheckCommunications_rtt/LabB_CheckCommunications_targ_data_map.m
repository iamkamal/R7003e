  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (LabB_CheckCommunications_P)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% LabB_CheckCommunications_P.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LabB_CheckCommunications_P.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% LabB_CheckCommunications_P.Constant1_Value
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LabB_CheckCommunications_P.Constant2_Value
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LabB_CheckCommunications_P.angleoffset_Value
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% LabB_CheckCommunications_P.rawyaccelerationtog_y_Gain
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% LabB_CheckCommunications_P.rawzaccelerationtog_z_Gain
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% LabB_CheckCommunications_P.accelerometeranglebias_Value
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% LabB_CheckCommunications_P.Gain_Gain
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% LabB_CheckCommunications_P.angularvelocitytoangle_gainval
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% LabB_CheckCommunications_P.angularvelocitytoangle_IC
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% LabB_CheckCommunications_P.Gain_Gain_o
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
	  ;% LabB_CheckCommunications_P.SineWave_Amp
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 10;
	
	  ;% LabB_CheckCommunications_P.SineWave_Bias
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 11;
	
	  ;% LabB_CheckCommunications_P.SineWave_Freq
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 12;
	
	  ;% LabB_CheckCommunications_P.SineWave_Hsin
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 13;
	
	  ;% LabB_CheckCommunications_P.SineWave_HCos
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 14;
	
	  ;% LabB_CheckCommunications_P.SineWave_PSin
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 15;
	
	  ;% LabB_CheckCommunications_P.SineWave_PCos
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 16;
	
	  ;% LabB_CheckCommunications_P.rawxvelocitytodegsec_Gain
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 17;
	
	  ;% LabB_CheckCommunications_P.Gain1_Gain
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 18;
	
	  ;% LabB_CheckCommunications_P.gyrovelocitybias_Value
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 19;
	
	  ;% LabB_CheckCommunications_P.conversiontodutycycleconverttoi
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 20;
	
	  ;% LabB_CheckCommunications_P.Constant3_Value
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 21;
	
	  ;% LabB_CheckCommunications_P.Saturation0to255_UpperSat
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 22;
	
	  ;% LabB_CheckCommunications_P.Saturation0to255_LowerSat
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 23;
	
	  ;% LabB_CheckCommunications_P.Gain1_Gain_b
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% LabB_CheckCommunications_P.Switch_Threshold
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% LabB_CheckCommunications_P.DualEncoderReading1819A86215Min
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LabB_CheckCommunications_P.DualEncoderReading1819A86215M_h
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 2;
	
	  ;% LabB_CheckCommunications_P.DualEncoderReading1819A86215M_c
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (LabB_CheckCommunications_B)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% LabB_CheckCommunications_B.Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LabB_CheckCommunications_B.Gain_j
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LabB_CheckCommunications_B.SineWave
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% LabB_CheckCommunications_B.Sum2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunction_
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_e
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_i
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_p
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFuncti_pc
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_j
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_c
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFuncti_im
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% LabB_CheckCommunications_B.HMC5883LMPU6050DriverSFunctio_g
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
	  ;% LabB_CheckCommunications_B.DualEncoderReading1819A86215Min
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 9;
	
	  ;% LabB_CheckCommunications_B.DualEncoderReading1819A86215M_f
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (LabB_CheckCommunications_DWork)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% LabB_CheckCommunications_DWork.HMC5883LMPU6050DriverSFunction_
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LabB_CheckCommunications_DWork.DualEncoderReading1819A86215Min
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LabB_CheckCommunications_DWork.angularvelocitytoangle_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% LabB_CheckCommunications_DWork.lastSin
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% LabB_CheckCommunications_DWork.lastCos
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% LabB_CheckCommunications_DWork.accelerometer_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% LabB_CheckCommunications_DWork.encoder_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% LabB_CheckCommunications_DWork.gyro_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% LabB_CheckCommunications_DWork.motor_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% LabB_CheckCommunications_DWork.systemEnable
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 828292839;
  targMap.checksum1 = 561445509;
  targMap.checksum2 = 3139536426;
  targMap.checksum3 = 3243436275;

