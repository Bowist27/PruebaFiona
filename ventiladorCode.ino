// Definición de pines
const int sensorPin = A0;   // Pin analógico para el sensor de temperatura
const int relayPin = 2;     // Pin digital para el relé que controla el ventilador

// Variables
int sensorValue;            // Valor leído del sensor de temperatura
float temperature;          // Temperatura calculada en grados Celsius
const int threshold = 25;   // Umbral de temperatura para activar el ventilador (ejemplo)

void setup() {
  pinMode(relayPin, OUTPUT);     // Configurar el pin del relé como salida
  Serial.begin(9600);            // Iniciar comunicación serial para depuración
}

void loop() {
  // Leer el valor del sensor de temperatura
  sensorValue = analogRead(sensorPin);

  // Convertir el valor del sensor a temperatura en grados Celsius
  temperature = sensorValue * (5.0 / 1023.0 * 100.0);  // Suponiendo un sensor lineal de 0 a 100 grados Celsius

  // Imprimir valor de temperatura en el monitor serial (opcional)
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" C");

  // Verificar si la temperatura supera el umbral para activar el ventilador
  if (temperature > threshold) {
    digitalWrite(relayPin, HIGH);   // Activar el ventilador
    Serial.println("Ventilador activado");
  } else {
    digitalWrite(relayPin, LOW);    // Desactivar el ventilador
    Serial.println("Ventilador desactivado");
  }

  delay(1000);  // Espera de 1 segundo entre lecturas de temperatura
}