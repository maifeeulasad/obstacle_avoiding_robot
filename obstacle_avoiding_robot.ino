// motor one
int in1 = 9;
int in2 = 8;
// motor two
int in3 = 7;
int in4 = 6;
//sonar
const int trig = 4;
const int echo = 5;
long duration;
long durationleft;
long durationright;
long distance;
long distanceleft;
long distanceright;
void dis() // to calculate distance
{
  digitalWrite(trig, HIGH);
  delay(15);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration / 58;
}
// anyone can simply avoid leftdis() and rightdis() function
void leftdis() // to calculate and save distance in left direction
{
  digitalWrite(trig, HIGH);
  delay(15);
  digitalWrite(trig, LOW);
  durationleft = pulseIn(echo, HIGH);
  distanceleft = durationleft / 58;
}
void rightdis() // to calculate and save distance in right direction
{
  digitalWrite(trig, HIGH);
  delay(15);
  digitalWrite(trig, LOW);
  durationright = pulseIn(echo, HIGH);
  distanceright = durationright / 58;
}
void stay() // to stay in a position
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void goforward() // to go forward
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void goleft() // to go left (actually anti-clockwise 360)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void goright() // to go right (actually clockwise 360)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void gobackward() // to go backward
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  delay(2000); // it gives you extra 2 sec to after turning on robot
}
void loop() {
  dis(); // measure distance
  if (distance > 20) // if the distance is greater than 20 robot will go forward
    goforward();
  else {
    stay(); // then it will stay there for 1 sec
    delay(1000);
    goleft(); // then it will turn left for 0.1 sec
    delay(100);
    leftdis(); // it will measure distance in left direction
    goright(); // it will turn right for 0.2 sec as it previously turned left for 0.1 sec
    delay(200);
    rightdis(); // measure right distance
    goleft(); // it will turn left for 0.1 sec , in this step the robot will turn into the direction where it was at first
    delay(100);
    if (distanceleft - distanceright > 20) // if free distance in left side is greater than free distance in right side by 20 cm then it will turn left for 0.1 sec
    {
      goleft(); // why 20 cm ??
      delay(100); // for my chassis its safe  because if it is less than 20 cm  then it may  get an obstacle in it's path while turning
    } else if (distanceright - distanceleft > 20) // if free distance in right side is greater than free distance in left side by 20 cm then it will turn right for 0.1 sec
    {
      goright(); // why 20 cm ??
      delay(100); // for my chassis its safe  because if it is less than 20 cm  then it may  get an obstacle in it's path while turning
    }
  }
  delay(50); // robot will do whatever it was doing for 0.05 sec
}
