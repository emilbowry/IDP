//#include"pitches.h"
int NOTE_D2= 73;
int NOTE_DS2=78;
int NOTE_G2  = 98;
int NOTE_GS2= 104;
int NOTE_A2 = 110;
int NOTE_AS2= 117;
int NOTE_B2 = 123;
int NOTE_C3  =131;
int NOTE_CS3 =139;
int NOTE_D3 = 147;
int NOTE_DS3= 156;
int NOTE_E3 = 165;
int NOTE_F3 = 175;
int NOTE_FS3= 185;
int NOTE_G3 = 196;
int NOTE_GS3= 208;
int NOTE_A3  =220;
int NOTE_AS3 =233;
int NOTE_B3  =247;
int NOTE_C4 = 262;
int NOTE_CS4= 277;
int NOTE_D4 = 294;
int NOTE_DS4 =311;
int NOTE_E4 = 330;
int NOTE_F4 = 349;
int NOTE_FS4= 370;
int NOTE_G4 = 392;
int NOTE_GS4= 415;
int NOTE_A4 = 440;
int NOTE_AS4= 466;
int NOTE_B4 = 494;
int NOTE_C5 = 523;
int NOTE_CS5= 554;
int NOTE_D5 = 587;
int NOTE_DS5= 622;
int NOTE_E5=  659;
int NOTE_F5 =698;
int NOTE_FS5= 740;
int NOTE_G5  =784;
int NOTE_GS5 =831;
int NOTE_A5  =880;
int NOTE_AS5 =932;
int NOTE_B5  =988;

int NOTE_C6  = 1047;
int NOTE_CS6 =1109;
int NOTE_D6  =1175;
int NOTE_DS6 =1245;
int NOTE_E6  =1319;
int NOTE_F6  =1397;
int NOTE_FS6 =1480;
int NOTE_G6  =1568;
int NOTE_GS6 =1661;
int NOTE_A6  =1760;
int NOTE_AS6 =1865;
int NOTE_B6  =1976;
int NOTE_C7  =2093;
int REST= 0;
unsigned int US = 40000;
int END =-1;
// notes in the song 'Mukkathe Penne'
int melody[] ={
NOTE_A5, NOTE_F5, NOTE_D5, NOTE_A4, NOTE_A5, NOTE_F5, NOTE_D5, NOTE_A4, NOTE_A5,NOTE_F5, NOTE_D5, NOTE_A4, NOTE_A5,

NOTE_F5, NOTE_D5, NOTE_A4, NOTE_G5, NOTE_E5, NOTE_CS5, NOTE_A4, NOTE_G5, NOTE_E5, NOTE_CS5, NOTE_A4, NOTE_G5,

NOTE_E5, NOTE_CS5, NOTE_A4, NOTE_G5, NOTE_E5, NOTE_CS5, NOTE_A4, NOTE_AS5, NOTE_G5, NOTE_E5, NOTE_CS5,

NOTE_AS5, NOTE_G5, NOTE_E5, NOTE_CS5, NOTE_AS5, NOTE_G5, NOTE_E5, NOTE_CS5, NOTE_AS5, NOTE_G5, NOTE_F5, NOTE_E5,

NOTE_G6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_CS6, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,

NOTE_CS5, NOTE_A4, NOTE_D5,

END,

}; 

long usmelody[] = {
  US,US,
};
int noteDurations[] = {
  4,4,2,4,2,2,2,2,2,2,2,2,2,

  2,4,4,4,2,2,4,2,2,2,2,2,

  2,2,2,2,2,4,6,4,4,2,2,

  2,2,2,2,2,2,2,2,2,2,4,8,

  2,4,2,2,2,2,2,2,2,6,6,

  8,2,16,
};



