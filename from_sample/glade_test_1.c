#include <gtk/gtk.h>
 
void on_window_main_destroy(void);

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
    GtkWidget       *image;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "picshower.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "PicShowWindow"));
    image = GTK_WIDGET(gtk_builder_get_object(builder, "picshow"));
    gtk_builder_connect_signals(builder, NULL);
 
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}
 
// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
