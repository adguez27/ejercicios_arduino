int8_t ctr1 = 0;
int8_t ctr2 = 0;
uint8_t n = 0;
String c1 = String(ctr1);
String c2 = String(ctr2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(100);
  ctr1++;
  c1 = String(ctr1);
  Serial.println( "C1:{" + c1 + "}");
  n++;
  if(n==20){
    n=0;
    ctr2++;
    c2 = String(ctr2);
    Serial.println( "C2:{" + c2 + "}");
    ctr1 -= ctr2;
  }
  
}
