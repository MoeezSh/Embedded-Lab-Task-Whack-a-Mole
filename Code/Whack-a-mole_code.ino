
// anodes
int row[] = {A5,A4,A3};

// cathodes
int col[] = {A0,A1,A2};

//for LEDs
int led_nmbr;

//for buttons
int button[9];
int pin_nmbr=13;
int button_nmbr;

//for limiting game to 20 sec
unsigned long timeOut = 20000;
boolean timing= true;
unsigned long startTime= millis();
int current_time;

// Score 
int score=0;

void setup()
{
  Serial.begin(9600);
  for (int i=0;i<3;i++)
  {
    pinMode(row[i], OUTPUT);
    pinMode(col[i], OUTPUT);
  } 
  for (int i=5;i>13;i++)
  {
    pinMode(i, INPUT_PULLUP);
  } 
  pinMode(3, OUTPUT);   
  randomSeed(analogRead(0));
}


void Random_LED()
{
  led_nmbr= rand() % 9 + 1;
  if(led_nmbr==1)
  {
    //Serial.println(random_nmbr);
    digitalWrite(row[0], HIGH);
    digitalWrite(col[0], LOW);
    digitalWrite(col[1], HIGH);
    digitalWrite(col[2], HIGH); 
  }
  else if(led_nmbr==2)
  {
    //Serial.println(random_nmbr);
    digitalWrite(row[0], HIGH);
    digitalWrite(col[1], LOW);
    digitalWrite(col[0], HIGH);
    digitalWrite(col[2], HIGH); 
    }
  else if(led_nmbr==3)
  {
    //Serial.println(random_nmbr);
    digitalWrite(row[0], HIGH);
    digitalWrite(col[2], LOW);
    digitalWrite(col[1], HIGH);
    digitalWrite(col[0], HIGH); 
    }
  else if(led_nmbr==4)
  {
    //Serial.println(random_nmbr);
      digitalWrite(row[1], HIGH);
      digitalWrite(col[0], LOW);
      digitalWrite(col[1], HIGH);
      digitalWrite(col[2], HIGH); 
    }
  else if(led_nmbr==5)
  {
    //Serial.println(random_nmbr);
    digitalWrite(row[1], HIGH);
    digitalWrite(col[1], LOW);
    digitalWrite(col[0], HIGH);
    digitalWrite(col[2], HIGH); 
    }
  else if(led_nmbr==6)
  {
    //Serial.println(random_nmbr);
    digitalWrite(row[1], HIGH);
    digitalWrite(col[2], LOW);
    digitalWrite(col[1], HIGH);
    digitalWrite(col[0], HIGH); 
    }
  else if(led_nmbr==7)
  {
    //Serial.println(random_nmbr);
    digitalWrite(row[2], HIGH);
      digitalWrite(col[0], LOW);
      digitalWrite(col[1], HIGH);
      digitalWrite(col[2], HIGH); 
    }
  else if(led_nmbr==8)
  {
    //Serial.println(random_nmbr);
    digitalWrite(row[2], HIGH);
    digitalWrite(col[1], LOW);
    digitalWrite(col[0], HIGH);
    digitalWrite(col[2], HIGH); 
    }
  else if(led_nmbr==9)
  {
    //Serial.println(random_nmbr);
    digitalWrite(row[2], HIGH);
    digitalWrite(col[2], LOW);
    digitalWrite(col[1], HIGH);
    digitalWrite(col[0], HIGH); 
  }
}




void Check_time()
{
  current_time=  millis();
  if (current_time - startTime >= timeOut)
    {timing = false;}
}


  
void Turn_off_LED()
{
  for (int i=0;i<3;i++)
    {
     digitalWrite(row[i], LOW);
     digitalWrite(col[i], LOW);
    }
}


  
int Buzzer(int times)
{
  for (int i=0;i<times;i++)
  {
    digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(3, LOW);
    delay(100);
  }
//  digitalWrite(2, HIGH);
//  delay(150);
//  digitalWrite(2, LOW);
//  delay(150);
//  digitalWrite(2, HIGH);
//  delay(150);
//  digitalWrite(2, LOW);
//  delay(150);
//  digitalWrite(2, HIGH);
//  delay(350);
//  digitalWrite(2, LOW);
return 0;
}



void Button_input(){
  unsigned long current;
  unsigned long end;
  current = millis();
  end = millis() + 850;
  
  while  (millis()<end) {
    for (int i=0;i<9;i++)
    {
      button[i]=digitalRead(pin_nmbr);
      pin_nmbr--;
      if(button[i]== LOW)
      {
          button_nmbr=i;
//        Serial.println(i+1);
//        break;
      }
    } 
  }
}


void Print_score()
{
  Serial.println("Score:");
  Serial.println(score);
}

void check_button()
{
 if(button_nmbr==led_nmbr)
    {
      score++;
      Print_score();}
}



void loop()
{
  Random_LED();
  //delay(850);
  Button_input();
  Turn_off_LED();
  check_button();
  delay(850);
  Check_time();
  if (timing == false)
  {
    Buzzer(3);   
    exit(0);
   }
}
