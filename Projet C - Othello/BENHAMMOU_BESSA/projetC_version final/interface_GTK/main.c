#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include<string.h>

#include "jeu1vs1.h"
#include "jeu1vsMachine.h"
#include "securite.h"

GtkBuilder *builder;

GtkWidget *W0;
GtkWidget *JJ;
GtkWidget *JM;
GtkWidget *T;
GtkWidget *V;
GtkWidget *Q;

 void new_window1(GtkWidget *widget, gpointer data);
 void new_window1bis(GtkWidget *widget, gpointer data);
 void new_window2(GtkWidget *widget, gpointer data);
 void new_window3(GtkWidget *widget, gpointer data);
 void new_window3bi(GtkWidget *widget, gpointer data);
 //void button_clicked(GtkButton *button);


int main(int argc, char const *argv[])
{
    gtk_init(&argc, &argv);


builder=gtk_builder_new_from_file("OTHELLO_PROJECT.glade");
W0=GTK_WIDGET(gtk_builder_get_object(builder,"W0"));
JJ=GTK_WIDGET(gtk_builder_get_object(builder,"JJ"));

JM=GTK_WIDGET(gtk_builder_get_object(builder,"JM"));
    T=GTK_WIDGET(gtk_builder_get_object(builder,"T"));
    V=GTK_WIDGET(gtk_builder_get_object(builder,"V"));
    Q=GTK_WIDGET(gtk_builder_get_object(builder,"Q"));

g_signal_connect(JJ,"clicked",G_CALLBACK(new_window1bis),NULL);
g_signal_connect(JM,"clicked",G_CALLBACK(new_window1),NULL);
g_signal_connect(Q,"clicked",G_CALLBACK(gtk_main_quit),NULL);
g_signal_connect(V,"clicked",G_CALLBACK(new_window3),NULL);

gtk_widget_show_all(W0);

gtk_main();
return 0;

}
void new_window1(GtkWidget *widget, gpointer data){


GtkWidget *W1;

GtkWidget *C;
GtkWidget *E1;
GtkWidget *E2;


builder=gtk_builder_new_from_file("OTHELLO_PROJECT.glade");
W1=GTK_WIDGET(gtk_builder_get_object(builder,"W1"));
C=GTK_WIDGET(gtk_builder_get_object(builder,"C"));

E1=GTK_WIDGET(gtk_builder_get_object(builder,"E1"));
E2=GTK_WIDGET(gtk_builder_get_object(builder,"E2"));

g_signal_connect(C,"clicked",G_CALLBACK(new_window2),NULL);
gtk_widget_show_all(W1);
}


void new_window1bis(GtkWidget *widget, gpointer data){



GtkWidget *W1bis;
GtkWidget *c;

GtkWidget *E3;
GtkWidget *E4;
GtkWidget *E5;
GtkWidget *E6;
builder=gtk_builder_new_from_file("OTHELLO_PROJECT.glade");
W1bis=GTK_WIDGET(gtk_builder_get_object(builder,"W1bis"));
c=GTK_WIDGET(gtk_builder_get_object(builder,"c"));


E3=GTK_WIDGET(gtk_builder_get_object(builder,"E3"));
E4=GTK_WIDGET(gtk_builder_get_object(builder,"E4"));
E5=GTK_WIDGET(gtk_builder_get_object(builder,"E5"));
E6=GTK_WIDGET(gtk_builder_get_object(builder,"E6"));

g_signal_connect(c,"clicked",G_CALLBACK(new_window2),NULL);
gtk_widget_show_all(W1bis);
}

void new_window2(GtkWidget *widget, gpointer data){

GtkWidget *W2;
GtkWidget *S;
GtkWidget *R;
GtkWidget *q;
GtkWidget *D;


builder=gtk_builder_new_from_file("OTHELLO_PROJECT.glade");
W2=GTK_WIDGET(gtk_builder_get_object(builder,"W2"));
S=GTK_WIDGET(gtk_builder_get_object(builder,"S"));
R=GTK_WIDGET(gtk_builder_get_object(builder,"R"));
q=GTK_WIDGET(gtk_builder_get_object(builder,"q"));
D=GTK_WIDGET(gtk_builder_get_object(builder,"D"));



g_signal_connect(R,"clicked",G_CALLBACK(new_window2),NULL);
g_signal_connect(q,"clicked",G_CALLBACK(gtk_main_quit),NULL);

gtk_widget_show_all(W2);

}

void new_window3(GtkWidget *widget, gpointer data){
    GtkWidget *W3;
     GtkWidget *EV;
 GtkWidget *L;
  builder=gtk_builder_new_from_file("OTHELLO_PROJECT.glade");
  W3=GTK_WIDGET(gtk_builder_get_object(builder,"W3"));
  EV=GTK_WIDGET(gtk_builder_get_object(builder,"EV"));
  L=GTK_WIDGET(gtk_builder_get_object(builder,"L"));
  g_signal_connect(L,"clicked",G_CALLBACK(new_window3bi),NULL);

  gtk_widget_show_all(W3);
  }
