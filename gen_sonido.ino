/*************************************************** 
  Proyecto Generador de Sonidos R2D2
  
  Para todos los fans de StarWars y Arduino!

  Escrito por Marcelo Larios
  
  Licencia BSD, todo el texto anterior debe ser incluido en cualquier redistribución
  
  Participó en el concurso Instructable Arduino 2019
  https://www.instructables.com/R2D2-Sound-Generator/
****************************************************/ 

#define SPKR_PIN 11  // Pin del altavoz
#define LED_PIN 13   // Pin del LED

void setup() {
    pinMode(SPKR_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    randomSeed(analogRead(0)); // Inicializa el generador de números aleatorios
}

void frase1() {
    int freq = random(1000, 2000); // Frecuencia base aleatoria
    digitalWrite(LED_PIN, HIGH);
    for (int i = 0; i <= random(100, 2000); i++) {
        tone(SPKR_PIN, freq - (i * 2)); // Genera tono decreciente
        delay(random(1, 3)); // Retraso aleatorio
    } 
    digitalWrite(LED_PIN, LOW);   
    for (int i = 0; i <= random(100, 1000); i++) {
        tone(SPKR_PIN, freq + (i * 10)); // Genera tono creciente
        delay(random(1, 3)); // Retraso aleatorio
    } 
    noTone(SPKR_PIN); // Asegúrate de que no quede tono sonando
}

void frase2() {
    int freq = random(1000, 2000); // Frecuencia base aleatoria
    digitalWrite(LED_PIN, HIGH);  
    for (int i = 0; i <= random(100, 2000); i++) {
        tone(SPKR_PIN, freq + (i * 2)); // Genera tono creciente
        delay(random(1, 3)); // Retraso aleatorio
    } 
    digitalWrite(LED_PIN, LOW);   
    for (int i = 0; i <= random(100, 1000); i++) {
        tone(SPKR_PIN, freq - (i * 10)); // Genera tono decreciente
        delay(random(1, 3)); // Retraso aleatorio
    } 
    noTone(SPKR_PIN); // Asegúrate de que no quede tono sonando
}

void loop() {
    int baseFreq = 2000; // Frecuencia base para los tonos
    switch (random(1, 7)) {
        case 1: frase1(); break;
        case 2: frase2(); break;
        case 3: frase1(); frase2(); break;
        case 4: frase1(); frase2(); frase1(); break;
        case 5: frase1(); frase2(); frase1(); frase2(); frase1(); break;
        case 6: frase2(); frase1(); frase2(); break;
    }
    for (int i = 0; i <= random(3, 9); i++) {
        digitalWrite(LED_PIN, HIGH);  
        tone(SPKR_PIN, baseFreq + random(-1700, 2000)); // Genera tono aleatorio
        delay(random(70, 170)); // Retraso aleatorio
        digitalWrite(LED_PIN, LOW);           
        noTone(SPKR_PIN);         
        delay(random(0, 30)); // Retraso aleatorio         
    } 
    noTone(SPKR_PIN);         
    delay(random(2000, 4000)); // Retraso antes de repetir el ciclo            
}
