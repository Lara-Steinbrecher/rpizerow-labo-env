#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/sched/signal.h>

// Variables globales para kernel threads
static struct task_struct *kthread1 = NULL;
static struct task_struct *kthread2 = NULL;

// TODO:
// Funciones para los hilos
static int hilo1(void *params) {
	// Creacion de variables

	// Bucle mientras que la tarea no sea detenida
	while(!kthread_should_stop()) {
		// Tareas recurrentes
	printk("Steinbrecher_Lara_ej02: Hola desde el primer hilo :D");
	msleep(100);
	}
	// Finalizacion del hilo
	return 0;
}
static int hilo2(void *params) {
	// Creacion de variables

	// Bucle mientras que la tarea no sea detenida
	while(!kthread_should_stop()) {
		// Tareas recurrentes
	printk("Steinbrecher_Lara_ej02: Hola desde el segundo hilo D:");
	msleep(100);
	}
	// Finalizacion del hilo
	return 0;
}
/**
 * @brief Se llama cuando se carga en el kernel
*/
static int __init ej02_module_init(void) {
	// TODO:
	// - Crear ambos hilos
	kthread1 = kthread_create(hilo1,NULL,"kthread1");
	if (kthread1 == NULL){
	printk("Steinbrecher_Lara_ej02: error no se pudo crear hilo 1");
}
	wake_up_process(kthread1);
	kthread2 = kthread_create(hilo2,NULL,"kthread2");
	if(kthread2 == NULL){
	printk ("Steinbrecher_Lara_ej02: error no se pudo crear hilo 2");
}
	wake_up_process(kthread2);
	// - Verificar que se hayan podido crear
	// - Correr hilos
	return 0;
}

/**
 * @brief Se llama cuando se retira del kernel
*/
static void __exit ej02_module_exit(void) {
	// TODO:
	// - Detener hilos
	kthread_stop(kthread1);
	kthread_stop(kthread2);
}

// Registro funciones de inicializacion y salida
module_init(ej02_module_init);
module_exit(ej02_module_exit);

// Informacion del modulo (completar lo que corresponda)
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Steinbrecher_Lara");
MODULE_DESCRIPTION("Creamos 2 hilos y corre uno luego el otro asi hasta que el programa se detenga");
