#include <Arduino.h>
#include <Servo.h>

Servo fs90rDroit;
Servo fs90rGauche;

#define Rouge A0
#define Vert A1
#define Jaune A2

void clignoter(int pin, int repetitions) {
  // for (int i = 0; i < repetitions; i++) {
  //   digitalWrite(pin, HIGH);
  //   delay(500);
  //   digitalWrite(pin, LOW);
  //   delay(500);
  // }
}

void executerCommande(String commande, int repetition) {
  if (commande == "AV") {
    fs90rDroit.write(180);
    fs90rGauche.write(0);
    delay(500 * repetition);
    fs90rDroit.write(90);
    fs90rGauche.write(90);
    clignoter(Jaune, repetition);
  }
  else if (commande == "RE") {
    fs90rDroit.write(0);
    fs90rGauche.write(180);
    delay(500 * repetition);
    fs90rDroit.write(90);
    fs90rGauche.write(90);
    clignoter(Jaune, repetition);
  }
  else if (commande == "TG") {
    fs90rDroit.write(0);
    fs90rGauche.write(0);
    delay(500 * repetition);
    fs90rDroit.write(90);
    fs90rGauche.write(90);
    clignoter(Vert, repetition);
  }
  else if (commande == "TD") {
    fs90rDroit.write(180);
    fs90rGauche.write(180);
    delay(500 * repetition);
    fs90rDroit.write(90);
    fs90rGauche.write(90);
    clignoter(Vert, repetition);
  }
  else {
    Serial.println("Commande inconnue : " + commande);
    clignoter(Rouge, 3);
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }
  pinMode(Rouge, OUTPUT);
  pinMode(Vert, OUTPUT);
  pinMode(Jaune, OUTPUT);

  fs90rDroit.attach(9); // Le servo droit est connecté à la broche D9
  fs90rGauche.attach(8); // Le servo gauche est connecté à la broche D8
}

int index = 0;
// String message = "TG5TD3AV4R E2"; // Exemple de message pour tester

void loop() {
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    message.trim(); // Enlève les espaces / retours à la ligne

    Serial.print("Reçu : ");
    Serial.println(message);

    String commande = "";
    int repetition = 1;

    while (index < message.length()) {
    String cmd = message.substring(index, index + 2);
    index += 2;

    String nombre = "";
    while (index < message.length() && isDigit(message[index])) {
      nombre += message[index];
      index++;
    }

    int repetition = nombre.toInt();
    executerCommande(cmd, repetition);
  }

    

    message = ""; // Réinitialiser le message après traitement
  }
}


// #include <Servo.h>
// #include <Arduino.h>

// Servo servoGauche;
// Servo servoDroit;

// void avancer() {
//   servoGauche.write(0);     // Avant
//   servoDroit.write(180);    // Avant
// }

// void reculer() {
//   servoGauche.write(180);   // Arrière
//   servoDroit.write(0);      // Arrière
// }

// void tournerGauche() {
//   servoGauche.write(180);   // Recule
//   servoDroit.write(180);    // Avance
// }

// void tournerDroite() {
//   servoGauche.write(0);     // Avance
//   servoDroit.write(0);      // Recule
// }

// void stopServos() {
//   servoGauche.write(90);    // Stop
//   servoDroit.write(90);     // Stop
// }


// void executeCommand(String cmd) {
//   int len = cmd.length();
//   int i = 0;
//   while (i < len) {
//     String action = cmd.substring(i, i + 2);
//     i += 2;

//     if (action == "NR") {
//       i += 1; // skip 'F'
//       stopServos();
//       delay(1000);
//       continue;
//     }

//     // Lire la valeur (jusqu'à un autre code ou fin)
//     String val = "";
//     while (i < len && isDigit(cmd.charAt(i))) {
//       val += cmd.charAt(i);
//       i++;
//     }

//     int n = val.toInt();

//     if (action == "AV") {
//       avancer();
//       delay(n * 500); // approx. 500ms pour 10 cm (à calibrer)
//       stopServos();
//     } else if (action == "RE") {
//       reculer();
//       delay(n * 500);
//       stopServos();
//     } else if (action == "TG") {
//       tournerGauche();
//       delay(n * 20); // approx. 20ms par degré (à ajuster)
//       stopServos();
//     } else if (action == "TD") {
//       tournerDroite();
//       delay(n * 20);
//       stopServos();
//     }
//   }
// }

// void setup() {
//   Serial.begin(9600);
//   servoGauche.attach(5); // Pin pour le servo gauche
//   servoDroit.attach(6);  // Pin pour le servo droit
//   stopServos();
// }

// void loop() {
//   if (Serial.available()) {
//     String cmd = Serial.readStringUntil('\n');
//     cmd.trim();
//     Serial.println("Command received: " + cmd);
//     if (cmd.length() == 0) {
//       Serial.println("Empty command received, ignoring.");
//       return; // Ignore empty commands
//     }
//     executeCommand(cmd);
//   }
// }

// #include <Arduino.h>

// #define Rouge A0
// #define Vert A1
// #define Jaune A2

// int message = 0;
// int couleurs[] = {Rouge, Vert, Jaune};

// void setup() {
//   Serial.begin(9600);
//   pinMode(Rouge, OUTPUT);
//   pinMode(Vert, OUTPUT);
//   pinMode(Jaune, OUTPUT);
// }

// void loop() {
//   // if (Serial.available())  {
//   //   message = Serial.read() - '0';
//   //   if (message > 3) {
//   //     digitalWrite(couleurs[message-4], LOW);
//   //   }
//   //   else {
//   //     digitalWrite(couleurs[message-1], HIGH);
//   //   }
//   // }
//   digitalWrite(Rouge, HIGH);
//   delay(1000);
//   digitalWrite(Rouge, LOW);
//   delay(1000);

//   digitalWrite(Vert, HIGH);
//   delay(1000);
//   digitalWrite(Vert, LOW);
//   delay(1000);

//   digitalWrite(Jaune, HIGH);
//   delay(1000);
//   digitalWrite(Jaune, LOW);
//   delay(1000);
// }

// #include <Arduino.h>

// #define Rouge A0

// #define Vert A1

// #define Jaune A2

// void setup() {
//   Serial.begin(9600);
//   while (!Serial) {
//     ; // Attend que la connexion série soit établie (nécessaire sur certains Arduino)
//   }
//   pinMode(Rouge, OUTPUT);
//   pinMode(Vert, OUTPUT);
//   pinMode(Jaune, OUTPUT);
// }

// void loop() {
//   if (Serial.available()) {
//     String message = Serial.readStringUntil('\n');
//     Serial.print("Reçu : ");
//     Serial.println(message);
//     if (message == "AV")
//     {
//       digitalWrite(Rouge, HIGH); // Allume la LED rouge
//       delay(1000);
//       digitalWrite(Rouge, LOW); // Éteint la LED rouge
//     } 
    
//     if (message == "T")
//     {
//       digitalWrite(Vert, HIGH); // Allume la LED rouge
//       delay(1000);
//       digitalWrite(Vert, LOW); // Éteint la LED rouge
//     }
    
//     if (message == "RE")
//     {
//       digitalWrite(Jaune, HIGH); // Allume la LED rouge
//       delay(1000);
//       digitalWrite(Jaune, LOW); // Éteint la LED rouge
//     } 
//   }
// }