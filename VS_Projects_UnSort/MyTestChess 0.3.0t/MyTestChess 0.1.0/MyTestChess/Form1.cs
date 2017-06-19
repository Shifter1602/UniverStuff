using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Reflection;

namespace MyTestChess
{


    public partial class Form1 : Form
    {
        Point tod = new Point();//точка отсчета на доске
        Point tobf = new Point(22,88);// Точка куда ставлю все битые фигуры tochka otschata bitih figur
        int[] MassiveOfDeadFigures = new int[32];//массив 'мертвых' фигур
        int CMODF = 0; //Счетчик для  MassiveOfDeadFigures
        int BRokir = 0,CRokir=0;

        int[,] doska = {//доска и все, что на ней расположено
            {1, 2, 3, 5, 4, 6, 7, 8}, 
            {9, 10, 11, 12, 13, 14, 15, 16},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {-9, -10, -11, -12, -13, -14, -15, -16},
            {-1, -2, -3, -5, -4, -6, -7, -8},};
        bool OpenMenu = false;// меню закрыто/меню открыто
        int[] NewPos = new int[2];//Позиция мыши на doska
        int[] FigNewPos = new int[2];//Позиция фигурки или пешки на doska
        int CounterForMove = 0;//Счетчик для ходов
        int tick=0;
        public Form1()
        {
            InitializeComponent();
            Menu.Location = new Point(11, 10);//координаты кнопки Меню
            Exit.Location = new Point(11, 40);//Кнопка выхода(Её координаты)
            Replay.Location = new Point(11, 70);//Кнопка Заново(Её координаты)
            tod = new Point(Convert.ToInt32(this.Size.Width/2-296), Convert.ToInt32(this.Size.Height/2 -296));//Находим координаты(разобраться для разрешений)
            tobf = new Point(20, Convert.ToInt32(this.Size.Height - 80)); //отображать битые фигуры внизу
            //ShowAll();//показываю фигуры и пешки на доске
            timer1.Enabled = true;
        }

