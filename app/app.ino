#define portTICK_PERIOD_MS ((TickType_t)(1000 / configTICK_RATE_HZ))
TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
int mode = 0; //0 fijo, 1 alt
int active = 0;//0 apagado, 1 encendido

void show_help(){
   Serial.println("H o h (help): muestra este menu de ayuda.");
   Serial.println("START o start: publica cada segundo un valor por el puerto serie");
   Serial.println("STOP o stop: detiene la publicación del valor.");
   Serial.println("T o t (time): El siguiente valor enviado cambiará el periodo de publicación de la señal entre 1 y 10 veces por segundo.");
   Serial.println("M o m (mode): cambia el modo de fijo a alternativo. En modo fijo la señal se emite mantiene siempre el mismo valor siendo el ultimo emitido, por defecto debe ser un 1. Por otra parte, en modo alternativo cada vez que se publica el valor se alterna entre 0 y 1");
}
void setup() {
  
  Serial.begin(9600);
  delay(1000);
  show_help();
  if(xTaskCreate( task_cont, "task_cont", 2048, NULL, 1, NULL) != pdPASS){
		Serial.println("Error en creacion tarea task_con");
		exit(-1);
	}
}

void loop() {
  String s = "";

  while (Serial.available() == 0) {
  }

  s = Serial.readString();
  s.trim();

  if (s.equalsIgnoreCase("h")) {
    show_help();  
  }

  else if (s.equalsIgnoreCase("start")) {
    active = 1;   
    Serial.println("Publicación activada");
  }

  else if (s.equalsIgnoreCase("stop")) {
    active = 0;   
    Serial.println("Publicación detenida");
  }

  else if (s.equalsIgnoreCase("t")) {
    
    if (xDelay == 1000 / portTICK_PERIOD_MS) {
      xDelay = 100 / portTICK_PERIOD_MS;
    } else {
      xDelay = 1000 / portTICK_PERIOD_MS;
    }
    Serial.println("xDelay alternado");
  }

  else if (s.equalsIgnoreCase("m")) {
   
    mode = (mode == 0) ? 1 : 0;
    Serial.println("Modo alternado");
  }
}

void task_cont(void *pvParameter) {
     int toggle = 0;  

    while(1) {
        if (active == 1) {
            if (mode == 0) {
                Serial.println("1");  
            } 
            else if (mode == 1) {
                Serial.println(toggle);
                toggle = 1 - toggle;  
            }
        }
    	vTaskDelay(xDelay);
    }
     
  }