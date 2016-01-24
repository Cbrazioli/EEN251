/**
 * IMT - Rafael Corsi
 * Simples LED 
*/

#include <asf.h>

/** 
 * Definição dos pinos
 * Pinos do uC referente aos LEDS
 */
#define PIN_LED_BLUE 19
#define PIN_LED_GREN 20
#define PIN_LED_RED	 20

/** 
 * Definição dos ports
 * Ports referentes a cada pino
 */
#define PORT_LED_BLUE PIOA
#define PORT_LED_GREN PIOA
#define PORT_LED_RED  PIOC

/** 
 * Criando os pinos
 * Criamos a entidade dos leds, necessário para as funções
 * que lidam com o IO: ioport
 */
#define LED_GREN IOPORT_CREATE_PIN(PIOA, PIN_LED_GREN)
#define LED_BLUE IOPORT_CREATE_PIN(PIOA, PIN_LED_BLUE)
#define LED_RED  IOPORT_CREATE_PIN(PIOC, PIN_LED_GREN)

int main (void)
{

	/**
	* Inicializando o clock do uP
	*/
	sysclk_init();
	
	
	/** 
	*  Desabilitando o WathDog do uP
	*/
	WDT->WDT_MR = WDT_MR_WDDIS;

	/** 
	* Inicializamos aqui as funcoes de acesso aos IOS
	* IOPORT
	*/
	ioport_init();
	
	/** 
	* Configuramos os pinos referentes aos LEDs como saída
	*/
	ioport_set_pin_dir(LED_GREN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED_BLUE, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED_RED,  IOPORT_DIR_OUTPUT);

    /**
	*  Setando o nível de sinal em cada pino
	*/
	ioport_set_pin_level(LED_BLUE,0); // 1 apaga  led, 
	ioport_set_pin_level(LED_RED ,0); // 1 acende led,
	ioport_set_pin_level(LED_GREN,0); // 0 acende led
		
	/**
	*	Loop infinito
	*/
		while(1){		
	}
}

