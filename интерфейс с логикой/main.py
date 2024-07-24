



from PyQt6.QtWidgets import QApplication, QMainWindow, QFileDialog
from datetime import date, datetime, timedelta
import sys
from untitled import Ui_Form
#from include 

import webbrowser


class Programm(QMainWindow, Ui_Form):
    def __init__(self): 
        QMainWindow.__init__(self)
        Ui_Form.setupUi(self, self)
        
    def gethtmgjl(self, link:str = ""):
        link = link.toString()
        if link.startswith("https"):
            
            webbrowser.open_new_tab(link)
            
        print(1002)
        print(link)



def main():
    app = QApplication(sys.argv) # Создает приложение
    
    
    
    main_window = Programm()
    
    main_window.textBrowser.anchorClicked['QUrl'].connect(main_window.gethtmgjl) # type: ignore
    
    main_window.show()


    app.exec() # Корректное отображение приложения
    
    
    
if __name__ == "__main__":
    main()
    