int8_t ctr1 = 0;
int8_t ctr2 = 0;
uint8_t n = 0;
unsigned long t;
String c1 = String(ctr1);
String c2 = String(ctr2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  t = micros();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long curr_time = micros();
  if(curr_time-t>=100000){
  ctr1++;
  c1 = String(ctr1);
  Serial.println( "C1:{" + c1 + "}");
  n++;
  t = curr_time;
  if(n==20){
    n=0;
    ctr2++;
    c2 = String(ctr2);
    Serial.println( "C2:{" + c2 + "}");
    ctr1 -= ctr2;
  }
  }
  
}
