int wheelLeftFront = 9, wheelLeftBack = 10;  
int wheelRightFront = 6, wheelRightBack = 5;
byte LED[3] = {7,8,4};

int trig = 2, echo = 3;
int trig2 = 12, echo2 = 11;   // 초음파센서 설정
int spdL = 130, spdR = 150;
int sppL = -500, sppR = -500;      // 속도

void setup() { 
   Serial.begin(9600);
   pinMode(trig, OUTPUT);
   pinMode(trig2, OUTPUT);
   pinMode(echo, INPUT);
   pinMode(echo2, INPUT);
   pinMode(wheelLeftFront, OUTPUT);
   pinMode(wheelLeftBack, OUTPUT);
   pinMode(wheelRightFront, OUTPUT);
   pinMode(wheelRightBack, OUTPUT);
   for(int i=0;i<3;i++)
   {
    pinMode(LED[i], OUTPUT);
   }
}
void loop() {
  //초음파센서 거리 측정 및 시리얼 모니터 출력 
  float distance, duration;
  digitalWrite(trig, LOW);    //초기화 
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;
  Serial.println(distance);
 
  if(distance > 15)
  // 장해물이 앞에 없을 때 전진, 초록
  {
    digitalWrite(LED[0], HIGH);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], LOW);
    analogWrite(wheelLeftFront, spdL);
    analogWrite(wheelLeftBack, 0);
    analogWrite(wheelRightFront, spdR);
    analogWrite(wheelRightBack, 0);
  }
  else if(distance > 10) //노랑
  {
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], HIGH);
    digitalWrite(LED[2], LOW);
    analogWrite(wheelLeftFront, spdL);
    analogWrite(wheelLeftBack, 0);
    analogWrite(wheelRightFront, spdR);
    analogWrite(wheelRightBack, 0);
  }
  else if(distance < 10)
  {
    // 장해물이 15cm 이내에 있을 경우 방향전환, 빨강
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], HIGH);
    int rd = random(2); // 좌, 우 랜덤 선택 랜덤 값(0,1)
    int delayed = random(200,500);
    if(rd == 1)
    {
      // 좌회전
      analogWrite(wheelLeftFront, 0);
      analogWrite(wheelLeftBack, spdL);
      analogWrite(wheelRightFront, spdR);
      analogWrite(wheelRightBack, 0);
    }
    else
    {
      // 우회전
      analogWrite(wheelLeftFront, spdL);
      analogWrite(wheelLeftBack, 0);
      analogWrite(wheelRightFront, 0);
      analogWrite(wheelRightBack, spdR);
    }
    delay(delayed);
  }


  float distance1, duration1;
  digitalWrite(trig2, LOW);   //초기화
  digitalWrite(trig2, HIGH);
  delay(1);
  digitalWrite(trig2, LOW);
  duration1 = pulseIn(echo2, HIGH);
  distance1 = ((float)(340 * duration1) / 10000) / 2;
  Serial.println(distance1);
  
    
    if(distance1 > 10)
    {
      if(distance > 10)
      {
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], HIGH);
    
      analogWrite(wheelLeftFront, sppL);
      analogWrite(wheelLeftBack, spdL);
      analogWrite(wheelRightFront, sppR);
      analogWrite(wheelRightBack, spdL);

      delay(1000);

      analogWrite(wheelLeftFront, 0);
      analogWrite(wheelLeftBack, spdL);
      analogWrite(wheelRightFront, 0);
      analogWrite(wheelRightBack, spdR);

      delay(500);

      int rd = random(2); // 좌, 우 랜덤 선택 랜덤 값(0,1)
    int delayed = random(200,500);
    if(rd == 1)
    {
      // 좌회전
      analogWrite(wheelLeftFront, 0);
      analogWrite(wheelLeftBack, spdL);
      analogWrite(wheelRightFront, spdR);
      analogWrite(wheelRightBack, 0);
    }
    else
    {
      // 우회전
      analogWrite(wheelLeftFront, spdL);
      analogWrite(wheelLeftBack, 0);
      analogWrite(wheelRightFront, 0);
      analogWrite(wheelRightBack, spdR);
    }
    delay(delayed);
  }
      }
    }
