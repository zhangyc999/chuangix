#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>

#define NUM_KEY    67
#define NUM_ROW    5
#define NUM_COL    15
#define KEY_WIDTH  66
#define KEY_HEIGHT 66

GtkWidget *keyboard_init(gint *width, gint *height)
{
  char *str[NUM_KEY] = {
    "Esc", "!\n1", "@\n2", "#\n3", "$\n4", "%\n5", "^\n6", "&\n7", "*\n8", "(\n9", ")\n0", "_\n-", "+\n=", "~\n`", "<-",
    "Tab", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{\n[", "}\n]", "|\n\\",
     "CapsLock", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":\n;", "\"\n'", "Enter",
     "Shift", "Z", "X", "C", "V", "B", "N", "M", "<\n,", ">\n.", "?\n/", "Shift", "^\n|", "Del",
     "Ctrl", "Win", "Alt", "Fn", "", "Fn", "Alt", "App", "<<", "|\nv", ">>"
  };
  GtkWidget *keyboard = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  GtkWidget *row[NUM_ROW];
  GtkWidget *key[NUM_KEY];
  for (int i = 0; i < NUM_ROW; i++) {
   row[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
   gtk_box_pack_start(GTK_BOX(keyboard), row[i], TRUE, FALSE, 0);
  }

  for (int i = 0; i < NUM_KEY; i++) {
    GtkWidget *key = gtk_toggle_button_new_with_label(str[NUM_KEY]);
    gtk_widget_set_size_request(str[NUM_KEY], KEY_WIDTH, KEY_HEIGHT);
    gtk_box_pack_start(gtk_box(row[0]), str[NUM_KEY], TRUE, FALSE, 0);
  }

     *width = KEY_WIDTH * NUM_COL;
     *height = KEY_HEIGHT * NUM_ROW;
     return keyboard;
}
