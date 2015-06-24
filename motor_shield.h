//Intención de ampliar biblioteca para manejar tambien http://me.web2.ncut.edu.tw/ezfiles/39/1039/img/617/L9110_2_CHANNEL_MOTOR_DRIVER.pdf

#ifndef RobotMovil_h
#define RobotMovil_h

class RobotMovil {
  public:  
    RobotMovil ();
    void forward(int l, int r, int t);
    void reverse(int l, int r, int t);
    void rotate(int p, int t);
    void brake();
    void relase();
};

#endif