int melody2[] ={

NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_DS2,NOTE_DS2,NOTE_DS2,

NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_DS2,NOTE_DS2,NOTE_DS2,

NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_DS2,NOTE_DS2,NOTE_DS2,

NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_DS2,NOTE_DS2,NOTE_DS2,

NOTE_G4, NOTE_G4, NOTE_G4, NOTE_D4, NOTE_AS4, 

NOTE_G4, NOTE_D4, NOTE_AS4, NOTE_G4,

NOTE_D5, NOTE_D5, NOTE_D5, NOTE_DS5, NOTE_AS4,

NOTE_FS4, NOTE_D4, NOTE_AS4, NOTE_G4,

NOTE_G5, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_F5,

NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_B4,

NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_D4, NOTE_FS4, NOTE_D4, NOTE_FS4,

NOTE_AS4, NOTE_G4, NOTE_AS4, NOTE_D5, 

NOTE_G5, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_GS5, NOTE_F5,

NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_B4,

NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_D4, NOTE_FS4, NOTE_D4, NOTE_FS4,

NOTE_G4, NOTE_D4, NOTE_AS4, NOTE_G4, 

NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_DS2,NOTE_DS2,NOTE_DS2,

NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_DS2,NOTE_DS2,NOTE_DS2,

NOTE_G3, NOTE_G3,NOTE_G3,NOTE_AS3,NOTE_G3,NOTE_AS3, NOTE_G3,NOTE_AS3, NOTE_G3,NOTE_AS4,NOTE_FS4,NOTE_AS4,NOTE_FS4,

NOTE_G2, NOTE_AS3, NOTE_D4, NOTE_D4, NOTE_B3, NOTE_DS4, NOTE_DS4, NOTE_CS4, NOTE_F4, NOTE_F4, NOTE_G2, NOTE_AS3, NOTE_G4, NOTE_G4, NOTE_B3, NOTE_GS4, NOTE_GS4, NOTE_AS4,

NOTE_D3,NOTE_D4, NOTE_D5, NOTE_D5,NOTE_DS4, NOTE_DS5, NOTE_DS5, NOTE_C4, NOTE_C5,NOTE_C5, NOTE_D3, NOTE_D4, NOTE_AS4, NOTE_AS4 ,NOTE_AS3, NOTE_A4,NOTE_A4,NOTE_CS4,NOTE_FS4,NOTE_FS4,

NOTE_D3,NOTE_FS4, NOTE_D5, NOTE_D5,NOTE_G4, NOTE_CS5, NOTE_CS5,NOTE_DS4,NOTE_A4,NOTE_A4,NOTE_E4,NOTE_C5,NOTE_C5,NOTE_D4,NOTE_AS4,NOTE_AS4,NOTE_AS3,NOTE_FS4,NOTE_FS4,NOTE_FS3,NOTE_DS4,NOTE_DS4,

NOTE_D3,NOTE_D4, NOTE_D5, NOTE_D5,NOTE_DS4, NOTE_DS5, NOTE_DS5, NOTE_C4, NOTE_C5,NOTE_C5, NOTE_D2,NOTE_D3, NOTE_AS4, NOTE_AS4, NOTE_AS3 ,NOTE_A4,NOTE_A4,NOTE_DS4,NOTE_FS4,NOTE_FS4,

NOTE_D3, NOTE_D5, NOTE_G5, NOTE_G5,NOTE_AS4,NOTE_D5,NOTE_D5,NOTE_G4,NOTE_AS4,NOTE_AS4,NOTE_C4,NOTE_GS4,NOTE_GS4,NOTE_GS3,NOTE_DS4,NOTE_DS4,NOTE_DS3,NOTE_B3,NOTE_B3,NOTE_B2,NOTE_GS3,NOTE_GS3,

NOTE_G2,NOTE_D3,NOTE_AS3,NOTE_G3,NOTE_DS3,NOTE_C4,NOTE_G3,NOTE_C3,NOTE_A3,NOTE_G2,NOTE_G2,NOTE_AS3,NOTE_G4,NOTE_D4,NOTE_A3,NOTE_A4,NOTE_D4,NOTE_FS4,

NOTE_G2, NOTE_FS3,NOTE_D4,NOTE_D4,NOTE_G3,NOTE_CS4,NOTE_CS4,NOTE_CS3,NOTE_A3,NOTE_A3,NOTE_DS3,NOTE_C4,NOTE_C4,NOTE_D3,NOTE_AS3,NOTE_AS3,NOTE_AS2,NOTE_FS3,NOTE_FS3,NOTE_G2,NOTE_DS3,NOTE_DS3,

NOTE_GS2,NOTE_GS3,NOTE_B4,NOTE_B4,NOTE_B3,NOTE_AS4,NOTE_AS4,NOTE_D4,NOTE_G4,NOTE_G4,NOTE_GS2,NOTE_AS3,NOTE_DS5,NOTE_DS5,NOTE_DS4,NOTE_D5,NOTE_D5,NOTE_G4,NOTE_B4,NOTE_B4,

NOTE_GS2,NOTE_DS3,NOTE_B4,NOTE_B4,NOTE_G3,NOTE_AS4,NOTE_AS4,NOTE_B3,NOTE_D4,NOTE_D4,NOTE_C4,NOTE_GS4,NOTE_GS4,NOTE_GS3,NOTE_G4,NOTE_G4,NOTE_GS3,NOTE_E4,NOTE_E4,NOTE_DS3,NOTE_GS3,NOTE_GS3,
END,
};

