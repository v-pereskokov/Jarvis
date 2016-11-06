#include "styles.h"


void setStyles(QString stylesList[stylesAmount])
{
    //стили кнопок PushButton  в классе MainWindow
    stylesList[0] = "QPushButton {"
                    "   background-color: rgb(93, 240, 84);"
                    "   border : none;"
                    "   font:  14px;"
                    "   max-width: 200px;"
                    "   min-width: 80px;"
                    "   min-height: 20px;"
                    "   padding: 5px;"
                    "}"
                    "QPushButton:disabled {"
                    "   background-color: #989898;"
                    "   color: #fff;"
                    " }"
                    "QPushButton:hover {"
                    "   background-color: #61b7ff;"
                    " }"
                    "QPushButton:focus { "
                    "   background-color: #61b7ff;"
                    " }"
                    "QPushButton:pressed {"
                    "   background-color: #54dff0;"
                    " }";

    //стили кнопок PushButton  в классе SettingsDialogWindow
    stylesList[1] = "QPushButton {"
                    "   background-color: rgb(93, 240, 84);"
                    "   border : none;"
                    "   font:  14px;"
                    "   max-width: 200px;"
                    "   min-width: 80px;"
                    "   min-height: 20px;"
                    "   margin: 5px;"
                    "   padding: 5px;"
                    "}"
                    "QPushButton:disabled {"
                    "   background-color: #989898;"
                    "   color: #fff;"
                    " }"
                    "QPushButton:hover {"
                    "   background-color: #61b7ff;"
                    " }"
                    "QPushButton:focus { "
                    "   background-color: #61b7ff;"
                    " }"
                    "QPushButton:pressed {"
                    "   background-color: #54dff0;"
                    " }";
}
