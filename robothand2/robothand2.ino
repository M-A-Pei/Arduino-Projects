 #include <Servo.h>

  #define servo1 2
  #define servo2 3
  #define servo3 4
  #define servo4 5
  #define servo5 6

  Servo Mservo1;
  Servo Mservo2;
  Servo Mservo3;
  Servo Mservo4;
  Servo Mservo5;

  char Input;

  int Delay = 25;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Mservo1.attach(servo1);
  Mservo2.attach(servo2);
  Mservo3.attach(servo3);
  Mservo4.attach(servo4);
  Mservo5.attach(servo5);

  Mservo1.write(90);
  Mservo2.write(90);
  Mservo3.write(170);
  Mservo4.write(90);
  Mservo5.write(90);

  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
  pinMode(servo3, OUTPUT);
  pinMode(servo4, OUTPUT);
  pinMode(servo5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    
  Input = Serial.read();

  Serial.print("real input = ");
  Serial.println(Input);
  
  switch (Input){
  case 'L':

    for(int i = Mservo1.read(); i <= 180; i++) //move left
    {
      Mservo1.write(i);
      Serial.print("servo 1= ");
      Serial.println(i);
      
      if(Serial.available()>0)
      {
         if(Input != 'L')
         {
          Serial.println(Input);
          break;  
         }
        Input = Serial.read(); 
      }
      
      delay(Delay);
    }
    break;
    
  case 'R':
  
    for(int i = Mservo1.read(); i >= 0; i--) //move right
    {
      Mservo1.write(i);
      Serial.print("servo 1= ");
      Serial.println(i);
      
      if(Serial.available()>0)
      {
         if(Input != 'R')
         {
          Serial.println(Input);
          break;  
         }
        Input = Serial.read(); 
      }
      
      delay(Delay);
    }
    break;
    
  case 'U':
  
    for(int i = Mservo2.read(); i <= 180; i++) //move up
    {
      Mservo2.write(i);
      Serial.print("servo 2= ");
      Serial.println(i);
      
      if(Serial.available()>0)
      {
         if(Input != 'U')
         {
          Serial.println(Input);
          break;  
         }
        Input = Serial.read(); 
      }
      
      delay(Delay);
      
    }
    break;
    
  case 'D':
  
    for(int i = Mservo2.read(); i >= 0; i--) //move down
    {
      Mservo2.write(i);
      Serial.print("servo 2= ");
      Serial.println(i);
      
      if(Serial.available()>0)
      {
         if(Input != 'D')
         {
          Serial.println(Input);
          break;  
         }
        Input = Serial.read(); 
      }
      
      delay(Delay);
    }
    break;
    
  case 'G':
    for(int i = Mservo3.read(); i <= 180; i++) //hand move up
    {
      Mservo3.write(i);
      Serial.print("servo 3= ");
      Serial.println(i);
      
      if(Serial.available()>0)
      {
         if(Input != 'G')
         {
          Serial.println(Input);
          break;  
         }
        Input = Serial.read(); 
      }
      
      delay(Delay);
      
    }
    break;

  case 'H':
    for(int i = Mservo3.read(); i >= 0; i--) //hand move down
    {
      Mservo3.write(i);
      Serial.print("servo 3= ");
      Serial.println(i);
      
      if(Serial.available()>0)
      {
         if(Input != 'H')
         {
          Serial.println(Input);
          break;  
         }
        Input = Serial.read(); 
      }
      
      delay(Delay);

    }
    break;

  case 'O':
    for(int i = Mservo4.read(); i <= 180; i++) //hand open
    {
      Mservo4.write(i);
      Serial.print("servo 4= ");
      Serial.println(i);
      
      if(Serial.available()>0)
      {
         if(Input != 'O')
         {
          Serial.println(Input);
          break;  
         }
        Input = Serial.read(); 
      }
      
      delay(10);
    }
    break;

  case 'C':
    for(int i = Mservo4.read(); i >= 0; i--) //hand close
    {
      Mservo4.write(i);
      Serial.print("servo 4= ");
      Serial.println(i);
      
      if(Serial.available()>0)
      {
         if(Input != 'C')
         {
          Serial.println(Input);
          break;  
         }
        Input = Serial.read(); 
      }
      
      delay(10);
    }
    break;

    case 'S':
    break;
    
  default:
     return; 
    break;
}
    
  }
}