// note durations: 8 = quarter note, 4 = 8th note, etc.

int noteDurations2[] = {   
   
8,4,1.333,1.333,1.333,4,2,2,2,2,4,
8,4,1.333,1.333,1.333,4,2,2,2,2,4,
8,4,1.333,1.333,1.333,4,2,2,2,2,4,
8,4,1.333,1.333,1.333,4,2,2,2,2,4,
8,8,8,6,2,
8,6,2,16,
8,8,8,6,2,
8,6,2,16,
8,6,2,8,6,2,
2,2,8,4,8,6,2,
2,2,8,4,8,6,2,
8,6,2,16,
8,4,4,8,6,2,
2,2,8,4,8,6,2,
2,2,8,4,8,6,2,
8,6,2,16,
8,4,1.333,1.333,1.333,4,2,2,2,2,4,
8,4,1.333,1.333,1.333,4,2,2,2,2,4,
8,4,1.333,1.333,1.333,4,1.333,1.333,1.333,1.333,1.333,1.333,4,
4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,4,1.33,1.33,1.33,1.33,1.33,1.33,4,
4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,
4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,
4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,
4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,
4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,4,1.33,1.33,1.33,1.33,1.33,1.33,4,
4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,
2,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,
4,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,1.33,8,

};

int ussound[] = {
  1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,
};

 //int noteDurations[] = {};/*
void starwars(){
  int speed=90;  //higher value, slower notes
    for (int thisNote = 0; melody2[thisNote]!=-1; thisNote++) {
      int noteDuration = speed*noteDurations2[thisNote];
      tone(3, melody2[thisNote],noteDuration*.95);
      Serial.println(melody2[thisNote]);

      delay(noteDuration);

      noTone(5);
      }
}

void theboys(){
  int speed=100;  //higher value, slower notes
    for (int thisNote = 0; melody[thisNote]!=-1; thisNote++) {
      int noteDuration = speed*noteDurations[thisNote];
      tone(3, melody[thisNote],noteDuration*.95);
      Serial.println(melody[thisNote]);

      delay(noteDuration);

      noTone(3);
      }
}



void setup() {

  Serial.begin(9600);
  //starwars();
  //theboys();

// put your main code here, to run repeatedly:
  int speed = 1000000;
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
}
void loop() {
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  /*delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);
  delayMicroseconds(17);
  tone(3, usmelody[1]);
  Serial.println(usmelody[1]);
  delayMicroseconds(17);
  noTone(3);*/
  delay(1000000);
}
