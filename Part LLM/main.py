import requests
import json

prompt = "Tourne à gauche de 90° puis tourne à droite 60° et avance de 5 !"

resp = requests.post(
    'http://localhost:11434/api/generate',
    json={'model': 'mistral', 'prompt': f'Tu es un robot capable de se déplacer disant * puis des codes : avancer de 10cm : AV1, reculer de 10cm : RE1, tourner à gauche de 10° : TG10, tourner à droite de 10° : TD10, ne rien faire : NRF. L utilisateur te donne des ordres et tu réponds. Voici ces ordres : {prompt}. Répond sans expliquation !'},
    stream=True
)
buffer = ""
for line in resp.iter_lines():
    if not line:
        continue
    data = json.loads(line)
    chunk = data.get("response", "")
    buffer += chunk  # si tu veux garder l'effet en streaming
    if buffer.endswith((" ", "\n")) or len(buffer) > 80 or data.get("done", False):
        print(buffer, end="", flush=True)
        buffer = ""

# # # #
# # # # import pygame
# # # # import math
# # # # import time
# # # #
# # # # # Initialisation de Pygame
# # # # pygame.init()
# # # # WIDTH, HEIGHT = 800, 600
# # # # WIN = pygame.display.set_mode((WIDTH, HEIGHT))
# # # # pygame.display.set_caption("Simulateur Robot Animé")
# # # #
# # # # # Constantes
# # # # WHITE = (255, 255, 255)
# # # # BLACK = (0, 0, 0)
# # # # ROBOT_COLOR = (0, 200, 0)
# # # # ROBOT_SIZE = 15
# # # # SCALE = 10  # 10 cm = 10 pixels
# # # # FPS = 60
# # # #
# # # # clock = pygame.time.Clock()
# # # #
# # # # # État initial
# # # # x, y = WIDTH // 2, HEIGHT // 2
# # # # angle = 0  # en degrés
# # # #
# # # # def draw_robot(x, y, angle):
# # # #     WIN.fill(WHITE)
# # # #     end_x = x + ROBOT_SIZE * math.cos(math.radians(angle))
# # # #     end_y = y - ROBOT_SIZE * math.sin(math.radians(angle))
# # # #     pygame.draw.circle(WIN, ROBOT_COLOR, (int(x), int(y)), ROBOT_SIZE)
# # # #     pygame.draw.line(WIN, BLACK, (x, y), (end_x, end_y), 3)
# # # #     pygame.display.update()
# # # #
# # # # def rotate_robot(current_angle, target_angle, clockwise=True):
# # # #     step = -2 if clockwise else 2
# # # #     while (clockwise and current_angle > target_angle) or (not clockwise and current_angle < target_angle):
# # # #         current_angle += step
# # # #         draw_robot(x, y, current_angle)
# # # #         clock.tick(FPS)
# # # #     return target_angle
# # # #
# # # # def move_robot(x, y, angle, distance_px):
# # # #     steps = int(distance_px)
# # # #     for _ in range(steps):
# # # #         x += math.cos(math.radians(angle))
# # # #         y -= math.sin(math.radians(angle))
# # # #         draw_robot(x, y, angle)
# # # #         clock.tick(FPS)
# # # #     return x, y
# # # #
# # # # # Exemple d'instructions
# # # # instructions = full_response
# # # # commands = instructions.split(',')
# # # #
# # # # # Exécution des commandes
# # # # for command in commands:
# # # #     command = command.strip()
# # # #     time.sleep(0.5)
# # # #
# # # #     if command.startswith("TG"):
# # # #         deg = int(command[2:])
# # # #         target = (angle + deg) % 360
# # # #         angle = rotate_robot(angle, target, clockwise=False)
# # # #
# # # #     elif command.startswith("TD"):
# # # #         deg = int(command[2:])
# # # #         target = (angle - deg) % 360
# # # #         angle = rotate_robot(angle, target, clockwise=True)
# # # #
# # # #     elif command.startswith("AV"):
# # # #         steps = int(command[2:])
# # # #         x, y = move_robot(x, y, angle, steps * SCALE)
# # # #
# # # #     elif command.startswith("RE"):
# # # #         steps = int(command[2:])
# # # #         reverse_angle = (angle + 180) % 360
# # # #         x, y = move_robot(x, y, reverse_angle, steps * SCALE)
# # # #
# # # #     time.sleep(0.5)
# # # #
# # # # # Boucle pour garder la fenêtre ouverte
# # # # running = True
# # # # while running:
# # # #     for event in pygame.event.get():
# # # #         if event.type == pygame.QUIT:
# # # #             running = False
# # # #
# # # # pygame.quit()
# #
# # import serial
# # import time
# #
# # # Port série : à adapter (vérifie avec `ls /dev/tty*`)
# # # ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# # ser = serial.Serial('COM3', 9600, timeout=1)
# #
# # time.sleep(2)  # Laisser le temps à l'Arduino de démarrer
# #
# # def envoyer_instruction(code):
# #     print(f"Envoi de la commande : {code}")
# #     ser.write((code + '\n').encode())  # \n déclenche la lecture côté Arduino
# #
# # if __name__ == "__main__":
# #     print("Tu es un robot capable de se déplacer.")
# #     print("Commande :")
# #     print("  AVx  - avancer de x×10cm")
# #     print("  REx  - reculer de x×10cm")
# #     print("  TGx  - tourner à gauche de x°")
# #     print("  TDx  - tourner à droite de x°")
# #     print("  NRF  - ne rien faire")
# #
# #     try:
# #         while True:
# #             commande = input("Entre une commande (ex: TG90TD60AV5) : ").strip().upper()
# #             if commande:
# #                 envoyer_instruction(commande)
# #
# #     except KeyboardInterrupt:
# #         print("\nFin du programme.")
# #         ser.close()
# #
#
# # import serial
# #
# # ser = serial.Serial('/dev/ttyXXXX', 9600)
# # # ser = serial.Serial('COM3', 9600)
# # print("CTRL + C pour arrêter")
# #
# # while True :
# # 	led = int(input('Quelle LED souhaitez-vous allumer / eteindre ? (Rouge=1 / Vert=2 / Bleu=3)'))
# # 	action = input("Souhaitez-vous allumer ou Eteindre la LED ? (Allumer=1 / Eteindre=0)")
# # 	if (action == 1) :
# # 		ser.write(str(led))
# # 	else :
# # 		msg = led+3
# # 		ser.write(str(msg))
#
# import serial
# import time
#
# # Remplace 'COM3' par le port série correspondant (ex: '/dev/ttyUSB0' sur Linux)
# arduino = serial.Serial(port='COM3', baudrate=9600, timeout=1)
# time.sleep(2)  # Laisse le temps à l'Arduino de redémarrer
#
# message = "RE1TG1TD2"
# arduino.write(message.encode('utf-8'))  # Envoie le message
# print("Message envoyé.")
#
# arduino.close()
