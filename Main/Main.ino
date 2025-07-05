

#define NOTE_B0  31
#define  NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define  NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define  NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define  NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define  NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define  NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define  NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3  185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define  NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4  277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define  NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4  415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define  NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5  622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define  NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5  932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define  NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define  NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define  NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define  NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define melodyPin 7

int sp =100;
int mot =1;
bool motionDetected = false;
// Jingle Bells

int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,

  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,

  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,

  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

int tempo[]
  = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8,
  8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

// We wish you a merry Christmas

int wish_melody[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,

  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,

  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,

  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,

  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

//Santa Claus is coming to town

int santa_melody[] = {
  NOTE_G4,
  NOTE_E4,
  NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,

  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,

  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};

int santa_tempo[] = {
  8,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4,
  4, 4,
  8, 8, 4, 2,
  4, 4, 4, 4,
  4, 2, 4,
  1
};

void setup()
{
  for(int i=13; i>8; i--){
    pinMode(i,OUTPUT);}
  for(int i=5; i<9;i++){
    pinMode(i,INPUT);}
  pinMode(4,OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  digitalWrite(4, HIGH);
  delayMicroseconds(10);
  digitalWrite(4, LOW);
  int pir = digitalRead(6); 

  int ldrValue = analogRead(A0);
  
  if(ldrValue > 200){
  	if(pir == HIGH){
    	if(!motionDetected){
    		mot++;
      		sing(mot);
      		pk();
      		motionDetected = true;
    	}
  	}
  	else{
    	if(motionDetected){
      		mot = mot;
      		sing(mot);
      		pk();
      		motionDetected = false;
    	}
  	}
  }
  
  
}

void pattern1(){
     for(int i=9; i<=13; i++){
      digitalWrite(i,HIGH);
      digitalWrite(i-1,HIGH);
      digitalWrite(i+1,HIGH);
      delay(sp);
      digitalWrite(i,LOW);
      digitalWrite(i-1,LOW);
      digitalWrite(i+1,LOW);
    }
    
    for(int i=13; i>=9; i--){
      digitalWrite(i,HIGH);
      digitalWrite(i-1,HIGH);
      digitalWrite(i+1,HIGH);
      delay(sp);
      digitalWrite(i,LOW);
      digitalWrite(i-1,LOW);
      digitalWrite(i+1,LOW);
    }
}

void pattern2(){   
      for(int i=9; i<=13; i++) {
      digitalWrite(i,HIGH);
      delay(sp);
    }
    
    for(int i=13; i>=9; i--) {
      digitalWrite(i,HIGH);
      delay(sp);
      digitalWrite(i,LOW);
    }
}
void pattern3(){   
    for(int i=13; i>=9; i--) {
      digitalWrite(i,HIGH);
      delay(sp);
      digitalWrite(i,LOW);
    }
}




int song = 0;

void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 3) {
    Serial.println("'We wish you a Merry Christmas'");
    int size = sizeof(wish_melody) / sizeof(int);

    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g.quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / wish_tempo[thisNote];
	  buzz(melodyPin, wish_melody[thisNote],noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop thetone playing:
      buzz(melodyPin, 0, noteDuration);

    }
  } else
  if (song == 2) {
    Serial.println(" 'Santa Claus is coming to town'");

    int size = sizeof(santa_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 900 / santa_tempo[thisNote];


      buzz(melodyPin, santa_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;

      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

    }
  } else {

    Serial.println(" 'Jingle Bells'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration,take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];


      buzz(melodyPin, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);


      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);


    }
  }
}

void buzz(int targetPin, long frequency, long length) {


  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }


}
void pk(){
   float echo = pulseIn(5,HIGH);
  float distance = 0.017 *echo;
  if(distance > 0 && distance <30){
    sp = 50;
  }
  else if(distance > 30 && distance <60){
    sp = 100;
  }
  else if(distance > 60 && distance <90){
    sp = 200;
  }
  pattern1();
  pattern2();
  pattern3();
}