#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>
#include <gdk/gdkscreen.h>
#include <glib.h>

#define NUM_KEY     67
#define NUM_ROW     5
#define NUM_ROW0    15
#define NUM_ROW1    14
#define NUM_ROW2    13
#define NUM_ROW3    14
#define NUM_ROW4    11
#define NUM_COL     15
#define KEY_WIDTH   66
#define KEY_HEIGHT  66


GtkWidget *keyboard_init(gint *width, gint *height)
{
  char *str0[NUM_ROW0] = {"Esc", "!\n1", "@\n2", "#\n3", "$\n4", "%\n5", "^\n6", "&\n7", "*\n8", "(\n9", ")\n0", "_\n-", "+\n=", "~\n`", "<-"};
  char *str1[NUM_ROW1] = {"Tab", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{\n[", "}\n]", "|\n\\"};
  char *str2[NUM_ROW2] = {"CapsLock", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":\n;", "\"\n'", "Enter"};
  char *str3[NUM_ROW3] = {"Shift", "Z", "X", "C", "V", "B", "N", "M", "<\n,", ">\n.", "?\n/", "Shift", "^\n|", "Del"};
  char *str4[NUM_ROW4] = {"Ctrl", "Win", "Alt", "Fn", "", "Fn", "Alt", "App", "<<", "|\nv", ">>"};

  GtkWidget *keyboard = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  GtkWidget *row[NUM_ROW];
  GtkWidget *key[NUM_KEY];
  for (int i = 0; i < NUM_ROW; i++) {
    row[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(keyboard), row[i], FALSE, FALSE, 0);
  } 
  for (int i = 0; i < NUM_ROW0; i++) {
    GtkWidget *key = gtk_toggle_button_new_with_label(str0[i]);
    gtk_widget_set_size_request(GTK_WIDGET(key), KEY_WIDTH, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[0]), GTK_WIDGET(key), TRUE, FALSE, 0);
  }
  GtkWidget *tab = gtk_toggle_button_new_with_label(str1[0]);
  gtk_widget_set_size_request(GTK_WIDGET(tab), KEY_WIDTH / 2 * 3, KEY_HEIGHT);
  gtk_box_pack_start(GTK_BOX(row[1]), GTK_WIDGET(tab), TRUE, FALSE, 0);
  for (int i = 1; i < NUM_ROW1 - 1; i++) {
    GtkWidget *key = gtk_toggle_button_new_with_label(str1[i]);
    gtk_widget_set_size_request(GTK_WIDGET(key), KEY_WIDTH, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[1]), GTK_WIDGET(key), TRUE, FALSE, 0);
  }
  GtkWidget *back_slash = gtk_toggle_button_new_with_label(str1[13]);
  gtk_widget_set_size_request(GTK_WIDGET(back_slash), KEY_WIDTH / 2 * 3, KEY_HEIGHT);
  gtk_box_pack_start(GTK_BOX(row[1]), GTK_WIDGET(back_slash), TRUE, FALSE, 0);

  GtkWidget *capslock = gtk_toggle_button_new_with_label(str2[0]);
  gtk_widget_set_size_request(GTK_WIDGET(capslock), KEY_WIDTH / 3 * 5, KEY_HEIGHT);
  gtk_box_pack_start(GTK_BOX(row[2]), GTK_WIDGET(capslock), TRUE, FALSE, 0);
  for (int i = 1; i < NUM_ROW2 - 1; i++) {
    GtkWidget *key = gtk_toggle_button_new_with_label(str2[i]);
    gtk_widget_set_size_request(GTK_WIDGET(key), KEY_WIDTH, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[2]), GTK_WIDGET(key), TRUE, FALSE, 0);
  }
  GtkWidget *enter = gtk_toggle_button_new_with_label(str2[12]);
  gtk_widget_set_size_request(GTK_WIDGET(enter), KEY_WIDTH / 3 * 7, KEY_HEIGHT);
  gtk_box_pack_start(GTK_BOX(row[2]), GTK_WIDGET(enter), TRUE, FALSE, 0);
  
  GtkWidget *shift = gtk_toggle_button_new_with_label(str3[0]);
  gtk_widget_set_size_request(GTK_WIDGET(shift), KEY_WIDTH * 2, KEY_HEIGHT);
  gtk_box_pack_start(GTK_BOX(row[3]), GTK_WIDGET(shift), TRUE, FALSE, 0);
  for (int i = 1; i < NUM_ROW3; i++) {
    GtkWidget *key = gtk_toggle_button_new_with_label(str3[i]);
    gtk_widget_set_size_request(GTK_WIDGET(key), KEY_WIDTH, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[3]), GTK_WIDGET(key), TRUE, FALSE, 0);
  }
    GtkWidget *ctrl = gtk_toggle_button_new_with_label(str4[0]);
    gtk_widget_set_size_request(GTK_WIDGET(ctrl), KEY_WIDTH / 3 * 5, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(ctrl), TRUE, FALSE, 0);
    GtkWidget *win = gtk_toggle_button_new_with_label(str4[1]);
    gtk_widget_set_size_request(GTK_WIDGET(win), KEY_WIDTH / 3 * 4, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(win), TRUE, FALSE, 0);
    GtkWidget *alt_left = gtk_toggle_button_new_with_label(str4[2]);
    gtk_widget_set_size_request(GTK_WIDGET(alt_left), KEY_WIDTH / 3 * 4, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(alt_left), TRUE, FALSE, 0);
    GtkWidget *fn_left = gtk_toggle_button_new_with_label(str4[3]);
    gtk_widget_set_size_request(GTK_WIDGET(fn_left), KEY_WIDTH / 3 * 4, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(fn_left), TRUE, FALSE, 0);
    GtkWidget *space = gtk_toggle_button_new_with_label(str4[4]);
    gtk_widget_set_size_request(GTK_WIDGET(space), KEY_WIDTH / 3 * 8, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(space), TRUE, FALSE, 0);
    GtkWidget *fn_right = gtk_toggle_button_new_with_label(str4[5]);
    gtk_widget_set_size_request(GTK_WIDGET(fn_right), KEY_WIDTH / 3 * 4, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(fn_right), TRUE, FALSE, 0);
    GtkWidget *alt_right = gtk_toggle_button_new_with_label(str4[6]);
    gtk_widget_set_size_request(GTK_WIDGET(alt_right), KEY_WIDTH / 3 * 4, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(alt_right), TRUE, FALSE, 0);
    GtkWidget *app = gtk_toggle_button_new_with_label(str4[7]);
    gtk_widget_set_size_request(GTK_WIDGET(app), KEY_WIDTH, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(app), TRUE, FALSE, 0);
    GtkWidget *key_left = gtk_toggle_button_new_with_label(str4[8]);
    gtk_widget_set_size_request(GTK_WIDGET(key_left), KEY_WIDTH, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(key_left), TRUE, FALSE, 0);
    GtkWidget *key_down = gtk_toggle_button_new_with_label(str4[9]);
    gtk_widget_set_size_request(GTK_WIDGET(key_down), KEY_WIDTH, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(key_down), TRUE, FALSE, 0);
    GtkWidget *key_right = gtk_toggle_button_new_with_label(str4[10]);
    gtk_widget_set_size_request(GTK_WIDGET(key_right), KEY_WIDTH, KEY_HEIGHT);
    gtk_box_pack_start(GTK_BOX(row[4]), GTK_WIDGET(key_right), TRUE, FALSE, 0);

  *width = KEY_WIDTH * NUM_COL;
  *height = KEY_HEIGHT * NUM_ROW;

  return keyboard;
}
