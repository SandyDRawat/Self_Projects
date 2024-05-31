const int trigger = 9; //Trigger pin of 1st Sesnor
const int echo = 10; //Echo pin of 1st Sesnor


long time_taken;
int dist,distance;

void setup() {
Serial.begin(9600); 
  
pinMode(trigger, OUTPUT); 
pinMode(echo, INPUT); 

}

void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>60)
dist = 60;
}

void loop() { 
calculate_distance(trigger,echo);
distance = dist; 

if ((distance > 40 && distance < 50 )) 
{Serial.println("Play/Pause"); delay (500);}

calculate_distance(trigger,echo);
distance=dist;

if ((distance < 9)) 
{Serial.println("next"); delay (500);}

calculate_distance(trigger,echo);
distance=dist;

if ((distance > 24 && distance < 40)) 
{Serial.println("Vdown"); delay (500);}

calculate_distance(trigger,echo);
distance=dist;

if ((distance > 9 && distance < 24))
{Serial.println("Vup"); delay (500);}

calculate_distance(trigger,echo);
distance=dist;

delay (200);
}