        private bool MoveForLadia()
        {
            bool test = false;
            bool raznie = (doska[NewPos[0], NewPos[1]] > 0 && doska[FigNewPos[0], FigNewPos[1]] < 0)
                || (doska[NewPos[0], NewPos[1]] < 0 && doska[FigNewPos[0], FigNewPos[1]] > 0);//проверяю фигуры на разные цвета
            if (FigNewPos[1] == NewPos[1])
            {
                
                //vertical
                if (NewPos[0] > FigNewPos[0])
                {
                    int ci = FigNewPos[0];
                    while (1 == 1)
                    {
                        if (doska[ci + 1, FigNewPos[1]] != 0 || ci + 1 == NewPos[0])
                            break;
                        
                        ci++;
                    }
                    if ((ci + 1 == NewPos[0] && raznie) || (doska[ci + 1, FigNewPos[1]] == 0))
                    {
                        test = true;
                    }
                }
                if (NewPos[0] < FigNewPos[0])
                {
                    int ci = FigNewPos[0];
                    while (1 == 1)
                    {


                        if (doska[ci - 1, FigNewPos[1]] != 0 || ci -1 == NewPos[0])
                            break;
                        ci--;

                    }
                    if ((ci - 1 == NewPos[0] && raznie) || (doska[ci - 1, FigNewPos[1]] == 0))
                    {
                        test = true;
                    }
                }

            }
            if (FigNewPos[0] == NewPos[0])
            {
                if (BRokir==1)
                {
                    doska[0, 7] = 0; doska[0, 5] = 8;
                    test = true;
                    return test;
                }
                if (BRokir == 2)
                {
                    doska[0, 0] = 0; doska[0, 3] = 1;
                    test = true;
                    return test;
                }
                if (CRokir == 1)
                {
                    doska[7, 7] = 0; doska[7, 5] = -8;
                    test = true;
                    return test;
                }
                if (CRokir == 2)
                {
                    doska[7, 0] = 0; doska[7, 4] = -1;
                    test = true;
                    return test;
                }
                //horizontal
                if (NewPos[1] > FigNewPos[1])
                {
                    int cj = FigNewPos[1];
                    while (1 == 1)
                    {
                        if (doska[FigNewPos[0], cj + 1] != 0 || cj + 1 == NewPos[1])
                            break;

                        cj++;
                    }
                    if ((cj + 1 == NewPos[1] && raznie) || (doska[FigNewPos[0], cj + 1] == 0))
                    {
                        test = true;
                    }
                }


                if (NewPos[1] < FigNewPos[1])
                {
                    int cj = FigNewPos[1];
                    while (1 == 1)
                    {


                        if (doska[FigNewPos[0], cj - 1] != 0 || cj - 1 == NewPos[1])
                            break;
                        cj--;

                    }
                    if ((cj - 1 == NewPos[1] && raznie) || (doska[FigNewPos[0], cj - 1] == 0))
                    {
                        test = true;
                    }
                }

            }
            return test;
        }
        private bool KonMove()
        {
            bool test = false;
            bool raznie = (doska[FigNewPos[0], FigNewPos[1]] > 0 && doska[NewPos[0], NewPos[1]] < 0) || (doska[FigNewPos[0], FigNewPos[1]] < 0 && doska[NewPos[0], NewPos[1]] > 0);
            if (FigNewPos[0] < NewPos[0] && FigNewPos[1] < NewPos[1])//SE
            {
                if (FigNewPos[0] <= 5 && FigNewPos[1] <= 5)
                {
                    if ((doska[FigNewPos[0] + 2, FigNewPos[1] + 1] == 0 || raznie) && FigNewPos[0] + 2 == NewPos[0] && FigNewPos[1] + 1 == NewPos[1]) { test = true; }
                    else if ((doska[FigNewPos[0] + 1, FigNewPos[1] + 2] == 0 || raznie) && FigNewPos[0] + 1 == NewPos[0] && FigNewPos[1] + 2 == NewPos[1]) { test = true; }
                }
                else if (FigNewPos[0] <= 6 && FigNewPos[1] <= 5)
                {
                    if ((doska[FigNewPos[0] + 1, FigNewPos[1] + 2] == 0 || raznie) && FigNewPos[0] + 1 == NewPos[0] && FigNewPos[1] + 2 == NewPos[1]) { test = true; }
                }
                else if (FigNewPos[0] <= 5 && FigNewPos[1] <= 6)
                {
                    if ((doska[FigNewPos[0] + 2, FigNewPos[1] + 1] == 0 || raznie) && FigNewPos[0] + 2 == NewPos[0] && FigNewPos[1] + 1 == NewPos[1]) { test = true; }
                }
                else { test = false; }
            }
            else if (FigNewPos[0] < NewPos[0] && FigNewPos[1] > NewPos[1])//SW
            {
                if (FigNewPos[0] <= 5 && FigNewPos[1] >= 2)
                {
                    if ((doska[FigNewPos[0] + 2, FigNewPos[1] - 1] == 0 || raznie) && FigNewPos[0] + 2 == NewPos[0] && FigNewPos[1] - 1 == NewPos[1]) { test = true; }
                    else if ((doska[FigNewPos[0] + 1, FigNewPos[1] - 2] == 0 || raznie) && FigNewPos[0] + 1 == NewPos[0] && FigNewPos[1] - 2 == NewPos[1]) { test = true; }
                }
                else if (FigNewPos[0] <= 5 && FigNewPos[1] >= 1)
                {
                    if ((doska[FigNewPos[0] + 2, FigNewPos[1] - 1] == 0 || raznie) && FigNewPos[0] + 2 == NewPos[0] && FigNewPos[1] - 1 == NewPos[1]) { test = true; }
                }
                else if (FigNewPos[0] <= 6 && FigNewPos[1] >= 2)
                {
                    if ((doska[FigNewPos[0] + 1, FigNewPos[1] - 2] == 0 || raznie) && FigNewPos[0] + 1 == NewPos[0] && FigNewPos[1] - 2 == NewPos[1]) { test = true; }
                }
                else { test = false; }
            }
            else if (FigNewPos[0] > NewPos[0] && FigNewPos[1] < NewPos[1])//NE
            {
                if (FigNewPos[0] >= 2 && FigNewPos[1] <= 5)
                {
                    if ((doska[FigNewPos[0] - 1, FigNewPos[1] + 2] == 0 || raznie) && FigNewPos[0] - 1 == NewPos[0] && FigNewPos[1] + 2 == NewPos[1]) { test = true; }
                    else if ((doska[FigNewPos[0] - 2, FigNewPos[1] + 1] == 0 || raznie) && FigNewPos[0] - 2 == NewPos[0] && FigNewPos[1] + 1 == NewPos[1]) { test = true; }
                }
                else if (FigNewPos[0] >= 1 && FigNewPos[1] <= 5)
                {
                    if ((doska[FigNewPos[0] - 1, FigNewPos[1] + 2] == 0 || raznie) && FigNewPos[0] - 1 == NewPos[0] && FigNewPos[1] + 2 == NewPos[1]) { test = true; }
                }
                else if (FigNewPos[0] >= 2 && FigNewPos[1] <= 6)
                {
                    if ((doska[FigNewPos[0] - 2, FigNewPos[1] + 1] == 0 || raznie) && FigNewPos[0] - 2 == NewPos[0] && FigNewPos[1] + 1 == NewPos[1]) { test = true; }
                }
                else { test = false; }
            }
            else//NW
            {
                if (FigNewPos[0] >= 2 && FigNewPos[1] >= 2)
                {
                    if ((doska[FigNewPos[0] - 2, FigNewPos[1] - 1] == 0 || raznie) && FigNewPos[0] - 2 == NewPos[0] && FigNewPos[1] - 1 == NewPos[1]) { test = true; }
                    else if ((doska[FigNewPos[0] - 1, FigNewPos[1] - 2] == 0 || raznie) && FigNewPos[0] - 1 == NewPos[0] && FigNewPos[1] - 2 == NewPos[1]) { test = true; }
                }
                else if (FigNewPos[0] >= 2 && FigNewPos[1] >= 1)
                {
                    if ((doska[FigNewPos[0] - 2, FigNewPos[1] - 1] == 0 || raznie) && FigNewPos[0] - 2 == NewPos[0] && FigNewPos[1] - 1 == NewPos[1]) { test = true; }
                }
                else if (FigNewPos[0] >= 1 && FigNewPos[1] >= 2)
                {
                    if ((doska[FigNewPos[0] - 1, FigNewPos[1] - 2] == 0 || raznie) && FigNewPos[0] - 1 == NewPos[0] && FigNewPos[1] - 2 == NewPos[1]) { test = true; }
                }
                else { test = false; }
            }
            return test;
        }
        private bool SlonMove()
        {
            int a, b;
            a = FigNewPos[0] - NewPos[0];
            b = FigNewPos[1] - NewPos[1];
            bool test2 = a * a == b * b;
            int num1, num2, num3, num4;
            bool test = false;
            bool raznie = (doska[FigNewPos[0], FigNewPos[1]] > 0 && doska[NewPos[0], NewPos[1]] < 0) || (doska[FigNewPos[0], FigNewPos[1]] < 0 && doska[NewPos[0], NewPos[1]] > 0);

            if (test2)
            {
                if (doska[FigNewPos[0], FigNewPos[1]] > 0)
                {
                    if (FigNewPos[0] > FigNewPos[1]) num1 = 7 - FigNewPos[0]; else num1 = 7 - FigNewPos[1];//SE
                    if (FigNewPos[0] > FigNewPos[1]) num2 = 7 - FigNewPos[0]; else num2 = FigNewPos[1];//SW
                    if (FigNewPos[0] < FigNewPos[1]) num3 = FigNewPos[0]; else num3 = 7 - FigNewPos[1];//NE
                    if (FigNewPos[0] < FigNewPos[1]) num4 = FigNewPos[0]; else num4 = FigNewPos[1];//NW

                    if ((FigNewPos[0] < NewPos[0]) & (FigNewPos[1] < NewPos[1]))//SE
                    {
                        for (int i = 1; i < num1 + 1; i++)
                        {
                            if (doska[FigNewPos[0] + i, FigNewPos[1] + i] > 0) break;
                            if (FigNewPos[0] + i == NewPos[0] && FigNewPos[1] + i == NewPos[1]) { test = true; break; }
                            if (doska[FigNewPos[0] + i - 1, FigNewPos[1] + i - 1] < 0) break;
                        }
                    }
                    else if ((FigNewPos[0] < NewPos[0]) & (FigNewPos[1] > NewPos[1]))//SW
                    {
                        for (int i = 1; i < num2 + 1; i++)
                        {
                            if (doska[FigNewPos[0] + i, FigNewPos[1] - i] > 0) break;
                            if (FigNewPos[0] + i == NewPos[0] && FigNewPos[1] - i == NewPos[1]) { test = true; break; }
                            if (doska[FigNewPos[0] + i - 1, FigNewPos[1] - i + 1] < 0) break;
                        }
                    }
                    else if ((FigNewPos[0] > NewPos[0]) & (FigNewPos[1] < NewPos[1]))//NE
                    {
                        for (int i = 1; i < num3 + 1; i++)
                        {

                            if (doska[FigNewPos[0] - i, FigNewPos[1] + i] > 0) break;
                            if (FigNewPos[0] - i == NewPos[0] && FigNewPos[1] + i == NewPos[1]) { test = true; break; }
                            if (doska[FigNewPos[0] - i + 1, FigNewPos[1] + i - 1] < 0) break;
                        }
                    }
                    else//NW
                    {
                        for (int i = 1; i < num4 + 1; i++)
                        {
                            if (doska[FigNewPos[0] - i, FigNewPos[1] - i] > 0) break;
                            if (FigNewPos[0] - i == NewPos[0] && FigNewPos[1] - i == NewPos[1]) { test = true; break; }
                            if (doska[FigNewPos[0] - i + 1, FigNewPos[1] - i + 1] < 0) break;
                        }
                    }
                }
                else
                {
                    if (FigNewPos[0] > FigNewPos[1]) num1 = 7 - FigNewPos[0]; else num1 = 7 - FigNewPos[1];//SE
                    if (FigNewPos[0] > FigNewPos[1]) num2 = 7 - FigNewPos[0]; else num2 = FigNewPos[1];//SW
                    if (FigNewPos[0] < FigNewPos[1]) num3 = FigNewPos[0]; else num3 = 7 - FigNewPos[1];//NE
                    if (FigNewPos[0] < FigNewPos[1]) num4 = FigNewPos[0]; else num4 = FigNewPos[1];//NW

                    if ((FigNewPos[0] < NewPos[0]) & (FigNewPos[1] < NewPos[1]))//SE
                    {
                        for (int i = 1; i < num1 + 1; i++)
                        {
                            if (doska[FigNewPos[0] + i, FigNewPos[1] + i] < 0) break;
                            if (FigNewPos[0] + i == NewPos[0] && FigNewPos[1] + i == NewPos[1]) { test = true; break; }
                            if (doska[FigNewPos[0] + i - 1, FigNewPos[1] + i - 1] > 0) break;
                        }
                    }
                    else if ((FigNewPos[0] < NewPos[0]) & (FigNewPos[1] > NewPos[1]))//SW
                    {
                        for (int i = 1; i < num2 + 1; i++)
                        {
                            if (doska[FigNewPos[0] + i, FigNewPos[1] - i] < 0) break;
                            if (FigNewPos[0] + i == NewPos[0] && FigNewPos[1] - i == NewPos[1]) { test = true; break; }
                            if (doska[FigNewPos[0] + i - 1, FigNewPos[1] - i + 1] > 0) break;
                        }
                    }
                    else if ((FigNewPos[0] > NewPos[0]) & (FigNewPos[1] < NewPos[1]))//NE
                    {
                        for (int i = 1; i < num3 + 1; i++)
                        {
                            if (doska[FigNewPos[0] - i, FigNewPos[1] + i] < 0) break;
                            if (FigNewPos[0] - i == NewPos[0] && FigNewPos[1] + i == NewPos[1]) { test = true; break; }
                            if (doska[FigNewPos[0] - i + 1, FigNewPos[1] + i - 1] > 0) break;
                        }
                    }
                    else//NW
                    {
                        for (int i = 1; i < num4 + 1; i++)
                        {
                            if (doska[FigNewPos[0] - i, FigNewPos[1] - i] < 0) break;
                            if (FigNewPos[0] - i == NewPos[0] && FigNewPos[1] - i == NewPos[1]) { test = true; break; }
                            if (doska[FigNewPos[0] - i + 1, FigNewPos[1] - i + 1] > 0) break;
                        }
                    }
                }
            }
            return test;
        }
        private bool WhitePeskaMove()
        {

            bool test = false;
            if (NewPos[0] > FigNewPos[0])
            {
                if (doska[FigNewPos[0] + 1, FigNewPos[1]] == 0 && FigNewPos[0] + 1 == NewPos[0] && FigNewPos[1] == NewPos[1]) { test = true; }
                else if (FigNewPos[0] == 1 && doska[FigNewPos[0] + 1, FigNewPos[1]] == 0 && doska[FigNewPos[0] + 2, FigNewPos[1]] == 0 && FigNewPos[0] + 2 == NewPos[0] && FigNewPos[1] == NewPos[1]) { test = true; }
                if (FigNewPos[1] <7)
                {
                    if (doska[FigNewPos[0] + 1, FigNewPos[1] + 1] < 0 && FigNewPos[0] + 1 == NewPos[0] && FigNewPos[1] + 1 == NewPos[1]) { test = true; }

                }
                if (FigNewPos[1] >0)
                {
                    if (doska[FigNewPos[0] + 1, FigNewPos[1] - 1] < 0 && FigNewPos[0] + 1 == NewPos[0] && FigNewPos[1] - 1 == NewPos[1]) { test = true; }
                }
            }
            return test;
        }
        private bool BlackPeskaMove()
        {

            bool test = false;
            if (NewPos[0] < FigNewPos[0])
            {
                if (doska[FigNewPos[0] - 1, FigNewPos[1]] == 0 && FigNewPos[0] - 1 == NewPos[0] && FigNewPos[1] == NewPos[1]) { test = true; }
                else if (FigNewPos[0] == 6 && doska[FigNewPos[0] - 1, FigNewPos[1]] == 0 && doska[FigNewPos[0] - 2, FigNewPos[1]] == 0 && FigNewPos[0] - 2 == NewPos[0] && FigNewPos[1] == NewPos[1]) { test = true; }
                if (FigNewPos[1] < 7)
                {
                    if (doska[FigNewPos[0] - 1, FigNewPos[1] + 1] > 0 && FigNewPos[0] - 1 == NewPos[0] && FigNewPos[1] + 1 == NewPos[1]) { test = true; }
                }
                if (FigNewPos[1] > 0)
                {
                    if (doska[FigNewPos[0] - 1, FigNewPos[1] - 1] > 0 && FigNewPos[0] - 1 == NewPos[0] && FigNewPos[1] - 1 == NewPos[1]) { test = true; }
                }
            }
            return test;
        }
        private bool MoveForLedy()
        {
            bool test = false;
            if (MoveForLadia() || SlonMove())
                test = true;
            return test;
        }
        private bool MoveForKing()
        {
            bool test = false;
            int a, b;
            if (FigNewPos[1]==4 & FigNewPos[0]==0 & NewPos[0]==0 & NewPos[1]==6 & doska[0, 5] == 0 & doska[0, 6] == 0)
            {
                BRokir = 1;
                MethodInfo mi1 = BLadia2.GetType().GetMethod("OnClick", BindingFlags.NonPublic | BindingFlags.Instance);
                mi1.Invoke(BLadia2, new object[] { EventArgs.Empty });
                test = MoveForLadia();
                bool test1 = MoveForLadia();
                return test & test1;
            }
            else if (FigNewPos[1] == 4 & FigNewPos[0] == 0 & NewPos[0] == 0 & NewPos[1] == 2 & doska[0, 1] == 0 & doska[0, 2] == 0 & doska[0, 3] == 0)
            {
                BRokir = 2;
                MethodInfo mi2 = BLadia1.GetType().GetMethod("OnClick", BindingFlags.NonPublic | BindingFlags.Instance);
                mi2.Invoke(BLadia1, new object[] { EventArgs.Empty });
                test = MoveForLadia();
                bool test1 = MoveForLadia();
                return test & test1;
            }
            else if (FigNewPos[1] == 4 & FigNewPos[0] == 7 & NewPos[0] == 7 & NewPos[1] == 6  & doska[7, 5] == 0 & doska[7, 6] == 0)
            {
                CRokir = 1;
                MethodInfo mi3 = CLadia1.GetType().GetMethod("OnClick", BindingFlags.NonPublic | BindingFlags.Instance);
                mi3.Invoke(CLadia1, new object[] { EventArgs.Empty });
                test = MoveForLadia();
                bool test1 = MoveForLadia();
                return test & test1;
            }
            else if (FigNewPos[1] == 4 & FigNewPos[0] == 7 & NewPos[0] == 7 & NewPos[1] == 2 & doska[7, 1] == 0 & doska[7, 2] == 0 & doska[7, 3] == 0)
            {
                CRokir = 2;
                MethodInfo mi4 = CLadia2.GetType().GetMethod("OnClick", BindingFlags.NonPublic | BindingFlags.Instance);
                mi4.Invoke(CLadia2, new object[] { EventArgs.Empty });
                test = MoveForLadia();
                bool test1 = MoveForLadia();
                return test & test1;
            }
            
            a = NewPos[0] - FigNewPos[0];
            b = NewPos[1] - FigNewPos[1];
            bool test2 = ((a*a) < 2) && ((b*b) < 2);
            if(test2)
            {
                test = MoveForLedy();
            }
            return test;
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            this.Close();//Работа кнопки выхода
        }
        private void ShowAll()
        {
            for(int i=0; i<8; i++)
                for (int j = 0; j < 8; j++)
                {
                    //Показываю белые фигуры
                        if (doska[i, j] == 1)
                        {
                            BLadia1.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 2)
                        {
                            BKon1.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 3)
                        {
                            BSlon1.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 4)
                        {
                            BKorol.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 5)
                        {
                            BLedi.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 6)
                        {
                            BSlon2.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 7)
                        {
                            BKon2.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 8)
                        {
                            BLadia2.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }

                        //Показываю белые пешки
                        if (doska[i, j] == 9)
                        {
                            BP0.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 10)
                        {
                            BP1.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 11)
                        {
                            BP2.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 12)
                        {
                            BP3.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 13)
                        {
                            BP4.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 14)
                        {
                            BP5.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 15)
                        {
                            BP6.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == 16)
                        {
                            BP7.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                    //Показываю черные фигуры

                        if (doska[i, j] == -1)
                        {
                            CLadia1.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -2)
                        {
                            CKon1.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -3)
                        {
                            CSlon1.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -4)
                        {
                            CKorol.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -5)
                        {
                            CLedi.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -6)
                        {
                            CSlon2.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -7)
                        {
                            CKon2.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] ==- 8)
                        {
                            CLadia2.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }


                    //Показываю черные пешки
                        if (doska[i, j] == -9)
                        {
                            CP0.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -10)
                        {
                            CP1.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] ==-11)
                        {
                            CP2.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -12)
                        {
                            CP3.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -13)
                        {
                            CP4.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -14)
                        {
                            CP5.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -15)
                        {
                            CP6.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                        if (doska[i, j] == -16)
                        {
                            CP7.Location = new Point(tod.X + j * 74, tod.Y + i * 74);
                        }
                }

            //Рисую битые фигуры
            for (int i = 0; i < 32; i++)
            {
                if (MassiveOfDeadFigures[i]==0)
                {
                    break;
                }
                //Показываю белые фигуры
                if (MassiveOfDeadFigures[i] == 1)
                {
                    BLadia1.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 2)
                {
                    BKon1.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 3)
                {
                    BSlon1.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 4)
                {
                    BKorol.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 5)
                {
                    BLedi.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 6)
                {
                    BSlon2.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 7)
                {
                    BKon2.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 8)
                {
                    BLadia2.Location = new Point(tobf.X + i * 55, tobf.Y);
                }

                //Показываю белые пешки
                if (MassiveOfDeadFigures[i] == 9)
                {
                    BP0.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 10)
                {
                    BP1.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 11)
                {
                    BP2.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 12)
                {
                    BP3.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 13)
                {
                    BP4.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 14)
                {
                    BP5.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 15)
                {
                    BP6.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == 16)
                {
                    BP7.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                //Показываю черные фигуры

                if (MassiveOfDeadFigures[i] == -1)
                {
                    CLadia1.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -2)
                {
                    CKon1.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -3)
                {
                    CSlon1.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -4)
                {
                    CKorol.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -5)
                {
                    CLedi.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -6)
                {
                    CSlon2.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -7)
                {
                    CKon2.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -8)
                {
                    CLadia2.Location = new Point(tobf.X + i * 55, tobf.Y);
                }


                //Показываю черные пешки
                if (MassiveOfDeadFigures[i] == -9)
                {
                    CP0.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -10)
                {
                    CP1.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -11)
                {
                    CP2.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -12)
                {
                    CP3.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -13)
                {
                    CP4.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -14)
                {
                    CP5.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -15)
                {
                    CP6.Location = new Point(tobf.X + i * 55, tobf.Y);
                }
                if (MassiveOfDeadFigures[i] == -16)
                {
                    CP7.Location = new Point(tobf.X + i * 55, tobf.Y);
                }


            }


        }
        private bool PermissionToMove()
        {
            if (doska[FigNewPos[0], FigNewPos[1]] == 1 || doska[FigNewPos[0], FigNewPos[1]] == -1 || doska[FigNewPos[0], FigNewPos[1]] == -8 || doska[FigNewPos[0], FigNewPos[1]] == 8)
            {
                return MoveForLadia();
            }
            else if (doska[FigNewPos[0], FigNewPos[1]] == 2 || doska[FigNewPos[0], FigNewPos[1]] == -2 || doska[FigNewPos[0], FigNewPos[1]] == -7 || doska[FigNewPos[0], FigNewPos[1]] == 7)
            {
                return KonMove();
            }
            else if (doska[FigNewPos[0], FigNewPos[1]] == 3 || doska[FigNewPos[0], FigNewPos[1]] == -3 || doska[FigNewPos[0], FigNewPos[1]] == -6 || doska[FigNewPos[0], FigNewPos[1]] == 6)
            {
                return SlonMove();
            }
            else if (doska[FigNewPos[0], FigNewPos[1]] > 8 && doska[FigNewPos[0], FigNewPos[1]] < 17)
            {
                return WhitePeskaMove();
            }
            else if (doska[FigNewPos[0], FigNewPos[1]] < -8 && doska[FigNewPos[0], FigNewPos[1]] > -17)
            {
                return BlackPeskaMove();
            }
            else if (doska[FigNewPos[0], FigNewPos[1]] == 5 || doska[FigNewPos[0], FigNewPos[1]] == -5)
            {
                return MoveForLedy();
            }
            else if (doska[FigNewPos[0], FigNewPos[1]] == 4 || doska[FigNewPos[0], FigNewPos[1]] == -4)
            {
                return MoveForKing();
            }
            else
            {
                return true;
            }
        }
        private void NewMove()
        {

            if (CounterForMove == 2 || CounterForMove == 3)
            {
                if (PermissionToMove())
                {
                    if ((doska[NewPos[0], NewPos[1]] > 0 && doska[FigNewPos[0], FigNewPos[1]] < 0) || (doska[NewPos[0], NewPos[1]] < 0 && doska[FigNewPos[0], FigNewPos[1]] > 0))
                    {
                        MassiveOfDeadFigures[CMODF] = doska[NewPos[0], NewPos[1]];
                        CMODF++;
                        doska[NewPos[0], NewPos[1]] = doska[FigNewPos[0], FigNewPos[1]];
                        doska[FigNewPos[0], FigNewPos[1]] = 0;
                    }
                    else
                    {
                        int i = doska[NewPos[0], NewPos[1]];
                        doska[NewPos[0], NewPos[1]] = doska[FigNewPos[0], FigNewPos[1]];
                        doska[FigNewPos[0], FigNewPos[1]] = i;
                    }
                }
                ShowAll();
                CounterForMove = 0;
            }
            else 
                return;
        }
        private void M_Click(object sender, MouseEventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 2;
            
            else
                CounterForMove = 0;
            //Ищу расположение мышки на доске для массива доски
            for(int i=0; i<8; i++)
                for (int j = 0; j < 8; j++)
                {
                    if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                    {
                        NewPos[0] = i;
                        NewPos[1] = j;
                    }
                }

            NewMove();
            
        }
        private void BLadia1_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if(CounterForMove==0)
                CounterForMove = 1;
            if(CounterForMove==1)
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                    {
                        FigNewPos[0] = i;
                        FigNewPos[1] = j;
                    }
                }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
            
            
        }
        private void BLadia2_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
            
            

        }
        private void BKon1_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
            
            

        }
        private void BKon2_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
            
            

        }
        private void BSlon1_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
            
            

        }
        private void BSlon2_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }         
        private void BKorol_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if(CounterForMove==0)
                CounterForMove = 1;
            if(CounterForMove==1)
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                    {
                        FigNewPos[0] = i;
                        FigNewPos[1] = j;
                    }
                }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
            
            

        }
        private void BLedi_Click(object sender, EventArgs e)
        {
                        if (CounterForMove == 1)
                CounterForMove = 3;
            if(CounterForMove==0)
                CounterForMove = 1;
            if(CounterForMove==1)
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                    {
                        FigNewPos[0] = i;
                        FigNewPos[1] = j;
                    }
                }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
            
            

        }
        private void BP0_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }
        private void BP1_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }
        private void BP2_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }
        private void BP3_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }
        private void BP4_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }
        private void BP5_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }
        private void BP6_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }
        private void BP7_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CP0_Click(object sender, EventArgs e)
        {

            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }

        }

        private void CP1_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CP2_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CP3_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CP4_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CP5_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CP6_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CP7_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CLadia1_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CKon1_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CSlon1_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CKorol_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CLedi_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CSlon2_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CKon2_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }

        private void CLadia2_Click(object sender, EventArgs e)
        {
            if (CounterForMove == 1)
                CounterForMove = 3;
            if (CounterForMove == 0)
                CounterForMove = 1;
            if (CounterForMove == 1)
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            FigNewPos[0] = i;
                            FigNewPos[1] = j;
                        }
                    }
            if (CounterForMove == 3)
            {
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        if (MousePosition.X > tod.X + j * 74 && MousePosition.Y > tod.Y + i * 74 && MousePosition.X < tod.X + j * 74 + 74 && MousePosition.Y < tod.Y + i * 74 + 74)
                        {
                            NewPos[0] = i;
                            NewPos[1] = j;
                        }
                    }
                NewMove();
            }
        }
        private void Menu_Click(object sender, EventArgs e)
        {
            if (OpenMenu)
            {
                Exit.Visible = false;
                Replay.Visible = false;
                OpenMenu = false;
            }
            else
            {
                Exit.Visible = true;
                Replay.Visible = true;
                OpenMenu = true;
            }
        }
        private void UpdateDoska()
        {
            int[,] NewDoska = {//доска и все, что на ней расположено
            {1, 2, 3, 5, 4, 6, 7, 8}, 
            {9, 10, 11, 12, 13, 14, 15, 16},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {-9, -10, -11, -12, -13, -14, -15, -16},
            {-1, -2, -3, -5, -4, -6, -7, -8},};
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    doska[i, j] = NewDoska[i, j];
                }
            for (int i = 0; i < 32; i++)
            {
                MassiveOfDeadFigures[i] = 0;
            }
            CMODF = 0;
            ShowAll();
        }
        private void Replay_Click(object sender, EventArgs e)
        {
            UpdateDoska();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            tod = new Point(Convert.ToInt32(this.Size.Width / 2 - 296), Convert.ToInt32(this.Size.Height / 2 - 296));
            ShowAll();
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (tick < 2)
            {
                UpdateDoska();
            }
            tick++;
        }
    }
}



