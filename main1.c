/********************************************//**
 * \file  main1.c
 * \brief This is brief
 * \author thanh.nguyen
 * \date 24-11-2016
 * This is file for learning GTK and Doxygent
 * Revision note :
 *          1.0.0 Initial version
 *
 *
 * \version 1.0.0
 * \bug No known bug
 *
 ***********************************************/

#include "main1.h"

/********************************************//**
 * \brief  loi chao dau
 * \return void
 * function for greeting
 ***********************************************/

void greeting(void)
{
    printf("This is project for demo gtk");
}

/********************************************//**
 * \brief Create Window
 *
 * \param void
 * \return GtkWidget *
 *
 ***********************************************/

GtkWidget * CreateWindow()
{
    GtkWidget * win ;
    //get window
    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //centralize
    gtk_window_set_title(GTK_WINDOW(win),"center");
    gtk_window_set_default_size(GTK_WINDOW(win),600,500);
    gtk_window_set_position(GTK_WINDOW(win),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(win),15);
    gtk_window_set_title(GTK_WINDOW(win),"Nguyen Xuan Thanh");

    return win;
}
/********************************************//**
 * \brief Create Pixbuf from file
 *
 * \param path to file name
 * \return GdkPixbuf pointer
 *
 ***********************************************/


GdkPixbuf *MakeSteinsvikIcon(const char *fileName)
{
    GdkPixbuf *pixBuf;
    GError *error = NULL;
    pixBuf =gdk_pixbuf_new_from_file(fileName,&error);
    if(!pixBuf)
    {
        fprintf(stderr, "%s\n",error->message);
        g_error_free(error);
    }
    return pixBuf;

}

/********************************************//**
 * \brief ACtion Callback function for button click
 *
 * \param
 * \param
 * \return void
 *
 ***********************************************/


void print_msg(GtkWidget *widget,gpointer window)
{
    g_print("Button Clicked \n");

}




int main(int argc, char* argv[])
{
    /**< ----------------------- Define some needed variable ----------- */

    GtkWidget * window = NULL;
    GtkWidget * button;
    GtkWidget * halign ;
    GdkPixbuf * icon ;
    GtkWidget * vbox;
    GtkWidget * menuBar;
    GtkWidget * fileMenu;
    GtkWidget * imprMenu;
    GtkWidget * fileMi;
    GtkWidget * quitMi;
    GtkWidget * imprMi;
    GtkWidget * feedMi;
    GtkWidget * bookMi;
    GtkWidget * mailMi;

    /**< ----------------------- Initial code -------------------------- */
    greeting();
    // init arg for gtk , need to call first before access any gtk function
    gtk_init(&argc,&argv);

    // ******************* Create window **********************************
    window = CreateWindow();
    //Make icon
    icon = MakeSteinsvikIcon("resource/steinsvikicon.png");
    gtk_window_set_icon(GTK_WINDOW(window),icon);
    /**< ---------------------  Create menu ---------------------------  */

    // initialize vertical menu
    vbox = gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window),vbox);

    // initialize menu
    menuBar = gtk_menu_bar_new();
    fileMenu = gtk_menu_new();

    fileMi = gtk_menu_item_new_with_label("File");
    quitMi = gtk_menu_item_new_with_label("Quit");
    imprMi = gtk_menu_item_new_with_label("Import");





    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar),fileMi);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi),fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),imprMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),quitMi);



    gtk_box_pack_start(GTK_BOX(vbox),menuBar,FALSE,FALSE,0);





    // ************** Create button **************************

    // normal button
/*    button = gtk_button_new_with_label("Button");
    gtk_widget_set_tooltip_text(button,"button widget"); */
    // button with hot key
/*    button = gtk_button_new_with_mnemonic("_Button");

    g_signal_connect(button,"clicked",G_CALLBACK(print_msg),NULL);
    halign = gtk_alignment_new(0,0,0,0);
    gtk_container_add(GTK_CONTAINER(halign),button);
    gtk_container_add(GTK_CONTAINER(window),halign); */

    // *****************







    // Show window
//  gtk_widget_show(window);
    // Show all widget window
    gtk_widget_show_all(window);




    // Catch signal destroy (when press exit button) to quit gtk main
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(G_OBJECT(quitMi),"activate",G_CALLBACK(gtk_main_quit),NULL);
    g_object_unref(icon);
    //main loop
    gtk_main();

    //exit with success code
    exit(EXIT_SUCCESS);

}
