#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>
#include <glib.h>

extern GtkWidget *keyboard_init(gint *width, gint *height);

int main(int argc, char *argv[])
{
        gtk_init(&argc, &argv);
        GdkScreen *screen = gdk_screen_get_default();
        gint main_width = gdk_screen_get_width(screen);
        gint main_height = gdk_screen_get_height(screen);
        GtkWidget *main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_fullscreen(GTK_WINDOW(main_window));
        GtkWidget *main_fixed = gtk_fixed_new();
        gtk_container_add(GTK_CONTAINER(main_window), main_fixed);
        gint keyboard_width;
        gint keyboard_height;
        GtkWidget *keyboard = keyboard_init(&keyboard_width, &keyboard_height);
        if (main_height >= keyboard_height) 
          gtk_fixed_put(GTK_FIXED(main_fixed), GTK_WIDGET(keyboard_init()), main_height - keyboard_height, 0);
        gtk_widget_show_all(main_window);
        gtk_main();
        return 0;
}
 
