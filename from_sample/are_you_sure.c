#include <gtk/gtk.h>
 
void on_window_main_destroy();
void i_am_sure();

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
    GtkWidget       *image;
    GtkWidget       *button;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "are_you_sure.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "ays_dialog"));
    image = GTK_WIDGET(gtk_builder_get_object(builder, "ays_warning"));
    button = GTK_WIDGET(gtk_builder_get_object(builder, "ays_ok"));
    gtk_builder_connect_signals(builder, NULL);

    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);
 
    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}

