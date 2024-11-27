unsigned long t;
uint8_t c = 0;
void setup() {
  Serial.begin(9600);
  t = millis();
}

void loop() {
  unsigned long curr_time = millis();
  if(curr_time-t>=1000){
    Serial.println(c);
    c++;
    t = curr_time;
  }
}