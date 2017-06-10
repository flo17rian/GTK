#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Struktur wird definiert.
struct elemente
{
	//erstellen eines Objektes
	GtkWidget *Fenster;		//Vokabeltrainer
	GtkWidget *Fenster1;		//TEST 2. Menü punkt
	GtkWidget *Schachtel; 		//erstellen eines Schachtelbausteins um mehrere Widgets in ein Fenster einzubinden
	GtkWidget *Schachtel1;		//TEST zweite Darstellung im Fenster
	GtkWidget *Button;		//Zum Vokabeltrainer
	GtkWidget *Button1;		//Vokabelliste bearbeiten
	GtkWidget *Button2;		//Programm beenden
	GtkWidget *Button3;		//Testbutton des 2. Menues
	GtkWidget *Button4;

	int zust;
}element;



//++++++++++++++++++++++++++++Funktion der Unterprogramme++++++++++++++++++++++++++++++++++
//----------------------------Vokabeltrainer wird zum üben geöffnet------------------------
void vokabel(GtkWidget *Button)
{

	
}


//----------------------------Vokabelliste wird zum ändern geöffnegt-----------------------
void liste(GtkWidget *Button1, gpointer data)
{
	element.zust=1;

	printf("%i\n",element.zust);

//+++++++++++++++++++++++++Test fenster um das Verschwinden des Hautptfensters/menues zu testen+++++++++
element.Fenster1 = gtk_window_new (GTK_WINDOW_TOPLEVEL); 
element.Schachtel1 = gtk_box_new(TRUE,2);
element.Button3 = gtk_button_new_with_mnemonic("Programm beenden");
//-----
gtk_container_add(GTK_CONTAINER(element.Fenster1), element.Schachtel1);

gtk_box_pack_start(GTK_BOX(element.Schachtel1),element.Button3, TRUE, FALSE,2);

g_signal_connect(G_OBJECT(element.Button3),"clicked",gtk_main_quit, NULL);	//hier soll zurück in main gegangen werden später
//----
gtk_window_set_title (GTK_WINDOW(element.Fenster1), "Vokabelliste");
gtk_window_set_default_size(GTK_WINDOW(element.Fenster1),500,400);
gtk_widget_show_all (element.Fenster1);

}


//+++++++++++++++++++++++++++++++HAUPTMENUE+++++++++++++++++++++++++++++++++++++++++++++++++
int main(int argc, char *argv[])
{
gtk_init(&argc,&argv);

//+++++++++++++++++++++++++++++++Definierung der Objekte+++++++++++++++++++++++++++++++++++++
element.Fenster = gtk_window_new (GTK_WINDOW_TOPLEVEL); 		//Fenster erstellen
element.Schachtel = gtk_box_new(TRUE,2);				//erstellen eines Schachtelbausteins um mehrere Widgets in ein Fenster einzubinden
element.Button = gtk_button_new_with_mnemonic("Zum Vokabeltrainer");
element.Button1 = gtk_button_new_with_mnemonic("Vokabelliste bearbeiten");
element.Button2 = gtk_button_new_with_mnemonic("Programm beenden");

//++++++++++++++++++++++++++++++Zusammenbau des ersten Menues++++++++++++++++++++++++++++++++
gtk_container_add(GTK_CONTAINER(element.Fenster), element.Schachtel);
gtk_box_pack_start(GTK_BOX(element.Schachtel),element.Button, TRUE, FALSE,2);
gtk_box_pack_start(GTK_BOX(element.Schachtel),element.Button1, TRUE, FALSE,2);
gtk_box_pack_start(GTK_BOX(element.Schachtel),element.Button2, TRUE, FALSE,2);

//++++++++++++++++++++++++++++++Funktion von Buttons freigeben+++++++++++++++++++++++++++++++
g_signal_connect(G_OBJECT(element.Fenster),"delete-event",gtk_main_quit, NULL);
g_signal_connect(G_OBJECT(element.Button),"clicked",G_CALLBACK(vokabel), NULL);
g_signal_connect(G_OBJECT(element.Button1),"clicked",G_CALLBACK(liste), NULL);
g_signal_connect(G_OBJECT(element.Button2),"clicked",gtk_main_quit, NULL);
//++++++++++++++++++++++++++++++Fenster Darstellung++++++++++++++++++++++++++++++++++++++++++
gtk_window_set_title (GTK_WINDOW(element.Fenster), "Vokabeltrainer");
gtk_window_set_default_size(GTK_WINDOW(element.Fenster),500,400);
gtk_widget_show_all(element.Fenster);


gtk_main();
return 0;
}



/*if(element.zust==1)
{
element.Fenster1 = gtk_window_new (GTK_WINDOW_TOPLEVEL); 
element.Schachtel1 = gtk_box_new(TRUE,2);
element.Button3 = gtk_button_new_with_mnemonic("Programm beenden");
//-----
gtk_container_add(GTK_CONTAINER(element.Fenster1), element.Schachtel1);

gtk_box_pack_start(GTK_BOX(element.Schachtel1),element.Button3, TRUE, FALSE,2);

g_signal_connect(G_OBJECT(element.Button3),"clicked",gtk_main_quit, NULL);
//----
gtk_widget_show_all (element.Fenster1);

}
*/
//G_Callback : main
