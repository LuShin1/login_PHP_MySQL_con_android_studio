const int LDR = A0;
int value = 0;
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char *ssid = "Cuetitos 2.4";
const char *password = "123456789.";
const char* mqtt_server = "68.183.119.177"; // Este es el address en mqtt dash
const char* keyDevice = "";
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
//int value = 0;
void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(300000);
  }
  Serial.println("OK");
  }
//void callback(char* topic, byte* payload, unsigned int length) {
//}


void reconnect() {

  if (!client.connected()) {

    if (client.connect(keyDevice,"","")){//Servidor broker es el usuario y prueba12 la contraseña en mqtt dash
      Serial.println("connected");
      client.subscribe("st/#"); // Topico al momento de crear el boton
    } else {
      delay(5000);
    }
  }
}
void setup() {
  Serial.begin(9600);
  Serial.println("iniciando");
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  //client.setCallback(callback);  
  
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
  value = analogRead(LDR);
  Serial.print("El valor sensor de luz es: ");
  Serial.println(value);
  delay(2000);
  client.publish("ps/ldr",String(value).c_str()); 
}

