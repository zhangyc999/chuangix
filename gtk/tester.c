#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkscreen.h>
#include <gdk/gdkkeysyms.h>
#include <glib.h>

extern GtkWidget *keyboard_init(gint *width, gint *height);

int main(int argc, char *argv[])
{
        gtk_init(&argc, &argv);
        GtkWidget *main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_fullscreen(GTK_WINDOW(main_window));
        GdkScreen *screen;
        screen = gtk_window_get_screen(GTK_WINDOW(main_window));
        gint main_width = gdk_window_get_width(GDK_WINDOW(main_window));
        gint main_height = gdk_window_get_height(GDK_WINDOW(main_window));
        
        GtkWidget *main_fixed = gtk_fixed_new();
        gtk_container_add(GTK_CONTAINER(main_window), main_fixed);
        
        gint keyboard_width;
        gint keyboard_height;
        GtkWidget *keyboard = keyboard_init(&keyboard_width, &keyboard_height);
        gtk_container_add(GTK_CONTAINER(main_fixed), keyboard);
        gtk_fixed_put(GTK_FIXED(main_fixed), GTK_WIDGET(keyboard), main_width - (main_width - keyboard_width), main_height - (main_height - keyboard_height));
        
        if (main_height >= keyboard_height) 
          gtk_fixed_put(GTK_FIXED(main_fixed), GTK_WIDGET(keyboard), main_height - keyboard_height, 0);
        
        gtk_widget_show_all(main_window);
        gtk_main();
        return 0;
}
 
