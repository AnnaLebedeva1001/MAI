# Лебедева А.И. М8О-110Б-19

from PyQt5 import QtCore, QtWidgets, QtGui
import pyqtgraph as pg
import numpy as np
import sys
import random

class SnakeGame(QtWidgets.QMainWindow):

    def __init__(self):
        super().__init__()

        main_widget = QtWidgets.QWidget()
        hlay = QtWidgets.QHBoxLayout()
        main_widget.setLayout(hlay)
        self.setCentralWidget(main_widget)
        self.setMinimumSize(800, 600)

        view = pg.GraphicsView()
        self.canvas = pg.PlotItem()
        view.setCentralWidget(self.canvas)
        hlay.addWidget(view)

        vlay = QtWidgets.QVBoxLayout()
        hlay.addLayout(vlay)

        self.canvas.setRange(xRange=(0, 1000), yRange=(0, 1000))
        # self.canvas.setLimits(xMin=0, xMax=1000, yMin=0, yMax=1000)

        self.label1 = QtWidgets.QLabel('Health: 5')
        self.label2 = QtWidgets.QLabel('Score: 0')
        self.health = 5
        self.score = 0

        vlay.addWidget(self.label1)
        vlay.addWidget(self.label2)

        self.button1 = QtWidgets.QPushButton("Выход", self)
        self.button1.clicked.connect(sys.exit)
        vlay.addWidget(self.button1)

        self.button2 = QtWidgets.QPushButton("Пауза/продолжение", self)
        self.button2.clicked.connect(self.SetPause)
        vlay.addWidget(self.button2)

        self.button3 = QtWidgets.QPushButton("Новая игра", self)
        self.button3.clicked.connect(self.SetNewGame)
        vlay.addWidget(self.button3)

        self.draw_snake()
        self.direction = "R"

        self.timer_run = True

        self.__timer_id = self.startTimer(int(1000/60)*15)
        self.spawn_point()
        if self.__timer_id == -1:
            print("Ошибка таймера")

    def keyPressEvent(self, event):
        key = event.key()
        if key == QtCore.Qt.Key_Left and self.direction != "R":
            self.direction = "L"
        if key == QtCore.Qt.Key_Right and self.direction != "L":
            self.direction = "R"
        if key == QtCore.Qt.Key_Up and self.direction != "D":
            self.direction = "U"
        if key == QtCore.Qt.Key_Down and self.direction != "U":
            self.direction = "D"
        if key == QtCore.Qt.Key_Space: self.timer_run = not self.timer_run


    def draw_snake(self):

        self.xy = [[500, 500]]
        self.plot = pg.PlotDataItem(np.array(self.xy), symbol='s', symbolSize=10)
       
        field = QtGui.QGraphicsRectItem(QtCore.QRectF(0, 0, 1000, 1000))
        field.setPen(pg.mkPen(200, 100, 100))

        self.canvas.addItem(self.plot)
        self.canvas.addItem(field)

    def spawn_point(self):
        x = random.random() * 960 + 20
        y = random.random() * 960 + 20
        x = round(x, -1)
        y = round(y, -1)
        self.point = [x, y]

    def grow(self):
        last = self.xy[0]
        if self.direction == "L":
            self.xy = [[last[0]+20, last[1]], *self.xy]

        if self.direction == "R":
            self.xy = [[last[0]-20, last[1]], *self.xy]

        if self.direction == "U":
            self.xy = [[last[0], last[1]-20], *self.xy]

        if self.direction == "D":
            self.xy = [[last[0], last[1]+20], *self.xy]

    def check_point(self):
        first = self.xy[-1]
        if first[0] - 10 <= self.point[0] <= first[0] + 10:
            if first[1] - 10 <= self.point[1] <= first[1] + 10:
                self.score += 1
                self.spawn_point()
                self.grow()

    def reset(self):
        self.health -= 1
        if self.health == 0:
            self.timer_run = False
        self.xy = [[500, 500]]
        self.spawn_point()


    def timerEvent(self, event):
        for i in range(len(self.xy)):
            for j in range(len(self.xy)):
                if i != j and self.xy[i] == self.xy[j]: self.reset()

        if self.xy[-1][0] >= 990 or self.xy[-1][0] <= 10 or self.xy[-1][1] >= 990 or self.xy[-1][1] <= 10:
                    self.reset()

        if self.timer_run:
            if self.health == 0:
                self.health = 5
                self.score = 0

            prev_elem = self.xy[-1]
                    
            if self.direction == "L":
                self.xy[-1] = [self.xy[-1][0] - 20, self.xy[-1][1]]

            if self.direction == "R":
                self.xy[-1] = [self.xy[-1][0] + 20, self.xy[-1][1]]

            if self.direction == "U":
                self.xy[-1] = [self.xy[-1][0], self.xy[-1][1] + 20]

            if self.direction == "D":
                self.xy[-1] = [self.xy[-1][0], self.xy[-1][1] - 20]

            for i in range(len(self.xy)-2, -1, -1):
                self.xy[i], prev_elem = prev_elem, self.xy[i]

            self.check_point()
            
            self.plot.setData(np.array([*self.xy, self.point]),
                connect=np.array([1 for i in range(len(self.xy)-1)] + [0, 0]))
        
        self.label1.setText(f'Health: {self.health}')
        self.label2.setText(f'Score: {self.score}')

    def SetPause(self):
        self.timer_run = not self.timer_run

    def SetNewGame(self):
        self.timer_run = True
        self.health = 5
        self.score = 0
        self.xy = [[500, 500]]
        self.spawn_point()
        

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = SnakeGame()
    window.show() 
    sys.exit(app.exec_())