void new_window3bi(GtkWidget *widget, gpointer data){
    GtkWidget *W3bi;
 GtkWidget *qu;
  builder=gtk_builder_new_from_file("OTHELLO_PROJECT.glade");
  W3bi=GTK_WIDGET(gtk_builder_get_object(builder,"W3bi"));
 g_signal_connect(qu,"clicked",G_CALLBACK(gtk_main_quit),NULL);
  gtk_widget_show_all(W3bi);
  }

/*void  button_clicked(GtkButton *button)
{
 GtkWidget *B00;
GtkWidget *B01;
GtkWidget *B02;
GtkWidget *B03;
GtkWidget *B04;
GtkWidget *B05;
GtkWidget *B06;
GtkWidget *B07;
GtkWidget *B10;
GtkWidget *B11;
GtkWidget *B12;
GtkWidget *B13;
GtkWidget *B14;
GtkWidget *B15;
GtkWidget *B16;
GtkWidget *B17;
GtkWidget *B20;
GtkWidget *B21;
GtkWidget *B22;
GtkWidget *B23;
GtkWidget *B24;
GtkWidget *B25;
GtkWidget *B26;
GtkWidget *B27;
GtkWidget *B20;
GtkWidget *B21;
GtkWidget *B22;
GtkWidget *B23;
GtkWidget *B24;
GtkWidget *B25;
GtkWidget *B26;
GtkWidget *B27;
GtkWidget *B20;
GtkWidget *B21;
GtkWidget *B22;
GtkWidget *B23;
GtkWidget *B24;
GtkWidget *B25;
GtkWidget *B26;
GtkWidget *B27;
GtkWidget *B20;
GtkWidget *B21;
GtkWidget *B22;
GtkWidget *B23;
GtkWidget *B24;
GtkWidget *B25;
GtkWidget *B26;
GtkWidget *B27;
 GtkWidget *B20;
GtkWidget *B21;
GtkWidget *B22;
GtkWidget *B23;
GtkWidget *B24;
GtkWidget *B25;
GtkWidget *B26;
GtkWidget *B27;
 GtkWidget *B20;
GtkWidget *B21;
GtkWidget *B22;
GtkWidget *B23;
GtkWidget *B24;
GtkWidget *B25;
GtkWidget *B26;
GtkWidget *B27;
GtkWidget *B30;
GtkWidget *B31;
GtkWidget *B32;
GtkWidget *B33;
GtkWidget *B34;
GtkWidget *B35;
GtkWidget *B36;
GtkWidget *B37;
GtkWidget *B40;
GtkWidget *B41;
GtkWidget *B42;
GtkWidget *B43;
GtkWidget *B44;
GtkWidget *B45;
GtkWidget *B46;
GtkWidget *B47;
GtkWidget *B50;
GtkWidget *B51;
GtkWidget *B52;
GtkWidget *B53;
GtkWidget *B54;
GtkWidget *B55;
GtkWidget *B56;
GtkWidget *B57;
GtkWidget *B60;
GtkWidget *B61;
GtkWidget *B62;
GtkWidget *B63;
GtkWidget *B64;
GtkWidget *B65;
GtkWidget *B66;
GtkWidget *B67;
GtkWidget *B70;
GtkWidget *B71;
GtkWidget *B72;
GtkWidget *B73;
GtkWidget *B74;
GtkWidget *B75;
GtkWidget *B76;
GtkWidget *B77;

builder=gtk_builder_new_from_file("OTHELLO_PROJECT.glade");
W2=GTK_WIDGET(gtk_builder_get_object(builder,"W2"));
B00=GTK_WIDGET(gtk_builder_get_object(builder,"B00"));
B01=GTK_WIDGET(gtk_builder_get_object(builder,"B01"));
B02=GTK_WIDGET(gtk_builder_get_object(builder,"B02"));
B03=GTK_WIDGET(gtk_builder_get_object(builder,"B03"));
B04=GTK_WIDGET(gtk_builder_get_object(builder,"B04"));
B05=GTK_WIDGET(gtk_builder_get_object(builder,"B05"));
B06=GTK_WIDGET(gtk_builder_get_object(builder,"B06"));
B07=GTK_WIDGET(gtk_builder_get_object(builder,"B07"));
B10=GTK_WIDGET(gtk_builder_get_object(builder,"B10"));
B11=GTK_WIDGET(gtk_builder_get_object(builder,"B11"));
B12=GTK_WIDGET(gtk_builder_get_object(builder,"B12"));
B13=GTK_WIDGET(gtk_builder_get_object(builder,"B13"));
B14=GTK_WIDGET(gtk_builder_get_object(builder,"B14"));
B15=GTK_WIDGET(gtk_builder_get_object(builder,"B15"));
B16=GTK_WIDGET(gtk_builder_get_object(builder,"B16"));
B17=GTK_WIDGET(gtk_builder_get_object(builder,"B17"));
B20=GTK_WIDGET(gtk_builder_get_object(builder,"B20"));
B21=GTK_WIDGET(gtk_builder_get_object(builder,"B21"));
B22=GTK_WIDGET(gtk_builder_get_object(builder,"B22"));
B23=GTK_WIDGET(gtk_builder_get_object(builder,"B23"));
B24=GTK_WIDGET(gtk_builder_get_object(builder,"B24"));
B25=GTK_WIDGET(gtk_builder_get_object(builder,"B25"));
B26=GTK_WIDGET(gtk_builder_get_object(builder,"B26"));
B27=GTK_WIDGET(gtk_builder_get_object(builder,"B27"));
B30=GTK_WIDGET(gtk_builder_get_object(builder,"B30"));
B31=GTK_WIDGET(gtk_builder_get_object(builder,"B31"));
B32=GTK_WIDGET(gtk_builder_get_object(builder,"B32"));
B33=GTK_WIDGET(gtk_builder_get_object(builder,"B33"));
B34=GTK_WIDGET(gtk_builder_get_object(builder,"B34"));
B35=GTK_WIDGET(gtk_builder_get_object(builder,"B35"));
B36=GTK_WIDGET(gtk_builder_get_object(builder,"B36"));
B37=GTK_WIDGET(gtk_builder_get_object(builder,"B37"));
B30=GTK_WIDGET(gtk_builder_get_object(builder,"B40"));
B41=GTK_WIDGET(gtk_builder_get_object(builder,"B41"));
B42=GTK_WIDGET(gtk_builder_get_object(builder,"B42"));
B43=GTK_WIDGET(gtk_builder_get_object(builder,"B43"));
B44=GTK_WIDGET(gtk_builder_get_object(builder,"B44"));
B45=GTK_WIDGET(gtk_builder_get_object(builder,"B45"));
B46=GTK_WIDGET(gtk_builder_get_object(builder,"B46"));
B47=GTK_WIDGET(gtk_builder_get_object(builder,"B47"));
B50=GTK_WIDGET(gtk_builder_get_object(builder,"B50"));
B51=GTK_WIDGET(gtk_builder_get_object(builder,"B51"));
B52=GTK_WIDGET(gtk_builder_get_object(builder,"B52"));
B53=GTK_WIDGET(gtk_builder_get_object(builder,"B53"));
B54=GTK_WIDGET(gtk_builder_get_object(builder,"B54"));
B55=GTK_WIDGET(gtk_builder_get_object(builder,"B55"));
B56=GTK_WIDGET(gtk_builder_get_object(builder,"B56"));
B57=GTK_WIDGET(gtk_builder_get_object(builder,"B57"));
B60=GTK_WIDGET(gtk_builder_get_object(builder,"B60"));
B61=GTK_WIDGET(gtk_builder_get_object(builder,"B61"));
B62=GTK_WIDGET(gtk_builder_get_object(builder,"B62"));
B63=GTK_WIDGET(gtk_builder_get_object(builder,"B63"));
B64=GTK_WIDGET(gtk_builder_get_object(builder,"B64"));
B65=GTK_WIDGET(gtk_builder_get_object(builder,"B65"));
B66=GTK_WIDGET(gtk_builder_get_object(builder,"B66"));
B77=GTK_WIDGET(gtk_builder_get_object(builder,"B67"));
B70=GTK_WIDGET(gtk_builder_get_object(builder,"B70"));
B71=GTK_WIDGET(gtk_builder_get_object(builder,"B71"));
B72=GTK_WIDGET(gtk_builder_get_object(builder,"B72"));
B73=GTK_WIDGET(gtk_builder_get_object(builder,"B73"));
B74=GTK_WIDGET(gtk_builder_get_object(builder,"B74"));
B75=GTK_WIDGET(gtk_builder_get_object(builder,"B75"));
B76=GTK_WIDGET(gtk_builder_get_object(builder,"B76"));
B77=GTK_WIDGET(gtk_builder_get_object(builder,"B77"));


if (((peut_jouer(m,joueur)==1)&&(coup_valide(m,lig,col,joueur)==1))
  {GtkWidget *image=gtk_image_new();
gtk_image_set_from_file(GTK_IMAGE(image),"images_glade\black-matt (3).png");
gtk_button_set_image(button,GTK_IMAGE(image));
joueur++;
    }
    if ((peut_jouer(m,joueur)==0)&&(coup_valide(m,lig,col,joueur)==1))
    {GtkWidget *image=gtk_image_new();
gtk_image_set_from_file(GTK_IMAGE(image),"images_glade\51UW1849rJL._AC_SY355_ (1).png");
gtk_button_set_image(button,GTK_IMAGE(image));
joueur++;
    }*/
