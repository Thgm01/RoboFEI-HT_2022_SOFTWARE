from time import sleep
import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from custom_interfaces.msg import Decision 
from custom_interfaces.msg import Vision
from custom_interfaces.msg import HumanoidLeagueMsgs as GC
from custom_interfaces.msg import NeckPosition
from std_msgs.msg import Bool
from sensor_msgs.msg import Imu

# ros2 run decision_pkg decision_node
# ros2 topic pub -1 /gamestate custom_interfaces/msg/HumanoidLeagueMsgs "{game_state: 1}"
# ros2 topic pub -1 /gamestate custom_interfaces/msg/HumanoidLeagueMsgs "{game_state: 1, secondary_state_mode: 2}"
# ros2 topic pub -1 /ball_position std_msgs/Bool "data: True"

TEAM_ROBOFEI = 7
ROBOT_NUMBER = 1 # JOGADOR, PARA GOLEIRO COLOCAR 0
LADO = 0 # 0 vira para o lado DIREITO e 1 para o lado ESQUERDO, depende de que lado o nosso time vai começar



class DecisionNode(Node):

    def __init__(self):
        super().__init__('decision_node')
        self.get_logger().info('Running Decision Node')
        self.ready_robot=False
        self.publisher_ = self.create_publisher(Decision, '/decision', 10)
        # Subscriber do Game Controller
        self.subscription = self.create_subscription(
            GC,
            'gamestate',
            self.listener_callback,
            10)
        # Subscriber da visão 
        self.subscription_vision = self.create_subscription(
            Vision, 
            '/ball_position',
            self.listener_callback_vision,
            10)
        # Subscriber da posição dos motores do pescoço
        self.subscription_neck = self.create_subscription(
        NeckPosition, 
        '/neck_position',
        self.listener_callback_neck,
        10)
        self.timer=self.create_timer(0.008,self.timer_callback)
        self.subscription  
        self.subscription_vision
        self.subscription_neck
        self.BALL_DETECTED = False
        self.BALL_LEFT = False
        self.BALL_CENTER_LEFT = False
        self.BALL_RIGHT = False
        self.BALL_CENTER_RIGHT = False
        self.BALL_FAR = False # bola longe
        self.BALL_CLOSE = False # bola perto
        self.BALL_MED = False # bola centralizada
        self.distance_to_kick = 40 #real robot
        self.ready_goalie=False
        self.gamestate = 0 # Initial state - Robô parado em pé
        self.secstate = 0
        self.secteam = 0
        self.penalized = False
        self.cont_falses = 0
        self.has_kick_off = False
        self.game_already_started = True

    def listener_callback_neck(self, msg):
            self.neck_position = [msg.position19, msg.position20]

    def listener_callback_vision(self, msg):
        self.BALL_DETECTED = msg.ball_detected
        self.get_logger().info('I see the ball "%s"' % self.BALL_DETECTED)
        self.BALL_LEFT = msg.ball_left
        self.BALL_CENTER_LEFT = msg.ball_center_left
        self.BALL_RIGHT = msg.ball_right
        self.BALL_CENTER_RIGHT = msg.ball_center_right
        self.BALL_FAR = msg.ball_far
        self.BALL_MED = msg.ball_med
        self.BALL_CLOSE = msg.ball_close
           

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.game_state)
        self.gamestate = msg.game_state
        self.secstate = msg.secondary_state
        self.secteam = msg.secondary_state_team
        self.penalized = msg.penalized
        self.has_kick_off = msg.has_kick_off



    def timer_callback(self):
        message = Decision()
        if(ROBOT_NUMBER == 1): # JOGADOR
            if(self.gamestate == 0): # Initial state - Robô parado em pé
                self.ready_robot = False
                self.stand_still(message)
                self.publisher_.publish(message)
                self.get_logger().info('INITIAL: Initial State')

            elif(self.gamestate == 1 and not self.ready_robot): # Robô vai para a posição inicial
                self.get_logger().info('READY: Go to start position')
                self.walking(message) # Anda até chegar no meio de campo
                sleep(25)
                self.turn(message, 0) # Virar para a direita quando chegar no meio de campo
                sleep(3)
                self.stand_still(message) 
                sleep(2)
                self.ready_robot=True

                
                if(self.BALL_DETECTED == False):
                    self.cont_falses += 1
                    if(self.cont_falses >= 500):
                        self.search_ball(message) # Procura a bola
                        self.get_logger().info('PROCURANDOOOO ')
                	
                else:
                    self.stand_still(message)
                    self.cont_falses = 0
                    self.get_logger().info('ACHEEEEEI' )
                    
                
            elif(self.gamestate == 2): # Espera o jogo começar
                self.get_logger().info('SET: Keep ready')
                self.stand_still(message)


            elif(self.gamestate == 3): # Jogo começou
                if (self.has_kick_off and game_already_started):
                    if(not self.BALL_DETECTED):
                        self.cont_falses += 1
                        if(self.cont_falses >= 500):
                            self.search_ball(message) # Procura a bola
                            self.get_logger().info('PROCURANDOOOO ')
                        
                    else:
                        self.stand_still(message)
                        self.cont_falses = 0
                        self.get_logger().info('ACHEEEEEI' )
                        #IMPLEMENTAR COMEÇO DO JOGO PARA CHUTAR A BOLA


                        self.game_already_started = False

                elif(self.secstate == 6): # Penalti do oponente
                    self.search_ball(message)
                    if(self.BALL_FAR == True):
                        self.walking(message) 
                        sleep(8)
                        self.gait(message)
                        sleep(4)
                        self.stand_still(message)
                    else:
                        self.stand_still(message)

                elif(self.secstate == 3): # Timeout
                    self.stand_still(message)

                elif(self.secstate == 1 and self.secteam == TEAM_ROBOFEI): # Penalti nosso 
                                              # O robô deve ser colocado a uma distância da marca de pênalti de 1,5 ∗ Htop (1,5 * altura total do robô que vai atirar) = 1,35 m.
                    self.search_ball(message) # Procura a bola
                    self.kicking(message, 1)
                

                elif(self.secstate == 1 and self.secteam != TEAM_ROBOFEI): # Penalti do outro time
                    self.search_ball(message)
                    if(self.BALL_FAR == True):
                        self.walking(message) 
                        sleep(8)
                        self.gait(message)
                        sleep(4)
                        self.stand_still(message)
                    else:
                        self.stand_still(message)
                elif(self.secstate == 4 and self.secteam != TEAM_ROBOFEI): # Direct freekick do oponente
                    self.search_ball(message)
                    if(self.BALL_FAR == True):
                        self.walking(message) 
                        sleep(8)
                        self.gait(message)
                        sleep(4)
                        self.stand_still(message)
                    else:
                        self.stand_still(message)
                elif(self.secstate == 5 and self.secteam != TEAM_ROBOFEI): # Indirect freekick do oponente
                    self.search_ball(message)
                    if(self.BALL_FAR == True):
                        self.walking(message) 
                        sleep(8)
                        self.gait(message)
                        sleep(4)
                        self.stand_still(message)
                    else:
                        self.stand_still(message)
                elif(self.secstate == 7 and self.secteam != TEAM_ROBOFEI): # Escanteio do oponente
                    self.search_ball(message)
                    if(self.BALL_FAR == True):
                        self.walking(message) 
                        sleep(8)
                        self.gait(message)
                        sleep(4)
                        self.stand_still(message)
                    else:
                        self.stand_still(message)
                
                elif(self.secstate == 8): # Tiro de meta do goleiro
                    self.stand_still(message)

                elif(self.secstate == 9 and self.secteam != TEAM_ROBOFEI): # Lateral do oponente
                    self.search_ball(message)
                    if(self.BALL_FAR == True):
                        self.walking(message) 
                        sleep(8)
                        self.gait(message)
                        sleep(4)
                        self.stand_still(message)
                    else:
                        self.stand_still(message)
                        
                elif(self.penalized==True):
                    self.stand_still(message)

                else: 
                    if(self.BALL_DETECTED == False):
                        self.cont_falses += 1
                        self.search_ball(message) # Procura a bola
                        self.get_logger().info('PROCURANDOOOO')
                        if(self.cont_falses>=4000):
                            self.stand_still(message)
                            sleep(2)
                            self.walking(message) 
                            sleep(8)
                            self.gait(message)
                            sleep(4)
                            self.get_logger().info('ANDANDO SEM BOLA ACHADA')
                            self.cont_falses = 0
                	
                    else:
                        self.get_logger().info('BALL DETECTED "%s"' % self.BALL_DETECTED)
                        self.stand_still(message)
                        self.cont_falses = 0
                        if(self.BALL_LEFT==True):
                            self.turn(message, 1)
                        elif (self.BALL_RIGHT==True):
                            self.turn(message, 0) # Vira para o lado direito
                        if(self.BALL_LEFT==True):
                            self.turn_head_left(message)
                        elif(self.BALL_RIGHT==True):
                            self.turn_head_right(message)
                        if (self.BALL_CENTER_LEFT or self.BALL_CENTER_RIGHT) and (self.neck_position[19] >=1948 or self.neck_position[19]<=2148):
                            if(self.BALL_FAR==True):
                                self.get_logger().info('LONGEEEEEEEE')
                                self.stand_still(message)
                                sleep(2)
                                self.walking(message) 
                                sleep(10)
                                self.gait(message)
                                sleep(4)
                            if(self.BALL_MED==True):
                                self.get_logger().info('MEDIOOOOOOOOOOOOO')
                                self.stand_still(message)
                                sleep(2)
                                self.walking(message) 
                                sleep(4)
                                self.gait(message)
                                sleep(4)
                            if(self.BALL_CLOSE==True and self.BALL_CENTER_LEFT==True):
                                self.get_logger().info('PERTOOOOOOOOO ESQ')
                                self.kicking(message, 0) # chuta com pe esquerdo
                            if(self.BALL_CLOSE==True and self.BALL_CENTER_RIGHT==True):
                                self.get_logger().info('PERTOOOOOOOOO DIR')
                                self.kicking(message, 1) # chuta com pe direito


            elif(self.gamestate == 4): # Jogo terminou, robô sai do campo
                self.stand_still(message)
        
        elif(ROBOT_NUMBER == 0): # GOLEIRO
            if(msg.game_state == 0): # Initial state - Robô parado em pé
                self.stand_still(message)
                self.get_logger().info('INITIAL: Initial State')

            elif(msg.game_state == 1): # Robô vai para a posição inicial
                self.get_logger().info('READY: Go to start position')
                if(ready_goalie==False):
                    self.walking(message) 
                    sleep(10)
                    self.turn(message, 0) # Virar para a direita quando chegar no meio de campo
                    sleep(6)
                    ready_goalie=True
                if(self.BALL_DETECTED == False):
                	self.search_ball(message) # Procura a bola
                else:
                    self.stand_still(message)

            elif(msg.game_state == 2): # Espera o jogo começar
                self.get_logger().info('Keep ready')
                self.stand_still(message)

            elif(msg.game_state == 3): # Jogo começou
                self.search_ball(message)
                if(self.BALL_DETECTED == True):  # Bola achada
                    if BALL_LEFT ==  True:  
                        self.goalkeeper(message, 1) # Bola na esquerda se joga para a esquerda
                    elif BALL_RIGHT ==  True: 
                        self.goalkeeper(message, 2) # Bola na direita se joga para a direita
                    else: # A bola está alinhada, goleiro agacha
                        self.goalkeeper(message, 0) 
                if(self.BALL_LEFT==True):
                    self.turn(message, 1) # Vira para o lado direito
                    sleep(8)
                elif (self.BALL_RIGHT==True):
                    self.turn(message, 0) # Vira para o lado direito
                    sleep(8)
                if(self.BALL_FAR==True):
                    self.walking(message) 
                    sleep(8)
                    self.gait(message)
                    sleep(4)
                if(self.BALL_MED==True):
                    self.walking(message) 
                    sleep(4)
                    self.gait(message)
                    sleep(4)
                if(self.BALL_CLOSE==True and self.BALL_CENTER_LEFT==True):
                    self.kicking(message, 0) # chuta com pe esquerdo
                if(self.BALL_CLOSE==True and self.BALL_CENTER_RIGHT==True):
                    self.kicking(message, 1) # chuta com pe direito

            elif(msg.game_state == 4): # Jogo terminou, robô sai do campo
                self.stand_still(message)

        

    def stand_still(self, message): # Robô em pé parado
        message.decision = 1
        self.publisher_.publish(message)
        self.get_logger().info('Publishing: "%d"' % message.decision)

    def kicking(self, message, side):
        if(side == 1): # Chuta com pé direito
            message.decision = 3 
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)
        else:
            message.decision = 4 # Chuta com o pé esquerdo
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)
        sleep(3)

    def walking(self, message):
        message.decision = 14 # Anda
        self.publisher_.publish(message)
        self.get_logger().info('Publishing: "%d"' % message.decision)

    def gait(self, message):
        message.decision = 15 # Gait
        self.publisher_.publish(message)
        self.get_logger().info('Publishing: "%d"' % message.decision)

    def search_ball(self, message):
        message.decision = 8 # Move o motor da cabeça para o robô procurar a bola
        self.publisher_.publish(message)
        self.get_logger().info('Publishing: "%d"' % message.decision)

    def turn(self, message, side):
        if(side == 0):
            message.decision = 5 # Direita
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)
        else:
            message.decision = 6 # Esquerda
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)

    def turn_around_ball(self, message, side):
        if (side == 0):
            message.decision = 9 # Horario
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)
        else:
            message.decision = 10 # Antihorario
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)
        sleep(4)

    def turn_around_ball(self, message, side):
        if (side == 0):
            message.decision = 9 # Horario
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)
        else:
            message.decision = 10 # Antihorario
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)
        sleep(4)

    def goalkeeper(self, message, action):
        if(action == 0): # Agachar
            message.decision = 13
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)
        elif(action == 1): # Se joga para a esquerda
            message.decision = 11 
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)
        elif(action == 2): # Se joga para a direita
            message.decision = 12 
            self.publisher_.publish(message)
            self.get_logger().info('Publishing: "%d"' % message.decision)

    def turn_head_left(self, message):
        message.decision = 20
        self.publisher_.publish(message)
        self.get_logger().info('Publishing: "%d"' % message.decision)

def main(args=None):
    rclpy.init(args=args)

    decisionNode = DecisionNode()

    rclpy.spin(decisionNode)
    decisionNode.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()